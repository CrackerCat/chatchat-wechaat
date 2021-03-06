// SendXmlMessage.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include "resource.h"

struct wxString
{
	wchar_t * pStr;
	int strLen;
	int strMaxLen;
};

struct wxString2
{
	wchar_t * pStr;
	int strLen;
	int strMaxLen;
	int fill;
	int	fill2;
};


//获取模块基址
DWORD GetWechatWin() {
	return (DWORD)LoadLibrary(L"WeChatWin.dll");
}



//发送xml消息
VOID SendXmlMessage(HWND Dlg, PWCHAR wxid, PWCHAR fWxid, PWCHAR title, PWCHAR content, PWCHAR pic)
{
	/*
		mov edi,dword ptr ss:[ebp-0x78C]
		push edi                                 ; 0x5 可能是类型
		lea eax,dword ptr ss:[ebp-0x88]
		push eax                                 ; 0X88
		lea eax,dword ptr ss:[ebp-0x9C]
		push eax                                 ; 0x9C
		lea eax,dword ptr ss:[ebp-0xE0]
		push eax                                 ; xml文本结构体
		push ebx                                 ; 接受者wxid
		lea eax,dword ptr ss:[ebp-0x6B0]
		push eax                                 ; 发送者wxid
		lea eax,dword ptr ss:[ebp-0x2D8]
		push eax                                 ; 0x2D8缓冲区
		call 22BFB0                   ; 发送xml消息
	*/
	wxString2 pWxid = { 0 };
	wxString2 pFromWxid = { 0 };
	wxString pXML = { 0 };
	wchar_t temWxid[0x100] = { 0 };
	wchar_t fromWxid[0x100] = { 0 };
	wchar_t xml[0x2000] = { 0 };

	wxString2 pIcons = { 0 };
	char* asmXml = (char*)&pXML.pStr;
	char* asmWxid = (char*)&pWxid.pStr;
	char* asmFWxid = (char*)&pFromWxid.pStr;
	char* asmIcon = (char*)&pIcons.pStr;
	char buff3[0x2D8] = { 0 };
	char buff1[0x88] = { 0 };
	char buff2[0x9C] = { 0 };
	char maxBuff[0x2D8] = { 0 };

	wchar_t iconPath[0x9C] = {0};
	swprintf_s(iconPath,L"C:\\Users\\szjy\\Documents\\WeChat Files\\HeDaDa-Alone\\Attachment\\4e590e84fc402a67994d4116bcf3bde9_t.jpg");
	pIcons.pStr = iconPath;
	pIcons.strLen = wcslen(iconPath);
	pIcons.strMaxLen = wcslen(iconPath) * 2;
	pIcons.fill = 0;
	pIcons.fill2 = 0;

	char buff4[0x2D8] = { 0 };
	
	swprintf_s(temWxid, L"%s", wxid);
	pWxid.pStr = temWxid;
	pWxid.strLen = wcslen(temWxid);
	pWxid.strMaxLen = wcslen(temWxid) * 2;
	pWxid.fill = 0;
	pWxid.fill2 = 0;

	
	swprintf_s(fromWxid, L"%s", fWxid);
	pFromWxid.pStr = fromWxid;
	pFromWxid.strLen = wcslen(fromWxid);
	pFromWxid.strMaxLen = wcslen(fromWxid) * 2;
	pFromWxid.fill = 0;
	pFromWxid.fill2 = 0;
	
	swprintf_s(xml, L"<msg><fromusername>hechongos</fromusername><scene>0</scene><commenturl></commenturl><appmsg appid=\"wxa4aafd8a14335fc9\" sdkver=\"0\"><title>%s</title><des>%s</des><action>view</action><type>5</type><showtype>0</showtype><content></content><url>http://www.baidu.com</url><dataurl></dataurl><lowurl></lowurl><thumburl></thumburl><messageaction></messageaction><recorditem><![CDATA[]]></recorditem><extinfo></extinfo><sourceusername></sourceusername><sourcedisplayname></sourcedisplayname><commenturl></commenturl><appattach><totallen>0</totallen><attachid></attachid><emoticonmd5></emoticonmd5><fileext></fileext><cdnthumburl>%s</cdnthumburl><aeskey>8884716e4ea321a5da7e16c25e5f6f3c</aeskey><cdnthumbaeskey>8884716e4ea321a5da7e16c25e5f6f3c</cdnthumbaeskey><encryver>0</encryver><cdnthumblength>3386</cdnthumblength><cdnthumbheight>96</cdnthumbheight><cdnthumbwidth>96</cdnthumbwidth></appattach></appmsg><appinfo><version>1</version><appname>Hezone</appname></appinfo></msg>", title, content, pic);
	
	pXML.pStr = xml;
	pXML.strLen = wcslen(xml);
	pXML.strMaxLen = wcslen(xml) * 2;
	

	DWORD callAdd = GetWechatWin() + 0x22BFB0;
	
	wchar_t debug[0x100] = {0};
	swprintf_s(debug,L"push=%p\r\npush=%p\r\npush=%p\r\npush=%p\r\npush=%p\r\npush=%p\r\nbuff3=%p\r\nSendXmlMessage=%p", maxBuff, asmFWxid, asmWxid, asmXml, buff2, buff1, buff3, asmIcon);
	SetDlgItemText(Dlg, XML_LOG, debug);
	__asm {
		mov edi,0x5
		push edi
		lea eax, buff1
		push eax
		mov eax, asmIcon
		push eax
		mov eax, asmXml
		push eax
		mov ebx, asmWxid
		push ebx
		mov eax, asmFWxid
		push eax
		lea eax, buff3
		push eax
		call callAdd
	}


}


