#include "registerServerCommand.h"

// 创建一个映射，用于存储指令和对应的函数
std::map<std::string, StartServer> StartServerCommand;

// 注册指令
void registerServerCommand(const std::string& CommandName, StartServer servercmd) {
    StartServerCommand[CommandName] = servercmd;
}
// 执行指令
void excuteServerCommand(const std::string& scLine) {
    std::istringstream server(scLine);
    std::string servercommand;
    server >> servercommand;
    if (StartServerCommand.find(servercommand) != StartServerCommand.end()) {
        std::string serverargs;
        server >> serverargs;
        StartServerCommand[servercommand](serverargs);
    }
    else {
        //输出错误信息
        std::cout << "Unkown command: " << servercommand << std::endl;
        std::cout << "使用“help”以查询指令" << std::endl;
    }
}
