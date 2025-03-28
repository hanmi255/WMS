<script lang="ts" setup>
import { ref, computed } from "vue";
import { storeToRefs } from "pinia";

import { useUserStore } from "stores/user";
import { useTabStore } from "@/stores/tab";
import { useRouterToMenuItem } from "composables/use-routers-to-menu-item/index";

import { Fold, Expand, Bell, Message, SwitchButton, Setting, User, WarnTriangleFilled } from "@element-plus/icons-vue";
import { TabPaneName } from "element-plus";

import TotalDialog from "./components/totalDialog.vue";

import ChangePasswordDialog from "./components/ChangePasswordDialog.vue";
import UserInfoDialog from "./components/UserInfoDialog.vue";
import SystemMessageDialog from "./components/SystemMessageDialog.vue";
import HomeStyleDialog from "./components/HomeStyleDialog.vue";
import ClearCacheDialog from "./components/ClearCacheDialog.vue";
import LogoutDialog from "./components/LogoutDialog.vue";

import avatarImage from "@/assets/layoutIcon/avatar2.png";
import guestImage from "@/assets/layoutIcon/游客.png";
import noticeDetail from "./components/notice-detail.vue";
import { getUnreadNoticeListAPI } from "@/apis/notice-remind";
import { updateNoticeStatusAPI } from "@/apis/notice-remind";
// 控制弹框
const dialogVisible = ref(false);
// 用来控制进入哪个dialog
const status = ref(0);

const sampleRouterStore = useSampleRouterStore();
const { isShowSamplePageMenus } = storeToRefs(sampleRouterStore);

const userStore = useUserStore();
const router = useRouter();

console.log(` ? 检查getRoutes扁平化数组的结果`, getRoutes());

/** 来自自动路由数组 生成的菜单 */
const menuFromRouter = useRouterToMenuItem({
	routes: getRoutes(),
	isSampleMenu: isShowSamplePageMenus,
});

const { getMenus } = storeToRefs(userStore);

/** 用户信息提示 */
const userInfo = computed(() => {
	return userStore.getUser === null ? "游客" : userStore.getUser.username;
});

const tabStore = useTabStore();
const { activeTab, tabs } = storeToRefs(tabStore); // 当前激活的选项卡,标签选项数组
const { setActiveTab, setTabs, addTab, extractMinimalMenus } = tabStore;

/** 菜单数据 */
const menus = computed(() => [...getMenus.value /**, ...menuFromRouter.value */]);

const isCollapse = ref(false);

const toggleCollapse = () => {
	isCollapse.value = !isCollapse.value;
};

/**所有没有子菜单的菜单项 */
const minimalTabs = ref(extractMinimalMenus(menus.value));

const handleMenuSelect = (menu: string) => {
	// 检查tabs中是否已存在该menu对应的tab
	const existingTab = tabs.value.find((tab) => tab.functionurl === menu);
	if (!existingTab) {
		// 获取当前菜单项信息
		const menuItem = minimalTabs.value.find((item) => item.functionurl === menu);
		if (menuItem?.functionurl !== "/home") {
			// 将非首页菜单项信息添加到tabs数组中
			addTab(menuItem as MenuItem);
		}
	}
	setActiveTab(menu);
};

const removeTab = (tabName: TabPaneName) => {
	// 1. 查找目标标签页索引
	const tabIndex = tabs.value.findIndex((tab) => tab.functionurl === tabName);
	if (tabIndex === -1) return;
	// 2. 预先计算要切换的标签页（在删除前）
	let nextTab: MenuItem | null = null;
	if (tabs.value.length > 1) {
		nextTab =
			tabs.value[
				// 如果是最后一个标签页，取前一个；否则取后一个
				tabIndex === tabs.value.length - 1 ? tabIndex - 1 : tabIndex + 1
			];
	}
	// 3. 执行删除操作
	tabs.value.splice(tabIndex, 1);
	// 4. 处理路由跳转
	if (activeTab.value === tabName) {
		// 存在有效标签页时跳转
		if (nextTab?.functionurl) {
			setActiveTab(nextTab.functionurl);
			router.push(nextTab.functionurl);
		}
		// 完全无标签页时
		else {
			setActiveTab("/home");
			router.push("/home"); // 跳转默认路由
		}
	}
};

