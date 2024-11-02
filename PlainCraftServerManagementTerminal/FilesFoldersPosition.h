#ifndef FILESFOLDERSPOSITION
#define FILESFOLDERSPOSITION

#include <string>
#include <fstream>
#include <iostream>

extern const int MaxServerTotals;
extern const int ServerAbsolutePathLong;

//Others
extern std::string ADot;
extern const char* TabKey;
extern std::string CD;
extern std::string StartString;
extern std::string RightSlash;
extern std::string HorizontalLine;
extern std::string Txt;
extern std::string Log;
extern std::string Colon;
extern std::string RightAngleBracket;
extern std::string VerticalLine;

//Files
extern std::string ServerPositionTxt;
extern std::string ServerNameTxt;
extern std::string ServerFolderTxt;
extern std::string StartBatch;
extern std::string StartServerBatch;
extern std::string ServerProperties;
extern std::string LogName;

//Folders
extern std::string PCSMTPositionFolder;
extern std::string PCSMTLogPositionFolder;
extern std::string sourcePositionFolder;

//Paths
extern std::string LogOutputPath;

//Server
extern std::string ServerPosition[];
extern std::string ServerName[];
extern std::string ServerFolder[];

extern int ServerNameNumber;
extern int ServerPositionNumber;
extern int ServerFolderNumber;

//将int转为string并加上 "/"
extern std::string YearsPath;
extern std::string MonthsPath;
extern std::string DaysPath;

//Path
extern std::string LogOutputPath;

//Times
extern std::string CompleteTime;
extern std::string OnlyTime;

#endif // !FILESFOLDERSPOSITION