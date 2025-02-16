#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:33:44
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
      https://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _EXCELCOMPONENT_H_
#define _EXCELCOMPONENT_H_
#include <xlnt/xlnt.hpp>
#include <string>
#include <vector>
/**
 * Excel组件
 * 注意：xlnt只支持xlsx文件格式
 */
class ExcelComponent
{
private:
	xlnt::workbook wb;
	xlnt::worksheet sheet;
	// 行高
	double rowHeight = 20;
	// 列宽
	double colWidth = 20;
	// 创建Sheet
	void createSheet(const std::string& sheetname);
	// 逐行写入数据
	void writeLineByLine(const std::vector<std::vector<std::string>>& source);
	// 逐行读取数据
	static void readLineByLine(xlnt::worksheet* source, std::vector<std::vector<std::string>>* target);
public:
	ExcelComponent();
	// 设置行高
	void setRowHeight(double rowHeight);
	// 设置列宽
	void setColWidth(double colWidth);
	// 清空工作薄
	void clearWorkbook();
	// 加载指定Excel文件到内存
	void loadFile(const std::string& filename);

	//************************************
	// Method:    writeVectorToFile
	// FullName:  ExcelComponent::writeVectorToFile
	// Access:    public 
	// Returns:   void
	// Parameter: const std::string& filename 文件名称的全路径，注意文件路径分隔符使用/
	// Parameter: const std::string& sheetname 新增内容保存到的页签名称
	// Parameter: const std::vector<std::vector<std::string>>& data 新增保存的数据
	// Description: 新增内容到指定页签，并保存到文件中
	//************************************
	void writeVectorToFile(const std::string& filename, const std::string& sheetname, const std::vector<std::vector<std::string>>& data);

	//************************************
	// Method:      writeVectorToBuff
	// FullName:    ExcelComponent::writeVectorToBuff
	// Access:      public 
	// Returns:     std::vector<std::uint8_t> 返回缓存结果，结果可以使用reinterpret_cast转换成const char*，如：const char* charData = reinterpret_cast<const char*>(data.data());
	// Parameter:   const std::string& sheetname 新增内容保存到的页签名称
	// Parameter:   const std::vector<std::vector<std::string>>& data 新增保存的数据
	// Description: 新增内容到指定页签，并保存到到缓存中方便传输
	//************************************
	std::vector<std::uint8_t> writeVectorToBuff(const std::string& sheetname, const std::vector<std::vector<std::string>>& data);
	
	//************************************
	// Method:    readIntoVector
	// FullName:  ExcelComponent::readIntoVector
	// Access:    public static
	// Returns:   std::vector<std::vector<std::string>> 指定页签内容的二维vector
	// Parameter: const std::string & filename 文件名称的全路径，注意文件路径分隔符使用/
	// Parameter: const std::string & sheetname 页签名称
	// Description: 读取指定文件指定页签的内容
	//************************************
	static std::vector<std::vector<std::string>> readIntoVector(const std::string& filename, const std::string& sheetname);
	
	//************************************
	// Method:      readIntoVector
	// FullName:    ExcelComponent::readIntoVector
	// Access:      public static
	// Returns:     std::vector<std::vector<std::string>> 指定页签内容的二维vector
	// Parameter:   const char* data 数据内容
	// Parameter:   size_t size 数据大小
	// Parameter:   const std::string & sheetname 页签名称
	// Description: 读取内存数据中指定页签的内容
	//************************************
	static std::vector<std::vector<std::string>> readIntoVector(const char* data, size_t size, const std::string& sheetname);
};
#endif // _EXCELCOMPONENT_H_
