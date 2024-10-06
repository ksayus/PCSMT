#include "OutputLog.h"

#include "getTime.h"
#include "FilesFoldersPosition.h"

void TimeLog()
{
	//获取时间
	tm* gettime = GetTime();

	//将int转为string并加上 "/"
	std::string YearsPath = RightSlash + std::to_string(gettime->tm_year + 1900);
	std::string MonthsPath = RightSlash + std::to_string(gettime->tm_mon + 1);
	std::string DaysPath = RightSlash + std::to_string(gettime->tm_mday);

	//定义文件名和日志输出目录
	std::string LogName = std::to_string(gettime->tm_hour) + HorizontalLine + std::to_string(gettime->tm_min) + HorizontalLine + std::to_string(gettime->tm_sec) + Txt;
	std::string LogOutputPath = ADot + PCSMTLogPositionFolder + YearsPath + MonthsPath + DaysPath + RightSlash + LogName;
	
	//
	//std::cout << LogOutputPath << std::endl;

	std::ofstream fout; //文件输出流对象

	fout.open(LogOutputPath, std::ios::out);

	if (!fout.is_open())
	{
		std::cout << "打开文件失败！" << std::endl;
		return;
	}
	else {
		std::cout << "成功打开文件" + LogName << std::endl;
		std::streambuf* pOld = std::cout.rdbuf(fout.rdbuf());
		std::cout << std::to_string(gettime->tm_hour) + Colon + std::to_string(gettime->tm_min) + Colon + std::to_string(gettime->tm_sec) + " 启动了PCSMT" << std::endl;
		std::cout.rdbuf(pOld);
		fout.close();
	}
}
