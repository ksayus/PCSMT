#ifndef SERVERCOMMAND
#define SERVERCOMMAND

#include "registerServerCommand.h"
#include "Help.h"
#include "fstream"
#include "FolderCheck.h"
#include "FileCheck.h"
#include "FilesFoldersPosition.h"

void Start(std::string args);
void Help(std::string args);
void AddServer(std::string args);

#endif // !SERVERCOMMAND

