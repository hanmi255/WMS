<script setup lang="ts">
import { Tickets } from "@element-plus/icons-vue";

definePage({
	meta: {
		menuType: "page",
		text: "订单类型",
		icon: Tickets,
	},
});
</script>

<style scoped lang="scss">
.picking-list {
	padding: 20px;
}
</style>
