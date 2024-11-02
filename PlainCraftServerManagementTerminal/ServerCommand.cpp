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
    //������ת��Ϊconst char*���͵ĳ���
    std::string ServerPathString = StartString + args;
    const char *ServerPathChar = ServerPathString.c_str();
    //ʹ��system�������д��ļ�
    system(ServerPathChar);
    //�����Ϣ
    Output("���ļ�:");
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

    //��Help�ڶ�����ı�������
    for (size_t HelpPosition = 0; HelpPosition < HelpCommandName[HelpPosition].size(); ++HelpPosition) {
        if (HelpCommandName[HelpPosition] == " ") {
            continue; // �����ǰԪ���ǿո��ַ�����������
        }
        //�����Ϣ
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

    Output("����������" + getServerName);

    CheckPCSMTFolder();
    //�����./PCSMT/ServerPosition.txt�ļ��ʹ򿪣�û���򴴽�
    //�洢ServerPosition
    std::fstream ServerAddress(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::out | std::ios::app);

    //����ļ��Ƿ��
    if (!ServerAddress.is_open())
    {
        Output("������·���洢���󣡴��ļ�ʱ��������");
        ServerAddress.close();
    }
    else {
        //std::cout << args << StartBatch << std::endl;
        //std::cout << ServerPath << StartBatch << std::endl;
        Output("������·����");
        Output(ServerAbsolutePath + RightSlash + getServerName + StartBatch);
        ServerAddress << ServerAbsolutePath << RightSlash + getServerName << StartBatch << std::endl;
        ServerAddress.close();
        //���Start.bat�ļ��Ĵ��ڲ�д��Start.bat��
        CheckStartBatch(ServerAbsolutePath + RightSlash + getServerName);
        //�����Ϣ
        Output("������·���洢��ɣ�");
    }

    //�洢ServerName
    ServerAddress.open(ADot + PCSMTPositionFolder + ServerNameTxt, std::ios::out | std::ios::app);

    if (!ServerAddress.is_open())
    {
        Output("���������洢���󣡴��ļ�ʱ��������");
        ServerAddress.close();
    }
    else {
        
        ServerAddress << getServerName << std::endl;
        ServerAddress.close();

        Output("���������洢��ɣ�");
    }

    ServerAddress.open(ADot + PCSMTPositionFolder + ServerFolderTxt, std::ios::out | std::ios::app);

    if (!ServerAddress.is_open())
    {
        Output("�����������ļ��д洢���󣡴��ļ�ʱ��������");
        ServerAddress.close();
    }
    else {
        Output("�����������ļ��У�");
        Output(ServerAbsolutePath + RightSlash + getServerName);
        ServerAddress << ServerAbsolutePath << RightSlash + getServerName << std::endl;
        ServerAddress.close();

        Output("�����������ļ��д洢��ɣ�");
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

    //�������ת��Ϊ����
    int ServerNamePositionTotals = std::atoi(args.c_str());
    Output("������������" + ServerName[ServerNamePositionTotals]);

    //��std::string ServerPositionת����const char* ServerNamePosition
    std::string cdServerPosition = CD + ServerFolder[ServerNamePositionTotals];
    std::string startServer = StartString + ServerFolder[ServerNamePositionTotals] + StartBatch;

    //ִ������
    system(cdServerPosition.c_str());
    int excuteResult = system(startServer.c_str());
    while (excuteResult != 0)
    {
        Output("ִ�������ű�ʧ�ܣ�");
        return;
    }
    Output("ִ�������ű��ɹ���");
    Output("��ǰ������������" + ServerName[ServerNamePositionTotals]);
    LogFile.close();
}

void ServerList(std::string args) {
    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    //��ȡ�б������������
    ServerNameNumber = InitializationFiles(ServerNameTxt);

    Output("�������б�");
    
    //����������б�
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
    Output("�򿪷����������ļ�server.properties��" + ServerName[ServerSettingPosition]);

    std::string cdServerPosition = CD + ServerFolder[ServerSettingPosition];
    std::string openServerSettingFile = StartString + ServerFolder[ServerSettingPosition] + ServerProperties;

    system(cdServerPosition.c_str());
    int excuteResult = system(openServerSettingFile.c_str());
    while (excuteResult != 0)
    {
        Output("�򿪷����������ļ���");
        return;
    }
    Output("�򿪷����������ļ��ɹ���");

    LogFile.close();
}

void About(std::string args)
{
    HomePage();
}