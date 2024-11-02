#include "Initialization.h"

#include "FilesFoldersPosition.h"

int InitializationFiles(std::string FilesName)
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

	const int MaxFilesTotals = 512;
	int ReadFilesContent = 0;

	std::string FilesReaded[MaxFilesTotals];
	std::ifstream ReadFilesPosition;
	//���ļ�
	ReadFilesPosition.open(ADot + PCSMTPositionFolder + "/" + FilesName, std::ios::in);

	if (ReadFilesPosition.is_open() == false)
	{
		Output("�ļ���ʧ�ܣ�");
		return 0;
	}

	Output("��ȡ�ļ�" + FilesName + "�У�");


	while (std::getline(ReadFilesPosition, FilesReaded[ReadFilesContent]))
	{
		Output("��ȡ:" + FilesReaded[ReadFilesContent]);
		if (FilesName == "/ServerName.txt")
		{
			ServerName[ReadFilesContent] = FilesReaded[ReadFilesContent];
		}
		ServerFolder[ReadFilesContent] = FilesReaded[ReadFilesContent];
		//return ServerPositionReaded[ReadServerPostionContent];
		ReadFilesContent++;
	}
	LogFile.close();
	return ReadFilesContent;
}