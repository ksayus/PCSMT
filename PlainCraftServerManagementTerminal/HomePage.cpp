#include "HomePage.h"

std::string HomePageCharactor{
        "_____   _____  _____ __  __ _______        \n"
        "|  __\\ / ____|/  ___|  \\/  |__   __|     \n"
        "| |__ )| |    | (___| \\  / |  | |         \n" 
        "| ___/ | |    \\___ \\| |\\/| |  | |       \n"
        "| |    | |________) | |  | |  | |          \n"
        "|_|    \\_____|_____/|_|  |_|  |_|         \n"
};

const char* ProgramName = "PCSMT (Plain Craft Server Management Terminal)";
const char* PowerBy = "Power by Ksayus";
const char* GithubPage = "--Github:https://github.com/Ksayus/PCSMT";
const char* GiteePage = "--Gitee:https://gitee.com/Ksayus/PCSMT";
const char* KsayusPage = "--Ksayus:https://ksayus.github.io/2024/10/19/PCSMT/";
const char* AuthorBilibiliPage = "--Bilibili:https://space.bilibili.com/558271819";
const char* PersonalWebsite = "--Personal Website:https://ksayus.github.io";

void HomePage()
{
    std::cout << "-------------------------------" << std::endl;
    std::cout << HomePageCharactor << std::endl;
    std::cout << "Welcome " << ProgramName << std::endl;
    std::cout << PowerBy << std::endl;
    std::cout << "My own homepage-->" << std::endl;
    std::cout << GithubPage << std::endl;
    std::cout << GiteePage << std::endl;
    std::cout << KsayusPage << std::endl;
    std::cout << AuthorBilibiliPage << std::endl;
    std::cout << PersonalWebsite << std::endl;
    std::cout << "-------------------------------" << std::endl;
}