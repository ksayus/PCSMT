#include "FileFind.h"


#include <windows.h>
#include <iostream>

std::string ReturnFileName;

std::string FindFilesWithExtension(const std::string& ServerCorePath, const std::string& Extension) {
    WIN32_FIND_DATA findFileData;
    HANDLE FindFile;

    // 构建搜索模式，如 "*.txt"
    std::string searchpattern = ServerCorePath + "/*" + Extension;
    std::cout << searchpattern << std::endl;

    //将string转换到wstring
    std::wstring midsearchpattern(searchpattern.begin(), searchpattern.end());
    std::wcout << midsearchpattern << std::endl;

    //将wstring转换到LPCWSTR
    LPCWSTR SearchPattern = midsearchpattern.c_str();
    std::wcout << SearchPattern << std::endl;

    // 
    std::cout << "test" << std::endl;
    FindFile = FindFirstFile(SearchPattern, &findFileData);
    std::cout << "test1" << std::endl;
    if (FindFile != INVALID_HANDLE_VALUE) {
        do {
            // 找到文件，打印文件名

            std::cout << "test2" << std::endl;
            std::wcout << findFileData.cFileName << std::endl;

            std::wstring midreturnfilename = findFileData.cFileName;
            //std::wcout << midreturnfilename << std::endl;

            std::string midReturnFileName(midreturnfilename.begin(), midreturnfilename.end());
            //std::cout << midReturnFileName << std::endl;

            //ReturnFileName = streammidreturnfilename.c_str();
            ReturnFileName = midReturnFileName.c_str();
        } while (FindNextFile(FindFile, &findFileData) != 0);
        FindClose(FindFile);
    }
    else {
        std::cout << "查找文件失败！" << std::endl;
        std::cout << "未找到.jar文件！" << std::endl;
    }
    return ReturnFileName;
}
//    使用方法
//    FindFilesWithExtension(directory, extension);