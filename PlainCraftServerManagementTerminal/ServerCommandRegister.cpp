#include "ServerCommandRegister.h"

#include "ServerCommand.h"
#include "registerServerCommand.h"

void setServerCommand()
{
	//注册指令
	//注册指令后记得在ServerCommand.cpp中实现指令,还有在ServerCommand.h中声明
	registerServerCommand("start", Start);
	registerServerCommand("help", Help);
	registerServerCommand("addserver", AddServer);
	registerServerCommand("startserver", ToStartServer);
	registerServerCommand("serverlist", ServerList);
}
