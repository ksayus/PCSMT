#include "FileCheck.h"
#include "FileFind.h"

#include "FilesFoldersPosition.h"

std::string XmsRam = "4096M";
std::string XmxRam = "4096M";

std::string ServerCoreFileName;

void CheckStartBatch(std::string StartBatchpath)
{
	ServerCoreFileName = FindFilesWithExtension(StartBatchpath, ".jar");
	std::string StartBatchPath = StartBatchpath + "/Start.bat";

	if (ServerCoreFileName == "")
	{
		return;
	}
	else {
		// 尝试打开文件
		std::fstream StartBatch;
		StartBatch.open(StartBatchPath);

		// 检查文件是否成功打开
		if (!StartBatch.is_open())
		{
			std::cout << "未发现Start.bat文件！" << std::endl;
			std::cout << "创建Start.bat文件！" << std::endl;
			StartBatch.open(StartBatchPath, std::fstream::out | std::fstream::trunc);

			//检查文件是否创建
			if (StartBatch.is_open()) {
				std::cout << "创建并打开了Start.bat文件。" << std::endl;

				//创建并配置Start.bat文件
				StartBatch << "cd " + StartBatchpath << std::endl;
				StartBatch << "java -jar -Xms" + XmsRam + " -Xmx" + XmxRam + " -jar " + ServerCoreFileName << std::endl;
				std::cout << "配置成功！" << std::endl;
				StartBatch.close(); // 操作完成后关闭文件
			}
			else {
				std::cout << "尝试创建文件失败！" << std::endl;
			}
		}
		else {
			//绑定并配置Start.bat文件
			std::cout << "已绑定Start.bat文件！" << std::endl;
			StartBatch << "cd " + StartBatchpath << std::endl;
			StartBatch << "java -jar -Xms" + XmsRam + " -Xmx" + XmxRam + " -jar " + ServerCoreFileName << std::endl;
			std::cout << "配置成功！" << std::endl;
			StartBatch.close(); // 操作完成后关闭文件
		}
	}
}
