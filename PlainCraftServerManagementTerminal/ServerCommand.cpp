#include "ServerCommand.h"

#include "registerServerCommand.h"
#include "Help.h"
#include "fstream"
#include "FolderCheck.h"
#include "FileCheck.h"
#include "Initialization.h"
#include "FilesFoldersPosition.h"
#include "HomePage.h"

//#include "FilesFoldersPosition.cpp"


void Start(std::string args) {
    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    //std::cout << "Start " << args << " units" << std::endl;
    //将输入转换为const char*类型的常量
    std::string ServerPathString = StartString + args;
    const char *ServerPathChar = ServerPathString.c_str();
    //使用system函数进行打开文件
    system(ServerPathChar);
    //输出信息
    Output("打开文件:");
    LogFile.close();
}

void Help(std::string args) {
    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    int HelpLoop = HelpQuantity;
    int HelpPosition = 0;

    //将Help内定义的文本检查输出
    for (size_t HelpPosition = 0; HelpPosition < HelpCommandName[HelpPosition].size(); ++HelpPosition) {
        if (HelpCommandName[HelpPosition] == " ") {
            continue; // 如果当前元素是空格字符串，则跳过
        }
        //输出信息
        Output(HelpCommandName[HelpPosition] + TabKey + HelpCommandRole[HelpPosition] + TabKey + HelpCommandUsage[HelpPosition]);
    }
    LogFile.close();
}

void AddServer(std::string args) {
    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    const char* ServerPath = args.c_str();
    //std::wstring StartBarchWstring(StartBatch.begin(), StartBatch.end());
    //std::wstring midServerPath(args.begin(), args.end());
    //std::wstring ServerPositionFolder = midServerPath + StartBarchWstring;

    const int ServerAbsolutePathLong = 512;
    char ServerAbsolutePath[ServerAbsolutePathLong]{};

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

    Output("服务器名：" + getServerName);

    CheckPCSMTFolder();
    //如果有./PCSMT/ServerPosition.txt文件就打开，没有则创建
    //存储ServerPosition
    std::fstream ServerAddress(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::out | std::ios::app);

    //检查文件是否打开
    if (!ServerAddress.is_open())
    {
        Output("服务器路径存储错误！打开文件时发生错误");
        ServerAddress.close();
    }
    else {
        //std::cout << args << StartBatch << std::endl;
        //std::cout << ServerPath << StartBatch << std::endl;
        Output("服务器路径：");
        Output(ServerAbsolutePath + RightSlash + getServerName + StartBatch);
        ServerAddress << ServerAbsolutePath << RightSlash + getServerName << StartBatch << std::endl;
        ServerAddress.close();
        //检查Start.bat文件的存在并写入Start.bat中
        CheckStartBatch(ServerAbsolutePath + RightSlash + getServerName);
        //输出信息
        Output("服务器路径存储完成！");
    }

    //存储ServerName
    ServerAddress.open(ADot + PCSMTPositionFolder + ServerNameTxt, std::ios::out | std::ios::app);

    if (!ServerAddress.is_open())
    {
        Output("服务器名存储错误！打开文件时发生错误");
        ServerAddress.close();
    }
    else {
        
        ServerAddress << getServerName << std::endl;
        ServerAddress.close();

        Output("服务器名存储完成！");
    }

    ServerAddress.open(ADot + PCSMTPositionFolder + ServerFolderTxt, std::ios::out | std::ios::app);

    if (!ServerAddress.is_open())
    {
        Output("服务器所在文件夹存储错误！打开文件时发生错误");
        ServerAddress.close();
    }
    else {
        Output("服务器所在文件夹：");
        Output(ServerAbsolutePath + RightSlash + getServerName);
        ServerAddress << ServerAbsolutePath << RightSlash + getServerName << std::endl;
        ServerAddress.close();

        Output("服务器所在文件夹存储完成！");
    }

    InitializationFiles(ServerPositionTxt);
    InitializationFiles(ServerNameTxt);
    InitializationFiles(ServerFolderTxt);

    LogFile.close();
}

void ToStartServer(std::string args) {
    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    //将输入的转换为整形
    int ServerNamePositionTotals = std::atoi(args.c_str());
    Output("启动服务器：" + ServerName[ServerNamePositionTotals]);

    //将std::string ServerPosition转换到const char* ServerNamePosition
    std::string cdServerPosition = CD + ServerFolder[ServerNamePositionTotals];
    std::string startServer = StartString + ServerFolder[ServerNamePositionTotals] + StartBatch;

    //执行命令
    system(cdServerPosition.c_str());
    int excuteResult = system(startServer.c_str());
    while (excuteResult != 0)
    {
        Output("执行启动脚本失败！");
        return;
    }
    Output("执行启动脚本成功！");
    Output("当前启动服务器：" + ServerName[ServerNamePositionTotals]);
    LogFile.close();
}

void ServerList(std::string args) {
    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    //获取列表服务器名数量
    ServerNameNumber = InitializationFiles(ServerNameTxt);

    Output("服务器列表：");
    
    //输出服务器列表
    //std::cout << ServerNameNumber << std::endl;
    for (int OutputServerName = 0; OutputServerName < ServerNameNumber; OutputServerName++)
    {
        Output(std::to_string(OutputServerName) + ADot + ServerName[OutputServerName].c_str());
    }
    LogFile.close();
}

void ServerSetting(std::string args)
{
    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    int ServerSettingPosition = std::atoi(args.c_str());
    Output("打开服务器配置文件server.properties：" + ServerName[ServerSettingPosition]);

    std::string cdServerPosition = CD + ServerFolder[ServerSettingPosition];
    std::string openServerSettingFile = StartString + ServerFolder[ServerSettingPosition] + ServerProperties;

    system(cdServerPosition.c_str());
    int excuteResult = system(openServerSettingFile.c_str());
    while (excuteResult != 0)
    {
        Output("打开服务器配置文件！");
        return;
    }
    Output("打开服务器配置文件成功！");

    LogFile.close();
}

void About(std::string args)
{
    HomePage();
}