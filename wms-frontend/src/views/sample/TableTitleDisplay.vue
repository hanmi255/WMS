<template>
	<div>
		<h1>表格标题栏展示及说明页面</h1>
		<p>组件位置:"src\components\table-title\TableTitle.vue"</p>
		<p>有问题请Q我or翻源码</p>
		<div style="border: 1px solid black">
			<div>
				<!-- 这里的接口就两个：v-model管数据；@user-click管子组件传过来的func -->
				<!-- 注意！！：传数据时请参考types\components\table-title.d.ts文件或者参考下面的实例数据titleData -->
				<TableTitle v-model="titleData" @user-click="userChildClick" />
			</div>
		</div>
		<div style="height: 200px; width: 100%; background: white; margin-top: 20px; overflow-y: auto">
			<div v-for="index in addList.length" :key="index">
				{{ addList[index - 1] }}
			</div>
		</div>
		<h3>试一试</h3>
		<div>
			是否显示展开按钮
			<el-switch v-model="titleData.unfold"></el-switch>
		</div>
		<div>
			<div>
				定义你自己的组件
				<div style="display: flex; justify-content: space-between; margin-top: 5px">
					<div>
						<el-button type="primary" @click="addContentData('日期框', 'AddCal')">添加日期框</el-button>
						<el-button type="primary" @click="addContentData('选择框', 'AddCheckBox')">添加选择框</el-button>
						<el-button type="primary" @click="addContentData('日期至日期框', 'AddDbcal')">添加日期至日期框</el-button>
						<el-button type="primary" @click="addContentData('输入框', 'AddSininput')">添加输入框</el-button>
						<el-button type="primary" @click="addContentData('输入至输入框', 'AddDbinput')">添加输入至输入框</el-button>
					</div>
					<el-button type="primary" @click="deletContentData()">清空列表</el-button>
				</div>
				<div style="display: flex; justify-content: space-between; margin-top: 5px">
					<div>
						<el-button type="primary" @click="addBottomData('添加', 'Add')">添加添加</el-button>
						<el-button type="primary" @click="addBottomData('删除', 'Delete')">添加删除</el-button>
						<el-button type="primary" @click="addBottomData('搜索', 'Search')">添加搜索</el-button>
						<el-button type="primary" @click="addBottomData('编辑', 'Edit')">添加编辑</el-button>
						<el-button type="primary" @click="addBottomData('导出', 'Export')">添加导出</el-button>
						<el-button type="primary" @click="addBottomData('加载', 'Load')">添加加载</el-button>
						<el-button type="primary" @click="addBottomData('重置', 'Reset')">添加重置</el-button>
						<el-button type="primary" @click="addBottomData('返回', 'Return')">添加返回</el-button>
						<el-button type="primary" @click="addBottomData('保存', 'Save')">添加保存</el-button>
					</div>
					<el-button type="primary" @click="deletBottomData()">清空列表</el-button>
				</div>
			</div>
		</div>
	</div>
</template>
<script setup lang="ts">
// 路由
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "表格标题栏",
		icon: "IconSetting",
	},
});
// 组件导入
import { ref } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
// 发送到子组件的数据
const titleData = ref<TableTitleListData>({
	unfold: true,
	rightButton: false,
	contentList: [
		{
			name: "日期框",
			type: "AddCal",
			content: ["", ""],
		},
		{
			name: "选择框",
			type: "AddCheckBox",
			content: ["", ""],
			optionData: ["马卡", "巴卡", "Makar", "Bakar"],
		},
		{
			name: "日期至日期",
			type: "AddDbcal",
			content: ["", ""],
		},
		{
			name: "输入框至输入框",
			type: "AddDbinput",
			content: ["", ""],
		},
		{
			name: "输入框",
			type: "AddSininput",
			content: ["", ""],
		},
	],
	bottomList: [
		{
			name: "编辑",
			iconType: "Edit",
		},
		{
			name: "删除",
			iconType: "Delete",
		},
		{
			name: "保存",
			iconType: "Save",
		},
	],
});
// 收到子组件的数据
const userChildClick = (data: FuncTransferData) => {
	const { name, iconType, rightButton } = data;
	if (name == "右侧查询" && rightButton == true) {
		console.log("VUE : 用户查询的数据 : one", titleData.value.contentList);
		addList.value.push(`用户点击了${name}按钮`);
		for (let index = 0; index < titleData.value.contentList.length; index++) {
			const addData =
				"查询数据为:" +
				titleData.value.contentList[index].name +
				": " +
				titleData.value.contentList[index].content[0] +
				titleData.value.contentList[index].content[1];
			addList.value.push(addData);
		}
	} else if (name == "右侧重置" && rightButton == true) {
		const { name } = data;
		addList.value.push(`用户点击了${name}按钮`);
		titleData.value.contentList.map((element: TableTitleContentList) => {
			element.content = ["", ""];
		});
	} else {
		console.log("VUE : 收到的数据 : one ", data);
		addList.value.push(`用户点击了 { name : ${name} ; iconType : ${iconType}} `);
	}
};
// 页面演示的数据和func
const addList = ref<string[]>([]);
const addContentData = (traName: string, traType: string) => {
	const dataOne = {
		name: traName,
		type: traType,
		optionData: ["黄色的奶龙", "绿色的奶龙", "蓝色的奶龙", "五彩斑斓的黑色的奶龙"],
	};
	titleData.value.contentList.push(dataOne);
};
const deletContentData = () => {
	titleData.value.contentList = [];
};
const addBottomData = (traName: string, traType: string) => {
	const dataOne = {
		name: traName,
		iconType: traType,
	};
	titleData.value.bottomList.push(dataOne);
};
const deletBottomData = () => {
	titleData.value.bottomList = [];
};
</script>
