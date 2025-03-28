// 这里导入你要使用的图标
// 写成多行避免解决冲突麻烦
import { Menu } from "@element-plus/icons-vue";
import { Setting } from "@element-plus/icons-vue";
import { User } from "@element-plus/icons-vue";
import { Tickets } from "@element-plus/icons-vue";
import { UploadFilled } from "@element-plus/icons-vue";
import { Printer } from "@element-plus/icons-vue";
import { Download } from "@element-plus/icons-vue";
import { Message } from "@element-plus/icons-vue";
import { House } from "@element-plus/icons-vue";

export default (app) => {
	app.component("IconMenu", Menu);
	app.component("IconSetting", Setting);
	app.component("IconUser", User);
	app.component("IconTickets", Tickets);
	app.component("IconUpload", UploadFilled);
	app.component("IconPrinter", Printer);
	app.component("IconDownload", Download);
	app.component("IconMessage", Message);
	app.component("IconHouse", House);
};
