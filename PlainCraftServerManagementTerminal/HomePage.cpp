#include "HomePage.h"
#include "iostream"

std::string HomePageCharactor{
        "_____   _____  _____ __  __ _______        \n"
        "|  __\\ / ____|/  ___|  \\/  |__   __|     \n"
        "| |__ )| |    | (___| \\  / |  | |         \n" 
        "| ___/ | |    \\___ \\| |\\/| |  | |       \n"
        "| |    | |________) | |  | |  | |          \n"
        "|_|    \\_____|_____/|_|  |_|  |_|         \n"
};

const char* ProgramName = "PCSMT (Plain Craft Server Management Terminal)";
const char* GithubPage = "Github:https://github.com/Ksayus/PCSMT";
const char* GiteePage = "Gitee:https://gitee.com/Ksayus/PCSMT";
const char* BilibiliPage = "Bilibili:https://space.bilibili.com/558271819?spm_id_from=333.1007.0.0";

void HomePage()
{
    std::cout << HomePageCharactor << std::endl;
    std::cout << "Welcome " << ProgramName << std::endl;
    std::cout << "My own homepage" << std::endl;
    std::cout << GithubPage << std::endl;
    std::cout << GiteePage << std::endl;
    std::cout << BilibiliPage << std::endl;
}