#include "getTime.h"

tm* GetTime()
{
	time_t nowtime;
	time(&nowtime); //获取1970年1月1日0点0分0秒到现在经过的秒数
	tm* NowTime = localtime(&nowtime); //将秒数转换为本地时间,年从1900算起,需要+1900,月为0-11,所以要+1
	return NowTime;
}

int YMD()
{
	tm* getymd = GetTime();
	int Years = getymd->tm_year + 1900;
	int Months = getymd->tm_mon + 1;
	int Days = getymd->tm_mday;
	return Years, Months, Days;
}
