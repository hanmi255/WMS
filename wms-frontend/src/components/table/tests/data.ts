/** 表格组件的测试业务数据 */
export interface TestBuziDataForTable {
	id: number;
	name: string;
	age: number;
}

// TODO: 使用测试框架 批量生成mock数据
export const testBuziDataForTable: TestBuziDataForTable[] = [
	{ id: 1, name: "张三", age: 18 },
	{ id: 2, name: "李四", age: 20 },
	{ id: 3, name: "王五", age: 22 },
	{ id: 4, name: "赵六", age: 25 },
	{ id: 5, name: "孙七", age: 28 },
	{ id: 6, name: "周八", age: 30 },
	{ id: 7, name: "吴九", age: 32 },
	{ id: 8, name: "郑十", age: 35 },
	{ id: 9, name: "钱十一", age: 38 },
	{ id: 10, name: "刘十二", age: 40 },
];
