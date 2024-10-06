#include "Initialization.h"

#include "FilesFoldersPosition.h"

int InitializationServerPosition()
{
	const int MaxServerTotals = 512;
	int ReadServerPostionContent = 0;

	std::string ServerPositionReaded[MaxServerTotals];
	std::ifstream ReadServerPosition;
	//打开文件
	ReadServerPosition.open(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::in);

	if (ReadServerPosition.is_open() == false)
	{
		std::cout << "文件打开失败！" << std::endl;
		return 0;
	}

	std::cout << "读取文件" + ServerPositionTxt + "中！" << std::endl;


	while (std::getline(ReadServerPosition, ServerPositionReaded[ReadServerPostionContent]))
	{
		std::cout << "读取服务器地址:" + ServerPositionReaded[ReadServerPostionContent] << std::endl;
		ServerPosition[ReadServerPostionContent] = ServerPositionReaded[ReadServerPostionContent];
		//return ServerPositionReaded[ReadServerPostionContent];
		ReadServerPostionContent++;
	}
	return ReadServerPostionContent;
}

int InitializationServerName()
{
	const int MaxServerTotals = 512;
	int ReadServerNameContent = 0;

	std::string ServerNameReaded[MaxServerTotals];
	std::ifstream ReadServerName;
	//打开文件
	ReadServerName.open(ADot + PCSMTPositionFolder + ServerNameTxt, std::ios::in);

	if (ReadServerName.is_open() == false)
	{
		std::cout << "文件打开失败！" << std::endl;
		return 0;
	}

	std::cout << "读取文件" + ServerNameTxt + "中！" << std::endl;

	while (std::getline(ReadServerName, ServerNameReaded[ReadServerNameContent]))
	{
		std::cout << "读取服务器名：" + ServerNameReaded[ReadServerNameContent] << std::endl;
		ServerName[ReadServerNameContent] = ServerNameReaded[ReadServerNameContent];
		std::cout << ReadServerNameContent << std::endl;
		ReadServerNameContent++;
	}
	return ReadServerNameContent;
}

int InitializationServerFolder() 
{
	const int MaxServerTotals = 512;
	int ReadServerFolderContent = 0;

	std::string ServerFolderReaded[MaxServerTotals];
	std::ifstream ReadServerFolder;
	//打开文件
	ReadServerFolder.open(ADot + PCSMTPositionFolder + ServerFolderTxt, std::ios::in);

	if (ReadServerFolder.is_open() == false)
	{
		std::cout << "文件打开失败！" << std::endl;
		return 0;
	}

	std::cout << "读取文件" + ServerFolderTxt + "中！" << std::endl;

	while (std::getline(ReadServerFolder, ServerFolderReaded[ReadServerFolderContent]))
	{
		std::cout << "读取服务器所在文件夹：" + ServerFolderReaded[ReadServerFolderContent] << std::endl;
		ServerFolder[ReadServerFolderContent] = ServerFolderReaded[ReadServerFolderContent];
		std::cout << ReadServerFolderContent << std::endl;
		ReadServerFolderContent++;
	}
	return ReadServerFolderContent;
}