//结构体数据
wxString pNewWxid = { 0 };
wxString2 pNewFromWxid = { 0 };
wxString pNewXML = { 0 };
//asm地址参数定义
char* asmNewXml = (char*)&pNewXML.pStr;
char* asmNewWxid = (char*)&pNewWxid.pStr;
char* asmNewFWxid = (char*)&pNewFromWxid.pStr;
wchar_t newXml[0x2000] = { 0 };
wchar_t newBuffWxid[0x100] = { 0 };
wchar_t newBuffFWxid[0x100] = {0};
//缓冲区定义
char newBuff1[0x24] = { 0 };
char newBuff2[0x44] = { 0 };
char newBuff3[0x344] = { 0 };

//新建转发xml
VOID newXmlMessage(HWND Dlg, PWCHAR wxid, PWCHAR fWxid, PWCHAR title, PWCHAR content, PWCHAR pic)
{
	
	swprintf_s(newBuffWxid, L"%s", wxid);
	swprintf_s(newBuffFWxid, L"%s", fWxid);

	pNewWxid.pStr = newBuffWxid;
	pNewWxid.strLen = wcslen(newBuffWxid);
	pNewWxid.strMaxLen = wcslen(newBuffWxid) * 2;

	pNewFromWxid.pStr = newBuffFWxid;
	pNewFromWxid.strLen = wcslen(newBuffFWxid);
	pNewFromWxid.strMaxLen = wcslen(newBuffFWxid) * 2;
	pNewFromWxid.fill = 0;
	pNewFromWxid.fill2 = 0;
	
	swprintf_s(newXml, L"<msg><fromusername>hechongos</fromusername><scene>0</scene><commenturl></commenturl><appmsg appid=\"\" sdkver=\"0\"><title>%s</title><des>%s</des><action>view</action><type>5</type><showtype>0</showtype><content></content><url>http://www.taobao.com</url><dataurl></dataurl><lowurl></lowurl><thumburl>%s</thumburl><messageaction></messageaction><recorditem><![CDATA[]]></recorditem><extinfo></extinfo><sourceusername></sourceusername><sourcedisplayname></sourcedisplayname><commenturl></commenturl><appattach><totallen>0</totallen><attachid></attachid><emoticonmd5></emoticonmd5><fileext></fileext></appattach></appmsg><appinfo><version>1</version><appname>Window wechat</appname></appinfo></msg>",title, content, pic);
	pNewXML.pStr = newXml;
	pNewXML.strLen = wcslen(newXml);
	pNewXML.strMaxLen = wcslen(newXml) * 2;
	

	wchar_t debug[0x100] = { 0 };
	swprintf_s(debug, L"push=%p\r\npush=%p\r\npush=%p\r\npush=%p\r\npush=%p\r\npush=%p\r\n", newBuff3, asmNewFWxid, asmNewWxid, asmNewXml, newBuff2, newBuff1);
	SetDlgItemText(Dlg, XML_LOG, debug);

	DWORD callAdd = GetWechatWin() + 0x22BFB0;
	__asm {
		push 0x5
		lea eax, newBuff1
		push eax
		lea eax, newBuff2
		push eax
		mov eax, asmNewXml
		push eax
		mov eax, asmNewWxid
		push eax
		mov eax, asmNewFWxid
		push eax
		lea eax, newBuff3
		push eax
		call callAdd
	}
}


//发送xml
VOID SendXmlCard(HWND Dlg, PWCHAR wxid, PWCHAR fWxid, PWCHAR name)
{
	wxString pWxid = { 0 };
	wxString pXml = {0};
	wchar_t xml[0x2000] = {0};
	pWxid.pStr = wxid;
	pWxid.strLen = wcslen(wxid);
	pWxid.strLen = wcslen(wxid) * 2;

	swprintf_s(xml,L"<?xml version=\"1.0\"?><msg bigheadimgurl=\"http://wx.qlogo.cn/mmhead/ver_1/7IiaGRVxyprWcBA9v2IA1NLRa1K5YbEX5dBzmcEKw4OupNxsYuYSBt1zG91O6p07XlIOQIFhPCC3hU1icJMk3z28Ygh6IhfZrV4oYtXZXEU5A/0\" smallheadimgurl=\"http://wx.qlogo.cn/mmhead/ver_1/7IiaGRVxyprWcBA9v2IA1NLRa1K5YbEX5dBzmcEKw4OupNxsYuYSBt1zG91O6p07XlIOQIFhPCC3hU1icJMk3z28Ygh6IhfZrV4oYtXZXEU5A/132\" username=\"%s\" nickname=\"%s\" fullpy=\"?\" shortpy=\"\" alias=\"%s\" imagestatus=\"3\" scene=\"17\" province=\"湖北\" city=\"中国\" sign=\"\" sex=\"2\" certflag=\"0\" certinfo=\"\" brandIconUrl=\"\" brandHomeUrl=\"\" brandSubscriptConfigUrl= \"\" brandFlags=\"0\" regionCode=\"CN_Hubei_Wuhan\" />", fWxid,name, fWxid);
	pXml.pStr = xml;
	pXml.strLen = wcslen(xml);
	pXml.strMaxLen = wcslen(xml) * 2;

	char* asmWxid = (char *)&pWxid.pStr;
	char* asmXml = (char *)&pXml.pStr;
	char buff[0x20C] = {0};
	DWORD callAdd = GetWechatWin() + 0x2DA720;
	__asm {
		mov eax, asmXml
		push 0x2A
		mov edx, asmWxid
		push 0x0
		push eax
		lea ecx,buff
		call callAdd
		add esp,0xC
	}
}