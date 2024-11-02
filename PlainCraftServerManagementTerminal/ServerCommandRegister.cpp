#include "ServerCommandRegister.h"

#include "ServerCommand.h"
#include "registerServerCommand.h"

void setServerCommand()
{
	//ע��ָ��
	//ע��ָ���ǵ���ServerCommand.cpp��ʵ��ָ��,������ServerCommand.h������
	registerServerCommand("start", Start);
	registerServerCommand("help", Help);
	registerServerCommand("addserver", AddServer);
	registerServerCommand("startserver", ToStartServer);
	registerServerCommand("serverlist", ServerList);
	registerServerCommand("serversetting", ServerSetting);
	registerServerCommand("about", About);
}
