#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <streambuf>

#include "ServerCommandRegister.h"
#include "HomePage.h"
#include "FolderCheck.h"
#include "Initialization.h"
#include "registerServerCommand.h"
#include "getTime.h"
#include "FilesFoldersPosition.h"



using namespace std;

int main() {
    //设置指令
	setServerCommand();

    //检查文件夹
    CheckPCSMTFolder();
    CheckTimeFolder();

    //输出页面
    HomePage();

    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    if (!LogFile.is_open()) {
        cerr << "无法打开日志文件" << endl;
        return 1;
    }

    Output("打开日志文件！");
    Output("日志文件目录：" + LogOutputPath);
    //cout << "打开日志文件！" << endl;
    //cout << "日志文件目录：" << LogOutputPath << endl;
    LogFile.close();

    //初始化
    InitializationServerPosition();
    InitializationServerName();
    InitializationServerFolder();




    //定义输入
    std::string input;

    //循环
    while (true) {
        tm* getalltime = GetTime();
        std::cout << std::to_string(getalltime->tm_year + 1900) + std::to_string(getalltime->tm_mon + 1) + std::to_string(getalltime->tm_mday) + std::to_string(getalltime->tm_hour) + Colon + std::to_string(getalltime->tm_min) + Colon + std::to_string(getalltime->tm_sec);
        std::cout << "——> ";
        std::getline(std::cin, input);
        //退出程序
        if (input == "exit") {
            LogFile.close();
            break;
        }
        //根据输入进行检测执行
        excuteServerCommand(input);
    }

    // 恢复cout的缓冲区，使其只输出到控制台
	return 0;
}