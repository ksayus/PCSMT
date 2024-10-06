#ifndef OUTPUTLOG
#define OUTPUTLOG

#include <functional>
#include <iostream>
#include <fstream>

std::ofstream LogFile("./PCSMT/Log/RunLog.txt", std::ios::out);

auto Output = [&](const std::string& text) {
    std::cout << text << std::endl;
    LogFile << text << std::endl;
    };

#endif // !OUTPUTLOG


