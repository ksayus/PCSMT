#include "FolderCheck.h"

#include "getTime.h"
#include "FilesFoldersPosition.h"

void CheckPCSMTFolder()
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

	std::string PCSMTFolderPosition = ADot + PCSMTPositionFolder;

	if (_access(PCSMTFolderPosition.c_str(), 0) == -1)
	{
		Output("文件夹不存在，创建中...");
		int serverposition = _mkdir(PCSMTFolderPosition.c_str());
		Output("创建完成！");
	}
	else {
		Output("检查完毕！文件夹存在！");
	}
	LogFile.close();
}

void CheckTimeFolder()
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

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
		Output("文件夹" + PCSMTLogPositionFolder + "不存在，创建中...");
		int serverposition = _mkdir(LogFolderPath.c_str());
		Output("创建完成！");
	}
	else {
		Output("检查完毕！文件夹" + PCSMTLogPositionFolder + "存在！");
	}

	//YearsFolder
	if (_access(YearFolderPath.c_str(), 0) == -1)
	{
		Output("文件夹" + Year + "不存在，创建中...");
		int serverposition = _mkdir(YearFolderPath.c_str());
		Output("创建完成！");
	}
	else {
		Output("检查完毕！文件夹" + Year + "存在！");
	}

	//MonthsFolder
	if (_access(MonthFolderPath.c_str(), 0) == -1)
	{
		Output("文件夹" + Month + "不存在，创建中...");
		int serverposition = _mkdir(MonthFolderPath.c_str());
		Output("创建完成！");
	}
	else {
		Output("检查完毕！文件夹" + Month + "存在！");
	}

	//DaysFolder
	if (_access(DayFolderPath.c_str(), 0) == -1)
	{
		Output("文件夹" + Day + "不存在，创建中...");
		int serverposition = _mkdir(DayFolderPath.c_str());
		Output("创建完成！");
	}
	else {
		Output("检查完毕！文件夹" + Day + "存在！");
	}
	LogFile.close();
}