const handleTabChange = (tab: TabPaneName) => {
	setActiveTab(tab);
	router.push(tab as string);
};

const handleCommand = (command: string, tabName: string) => {
	switch (command) {
		case "refresh":
			router.go(0);
			break;
		case "close": {
			removeTab(tabName);
			break;
		}
		case "closeAll": {
			setTabs([]);
			activeTab.value = "/home";
			router.push("/home"); // 跳转默认路由
			break;
		}
		case "closeElse": {
			const currentTab = tabs.value.find((t) => t.functionurl === tabName);
			if (!currentTab) return;
			// 过滤保留当前标签和首页
			tabs.value = tabs.value.filter((t) => t.functionurl === tabName || t.functionurl === "/home");
			setActiveTab(tabName);
			router.push(tabName);
			break;
		}
		case "closeRight": {
			const currentIndex = tabs.value.findIndex((t) => t.functionurl === tabName);
			if (currentIndex === -1) return;
			activeTab.value = tabName;
			// 保留当前及左侧标签（slice含头不含尾）
			tabs.value = tabs.value.slice(0, currentIndex + 1);
			break;
		}
		case "closeLeft": {
			const currentIndex = tabs.value.findIndex((t) => t.functionurl === tabName);
			if (currentIndex === -1) return;
			activeTab.value = tabName;
			// 保留当前及右侧标签
			tabs.value = tabs.value.slice(currentIndex);
			break;
		}
	}
};

// 处理弹框逻辑
const showDialog = (i: any) => {
	status.value = i;
	dialogVisible.value = true;
};

const changePasswordDialogVisible = ref(false); // 修改密码控制弹框显示/隐藏
// 控制个人信息弹框显示/隐藏
const userInfoDialogVisible = ref(false);
// 系统消息控制弹框显示
const systemMessageDialogVisible = ref(false);
// 消息数据
const messages = ref([]);
// 打开弹框
const showSystemMessageDialog = () => {
	systemMessageDialogVisible.value = true;
};
// 控制弹框显示
const homeStyleDialogVisible = ref(false);

// 当前选中的风格
const currentStyle = ref("ace"); // 默认风格

// // 打开弹框
const showHomeStyleDialog = () => {
	homeStyleDialogVisible.value = true;
};

// 控制详情页
const showDetail = ref(false);

// 传递的标题
const dialogTitle = ref("");
// 传递的noticeId
const noticeId = ref();

// 页面加载时读取风格
onMounted(() => {
	const savedStyle = localStorage.getItem("homeStyle");
	if (savedStyle) {
		currentStyle.value = savedStyle; // 从 localStorage 中读取风格
	}
});
// 处理风格确认
const handleStyleConfirm = (style: string) => {
	currentStyle.value = style; // 更新当前风格
	localStorage.setItem("homeStyle", style); // 将风格保存到 localStorage
	console.log("选中的风格:", style);
};

// 根据当前风格动态设置首页的 class
const homeStyleClass = computed(() => {
	return `home-style-${currentStyle.value}`;
});
const clearCacheDialog = ref();

const handleClearCache = () => {
	// 模拟清除缓存操作
	clearCacheDialog.value.showDialog("浏览器缓存清除成功！");
};
const logoutDialog = ref();

const handleLogout = () => {
	logoutDialog.value.showDialog();
};

// 未读公告标题列表
const unreadNoticeList = ref([]);

// TODO 去往公告详情页
const goNoticeDetail = async (type: string, id: string) => {
	// 修改成已读
	console.log(id, typeof id);
	await updateNoticeStatusAPI({
		noticeId: id,
	});
	getUnreadNoticeList();
	noticeId.value = id;
	dialogTitle.value = type === "1" ? "通知公告详情" : "系统消息详情";
	showDetail.value = true;
};

