import { type Config } from "@ruan-cat/vercel-deploy-tool/src/config.ts";
import { domains } from "@ruan-cat/domains";

// 这里使用的是阮喵喵的vercel账号
export default <Config>{
	// 01星球专门的vercel部署项目
	vercelProjetName: "01s-vercel",
	vercelOrgId: "team_cUeGw4TtOCLp0bbuH8kA7BYH",
	vercelProjectId: "prj_0dbaKzhoqP9C3A7C4QDkzjSprN2L",

	/**
	 * 警告 token时效警告
	 *
	 * 这是阮喵喵自己提供的token，用的是阮喵喵的token，有效期仅为大项目期间。
	 *
	 * token标识名：  01s-10wsm-vercel-token
	 *
	 * 有效期：  25 年 8 月 19 日
	 */
	vercelToken: "RAR6YMjcE0cVTqjNEy30GIFo",

	// TODO: 后端接口尚未部署 不考虑反向代理
	// TODO: 处理项目的404页面显示，让vercel项目可以自己显示出404
	// vercelJsonPath: "./vercel.404.json",

	deployTargets: [
		// wms 主项目 预发布环境
		{
			type: "userCommands",
			targetCWD: "./",
			outputDirectory: "dist",
			url: domains["10wms"] as unknown as string[],
			userCommands: ["pnpm -C=./ build"],
		},

		// wms 前端技术文档
		{
			type: "userCommands",
			targetCWD: "./src",
			outputDirectory: ".vitepress/dist",
			// url: domains["10wms"] as unknown as string[],
			url: ["01s-10wms-frontend-docs.ruancat6312.top"],
			userCommands: ["pnpm -C=./ docs:build"],
		},
	],
};
