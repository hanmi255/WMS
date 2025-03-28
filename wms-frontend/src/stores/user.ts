import { defineStore } from "pinia";
import { ref, computed } from "vue";
import Request from "@/apis/request";

import type { MenuItem } from "types/MenuItem";
import type { User } from "types/User";

export const useUserStore = defineStore("user", () => {
	/** 记录token */
	const token = ref<string | null>(null);

	/** 记录refreshToken */
	const refreshToken = ref<string | null>(null);

	/** 保存一个标识信息，指示登陆后需要加载的初始化数据是否完成 */
	const loaded = ref(false);

	/** 保存当前用户 */
	const user = ref<User | null>(null);

	/** 菜单数据 */
	const menus = ref<MenuItem[]>([]);

	/** 获取token */
	const getToken = computed(() => token.value || localStorage.getItem("token"));

	/** 是否已加载 */
	const isLoaded = computed(() => loaded.value);

	/** 获取当前用户 */
	const getUser = computed(() => user.value);

	/** 测试菜单数据 */
	const testMenus = ref<MenuItem[]>([
		{
			path: "/daily-check",
			name: "daily-check",
			//
			id: 567,
			text: "日常检查",
			href: "/daily-check",
			icon: "IconTickets",
			children: [
				{
					// path: "abnormal-shipment",
					// name: "daily-check-abnormal-shipment",
					//
					id: 568,
					text: "异常出库",
					// href: "/daily-check/abnormal-shipment-",
					href: "abnormal-shipment",
					icon: "IconTickets",
				},
				{
					// path: "received-unsold",
					// name: "daily-check-received-unsold",
					// @ts-ignore
					meta: {
						id: 569,
						text: "收货未上架",
						href: "/received-unsold",
						icon: "IconSetting",
						pid: 99,
					},
					alias: [],
					//
					id: 570,
					text: "收货未上架",
					href: "/daily-check/received-unsold",
					icon: "IconTickets",
				},
			],
		},
	]);

	/** 获取菜单 */
	// const getMenus = computed(() => [...menus.value, ...testMenus.value]);
	const getMenus = computed(() => menus.value);

	/** 加载用户 */
	async function loadUser() {
		// 发送获取当前用户信息请求
		const data = await Request.requestForm(Request.GET, "/login/current-user", null);
		user.value = data.data;
	}

	/** 加载菜单 */
	async function loadMenus() {
		//TODO[TEST_CODE]:此处写测试数据设定
		//this.menus = testMenus

		// 发送获取菜单请求
		const data = await Request.requestForm(Request.GET, "/login/get-menus", null);
		menus.value = data.data;
	}

	/** 加载刷新凭证 */
	function loadRefreshToken() {
		if (!refreshToken.value) {
			refreshToken.value = localStorage.getItem("refreshToken");
		}
	}

	/** 刷新token */
	async function reloadToken() {
		// 先加载刷新凭证
		loadRefreshToken();

		// 发送刷新凭证请求
		const data = await Request.requestForm(Request.POST, "/login/refresh-token", {
			refreshToken: refreshToken.value,
			clientId: import.meta.env.VITE_API_URL,
		});

		//设置Token相关属性
		setToken(data.data);
	}

	/** 设置是否加载完成 */
	function setLoaded(isLoaded: boolean) {
		loaded.value = isLoaded;
	}

	/** 设置token */
	function setToken(data: { token: string; refreshToken: string }) {
		token.value = data.token;
		refreshToken.value = data.refreshToken;
		localStorage.setItem("token", data.token);
		localStorage.setItem("refreshToken", data.refreshToken);
	}

	/** 重置数据 */
	function resetSaveData() {
		loaded.value = false;
		user.value = null;
		token.value = null;
		refreshToken.value = null;
		localStorage.removeItem("token");
		localStorage.removeItem("refreshToken");
	}
	/** 清除用户信息（注销时调用） */
	function clearUser() {
		resetSaveData(); // 清除 Token 和用户信息
		menus.value = []; // 清空菜单数据
	}

	return {
		// state
		token,
		refreshToken,
		loaded,
		user,
		menus,
		testMenus,

		// getters
		getToken,
		isLoaded,
		getUser,
		getMenus,

		// actions
		loadUser,
		loadMenus,
		loadRefreshToken,
		reloadToken,
		setLoaded,
		setToken,
		resetSaveData,
		clearUser, // 添加 clearUser 方法
	};
});
