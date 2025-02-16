/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/12/28 21:32:53

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
#ifdef USE_PDF

#include "pch.h"
#include "../include/PdfComponent.h"
#include "yaml-cpp/yaml.h"
#include "CharsetConvertHepler.h"
#include <iostream>
#include "zxing/MultiFormatWriter.h"
#include "zxing/CharacterSet.h"
using namespace ZXing;

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

std::map<std::string, PdfTplRenderCf> PdfComponent::tplRender;

// 图码在线预览 https://zxing-cpp.github.io/zxing-cpp/demo_writer.html
ZXing::Matrix<uint8_t> PdfComponent::genPictureCode(const int& w, const int& h, const std::string& text, const std::string& type, const int& margin, const int& eccLevel)
{
	// 格式化类型
	BarcodeFormat format = BarcodeFormatFromString(type);
	// 生成图形码
	auto writer = MultiFormatWriter(format)
		.setMargin(margin)
		.setEncoding(CharacterSet::UTF8)
		.setEccLevel(eccLevel);
	BitMatrix matrix = writer.encode(text, w, h);
	return ToMatrix<uint8_t>(matrix);
}

void PdfComponent::registerTplRender(const std::string& tplName, PdfTplRenderCf cf)
{
	tplRender.insert(std::make_pair(tplName, cf));
}

PdfComponent::PdfComponent()
{
	/**
	 * 异常处理函数，相关错误码定义在hpdf_error.h中
	 * 错误码信息参考：https://github.com/libharu/libharu/wiki/Error-handling
	 */
	auto fun = [](HPDF_STATUS error_no, HPDF_STATUS detail_no, void* user_data) {
		printf("ERROR: error_no=%04X, detail_no=%d\n", (unsigned int)error_no, (int)detail_no);
		/* throw exception on error */
		throw std::runtime_error("trigger hpdf_error_handler.");
		};
	_doc = HPDF_New(fun, NULL);
	if (!_doc)
	{
		throw std::runtime_error("error: cannot create PdfDoc object.");
	}
	_currPage = 0;
	_currFontSize = 20;
	_currFont = 0;
	// 标记是否使用使用了编码器
	isUseCnsEncoding = false;
	isUseCntEncoding = false;
	isUseUtfEncoding = false;
}

PdfComponent::~PdfComponent()
{
	if (_doc)
	{
		HPDF_Free(_doc);
	}
}

HPDF_Doc PdfComponent::getDoc() const
{
	return _doc;
}

HPDF_Page PdfComponent::getCurrPage() const
{
	return _currPage;
}

HPDF_REAL PdfComponent::getCurrPageWidth() const
{
	return HPDF_Page_GetWidth(_currPage);
}

HPDF_REAL PdfComponent::getCurrPageHeight() const
{
	return HPDF_Page_GetHeight(_currPage);
}

void PdfComponent::setCurrPageFontAndSize(HPDF_Font font, HPDF_REAL size)
{
	if (!_currPage) return;
	_currFont = font;
	_currFontSize = size;
	HPDF_Page_SetFontAndSize(_currPage, _currFont, _currFontSize);
}

void PdfComponent::setCurrPageFont(HPDF_Font font)
{
	setCurrPageFontAndSize(font, _currFontSize);
}

void PdfComponent::setCurrPageFontSize(HPDF_REAL size)
{
	setCurrPageFontAndSize(_currFont, size);
}

HPDF_Font PdfComponent::getBase14Font(const std::string& name)
{
	return HPDF_GetFont(_doc, name.c_str(), NULL);
}

HPDF_Font PdfComponent::getCnSFont(const std::string& name, bool isVertical /*= false*/)
{
	if (!isUseCnsEncoding)
	{
		isUseCnsEncoding = true;
		HPDF_UseCNSFonts(_doc);
		HPDF_UseCNSEncodings(_doc);
	}
	const char* encoding = "GBK-EUC-H";
	if (isVertical)encoding = "GBK-EUC-V";
	return HPDF_GetFont(_doc, name.c_str(), encoding);
}

HPDF_Font PdfComponent::getCnTFont(bool isVertical /*= false*/)
{
	if (!isUseCntEncoding)
	{
		isUseCntEncoding = true;
		HPDF_UseCNTFonts(_doc);
		HPDF_UseCNTEncodings(_doc);
	}
	const char* encoding = "ETen-B5-H";
	if (isVertical)encoding = "ETen-B5-V";
	return HPDF_GetFont(_doc, "MingLiU", encoding);
}

HPDF_Font PdfComponent::getTtFont(const std::string& fontPath, const std::string& encoding /*= "CP1252"*/)
{
	if (!isUseUtfEncoding)
	{
		isUseUtfEncoding = true;
		HPDF_UseUTFEncodings(_doc);
	}
	HPDF_SetCurrentEncoder(_doc, encoding.c_str());
	const char* f = HPDF_LoadTTFontFromFile(_doc, fontPath.c_str(), HPDF_TRUE);
	return HPDF_GetFont(_doc, f, encoding.c_str());
}

HPDF_Page PdfComponent::getNewPage(HPDF_Font font, HPDF_REAL size /*= 20*/, HPDF_PageSizes pageSize /*= HPDF_PageSizes::HPDF_PAGE_SIZE_A4*/, HPDF_PageDirection direction /*= HPDF_PageDirection::HPDF_PAGE_PORTRAIT*/)
{
	// 添加一个页面
	_currPage = HPDF_AddPage(_doc);
	// 设置字体
	setCurrPageFontAndSize(font, size);
	// 设置页面
	HPDF_Page_SetSize(_currPage, pageSize, direction);
	// 返回页面引用
	return _currPage;
}

