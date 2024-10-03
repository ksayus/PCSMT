#include "ServerCommandRegister.h"

void setServerCommand()
{
	//注册指令
	//注册指令后记得在ServerCommand.cpp中实现指令,还有在ServerCommand.h中声明
	registerServerCommand("start", Start);
	registerServerCommand("help", Help);
	registerServerCommand("addserver", AddServer);
}
