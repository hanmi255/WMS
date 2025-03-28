<template>
	<section class="auto-import-mini-example-root">
		<!-- 自动导入的最低限度案例 -->
		<ComponentsTable
			:data="[
				{ user: '阮喵喵', age: 18 },
				{ user: 'KK', age: 16 },
				{ user: 'awei', age: 30 },
			]"
			:columns="[
				{ prop: 'user', label: '用户名' },
				{ prop: 'age', label: '年龄' },
			]"
		/>
	</section>
</template>