// 未读公告数量
const unreadNoticeCount = ref(0);
// 获取未读公告标题列表
const getUnreadNoticeList = async () => {
	const res = await getUnreadNoticeListAPI();
	console.log(res);
	if (res.code === 10000) {
		unreadNoticeCount.value = res.data.length;
		if (res.data.length > 10) {
			// 最多显示10条未读公告
			unreadNoticeList.value = res.data.slice(0, 10);
		} else {
			unreadNoticeList.value = res.data;
		}
	} else if (res.code === 9999) {
		// 说明没有未读公告
	} else {
		ElMessage.error(res.message);
	}
};

onMounted(() => {
	getUnreadNoticeList();
});
</script>

<template>
	<div class="layout-container" :class="homeStyleClass">
		<el-container class="sec-container">
			<el-aside :style="{ width: isCollapse ? '64px' : '220px' }" class="sidebar-wrapper">
				<!-- 侧边栏菜单 -->
				<div class="menu-wrap">
					<el-scrollbar :style="{ width: isCollapse ? '64px' : '220px' }" class="scrollbar-wrap" max-height="100vh">
						<div :style="{ width: isCollapse ? '64px' : '220px' }" class="collapse-trigger" @click="toggleCollapse">
							<el-icon :size="20">
								<component :is="isCollapse ? Expand : Fold" />
							</el-icon>
						</div>

						<el-menu
							default-active="/home"
							class="sidebar-menu"
							active-text-color="#409EFF"
							text-color="#585858"
							background-color="#F9F9F9"
							unique-opened
							router
							:collapse="isCollapse"
							@select="handleMenuSelect"
						>
							<el-menu-item index="/home">
								<el-icon>
									<icon-menu />
								</el-icon>
								<span>首页</span>
							</el-menu-item>

							<template v-for="item in menus" :key="item.id">
								<template v-if="isShowSamplePageMenus">
									<el-menu-item :index="item.functionurl">
										<el-icon>
											<component :is="item.iconName" />
										</el-icon>
										<span> {{ item.functionname }} </span>
									</el-menu-item>
								</template>

								<template v-else>
									<el-sub-menu :index="item.id + ''">
										<template #title>
											<el-icon>
												<component :is="item.iconName" />
											</el-icon>
											<span>{{ item.functionname }}</span>
										</template>

										<el-menu-item-group>
											<el-menu-item v-for="i in item.children" :key="i.id" :index="i.functionurl">
												<el-icon>
													<component :is="i.iconName" />
												</el-icon>
												<span> {{ i.functionname }} </span>
											</el-menu-item>
										</el-menu-item-group>
									</el-sub-menu>
								</template>
							</template>
						</el-menu>
					</el-scrollbar>
				</div>
			</el-aside>

			<el-container>
				<!-- 导航栏 -->
				<el-header>
					<div class="header-nav">
						<div class="left"><span style="font-size: 20px">WMS仓储管理系统</span></div>
						<div class="right">
							<el-dropdown trigger="click">
								<div class="icon-container">
									<el-icon :size="20" class="icon move">
										<Bell />
										<span class="badge">{{ unreadNoticeCount }}</span>
									</el-icon>
								</div>

								<template #dropdown>
									<el-dropdown-menu size="large">
										<div class="notice">
											<div class="header">
												<el-icon style="margin: 0 4px 0 4px; color: #b471a0" size="16"><WarnTriangleFilled /></el-icon>
												<span>{{ unreadNoticeCount }}公告</span>
											</div>
											<div class="content">
												<ul>
													<li
														v-for="(item, index) in unreadNoticeList"
														@click="goNoticeDetail('1', item.noticeId)"
														:key="item.noticeId"
													>
														<svg
															t="1741875609474"
															class="icon"
															viewBox="0 0 1107 1024"
															version="1.1"
															xmlns="http://www.w3.org/2000/svg"
															p-id="3048"
															width="12"
															height="12"
														>
															<path
																d="M563.323289 661.336738a330.663562 330.663562 0 1 0-330.531877-330.663562 331.190306 331.190306 0 0 0 330.531877 330.663562z"
																fill="#ffffff"
																p-id="3049"
															></path>
															<path
																d="M1106.528066 975.53955c-16.724123-134.319727-137.611877-293.001365-273.38015-373.066457a381.889419 381.889419 0 0 1-539.912627-0.65843C157.335331 679.246035 18.274908 834.635523 0.365611 975.53955a42.797952 42.797952 0 0 0 37.26714 48.065392h1031.628175A43.061324 43.061324 0 0 0 1106.528066 975.53955z"
																fill="#ffffff"
																p-id="3050"
															></path>
														</svg>
														<span>{{ item.noticeTitle }}</span>
													</li>
												</ul>
											</div>
											<div class="footer" @click="showDialog(1)">
												<span>查看全部</span>
												<svg
													t="1741346481645"
													class="icon"
													viewBox="0 0 1024 1024"
													version="1.1"
													xmlns="http://www.w3.org/2000/svg"
													p-id="1825"
													width="16"
													height="16"
												>
													<path
														d="M885.113 489.373L628.338 232.599c-12.496-12.497-32.758-12.497-45.254 0-12.497 12.497-12.497 32.758 0 45.255l203.3 203.3H158.025c-17.036 0-30.846 13.811-30.846 30.846 0 17.036 13.811 30.846 30.846 30.846h628.36L583.084 746.147c-12.497 12.496-12.497 32.758 0 45.255 6.248 6.248 14.438 9.372 22.627 9.372s16.379-3.124 22.627-9.372l256.775-256.775a31.999 31.999 0 0 0 0-45.254z"
														fill="#4f99c6"
														p-id="1826"
													></path>
												</svg>
											</div>
										</div>
									</el-dropdown-menu>
								</template>
							</el-dropdown>

							<el-dropdown trigger="click">
								<div class="icon-container">
									<el-icon :size="20" class="icon move">
										<Message />
										<span class="badge">0</span>
									</el-icon>
								</div>

								<template #dropdown>
									<el-dropdown-menu size="large">
										<div class="notice">
											<div class="header">
												<el-icon style="margin: 0 4px 0 4px; color: #b471a0" size="16"><Message /></el-icon>
												<span>0消息</span>
											</div>
											<div class="content">
												<ul>
													<li
														v-for="(item, index) in messageList"
														:key="item.noticeId"
														@click="goNoticeDetail('2', noticeId)"
													>
														<svg
															t="1741877490824"
															class="icon"
															viewBox="0 0 1024 1024"
															version="1.1"
															xmlns="http://www.w3.org/2000/svg"
															p-id="4218"
															width="16"
															height="16"
														>
															<path
																d="M815.2064 150.272H221.3376c-68.6592 0-124.3136 55.6544-124.3136 124.3136v395.9296c0 68.6592 55.6544 124.3136 124.3136 124.3136h194.816l68.7104 73.3696c20.0704 21.4016 54.1184 21.0944 73.7792-0.7168l65.4848-72.6528h191.1296c68.6592 0 124.3136-55.6544 124.3136-124.3136V274.5344c-0.0512-68.608-55.7056-124.2624-124.3648-124.2624zM287.5392 524.6976c-32.5632 0-58.9312-26.368-58.9312-58.9312 0-32.5632 26.368-58.9312 58.9312-58.9312s58.9312 26.368 58.9312 58.9312c0 32.512-26.4192 58.9312-58.9312 58.9312z m234.752 0c-32.5632 0-58.9312-26.368-58.9312-58.9312 0-32.5632 26.368-58.9312 58.9312-58.9312 32.5632 0 58.9312 26.368 58.9312 58.9312 0 32.512-26.368 58.9312-58.9312 58.9312z m234.8032 0c-32.5632 0-58.9312-26.368-58.9312-58.9312 0-32.5632 26.368-58.9312 58.9312-58.9312 32.5632 0 58.9312 26.368 58.9312 58.9312 0 32.512-26.368 58.9312-58.9312 58.9312z"
																fill="#ffffff"
																p-id="4219"
															></path>
														</svg>
														<span>{{ item.noticeTitle }}</span>
													</li>
												</ul>
											</div>
											<div class="footer" @click="showDialog(2)">
												<span>查看全部消息</span>
												<svg
													t="1741346481645"
													class="icon"
													viewBox="0 0 1024 1024"
													version="1.1"
													xmlns="http://www.w3.org/2000/svg"
													p-id="1825"
													width="16"
													height="16"
												>
													<path
														d="M885.113 489.373L628.338 232.599c-12.496-12.497-32.758-12.497-45.254 0-12.497 12.497-12.497 32.758 0 45.255l203.3 203.3H158.025c-17.036 0-30.846 13.811-30.846 30.846 0 17.036 13.811 30.846 30.846 30.846h628.36L583.084 746.147c-12.497 12.496-12.497 32.758 0 45.255 6.248 6.248 14.438 9.372 22.627 9.372s16.379-3.124 22.627-9.372l256.775-256.775a31.999 31.999 0 0 0 0-45.254z"
														fill="#4f99c6"
														p-id="1826"
													></path>
												</svg>
											</div>
										</div>
									</el-dropdown-menu>
								</template>
							</el-dropdown>

							<el-dropdown trigger="click">
								<span style="color: white" class="move">
									<!-- 根据用户是否登录显示不同的图片 -->
									<img
										v-if="userStore.getUser !== null"
										:src="avatarImage"
										alt="欢迎用户"
										style="width: 32px; height: 32px; vertical-align: middle; border-radius: 50%"
									/>
									<img
										v-else
										:src="guestImage"
										alt="欢迎游客"
										style="width: 32px; height: 32px; vertical-align: middle; border-radius: 50%"
									/>
									{{ userInfo }}
								</span>

								<template #dropdown>
									<el-dropdown-menu size="large">
										<el-dropdown-item :icon="User" @click="userInfoDialogVisible = true">个人信息</el-dropdown-item>
										<el-dropdown-item :icon="Setting" @click="showSystemMessageDialog"> 系统消息 </el-dropdown-item>
										<el-dropdown-item :icon="Setting" @click="showHomeStyleDialog"> 首页风格 </el-dropdown-item>
										<el-dropdown-item :icon="Setting" @click="handleClearCache">消除缓存</el-dropdown-item>
										<el-dropdown-item :icon="SwitchButton" @click="changePasswordDialogVisible = true"
											>修改密码</el-dropdown-item
										>
										<el-dropdown-item :icon="SwitchButton" @click="handleLogout">注销</el-dropdown-item>
									</el-dropdown-menu>
								</template>
							</el-dropdown>
						</div>
					</div>
				</el-header>

				<el-main>
					<el-tabs
						v-model="activeTab"
						type="card"
						class="demo-tabs"
						@tab-remove="removeTab"
						@tab-change="handleTabChange"
					>
						<el-tab-pane label="首页" name="/home" :closable="false"></el-tab-pane>
						<el-tab-pane
							v-for="item in tabs"
							:key="item?.functionurl"
							closable
							:label="item?.functionname"
							:name="item?.functionurl"
						>
							<template #label>
								<el-dropdown @command="(command) => handleCommand(command, item?.functionurl as string)">
									<span :style="{ color: item?.functionurl === activeTab ? '#409EFF' : '#64696D' }">
										{{ item?.functionname }}
									</span>
									<template #dropdown>
										<el-dropdown-menu>
											<el-dropdown-item command="refresh">刷新缓存</el-dropdown-item>
											<el-dropdown-item command="close">关闭</el-dropdown-item>
											<el-dropdown-item command="closeAll">全部关闭</el-dropdown-item>
											<el-dropdown-item command="closeElse">除此之外全部关闭</el-dropdown-item>
											<el-dropdown-item divided command="closeRight">当前也右侧关闭</el-dropdown-item>
											<el-dropdown-item command="closeLeft">当前页左侧关闭</el-dropdown-item>
										</el-dropdown-menu>
									</template>
								</el-dropdown>
							</template>
						</el-tab-pane>
					</el-tabs>
					<!-- 布局路由 -->
					<router-view />
				</el-main>
			</el-container>
		</el-container>
	</div>

	<!-- 修改密码弹框 -->
	<ChangePasswordDialog v-model="changePasswordDialogVisible" />
	<!-- 个人信息弹框 -->
	<UserInfoDialog v-model:visible="userInfoDialogVisible" />
	<SystemMessageDialog v-model:visible="systemMessageDialogVisible" :messages="messages" />
	<HomeStyleDialog v-model:visible="homeStyleDialogVisible" @confirm="handleStyleConfirm" />
	<!-- 清除缓存弹框 -->
	<ClearCacheDialog ref="clearCacheDialog" />
	<!-- 注销弹框 -->
	<LogoutDialog ref="logoutDialog" />
	<!-- 点击右上角按钮中的查看全部后显示的组件 -->
	<TotalDialog v-model:visible="dialogVisible" :status="status"></TotalDialog>
	<noticeDetail v-model:control="showDetail" :dialogTitle="dialogTitle" :noticeId="noticeId"></noticeDetail>
