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
		// ���Դ��ļ�
		std::fstream StartBatch;
		StartBatch.open(StartBatchPath);

		// ����ļ��Ƿ�ɹ���
		if (!StartBatch.is_open())
		{
			Output("δ����Start.bat�ļ���");
			Output("����Start.bat�ļ���");
			StartBatch.open(StartBatchPath, std::fstream::out | std::fstream::trunc);

			//����ļ��Ƿ񴴽�
			if (StartBatch.is_open()) {
				Output("����������Start.bat�ļ���");

				//����������Start.bat�ļ�
				StartBatch << "cd " + StartBatchpath << std::endl;
				StartBatch << "java -jar -Xms" + XmsRam + " -Xmx" + XmxRam + " -jar " + ServerCoreFileName + " nogui" << std::endl;
				Output("���óɹ���");
				StartBatch.close(); // ������ɺ�ر��ļ�
			}
			else {
				Output("���Դ����ļ�ʧ�ܣ�");
			}
		}
		else {
			//�󶨲�����Start.bat�ļ�
			Output("�Ѱ�Start.bat�ļ���");
			StartBatch << "cd " + StartBatchpath << std::endl;
			StartBatch << "java -jar -Xms" + XmsRam + " -Xmx" + XmxRam + " -jar " + ServerCoreFileName << std::endl;
			Output("���óɹ���");
			StartBatch.close(); // ������ɺ�ر��ļ�
		}
	}
	LogFile.close();
}
