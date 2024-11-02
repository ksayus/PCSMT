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
	//打开文件
	ReadFilesPosition.open(ADot + PCSMTPositionFolder + "/" + FilesName, std::ios::in);

	if (ReadFilesPosition.is_open() == false)
	{
		Output("文件打开失败！");
		return 0;
	}

	Output("读取文件" + FilesName + "中！");


	while (std::getline(ReadFilesPosition, FilesReaded[ReadFilesContent]))
	{
		Output("读取:" + FilesReaded[ReadFilesContent]);
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