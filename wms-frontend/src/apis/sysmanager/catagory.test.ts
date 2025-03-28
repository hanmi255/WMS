import { describe, it } from "vitest";
import { sysmanagerCatagoryRemoveCatagory, sysmanagerCatagoryQueryCatagoryList } from "./catagory";

describe("分类管理接口实现", () => {
	it("新增分类接口", async () => {
		const { execute, data } = sysmanagerCatagoryAddCatagory({
			onSuccess(data) {
				console.log("新增分类接口 onSuccess", data);
			},
		});
		await execute({
			data: {
				name: "分类名称",
				parentId: "上级id",
				iconId: "fregwer",
			},
		});
		console.log("查看简单的 data.value ", data.value);
	});

	it("编辑分类接口", async () => {
		const { execute, data } = sysmanagerCatagoryModifyCatagory({
			onSuccess(data) {
				console.log("编辑分类接口 onSuccess", data);
			},
		});
		await execute({
			data: {
				id: "rfgwerg",
				iconId: "afger",
				name: "家清",
				parentId: "A01",
			},
		});
		console.log("查看简单的 data.value ", data.value);
	});

	it("分类列表查询接口", async () => {
		const { execute, data } = sysmanagerCatagoryQueryCatagoryList({
			onSuccess(data) {
				console.log("分类列表查询接口 onSuccess", data);
			},
		});
		await execute({
			data: {
				iconId: "rgwerghert",
			},
		});
		console.log("查看简单的 data.value ", data.value);
	});

	it("删除分类接口", async () => {
		const { execute, data } = sysmanagerCatagoryRemoveCatagory({
			onSuccess(data) {
				console.log("删除分类接口 onSuccess", data);
			},
		});
		await execute({
			data: {
				id: "",
			},
		});
		console.log("查看简单的 data.value ", data.value);
	});
});
