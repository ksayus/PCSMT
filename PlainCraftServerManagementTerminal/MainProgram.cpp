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
    //����ָ��
	setServerCommand();

    //���ҳ��
    HomePage();

    //����ļ���
    CheckPCSMTFolder();
    CheckTimeFolder();

    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    if (!LogFile.is_open()) {
        cerr << "�޷�����־�ļ�" << endl;
        return 1;
    }

    Output("����־�ļ���");
    Output("��־�ļ�Ŀ¼��" + LogOutputPath);
    //cout << "����־�ļ���" << endl;
    //cout << "��־�ļ�Ŀ¼��" << LogOutputPath << endl;
    LogFile.close();

    //��ʼ��
    InitializationFiles(ServerPositionTxt);
    InitializationFiles(ServerNameTxt);
    InitializationFiles(ServerFolderTxt);




    //��������
    std::string input;

    //ѭ��
    while (true) {
        tm* getalltime = GetTime();
        std::cout << std::to_string(getalltime->tm_year + 1900) + std::to_string(getalltime->tm_mon + 1) + std::to_string(getalltime->tm_mday) + std::to_string(getalltime->tm_hour) + Colon + std::to_string(getalltime->tm_min) + Colon + std::to_string(getalltime->tm_sec);
        std::cout << "����> ";
        std::getline(std::cin, input);
        //�˳�����
        if (input == "exit") {
            LogFile.close();
            break;
        }
        //����������м��ִ��
        excuteServerCommand(input);
    }

    // �ָ�cout�Ļ�������ʹ��ֻ���������̨
	return 0;
}