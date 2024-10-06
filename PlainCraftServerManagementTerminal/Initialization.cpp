#include "Initialization.h"

#include "FilesFoldersPosition.h"

int InitializationServerPosition()
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

	const int MaxServerTotals = 512;
	int ReadServerPostionContent = 0;

	std::string ServerPositionReaded[MaxServerTotals];
	std::ifstream ReadServerPosition;
	//打开文件
	ReadServerPosition.open(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::in);

	if (ReadServerPosition.is_open() == false)
	{
		Output("文件打开失败！");
		return 0;
	}

	Output("读取文件" + ServerPositionTxt + "中！");


	while (std::getline(ReadServerPosition, ServerPositionReaded[ReadServerPostionContent]))
	{
		Output("读取服务器地址:" + ServerPositionReaded[ReadServerPostionContent]);
		ServerPosition[ReadServerPostionContent] = ServerPositionReaded[ReadServerPostionContent];
		//return ServerPositionReaded[ReadServerPostionContent];
		ReadServerPostionContent++;
	}
	LogFile.close();
	return ReadServerPostionContent;
}

int InitializationServerName()
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

	const int MaxServerTotals = 512;
	int ReadServerNameContent = 0;

	std::string ServerNameReaded[MaxServerTotals];
	std::ifstream ReadServerName;
	//打开文件
	ReadServerName.open(ADot + PCSMTPositionFolder + ServerNameTxt, std::ios::in);

	if (ReadServerName.is_open() == false)
	{
		Output("文件打开失败！");
		return 0;
	}

	Output("读取文件" + ServerNameTxt + "中！");

	while (std::getline(ReadServerName, ServerNameReaded[ReadServerNameContent]))
	{
		Output("读取服务器名：" + ServerNameReaded[ReadServerNameContent]);
		ServerName[ReadServerNameContent] = ServerNameReaded[ReadServerNameContent];
		//std::cout << ReadServerNameContent << std::endl;
		ReadServerNameContent++;
	}
	LogFile.close();
	return ReadServerNameContent;
}

int InitializationServerFolder() 
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

	const int MaxServerTotals = 512;
	int ReadServerFolderContent = 0;

	std::string ServerFolderReaded[MaxServerTotals];
	std::ifstream ReadServerFolder;
	//打开文件
	ReadServerFolder.open(ADot + PCSMTPositionFolder + ServerFolderTxt, std::ios::in);

	if (ReadServerFolder.is_open() == false)
	{
		Output("文件打开失败！");
		return 0;
	}

	Output("读取文件" + ServerFolderTxt + "中！");

	while (std::getline(ReadServerFolder, ServerFolderReaded[ReadServerFolderContent]))
	{
		Output("读取服务器所在文件夹：" + ServerFolderReaded[ReadServerFolderContent]);
		ServerFolder[ReadServerFolderContent] = ServerFolderReaded[ReadServerFolderContent];
		//std::cout << ReadServerFolderContent << std::endl;
		ReadServerFolderContent++;
	}
	LogFile.close();
	return ReadServerFolderContent;
}