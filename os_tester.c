#include <stdio.h>
	//from stackoverflow:
#ifdef WIN32
#define SYSTEM_CALL "dir /p"
#else
#define SYSTEM_CALL "ls -a | less"
#endif


int main(int argc, const char *argv[])
{
	system(SYSTEM_CALL);

	return 0;
}