</template>

<style scoped>
.sec-container {
	height: 100vh;
}
.el-aside {
	background-color: #f9f9f9;
}
.sidebar-wrapper {
	transition: width 0.6s ease;
	background-color: #f9f9f9;
}
.sidebar-menu {
	border-right: none;
	background-color: inherit;
}
.collapse-trigger {
	height: 60px;
	display: flex;
	align-items: center;
	justify-content: center;
	cursor: pointer;
	color: #fff;
	background-color: #2b2f3a;
	transition: width 0.6s ease;
}

.menu-wrap {
	height: 100vh;
	width: 220px;
	position: fixed;
	top: 0;
	left: 0;
}
.scrollbar-wrap {
	transition: width 0.6s ease;
}
.el-menu {
	border: 0;
}
.el-menu-item-group .el-menu-item {
	text-indent: 1.5em;
}
.el-main {
	padding: 20px;
}
.el-header {
	background-color: #fff;
	display: flex;
	justify-content: space-between;
	padding: 0;
}
.header-nav {
	display: flex;
	padding: 20px;
	background-color: #6c777f;
	width: 100%;
	color: #f8f8f8;
	justify-content: space-between;
	line-height: 20px;
}
.header-nav .right {
	width: 200px;
	display: flex;
	align-items: center;
	justify-content: space-around;
}

