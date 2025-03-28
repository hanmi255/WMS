import Components from "unplugin-vue-components/vite";
import { ElementPlusResolver } from "unplugin-vue-components/resolvers";
import IconsResolver from "unplugin-icons/resolver";
import { resolver } from "../vite-plugin-autogeneration-import-file";

export default Components({
	version: 3,
	include: [],
	dirs: [
		// 不生成 不负责。目前此文件夹下面的组件，交给其他的插件实现生成，生成特定的命名规则前缀
	],
	dts: "./types/components.d.ts",
	directoryAsNamespace: true,
	resolvers: [
		ElementPlusResolver(),
		resolver([0]),
		IconsResolver({
			enabledCollections: ["icon-park"],
		}),
	],
});
