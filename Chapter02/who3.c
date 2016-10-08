/*who3.c  who with buffered reads
					suppresses empty records
					formats time nicely
					buffers input (using utmplib)
 */
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>
#include "utmplib.c"
#define SHOWHOST
void showtime(time_t);
void show_info(struct utmp *utbufp);
int main()
{
	struct utmp *utbufp,*utmp_next();
//	int reclen = sizeof(current_record);
//	printf("reclen = %d \n",reclen);
	if ((utmp_open(UTMP_FILE)) == -1){
		perror(UTMP_FILE);
		exit(1);
	}
	while((utbufp = utmp_next())!=((struct utmp *)NULL))
		show_info(utbufp);
	utmp_close();
	return 0;
}

void show_info(struct utmp * utbufp)
{
	if (utbufp->ut_type != USER_PROCESS)
		return;
	printf("%-8.8s",utbufp->ut_name);
	printf(" ");
	printf("%-8.8s",utbufp->ut_line);
	printf(" ");
	
	showtime(utbufp->ut_time);
	printf(" ");
#ifdef SHOWHOST
	if(utbufp->ut_host[0]!='\0')
		printf("(%s)",utbufp->ut_host);
#endif
	printf("\n");
}
void showtime(long timeval)
{
	char * cp;
	cp = ctime(&timeval);
	printf("%12.12s",cp+4);
}
