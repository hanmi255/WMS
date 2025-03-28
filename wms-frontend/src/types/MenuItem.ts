/**
 * 菜单项
 * TODO: 查看接口文档 迁移到专门的api区域
 */
export interface MenuItem {
	id: number;
	functionname: string;
	iconName: string;
	functionurl?: string;
	parentfunctionid?: number;
	children?: MenuItem[];
}
