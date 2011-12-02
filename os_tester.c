#include <stdio.h>

int main(int argc, const char *argv[])
{
	//from stackoverflow:
#ifdef WIN32
	printf("pokermons & Windows");
#else
	printf("pokermons & Unix");
#endif
	return 0;
}
