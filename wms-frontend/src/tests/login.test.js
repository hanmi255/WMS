import { expect, describe, it, beforeAll, afterAll } from "vitest";
import { withSetup } from "./test-apis-settings";
import { login } from "@/apis/login";

// 测试指令 npm run test:unit login
describe("login", () => {
	let app;
	beforeAll(() => {
		app = withSetup()[1];
	});
	afterAll(() => {
		app.unmount();
	});
	// 测试调用登录接口
	it("login", async () => {
		await login(
			{
				username: "admin",
				password: "123456",
			},
			() => {
				expect(1).toBe(1);
			},
			() => {
				expect(0).toBe(1);
			},
		);
	});
	// 一个测试测试案例，用于演示多个测试案例
	it("login fail", async () => {
		expect(1).toBe(1);
	});
});
