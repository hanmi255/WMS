import { defineStore } from "pinia";
import { ref } from "vue";

import type { MenuItem } from "types/MenuItem";
import type { TabPaneName } from "element-plus";

export const useTabStore = defineStore(
	"tab",
	() => {
		/**
		 * 记录当前tabs
		 */
		const tabs = ref<MenuItem[]>([]);
		/**
		 * 当前页面对应的TabPaneName
		 */
		const activeTab = ref<TabPaneName>("/home");

		/**
		 *设置当前 tabs
		 * @param newTabs
		 */
		const setTabs = (newTabs: MenuItem[]) => {
			tabs.value = newTabs;
		};
		/**
		 *设置当前activeTab
		 * @param tabName
		 */
		const setActiveTab = (tabName: TabPaneName) => {
			activeTab.value = tabName;
		};

		/**
		 * 添加tab
		 * @param newTab
		 */
		const addTab = (newTab: MenuItem) => {
			tabs.value.push(newTab);
		};

		/**
		 * 提取出所有没有子菜单的菜单项
		 * @param menus
		 * @returns
		 */
		const extractMinimalMenus = (menus: MenuItem[]): MenuItem[] => {
			const result: MenuItem[] = [];
			const traverse = (menuItems: MenuItem[]) => {
				menuItems.forEach((item) => {
					if (!item.children?.length) {
						result.push(item);
					} else {
						traverse(item.children);
					}
				});
			};
			traverse(menus);
			return result;
		};

		return {
			// state
			tabs,
			activeTab,

			// getters

			// actions
			setTabs,
			setActiveTab,
			addTab,
			extractMinimalMenus,
		};
	},
	{
		persist: true,
	},
);