/* 去除dropdown黑框 */
.el-tooltip__trigger:focus-visible {
	outline: unset;
}

/* 按钮小数字 */
.icon-container {
	position: relative;
	display: inline-block;
}

.icon-container .el-icon {
	width: 30px;
	height: 30px;
	color: white;
}

.badge {
	position: absolute;
	top: 0px; /* 距离图标上边的距离 */
	right: 0px; /* 距离图标右边的距离 */
	background-color: red; /* 背景色，可以修改 */
	color: white; /* 字体颜色 */
	width: 10px; /* 宽度 */
	height: 10px; /* 高度 */
	border-radius: 50%; /* 圆形 */
	display: flex;
	justify-content: center;
	align-items: center;
	font-size: 12px; /* 数字字体大小 */
}

.move {
	cursor: pointer;
}

/* 右上角下拉菜单样式 */
.notice {
	width: 240px;
	/* height: 100px; */
	display: flex;
	flex-wrap: wrap;
}
.notice .header {
	padding: 0px 0px;
	background-color: #f4deea;
	border-bottom: 1px solid #d3d0d0;
	width: 100%;
	height: 35px;
	line-height: 35px;
	display: flex;
	align-items: center;
}

.notice .header el-icon {
}
.notice .header span {
	color: #c06090;
	font-size: 16px;
}

