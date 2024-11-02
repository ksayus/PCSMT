#ifndef SERVERCOMMAND
#define SERVERCOMMAND

#include <string>
#include <Windows.h>

void Start(std::string args);
void Help(std::string args);
void AddServer(std::string args);
void ToStartServer(std::string args);
void ServerList(std::string args);
void ServerSetting(std::string args);
void About(std::string args);

#endif // !SERVERCOMMAND

