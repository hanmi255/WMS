/**
 * 表示表格标题的数据结构，包含展开状态、内容列表和底部操作列表。
 */
export interface TableTitleListData {
	/**
	 * 指示表格内容是否展开。
	 */
	unfold: boolean;
	/**
	 * 指示表格右边两按钮是否显示。
	 */
	rightButton?: boolean;
	/**
	 * 内容列表，包含多个表格标题内容项。
	 */
	contentList: TableTitleContentList[];

	/**
	 * 底部操作列表，包含多个表格标题底部操作项。
	 */
	bottomList: TableTitleBottomData[];
}
/**
 * 表示表格标题的内容项。
 */
export interface TableTitleContentList {
	/**
	 * 内容项的名称。
	 */
	name: string;

	/**
	 * 内容项的类型，可以是以下之一：
	 * - "AddCal"
	 * - "AddCheckBox"
	 * - "AddDbcal"
	 * - "AddDbinput"
	 * - "AddSininput"
	 */
	type: "AddCal" | "AddCheckBox" | "AddDbcal" | "AddDbinput" | "AddSininput";

	/**
	 * 内容项的具体内容数组。
	 */
	content: string[];

	/**
	 * 可选的选项数据数组。
	 */
	optionData?: string[];
}
/**
 * 表示表格标题的底部操作项。
 */
export interface TableTitleBottomData {
	/**
	 * 操作项的名称。
	 */
	name: string;

	/**
	 * 图标类型，可以是以下之一：
	 * - "Add"
	 * - "Delete"
	 * - "Edit"
	 * - "Export"
	 * - "Load"
	 * - "Reset"
	 * - "Return"
	 * - "Save"
	 * - "Search"
	 */
	iconType: "Add" | "Delete" | "Edit" | "Export" | "Load" | "Reset" | "Return" | "Save" | "Search";
}
/**
 * 表示功能传输的数据结构。
 */
export interface FuncTransferData {
	/**
	 * 功能的名称。
	 */
	name: string;

	/**
	 * 可选的图标类型。
	 */
	iconType?: string;

	/**
	 * 可选的类型。
	 */
	type?: string;

	/**
	 * 可选的内容。
	 */
	content?: string;

	/**
	 * 指示是否为右侧按钮。
	 */
	rightButton?: true;
}
