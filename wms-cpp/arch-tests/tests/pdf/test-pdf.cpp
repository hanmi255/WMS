/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/08 11:02:33

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
#include <iostream>
#include <fstream>
#include "Macros.h"
#include "PdfComponent.h"

#include "gtest/gtest.h"

TEST(PdfTest, TestText) {
	// 创建PDF组件
	PdfComponent pdf;

	// 创建一个页面
	pdf.getNewPage();
	// 绘制文字
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title"), pdf.getCurrPageHeight() - 20);
	pdf.drawTextCenter(ZH_WORDS_GETTER("pdf.content"));
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.foot"), 20);
	
	// 再创建一个页面，使用ttf字体
	pdf.getNewPage(pdf.getTtFont("fonts/PenguinAttack.ttf"));
	// 绘制文字
	pdf.drawTextCenterH("I am ttf title", pdf.getCurrPageHeight() - 20);
	pdf.drawTextCenter("I am ttf content");
	pdf.drawTextCenterH("I am ttf foot", 20);
	
	// 保存到文件
	ASSERT_EQ(pdf.saveDocToFile("pdf-text.pdf"), true);
}

TEST(PdfTest, TestTpl) {
	// 测试注册渲染模板
	PdfComponent::registerTplRender("test", [](YAML::Node* node, PdfComponent* pdf, void* realData) {
		// 创建一个页面
		pdf->getNewPage();

		// 绘制静态数据
		auto title = (*node)["t"].as<std::string>();
		auto foot = (*node)["f"].as<std::string>();
		pdf->drawTextCenterH(title, pdf->getCurrPageHeight() - 20);
		pdf->drawTextCenterH(foot, 20);

		// 绘制动态数据
		std::string content = static_cast<std::string*>(realData)->c_str();
		pdf->drawTextCenter(content);
		});

	// 测试绘制
	PdfComponent pdf;
	auto content = ZH_WORDS_GETTER("pdf.content");
	pdf.drawWithTemplate("tpl/test.yaml", "test", &content);
	// 保存到文件
	pdf.saveDocToFile("pdf-tpl.pdf");
}

// 图码在线预览 https://zxing-cpp.github.io/zxing-cpp/demo_writer.html
TEST(PdfTest, TestPictureCode) {
	// 创建PDF组件
	PdfComponent pdf;
	// 创建一个页面
	pdf.getNewPage();
	// 图码临时保存位置
	std::string filepath = "tmp.jpg";
	// 定义条码中的内容
	std::string input = "11223344";
	// 生成条码到文件
	bool success = PdfComponent::genPictureCodeToFile(filepath, 200, 30, input, "Code93");
	if (success)
	{
		// 加载图片文件
		HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf.getDoc(), filepath.c_str());
		// 绘制图片到PDF中
		pdf.drawImage(image, 200, 500);
	}
	
	// 生成二维码到文件
	std::string url = "www.baidu.com";
	success = PdfComponent::genPictureCodeToFile(filepath, 200, 150, url, "QRCode");
	if (success)
	{
		// 加载图片文件
		HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf.getDoc(), filepath.c_str());
		// 绘制图片到PDF中
		pdf.drawImage(image, 200, 350);
	}
	// 保存到文件，这里演示使用内存数据保存到文件的方式
	auto data = pdf.saveDocToMem();
	auto buff = reinterpret_cast<const char*>(data.data());
	std::ofstream fsWrite;
	fsWrite.open("pdf-picturecode.pdf", std::ios::out | std::ios::binary);
	fsWrite.write(buff, data.size());
	fsWrite.close();
}