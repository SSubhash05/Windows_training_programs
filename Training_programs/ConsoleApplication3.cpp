
#include "ConsoleApplication3.h"
using namespace std;

#pragma pack(1)
typedef struct time
{
	WORD hour;
	WORD minute;
}TIME;

/* Program to write the current time of the system into a file every 65 seconds*/
int main()
{
	SYSTEMTIME time_info;
	TIME t;
	DWORD sleep_time = 65000;
	FILE *fp;

	while (1)
	{
		Sleep(sleep_time);
		GetLocalTime(&time_info);
		t.hour = time_info.wHour;
		t.minute = time_info.wMinute;

		if (!(fp = fopen("time.txt", "wb")))
		{
			printf("file not opened properly\n");
			return false;
		}

		if (fwrite(&t, 4, NMEB, fp) == EOF)
		{
			printf("fwrite is not excecuted successfully\n");
		}
		
		if (fclose(fp) == EOF)
		{
			printf("The file is not closed successfully\n");
		}
	}

	return 0;
}

