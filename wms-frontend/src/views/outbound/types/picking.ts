export interface Column {
	title: string;
	field: string;
	width?: number;
	editable?: boolean;
	formatter?: (val: any) => string;
}

export interface TableData {
	id: string | number;
	[key: string]: any;
}
