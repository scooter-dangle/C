#include <stdio.h>
	//from stackoverflow:
#ifdef WIN32
#define SYSTEM_CALL "dir /p"
#else
#define SYSTEM_CALL "ls -a"
#endif


int main(int argc, const char *argv[])
{
	printf(SYSTEM_CALL);

	return 0;
}