HPDF_Page PdfComponent::getNewPage(HPDF_PageSizes pageSize /*= HPDF_PageSizes::HPDF_PAGE_SIZE_A4*/, HPDF_PageDirection direction /*= HPDF_PageDirection::HPDF_PAGE_PORTRAIT*/)
{
	return getNewPage(getCnSFont("SimSun"), 20, pageSize, direction);
}

void PdfComponent::drawText(const std::string& text, HPDF_REAL posx, HPDF_REAL posy, HPDF_Page page /*= 0*/)
{
	HPDF_Page_BeginText(page);
	HPDF_Page_MoveTextPos(page, posx, posy);
	HPDF_Page_ShowText(page, CharsetConvertHepler::utf8ToGbk(text).c_str());
	HPDF_Page_EndText(page);
}

void PdfComponent::drawTextCenter(const std::string& text, HPDF_Page page /*= 0*/)
{
	if (!page) page = _currPage;
	if (!page) return;
	HPDF_REAL posx, posy, tw, th;
	tw = HPDF_Page_TextWidth(page, CharsetConvertHepler::utf8ToGbk(text).c_str());
	th = HPDF_Page_GetCurrentFontSize(page);
	posx = (HPDF_Page_GetWidth(page) - tw) / 2;
	posy = (HPDF_Page_GetHeight(page) - th) / 2;
	drawText(text, posx, posy, page);
}

void PdfComponent::drawTextCenterH(const std::string& text, HPDF_REAL posy, HPDF_Page page /*= 0*/)
{
	if (!page) page = _currPage;
	if (!page) return;
	HPDF_REAL posx, tw;
	tw = HPDF_Page_TextWidth(page, CharsetConvertHepler::utf8ToGbk(text).c_str());
	posx = (HPDF_Page_GetWidth(page) - tw) / 2;
	drawText(text, posx, posy, page);
}

void PdfComponent::drawTextCenterV(const std::string& text, HPDF_REAL posx, HPDF_Page page /*= 0*/)
{
	if (!page) page = _currPage;
	if (!page) return;
	HPDF_REAL posy, th;
	th = HPDF_Page_GetCurrentFontSize(page);
	posy = (HPDF_Page_GetHeight(page) - th) / 2;
	drawText(text, posx, posy, page);
}

void PdfComponent::drawImage(HPDF_Image image, HPDF_REAL x, HPDF_REAL y, HPDF_REAL w, HPDF_REAL h, HPDF_Page page /*= 0*/)
{
	if (!page) page = _currPage;
	if (!page) return;
	// 绘制图片
	HPDF_Page_DrawImage(page, image, x, y, w, h);
}

void PdfComponent::drawImage(HPDF_Image image, HPDF_REAL x, HPDF_REAL y, HPDF_Page page /*= 0*/)
{
	// 获取图片大小
	HPDF_REAL iw = HPDF_Image_GetWidth(image) * 1.f;
	HPDF_REAL ih = HPDF_Image_GetHeight(image) * 1.f;
	// 绘制图片
	drawImage(image, x, y, iw, ih, page);
}

void PdfComponent::drawWithTemplate(const std::string& tplPath, const std::string& tplName, void* realData)
{
	// 判断是否存在注册模板
	auto itCf = tplRender.find(tplName);
	if (itCf == tplRender.end())
	{
		throw std::runtime_error("pdf render template not exist.");
	}
	try
	{
		// 加载模板配置文件
		auto tmplConf = YAML::LoadFile(tplPath);
		// 执行渲染
		itCf->second(&tmplConf, this, realData);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

bool PdfComponent::saveDocToFile(const std::string& fullPath)
{
	try
	{
		HPDF_SaveToFile(_doc, fullPath.c_str());
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return false;
	}
	return true;
}

std::vector<HPDF_BYTE> PdfComponent::saveDocToMem()
{
	// 保存数据到流
	HPDF_SaveToStream(_doc);

	// 获取数据大小
	auto size = HPDF_GetStreamSize(_doc);
	if (!size) return {};

	// 将流中的数据存储到集合中
	std::vector<HPDF_BYTE> buffvec;
	HPDF_ResetStream(_doc);
	for (;;) {
		HPDF_BYTE buf[4096];
		HPDF_UINT32 siz = 4096;
		HPDF_STATUS ret = HPDF_ReadFromStream(_doc, buf, &siz);
		if (siz == 0)
			break;
		for (HPDF_UINT32 i = 0; i < siz; i++)
			buffvec.emplace_back(buf[i]);
	}

	// 返回缓存提供给调用者使用
	return buffvec;
}

bool PdfComponent::genPictureCodeToFile(const std::string& savePath, const int& w, const int& h, const std::string& text, const std::string& type, const int& margin /*= 10*/, const int& eccLevel /*= 0*/)
{
	try
	{
		// 产生图码数据
		auto bitmap = genPictureCode(w, h, text, type, margin, eccLevel);
		// 保存到文件
		int success = stbi_write_jpg(savePath.c_str(), bitmap.width(), bitmap.height(), 1, bitmap.data(), 0);
		// 如果保存成功
		if (success) return true;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return false;
}

#undef STB_IMAGE_WRITE_IMPLEMENTATION

#endif // USE_PDF