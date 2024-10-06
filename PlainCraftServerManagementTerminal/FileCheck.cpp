#include "FileCheck.h"
#include "FileFind.h"

#include "FilesFoldersPosition.h"

std::string XmsRam = "4096M";
std::string XmxRam = "4096M";

std::string ServerCoreFileName;

void CheckStartBatch(std::string StartBatchpath)
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

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
			Output("未发现Start.bat文件！");
			Output("创建Start.bat文件！");
			StartBatch.open(StartBatchPath, std::fstream::out | std::fstream::trunc);

			//检查文件是否创建
			if (StartBatch.is_open()) {
				Output("创建并打开了Start.bat文件。");

				//创建并配置Start.bat文件
				StartBatch << "cd " + StartBatchpath << std::endl;
				StartBatch << "java -jar -Xms" + XmsRam + " -Xmx" + XmxRam + " -jar " + ServerCoreFileName << std::endl;
				Output("配置成功！");
				StartBatch.close(); // 操作完成后关闭文件
			}
			else {
				Output("尝试创建文件失败！");
			}
		}
		else {
			//绑定并配置Start.bat文件
			Output("已绑定Start.bat文件！");
			StartBatch << "cd " + StartBatchpath << std::endl;
			StartBatch << "java -jar -Xms" + XmsRam + " -Xmx" + XmxRam + " -jar " + ServerCoreFileName << std::endl;
			Output("配置成功！");
			StartBatch.close(); // 操作完成后关闭文件
		}
	}
	LogFile.close();
}
