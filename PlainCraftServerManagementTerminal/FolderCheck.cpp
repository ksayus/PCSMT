#include "FolderCheck.h"

void CheckPCSMTFolder()
{
	if (_access("./PCSMT", 0) == -1)
	{
		std::cout << "文件夹不存在，创建中..." << std::endl;
		int serverposition = _mkdir("./PCSMT");
		std::cout << "创建完成！" << std::endl;
	}
	else {
		std::cout << "检查完毕！文件夹存在！" << std::endl;
	}
}
