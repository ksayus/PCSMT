#include "FilesFoldersPosition.h"

#include "getTime.h"

//获取时间
tm* gettime = GetTime();


const int MaxServerTotals = 512;
const int ServerAbsolutePathLong = 512;

//Others
std::string ADot = ".";
const char* TabKey = "\t";
std::string CD = "cd ";
std::string StartString = "start ";
std::string RightSlash = "/";
std::string HorizontalLine = "-";
std::string Txt = ".txt";
std::string Log = ".log";
std::string Colon = ":";
std::string RightAngleBracket = ">";
std::string VerticalLine = "|";

//Files
std::string ServerPositionTxt = "/ServerPosition.txt";
std::string ServerNameTxt = "/ServerName.txt";
std::string ServerFolderTxt = "/ServerFolder.txt";
std::string StartBatch = "/Start.bat";
std::string StartServerBatch = "Start.bat";
std::string LogName = std::to_string(gettime->tm_hour) + HorizontalLine + std::to_string(gettime->tm_min) + HorizontalLine + std::to_string(gettime->tm_sec) + Log;

//Folders
std::string PCSMTPositionFolder = "/PCSMT";
std::string PCSMTLogPositionFolder = "/PCSMT/Log";
std::string sourcePositionFolder = "/source";

//Server
std::string ServerPosition[MaxServerTotals];
std::string ServerName[MaxServerTotals];
std::string ServerFolder[MaxServerTotals];

int ServerNameNumber = 0;
int ServerPositionNumber = 0;
int ServerFolderNumber = 0;

//将int转为string并加上 "/"
std::string YearsPath = RightSlash + std::to_string(gettime->tm_year + 1900);
std::string MonthsPath = RightSlash + std::to_string(gettime->tm_mon + 1);
std::string DaysPath = RightSlash + std::to_string(gettime->tm_mday);

//Path
std::string LogOutputPath = ADot + PCSMTLogPositionFolder + YearsPath + MonthsPath + DaysPath + RightSlash + LogName;

//Times
std::string CompleteTime = std::to_string(gettime->tm_year + 1900) + RightSlash + std::to_string(gettime->tm_mon + 1) + RightSlash + std::to_string(gettime->tm_mday) + VerticalLine + std::to_string(gettime->tm_hour) + Colon + std::to_string(gettime->tm_min) + Colon + std::to_string(gettime->tm_sec) + RightAngleBracket;
std::string OnlyTime = std::to_string(gettime->tm_hour) + Colon + std::to_string(gettime->tm_min) + Colon + std::to_string(gettime->tm_sec) + RightAngleBracket;