.notice .content {
	border-bottom: 1px solid #efefef;
}
.notice .content ul {
	/* width: 900%; */
	list-style: none;
	display: flex;
	flex-wrap: wrap;
	padding-left: 12px;
	align-items: center;
}

.notice .content ul li {
	padding-right: 0;
	height: 25px;
	margin-top: 5px;
	width: 100%;
	display: flex;
}
.notice .content ul li svg {
	width: 20px;
	height: 20px;
	color: white;
	background-color: #428bca;
	border: 3px solid #428bca;
	margin-right: 5px;
	cursor: pointer;
}

.notice .content ul li svg:hover {
	border-bottom: 1px solid #428bca;
}

.notice .content ul li span {
	font-size: 12px;
	line-height: 20px;
	color: #428bca;
	cursor: pointer;
}

.notice .content ul li span:hover {
	border-bottom: 1px solid #428bca;
}

.notice .footer {
	padding: 0;
	cursor: pointer;
	width: 100%;
	text-align: center;
	height: 40px;
	color: #4f99c6;
	line-height: 40px;
}

.notice .footer span:hover {
	border-bottom: 0.5px solid #4f99c6;
}
.notice .footer:hover {
	background-color: #f4deea;
	width: 100%;
}

.el-dropdown-menu {
	padding: 0px 0px;
}

