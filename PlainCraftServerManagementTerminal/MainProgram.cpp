#include <iostream>
#include <Windows.h>

#include "ServerCommandRegister.h"
#include "HomePage.h"
#include "FolderCheck.h"
#include "Initialization.h"
#include "registerServerCommand.h"
#include "getTime.h"
#include "OutputLog.h"
#include "FilesFoldersPosition.h"

using namespace std;

int main() {
    //设置指令
	setServerCommand();

    //输出页面
    HomePage();

    //检查文件夹
    CheckPCSMTFolder();
    CheckTimeFolder();

    //打开日志
    TimeLog();

    //初始化
    InitializationServerPosition();
    InitializationServerName();
    InitializationServerFolder();

    tm* getalltime = GetTime();

    //定义输入
    std::string input;

    //循环
    while (true) {
        std::cout << std::to_string(getalltime->tm_year + 1900) + std::to_string(getalltime->tm_mon + 1) + std::to_string(getalltime->tm_mday) + std::to_string(getalltime->tm_hour) + Colon + std::to_string(getalltime->tm_min) + Colon + std::to_string(getalltime->tm_sec);
        std::cout << "——> ";
        std::getline(std::cin, input);
        //退出程序
        if (input == "exit") {
            break;
        }
        //根据输入进行检测执行
        excuteServerCommand(input);
    }
	return 0;
}