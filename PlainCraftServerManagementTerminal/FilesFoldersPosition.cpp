#include "FilesFoldersPosition.h"

const int MaxServerTotals = 512;
const int ServerAbsolutePathLong = 512;

//Files
std::string ServerPositionTxt = "/ServerPosition.txt";
std::string ServerNameTxt = "/ServerName.txt";
std::string ServerFolderTxt = "/ServerFolder.txt";
std::string StartBatch = "/Start.bat";
std::string StartServerBatch = "Start.bat";

//Folders
std::string PCSMTPositionFolder = "/PCSMT";
std::string PCSMTLogPositionFolder = "/PCSMT/Log";
std::string sourcePositionFolder = "/source";

//Others
std::string ADot = ".";
const char* TabKey = "\t";
std::string CD = "cd ";
std::string StartString = "start ";
std::string RightSlash = "/";
std::string HorizontalLine = "-";
std::string Txt = ".txt";
std::string Colon = ":";

//Server
std::string ServerPosition[MaxServerTotals];
std::string ServerName[MaxServerTotals];
std::string ServerFolder[MaxServerTotals];

int ServerNameNumber = 0;
int ServerPositionNumber = 0;
int ServerFolderNumber = 0;