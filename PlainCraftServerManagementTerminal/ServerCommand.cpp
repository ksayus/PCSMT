#include "ServerCommand.h"
#include "Help.h"
#include "fstream"
#include "FolderCheck.h"
#include "FileCheck.h"

const char* TabKey = "\t";

std::string StartString = "start";
std::string StartBatch = "/Start.bat";

void Start(std::string args) {
    //std::cout << "Start " << args << " units" << std::endl;
    //将输入转换为const char*类型的常量
    std::string ServerPathString = StartString + args;
    const char *ServerPathChar = ServerPathString.c_str();
    //使用system函数进行打开文件
    system(ServerPathChar);
    //输出信息
    std::cout << "打开文件:" << args << std::endl;
}

void Help(std::string args) {
    int HelpLoop = HelpQuantity;
    int HelpPosition = 0;

    //将Help内定义的文本检查输出
    for (size_t HelpPosition = 0; HelpPosition < HelpCommandName[HelpPosition].size(); ++HelpPosition) {
        if (HelpCommandName[HelpPosition] == " ") {
            continue; // 如果当前元素是空格字符串，则跳过
        }
        //输出信息
        std::cout << HelpCommandName[HelpPosition] << TabKey << HelpCommandRole[HelpPosition] << TabKey << HelpCommandUsage[HelpPosition] << std::endl;
    }

}

void AddServer(std::string args) {
    const char* ServerPosition = args.c_str();

    CheckServerPosition();
    //如果有./ServerPosition/ServerPosition.txt文件就打开，没有则创建
    std::fstream ServerAddress("./ServerPosition/ServerPosition.txt",std::ios::out|std::ios::app);

    //检查文件是否打开
    if (!ServerAddress.is_open())
    {
        std::cout << "存储错误！打开文件时发生错误" << std::endl;
    }
    else {
        //std::cout << args << StartBatch << std::endl;
        //std::cout << ServerPosition << StartBatch << std::endl;
        ServerAddress << ServerPosition << StartBatch << std::endl;
        ServerAddress.close();
        //检查Start.bat文件的存在并写入Start.bat中
        CheckStartBatch(args);
        //输出信息
        std::cout << "服务器路径存储完成！" << std::endl;
    }
}
