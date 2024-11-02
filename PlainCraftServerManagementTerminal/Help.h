#ifndef HELP
#define HELP

#include <iostream>
//Help内容的指令数
const int HelpQuantity = 50;

//Help的具体内容
static std::string HelpCommandName[HelpQuantity] = {
	"-start",
	"-addserver",
	"-startserver",
	"-serverlist",
	"-serversetting",
	"-about",
};

static std::string HelpCommandRole[HelpQuantity] = {
	"-打开文件",
	"-添加服务器路径和服务器名",
	"-启动服务器",
	"-列出服务器列表",
	"-打开服务器配置文件",
	"-关于界面",
};

static std::string HelpCommandUsage[HelpQuantity] = {
	"-start {path}",
	"-addserver {path}",
	"-tostartserver {number}",
	"-serverlist",
	"-serversetting {number}"
	"-about",
};

#endif // !HELP


