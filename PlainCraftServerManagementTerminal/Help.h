#ifndef HELP
#define HELP

#include <iostream>
//Help内容的指令数
const int HelpQuantity = 50;

//Help的具体内容
std::string HelpCommandName[HelpQuantity] = {
	"-start",
	"-addserver"
};

std::string HelpCommandRole[HelpQuantity] = {
	"-打开文件",
	"-添加服务器路径"
};

std::string HelpCommandUsage[HelpQuantity] = {
	"-start {path}",
	"-addserver {path}"
};

#endif // !HELP


