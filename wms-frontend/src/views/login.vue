<script setup>
import { ref, reactive, onMounted } from "vue";
import { useI18n } from "vue-i18n"; // 引入 useI18n
import Verify from "@/components/verifition/Verify.vue"; // 登录表单数据
import { login } from "@/apis/login";
import { ElMessage } from "element-plus";
import { useRouter } from "vue-router";
import { User, Lock, Hide, View } from "@element-plus/icons-vue";

// 使用 i18n
const { t, locale } = useI18n();

// 定义页面路由信息
definePage({
	name: "Login",
	path: "/",
	meta: {
		layout: "login",
		menuType: "ignore", // 登录页不属于菜单侧边栏的一部分
	},
});

const sampleRouterStore = useSampleRouterStore();
const { setClickShowSampleLink } = sampleRouterStore;
const { isShowSampleLink } = storeToRefs(sampleRouterStore);

// 获取router对象
const $router = useRouter();

const formData = reactive({
	username: "",
	password: "",
	rememberUsername: false, // 记住用户名
});

// 验证码组件引用
const verify = ref(null);

// 验证码类型
const captchaType = ref("clickWord"); // 默认使用滑动验证码
const showPassword = ref(false); // 控制密码显示状态

// 验证码开关状态（默认根据环境变量设置）
const captchaEnabled = ref(true);
/**
 * 执行登录
 * @param {string} code 验证码字符串
 */
function doLogin(code) {
	console.log("登录请求参数:", { ...formData, code }); // 调试信息
	login(
		{
			...formData,
			code: captchaEnabled.value ? code : null, // 如果验证码关闭，则不发送验证码
		},
		() => {
			// 登录成功
			if (formData.rememberUsername) {
				// 保存用户名到 localStorage
				localStorage.setItem("savedUsername", formData.username);
			} else {
				// 清除 localStorage 中的用户名
				localStorage.removeItem("savedUsername");
			}
			$router.push("/home");
			ElMessage.success("登录成功，前往首页");
		},
		() => {
			// 登录失败
			ElMessage.error("账号或密码错误");
		},
	);
}

/**
 * 提交登录表单
 */

function submitForm() {
	if (captchaEnabled.value) {
		verify.value.show(); // 显示点击文字验证码
	} else {
		// 如果验证码关闭，直接执行登录
		doLogin(null);
	}
}

/**
 * 验证码验证通过后的回调
 * @param {object} res 验证码验证结果
 */
function handleSuccess(res) {
	// 验证码验证通过后，执行登录
	doLogin(res.captchaVerification);
}

function togglePasswordVisibility() {
	console.log("Toggle password visibility"); // 调试信息
	showPassword.value = !showPassword.value;
}

// 表单验证规则
const rules = reactive({
	username: [
		{ required: true, message: t("login.username"), trigger: "blur" },
		{ min: 3, max: 10, message: "账号长度在 3 到 10 个字符", trigger: "blur" },
	],
	password: [
		{ required: true, message: t("login.password"), trigger: "blur" },
		{ min: 6, max: 16, message: "密码长度在 6 到 16 个字符", trigger: "blur" },
	],
});

// 页面加载时，从 localStorage 读取保存的用户名
onMounted(() => {
	const savedUsername = localStorage.getItem("savedUsername");
	if (savedUsername) {
		formData.username = savedUsername;
		formData.rememberUsername = true; // 自动勾选“记住用户名”
	}
});
</script>

<template>
	<div class="video-background">
		<video autoplay muted loop class="video">
			<source src="/login.mp4" type="video/mp4" />
		</video>
		<div>
			<div class="login">
				<h1>{{ t("login.title") }}</h1>
				<el-form ref="formRef" :model="formData" :rules="rules" style="max-width: 600px">
					<div class="yh">
						<img src="../../public/favicon.ico" alt="" />
						<h2>&nbsp;&nbsp;用户登录</h2>
					</div>
					<hr />
					<el-form-item prop="username">
						<el-input v-model="formData.username" :prefix-icon="User" :placeholder="t('login.username')" />
					</el-form-item>

					<el-form-item label="" prop="password" class="custom-input">
						<el-input
							v-model="formData.password"
							:type="showPassword ? 'text' : 'password'"
							:prefix-icon="Lock"
							:placeholder="t('login.password')"
						>
							<template #suffix>
								<el-icon @click="togglePasswordVisibility">
									<component :is="showPassword ? View : Hide" />
								</el-icon>
							</template>
						</el-input>
					</el-form-item>

					<!-- 记住用户名和登录按钮 -->
					<el-form-item>
						<section style="display: flex; align-items: center; justify-content: space-between; width: 100%">
							<el-checkbox v-model="formData.rememberUsername">{{ t("login.rememberMe") }}</el-checkbox>
							<el-button type="primary" class="iconfont icon-key" @click="submitForm">
								&nbsp;&nbsp;{{ t("login.loginButton") }}
							</el-button>
						</section>
					</el-form-item>

					<!-- TODO[TEST_CODE]:测试代码后期发布需要删除 -->
					<el-form-item>
						<router-link v-if="isShowSampleLink" to="/sample" @click.native="setClickShowSampleLink(true)">
							进入示例演示页面
						</router-link>
					</el-form-item>
				</el-form>

				<div class="lang">
					<h1>语言 <i class="iconfont icon-arrowright"></i></h1>
					<!-- 语言切换 -->
					<el-select v-model="locale" class="custom-select">
						<el-option label="中文" value="zh" />
						<el-option label="English" value="en" />
					</el-select>
				</div>
			</div>
		</div>
	</div>

	<!-- 验证码组件 -->
	<Verify
		ref="verify"
		mode="pop"
		:captcha-type="captchaType"
		:img-size="{ width: '400px', height: '200px' }"
		@success="handleSuccess"
	></Verify>
