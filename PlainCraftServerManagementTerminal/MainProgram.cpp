#include <iostream>
#include <Windows.h>

#include "ServerCommandRegister.h"
#include "HomePage.h"

using namespace std;

int main() {
	setServerCommand();
    HomePage();

    //定义输入
    std::string input;
    while (true) {
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