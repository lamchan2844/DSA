#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void main()
{
	void wakeup(int);
	printf("about to sleep for 4 seconds\n");
	signal(SIGALRM,wakeup);
	alarm(2);
	pause();
	printf("Morning so soon? \n");
}
void wakeup(int signum)
{
	printf("Alarm received from kernel\n");
}

