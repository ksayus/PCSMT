#include "ServerCommand.h"

#include "registerServerCommand.h"
#include "Help.h"
#include "fstream"
#include "FolderCheck.h"
#include "FileCheck.h"
#include "Initialization.h"
#include "FilesFoldersPosition.h"

//#include "FilesFoldersPosition.cpp"


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
    const char* ServerPath = args.c_str();
    //std::wstring StartBarchWstring(StartBatch.begin(), StartBatch.end());
    //std::wstring midServerPath(args.begin(), args.end());
    //std::wstring ServerPositionFolder = midServerPath + StartBarchWstring;

    const int ServerAbsolutePathLong = 512;
    char ServerAbsolutePath[ServerAbsolutePathLong]{};

    //获取当前程序的绝对路径
    GetCurrentDirectory(ServerAbsolutePathLong, ServerAbsolutePath);

    //LPCWSTR ServerAbsolutePositionFolder = ServerPositionFolder.c_str();

    //GetFullPathName(ServerAbsolutePositionFolder, MAX_PATH, ServerAbsolutePath, NULL);

    std::string getServerName;

    for (char get : args)
    {
        if (get != '.' && get != '/') {
            getServerName += get;
        }
    }

    std::cout << "服务器名：" + getServerName << std::endl;

    CheckPCSMTFolder();
    //如果有./PCSMT/ServerPosition.txt文件就打开，没有则创建
    //存储ServerPosition
    std::fstream ServerAddress(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::out | std::ios::app);

    //检查文件是否打开
    if (!ServerAddress.is_open())
    {
        std::cout << "服务器路径存储错误！打开文件时发生错误" << std::endl;
        ServerAddress.close();
    }
    else {
        //std::cout << args << StartBatch << std::endl;
        //std::cout << ServerPath << StartBatch << std::endl;
        std::cout << "服务器路径：" << ServerAbsolutePath + RightSlash + getServerName; std::cout << StartBatch << std::endl;
        ServerAddress << ServerAbsolutePath << RightSlash + getServerName << StartBatch << std::endl;
        ServerAddress.close();
        //检查Start.bat文件的存在并写入Start.bat中
        CheckStartBatch(ServerAbsolutePath + RightSlash + getServerName);
        //输出信息
        std::cout << "服务器路径存储完成！" << std::endl;
    }

    //存储ServerName
    ServerAddress.open(ADot + PCSMTPositionFolder + ServerNameTxt, std::ios::out | std::ios::app);

    if (!ServerAddress.is_open())
    {
        std::cout << "服务器名存储错误！打开文件时发生错误" << std::endl;
        ServerAddress.close();
    }
    else {
        
        ServerAddress << getServerName << std::endl;
        ServerAddress.close();

        std::cout << "服务器名存储完成！" << std::endl;
    }

    ServerAddress.open(ADot + PCSMTPositionFolder + ServerFolderTxt, std::ios::out | std::ios::app);

    if (!ServerAddress.is_open())
    {
        std::cout << "服务器所在文件夹存储错误！打开文件时发生错误" << std::endl;
        ServerAddress.close();
    }
    else {
        std::cout << "服务器所在文件夹：" << ServerAbsolutePath << RightSlash + getServerName << std::endl;
        ServerAddress << ServerAbsolutePath << RightSlash + getServerName << std::endl;
        ServerAddress.close();

        std::cout << "服务器所在文件夹存储完成！" << std::endl;
    }

    InitializationServerPosition();
    InitializationServerName();
    InitializationServerFolder();
}

void ToStartServer(std::string args) {

    //将输入的转换为整形
    int ServerNamePositionTotals = std::atoi(args.c_str());
    std::cout << "启动服务器：" + ServerName[ServerNamePositionTotals] << std::endl;

    //将std::string ServerPosition转换到const char* ServerNamePosition
    std::string cdServerPosition = CD + ServerFolder[ServerNamePositionTotals];
    std::string startServer = StartString + ServerFolder[ServerNamePositionTotals] + StartBatch;

    //执行命令
    system(cdServerPosition.c_str());
    int excuteResult = system(startServer.c_str());
    while (excuteResult != 0)
    {
        std::cout << "执行启动脚本失败！" << std::endl;
        return;
    }
    std::cout << "执行启动脚本成功！" << std::endl;
    std::cout << "当前启动服务器：" + ServerName[ServerNamePositionTotals] << std::endl;
}

void ServerList(std::string args) {
    //获取列表服务器名数量
    ServerNameNumber = InitializationServerName();

    std::cout << "服务器列表：" << std::endl;
    
    //输出服务器列表
    std::cout << ServerNameNumber << std::endl;
    for (int OutputServerName = 0; OutputServerName < ServerNameNumber; OutputServerName++)
    {
        std::cout << OutputServerName << ADot << ServerName[OutputServerName].c_str() << std::endl;
    }
}
