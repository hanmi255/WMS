#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/12/28 21:31:30

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
#ifndef _PDFCOMPONENT_H_
#define _PDFCOMPONENT_H_

#ifdef LINUX
#include "haru/linux/hpdf.h"
#else
#include "haru/win/hpdf.h"
#endif
#include <string>
#include <functional>
#include "yaml-cpp/node/node.h"
#include <map>
#include <set>
#include "zxing/BitMatrix.h"

class PdfComponent;
// 定义一个模板渲染函数
using PdfTplRenderCf = void(*)(YAML::Node*, PdfComponent*, void* realData);

/**
 * 书写一个PDF组件，用于封装libharu库常用操作
 * 注意：libharu坐标系是原点在左下角不是左上角
 */
class PdfComponent final
{
private:
	// 标记是否使用使用了编码器
	bool isUseCnsEncoding;
	bool isUseCntEncoding;
	bool isUseUtfEncoding;
	// 文档句柄
	HPDF_Doc _doc;
	// 当前页面句柄
	HPDF_Page _currPage;
	// 当前页面字体
	HPDF_Font _currFont;
	// 当前页面字体大小
	HPDF_REAL _currFontSize;
	// 记录注册的渲染模板
	static std::map<std::string, PdfTplRenderCf> tplRender;
	// 生成图形码
	static ZXing::Matrix<uint8_t> genPictureCode(const int& w, const int& h, const std::string& text, const std::string& type, const int& margin, const int& eccLevel);
public:
	//************************************
	// Method:    registerTplRender
	// FullName:  PdfComponent::registerTplRender
	// Access:    public static 
	// Returns:   void
	// Description: 注册渲染模板
	// Parameter: const std::string& tplName 模板名称
	// Parameter: PdfTplRenderCf cf 渲染回调函数
	//************************************
	static void registerTplRender(const std::string& tplName, PdfTplRenderCf cf);
	// 构造初始化
	PdfComponent();
	// 析构释放资源
	~PdfComponent();
	// 获取文档句柄
	HPDF_Doc getDoc() const;
	// 获取当前页面句柄
	HPDF_Page getCurrPage() const;
	// 获取当前页面宽度
	HPDF_REAL getCurrPageWidth() const;
	// 获取当前页面高度
	HPDF_REAL getCurrPageHeight() const;
	// 设置当前页面字体和大小
	void setCurrPageFontAndSize(HPDF_Font font, HPDF_REAL size);
	// 设置当前页面字体
	void setCurrPageFont(HPDF_Font font);
	// 设置当前页面字体大小
	void setCurrPageFontSize(HPDF_REAL size);
	//************************************
	// Method:    getBase14Font
	// FullName:  PdfComponent::getBase14Font
	// Access:    public 
	// Returns:   HPDF_Font
	// Description: 获取PDF内置PBase14字体句柄，更多参考：https://github.com/libharu/libharu/wiki/Fonts
	// Parameter: const std::string& name 字体名称
	//************************************
	HPDF_Font getBase14Font(const std::string& name);
	//************************************
	// Method:    getCnSFont
	// FullName:  PdfComponent::getCnSFont
	// Access:    public 
	// Returns:   HPDF_Font
	// Description: 获取Haru内置中文简体字体句柄
	// Parameter: const std::string& name 字体名称，目前支持：SimSun, SimHei
	// Parameter: bool isVertical 是否纵向显示
	//************************************
	HPDF_Font getCnSFont(const std::string& name, bool isVertical = false);
	//************************************
	// Method:    getCnTFont
	// FullName:  PdfComponent::getCnTFont
	// Access:    public 
	// Returns:   HPDF_Font
	// Description: 获取Haru内置中文繁体字体句柄，目前只支持一种：MingLiU
	// Parameter: bool isVertical 是否纵向显示
	//************************************
	HPDF_Font getCnTFont(bool isVertical = false);
	//************************************
	// Method:    getTtFont
	// FullName:  PdfComponent::getTtFont
	// Access:    public 
	// Returns:   HPDF_Font
	// Description: 获取TTF字体
	// Parameter: const std::string& fontPath 字体文件全路径
	// Parameter: const std::string& encoding 编码名称，默认为CP1252
	//************************************
	HPDF_Font getTtFont(const std::string& fontPath, const std::string& encoding = "CP1252");
	//************************************
	// Method:      getNewPage
	// FullName:    PdfComponent::getNewPage
	// Access:      public 
	// Returns:     HPDF_Page 新页面的引用
	// Parameter:   HPDF_Font font 字体
	// Parameter:   HPDF_REAL size 字体大小，默认20
	// Parameter:   HPDF_PageSizes pageSize 页面大小，默认A4
	// Parameter:   HPDF_PageDirection direction 页面方向，默认纵向
	// Description: 获取一个新的页面
	//************************************
	HPDF_Page getNewPage(HPDF_Font font, HPDF_REAL size = 20, HPDF_PageSizes pageSize = HPDF_PageSizes::HPDF_PAGE_SIZE_A4, HPDF_PageDirection direction = HPDF_PageDirection::HPDF_PAGE_PORTRAIT);
	//************************************
	// Method:    getNewPage
	// FullName:  PdfComponent::getNewPage
	// Access:    public 
	// Returns:   HPDF_Page 新页面的引用
	// Parameter: HPDF_PageSizes pageSize 页面大小，默认A4
	// Parameter: HPDF_PageDirection direction 页面方向，默认纵向
	// Description: 获取一个新的页面（新页面的默认字体是中文简体，大小20号）
	//************************************
	HPDF_Page getNewPage(HPDF_PageSizes pageSize = HPDF_PageSizes::HPDF_PAGE_SIZE_A4, HPDF_PageDirection direction = HPDF_PageDirection::HPDF_PAGE_PORTRAIT);
	//************************************
	// Method:    drawText
	// FullName:  PdfComponent::drawText
	// Access:    public 
	// Returns:   void
	// Description: 绘制文字
	// Parameter: const std::string& text 文字内容
	// Parameter: HPDF_REAL posx x坐标
	// Parameter: HPDF_REAL posy y坐标
	// Parameter: HPDF_Page page 页面句柄，默认值为当前页面句柄
	//************************************
	void drawText(const std::string& text, HPDF_REAL posx, HPDF_REAL posy, HPDF_Page page = 0);
	//************************************
	// Method:    drawTextCenter
	// FullName:  PdfComponent::drawTextCenter
	// Access:    public 
	// Returns:   void
	// Description: 绘制文字，文字在页面中居中显示
	// Parameter: const std::string& text 文字内容
	// Parameter: HPDF_Page page 页面句柄，默认值为当前页面句柄
	//************************************
	void drawTextCenter(const std::string& text, HPDF_Page page = 0);
	//************************************
	// Method:    drawTextCenterH
	// FullName:  PdfComponent::drawTextCenterH
	// Access:    public 
	// Returns:   void
	// Description: 绘制文字，让文字水平居中显示
	// Parameter: const std::string& text 文字内容
	// Parameter: HPDF_REAL posy y坐标
	// Parameter: HPDF_Page page 页面句柄，默认值为当前页面句柄
	//************************************
	void drawTextCenterH(const std::string& text, HPDF_REAL posy, HPDF_Page page = 0);
	//************************************
	// Method:    drawTextCenterV
	// FullName:  PdfComponent::drawTextCenterV
	// Access:    public 
	// Returns:   void
	// Description: 绘制文字，让文字垂直居中显示
	// Parameter: const std::string& text 文字内容
	// Parameter: HPDF_REAL posx x坐标
	// Parameter: HPDF_Page page 页面句柄，默认值为当前页面句柄
	//************************************
	void drawTextCenterV(const std::string& text, HPDF_REAL posx, HPDF_Page page = 0);
	//************************************
	// Method:      drawImage
	// FullName:    PdfComponent::drawImage
	// Access:      public 
	// Returns:     void
	// Parameter:   HPDF_Image image 图片句柄
	// Parameter:   HPDF_REAL x x坐标
	// Parameter:   HPDF_REAL y y坐标
	// Parameter:   HPDF_REAL w 绘制宽度
	// Parameter:   HPDF_REAL h 绘制高度
	// Parameter:   HPDF_Page page 页面句柄，默认值为当前页面句柄
	// Description: 绘制图片
	//************************************
	void drawImage(HPDF_Image image, HPDF_REAL x, HPDF_REAL y, HPDF_REAL w, HPDF_REAL h, HPDF_Page page = 0);
	//************************************
	// Method:      drawImage
	// FullName:    PdfComponent::drawImage
	// Access:      public 
	// Returns:     void
	// Parameter:   HPDF_Image image
	// Parameter:   HPDF_REAL x x坐标
	// Parameter:   HPDF_REAL y y坐标
	// Parameter:   HPDF_Page page 页面句柄，默认值为当前页面句柄
	// Description: 绘制图片，绘制图片大小为原图片的大小
	//************************************
	void drawImage(HPDF_Image image, HPDF_REAL x, HPDF_REAL y, HPDF_Page page = 0);
	//************************************
	// Method:    drawWithTemplate
	// FullName:  PdfComponent::drawWithTemplate
	// Access:    public 
	// Returns:   void
	// Description: 通过模板绘制
	// Parameter: const std::string& tplPath 模板配置文件
	// Parameter: const std::string& tplName 模板名称
	// Parameter: void* realData 实时运行数据，用于传递动态数据
	//************************************
	void drawWithTemplate(const std::string& tplPath, const std::string& tplName, void* realData);
	//************************************
	// Method:    saveDocToFile
	// FullName:  PdfComponent::saveDocToFile
	// Access:    public 
	// Returns:   bool 保存成功返回true
	// Description: 保存文档到文件
	// Parameter: const std::string& fullPath 文件全路径
	//************************************
	bool saveDocToFile(const std::string& fullPath);
	//************************************
	// Method:      saveDocToMem
	// FullName:    PdfComponent::saveDocToMem
	// Access:      public 
	// Returns:     std::vector<HPDF_BYTE> 返回缓存结果，结果可以使用reinterpret_cast转换成const char*，如：const char* charData = reinterpret_cast<const char*>(data.data());
	// Description: 保存文档到内存
	//************************************
	std::vector<HPDF_BYTE> saveDocToMem();
	//************************************
	// Method:      genPictureCodeToFile
	// FullName:    PdfComponent::genPictureCodeToFile
	// Access:      public 
	// Returns:     bool
	// Parameter:   const std::string& savePath 保存路径
	// Parameter:   const int& w 图片宽度
	// Parameter:   const int& h 图片高度
	// Parameter:   const std::string& text 图片中的文本信息
	// Parameter:   const std::string& type 图码类型
	// Parameter:   const int& margin 间距，默认值10
	// Parameter:   const int& eccLevel ecc等级0-10，默认0
	// Description: 生成图形码并存储到指定文件中
	//************************************
	static bool genPictureCodeToFile(const std::string& savePath, const int& w, const int& h, const std::string& text, const std::string& type, const int& margin = 10, const int& eccLevel = 0);
};

#endif // !_PDFCOMPONENT_H_