#ifndef HELP
#define HELP

#include <iostream>
//Help内容的指令数
const int HelpQuantity = 50;

//Help的具体内容
static std::string HelpCommandName[HelpQuantity] = {
	"-start",
	"-addserver",
	"-tostartserver",
	"-serverlist",
};

static std::string HelpCommandRole[HelpQuantity] = {
	"-打开文件",
	"-添加服务器路径和服务器名",
	"-启动服务器",
	"列出服务器列表",
};

static std::string HelpCommandUsage[HelpQuantity] = {
	"-start {path}",
	"-addserver {path}",
	"-tostartserver {number}",
	"-serverlist",
};

#endif // !HELP


