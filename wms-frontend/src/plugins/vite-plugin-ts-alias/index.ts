import tsAlias from "vite-plugin-ts-alias";

export default tsAlias({
	/**
	 * tsconfig name, optional.
	 * @default 'tsconfig.json'
	 */
	tsConfigName: "tsconfig.app.json",
});
