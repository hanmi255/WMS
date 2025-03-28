import { describe, it } from "vitest";

describe("温度信息-接口测试", () => {
	it("查询温度信息详情接口", async () => {
		const { execute, data } = daycheckTemperatureDetail();
		await execute();
		console.log(" ?? ", data.value);
	});
});
