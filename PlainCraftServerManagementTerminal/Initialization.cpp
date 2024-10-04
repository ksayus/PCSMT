#include "Initialization.h"

int InitializationServerPosition()
{
	int ReadServerPostionContent = 0;

	std::string ServerPositionReaded[MaxServerPositonTotals];
	std::ifstream ReadServerPosition;
	//打开文件
	ReadServerPosition.open(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::in);

	std::cout << "读取文件" + ServerPositionTxt + "中！" << std::endl;


	while (std::getline(ReadServerPosition, ServerPositionReaded[ReadServerPostionContent]))
	{
		std::cout << "读取服务器地址:" + ServerPositionReaded[ReadServerPostionContent] << std::endl;
		ServerPosition[ReadServerPostionContent] = ServerPositionReaded[ReadServerPostionContent];
		//return ServerPositionReaded[ReadServerPostionContent];
	}
	return ReadServerPostionContent;
}