</template>

<style>
.video-background {
	position: relative;
	width: 100%;
	height: 100vh;
	overflow: hidden;
}
.yh {
	display: flex;
	margin-bottom: 10px;
}
.video {
	position: absolute;
	top: 0;
	left: 0;
	width: 100%;
	height: 100%;
	object-fit: cover;
	z-index: -1; /* 将视频置于底层 */
}
::v-deep .el-input__inner {
	font-size: 16px;
	height: 35px;
	padding: 10px 10px;
}

.login {
	position: relative;
	z-index: 1; /* 将表单内容置于视频上方 */
	text-align: center;
	color: white;
	padding-top: 50px;
	width: 390px; /* 固定宽度 */
	margin: 0 auto; /* 居中 */

	h1 {
		margin-bottom: 20px;
		font-size: 30px;
		color: rgba(80, 80, 90);
		display: flex;
		align-items: center;
		justify-content: center;

		.iconfont {
			margin-left: 10px; /* 调整图标与文本的间距 */
		}
	}

	.el-form {
		width: 390px;
		height: 340px;
		background-color: rgba(234, 238, 242);
		margin: 0 auto;
		padding: 50px;
		box-shadow: 0 2px 12px rgba(0, 0, 0, 0.1);
		h2 {
			margin-bottom: 1px;
			font-size: 20px;
			color: rgba(66, 139, 202);
		}

		.el-form-item {
			margin-top: 20px;

			.el-button {
				background-color: rgba(66, 139, 202, 0.8);
				color: rgba(255, 255, 255);
				border: none;
				width: 90px;
				height: 40px;
				font-size: 16px;
			}
		}

		/* 记住用户名和登录按钮的样式 */
		.el-form-item:last-child {
			display: flex;
			align-items: center;
			justify-content: space-between;
			margin-top: 20px;

			.el-checkbox {
				margin-right: 105px; /* 调整复选框和按钮之间的间距 */
			}

			.el-button {
				margin-left: 0;
			}
		}
	}
}
.lang {
	width: 390px; /* 与 .login 的宽度一致 */
	margin: 0 auto; /* 居中 */
	background-color: rgba(66, 139, 202, 0.8);
	display: flex;
	align-items: center;
	justify-content: space-between; /* 让内容分布在两端 */
	padding: 10px; /* 添加内边距 */

	h1 {
		color: rgba(255, 238, 153);
		font-size: 15px;
		flex-shrink: 0; /* 防止文本过长挤压下拉框 */
		display: flex;
		align-items: center;
		margin: 0; /* 去掉默认的 margin */

		.iconfont {
			margin-left: 10px; /* 调整图标与文本的间距 */
		}
	}
}
/* 自定义下拉框样式 */
.custom-select {
	width: 11vh; /* 设置宽度 */
	margin-left: 10px; /* 调整与 h1 的间距 */
}
/* 下拉框弹出层宽度 */
.custom-select ::v-deep .el-select-dropdown {
	width: 11vh; /* 与输入框宽度一致 */
}
/* 下拉框输入框样式 */
.custom-select ::v-deep .el-input__inner {
	background-color: #f0f0f0;
	border: 1px solid #ccc;
	border-radius: 8px;
	color: #333;
	font-size: 14px;
	padding: 8px 12px;
}

/* 下拉框选项样式 */
.custom-select ::v-deep .el-select-dropdown__item {
	color: #555;
	font-size: 14px;
	padding: 8px 12px;
}

/* 下拉框选项悬停样式 */
.custom-select ::v-deep .el-select-dropdown__item:hover {
	background-color: #f5f5f5;
	color: #000;
}

/* 下拉框选项选中样式 */
.custom-select ::v-deep .el-select-dropdown__item.selected {
	background-color: #e0f0ff;
	color: #007bff;
}
</style>
