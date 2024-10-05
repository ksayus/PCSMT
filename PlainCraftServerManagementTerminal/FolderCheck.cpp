#include "FolderCheck.h"

#include "getTime.h"
#include "FilesFoldersPosition.h"

void CheckPCSMTFolder()
{
	std::string PCSMTFolderPosition = ADot + PCSMTPositionFolder;

	if (_access(PCSMTFolderPosition.c_str(), 0) == -1)
	{
		std::cout << "文件夹不存在，创建中..." << std::endl;
		int serverposition = _mkdir(PCSMTFolderPosition.c_str());
		std::cout << "创建完成！" << std::endl;
	}
	else {
		std::cout << "检查完毕！文件夹存在！" << std::endl;
	}
}

void CheckTimeFolder()
{
	tm* gettime = GetTime();

	//存储时间
	std::string Year = RightSlash + std::to_string(gettime->tm_year + 1900);
	std::string Month = RightSlash + std::to_string(gettime->tm_mon + 1);
	std::string Day = RightSlash + std::to_string(gettime->tm_mday);

	//日志文件路径
	std::string LogFolderPath = ADot + PCSMTLogPositionFolder;
	std::string YearFolderPath = LogFolderPath + Year;
	std::string MonthFolderPath = YearFolderPath + Month;
	std::string DayFolderPath = MonthFolderPath + Day;

	if (_access(LogFolderPath.c_str(), 0) == -1)
	{
		std::cout << "文件夹" << PCSMTLogPositionFolder << "不存在，创建中..." << std::endl;
		int serverposition = _mkdir(LogFolderPath.c_str());
		std::cout << "创建完成！" << std::endl;
	}
	else {
		std::cout << "检查完毕！文件夹" << PCSMTLogPositionFolder << "存在！" << std::endl;
	}

	//YearsFolder
	if (_access(YearFolderPath.c_str(), 0) == -1)
	{
		std::cout << "文件夹" << Year << "不存在，创建中..." << std::endl;
		int serverposition = _mkdir(YearFolderPath.c_str());
		std::cout << "创建完成！" << std::endl;
	}
	else {
		std::cout << "检查完毕！文件夹" << Year << "存在！" << std::endl;
	}

	//MonthsFolder
	if (_access(MonthFolderPath.c_str(), 0) == -1)
	{
		std::cout << "文件夹" << Month << "不存在，创建中..." << std::endl;
		int serverposition = _mkdir(MonthFolderPath.c_str());
		std::cout << "创建完成！" << std::endl;
	}
	else {
		std::cout << "检查完毕！文件夹" << Month << "存在！" << std::endl;
	}

	//DaysFolder
	if (_access(DayFolderPath.c_str(), 0) == -1)
	{
		std::cout << "文件夹" << Day << "不存在，创建中..." << std::endl;
		int serverposition = _mkdir(DayFolderPath.c_str());
		std::cout << "创建完成！" << std::endl;
	}
	else {
		std::cout << "检查完毕！文件夹" << Day << "存在！" << std::endl;
	}
}
