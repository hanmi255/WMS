import { describe, it } from "vitest";
import { sysmanagerTypegroupRemove } from "./typegroup";

describe("字典分类接口实现", () => {
	it("删除字典分类", async () => {
		const { execute, data } = sysmanagerTypegroupRemove({});
		await execute({
			url: "",
		});
		console.log(" ?? ", data.value);
	});
});