span {
	font-size: 14px;
}

/* 隐藏滚动条样式 */
::v-deep(.el-scrollbar__bar.is-horizontal) {
	top: 0;
	bottom: 0;
	width: 0;
	height: 0;
}
.home-style-ace {
	/* ACE平面风格样式 */
	background-color: rgba(255, 231, 81, 0.6);
	font-family: Arial, sans-serif;
	color: #333;
	/* 标题样式 */
	.header-nav {
		background-color: rgba(12, 181, 116); /* 设置导航栏背景颜色 */
		padding: 20px; /* 设置内边距 */
		color: #fff; /* 设置文字颜色为白色 */

		.left {
			font-size: 24px; /* 设置标题字体大小 */
			font-weight: bold; /* 设置标题字体加粗 */
		}
	}
}

.home-style-shortcut {
	/* ShortCut风格样式 */
	background-color: rgba(224, 236, 255);
	/* 标题样式 */
	.header-nav {
		background-color: rgba(168, 215, 233); /* 设置导航栏背景颜色 */
		padding: 20px; /* 设置内边距 */
		color: rgba(93, 102, 114); /* 设置文字颜色为白色 */

		.left {
			font-size: 24px; /* 设置标题字体大小 */
			font-weight: bold; /* 设置标题字体加粗 */
		}
	}
}
.home-style-classic {
	/* 经典风格样式 */
	background-color: #d0d0d0;
	font-family: "Times New Roman", serif;
	color: #333;

	/* 标题样式 */
	.header-nav {
		background-color: rgba(93, 102, 114); /* 设置导航栏背景颜色 */
		padding: 20px; /* 设置内边距 */

		.left {
			font-size: 24px; /* 设置标题字体大小 */
			font-weight: bold; /* 设置标题字体加粗 */
		}
	}
}

.home-style-hplus {
	/* H+平面风格样式 */
	background-color: rgba(255, 115, 162, 0.4);
	/* 标题样式 */
	.header-nav {
		background-color: rgba(163, 167, 254, 0.8); /* 设置导航栏背景颜色 */
		padding: 20px; /* 设置内边距 */
		color: rgba(93, 102, 114);
		.left {
			font-size: 24px; /* 设置标题字体大小 */
			font-weight: bold; /* 设置标题字体加粗 */
		}
	}
}
</style>
