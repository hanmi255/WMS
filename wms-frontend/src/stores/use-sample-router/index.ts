import { useToggle } from "@vueuse/core";

/** 案例页面的状态控制对象 */
export const useSampleRouterStore = defineStore("sample-router", () => {
	const router = useRouter();

	/**
	 * 当前是否是案例页面？
	 * @description
	 * 当前路由的名称是否包含了 sample 字样？
	 * 用于判断当前路由是否是 sample 相关的页面
	 */
	const isSamplePage = computed(() => router.currentRoute.value.name?.includes("sample") ?? false);

	/** 当前页面是否是登录页？ */
	const isLoginPage = computed(() => router.currentRoute.value.name === "Login");

	/**
	 * 是否显示案例入口链接？
	 * @description
	 * 在开发模式下，才显示案例入口链接
	 */
	const isShowSampleLink = computed(() => import.meta.env?.DEV);

	const [
		/**
		 * 是否点击了入口链接？
		 * @description 默认定位
		 * @default false
		 */
		hasClickShowSampleLink,

		/** 设置点击状态 */
		setClickShowSampleLink,
	] = useToggle(false);

	watch(
		() => isSamplePage.value,
		(isSamplePage) => {
			if (isSamplePage) {
				// 如果是案例页面 那就认定为已经点击了案例链接
				setClickShowSampleLink(true);
			}
		},
	);

	watch(
		() => isLoginPage.value,
		(isLoginPage) => {
			if (isLoginPage) {
				// 如果是登陆页面 那就认定为没有点击案例链接
				setClickShowSampleLink(false);
			}
		},
	);

	/**
	 * 是否显示案例页面菜单？
	 * @description
	 * 如果认定用户已经点击了案例链接，那么就显示案例页面菜单
	 */
	const isShowSamplePageMenus = computed(() => hasClickShowSampleLink.value);

	return {
		isSamplePage,
		isShowSampleLink,
		isLoginPage,
		isShowSamplePageMenus,
		hasClickShowSampleLink,
		setClickShowSampleLink,
	};
});
