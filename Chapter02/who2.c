/*who2.c  read /etc/utmp and list info therein 
					suppresses empty records
					formats time nicely
 */
#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#define SHOWHOST
void showtime(long);
void show_info(struct utmp *utbufp);
int main()
{
	struct utmp utbuf;
	int utmpfd;
//	int reclen = sizeof(current_record);
//	printf("reclen = %d \n",reclen);
	if ((utmpfd = open(UTMP_FILE,O_RDONLY)) == -1){
		perror(UTMP_FILE);
		exit(1);
	}
	while(read(utmpfd,&utbuf,sizeof(utbuf)) == sizeof(utbuf))
		show_info(&utbuf);
	close(utmpfd);
	return 0;
}

void show_info(struct utmp * utbufp)
{
	if (utbufp->ut_type != USER_PROCESS)//判断是否为当前已经登录的用户
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
//将unix时间转换为Jul 24 01:07格式的时间
void showtime(long timeval)
{
	char * cp;
	cp = ctime(&timeval);
	printf("%12.12s",cp+4);
}
