/*who1.c -a first version of the who program
 * 				open ,read UTMP file,and show results 打开并且读入UTMP文件，显示其结果
 */
#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST 
void show_info(struct utmp * utbufp);
int main()
{
	struct utmp current_record;//定义utmp结构的current_record
	int utmpfd;//文件描述
	int reclen = sizeof(current_record);//utmp结构的长度
//	printf("reclen = %d \n",reclen);
//打开UTMP_FILE文件
	if ((utmpfd = open(UTMP_FILE,O_RDONLY)) == -1){
		perror(UTMP_FILE);
		exit(1);
	}
	//读取UTMP_FILE的内容
	while(read(utmpfd,&current_record,reclen) == reclen)
		show_info(&current_record);//输出读取的内容
	close(utmpfd);
	return 0;
}
//显示utmp结构的数据
void show_info(struct utmp * utbufp)
{
	if (utbufp->ut_type != USER_PROCESS)
		return;
	printf("%-8.8s",utbufp->ut_name);
	printf(" ");
	printf("%-8.8s",utbufp->ut_line);
	printf(" ");
	printf("%10ld",utbufp->ut_time);
	printf(" ");
#ifdef SHOWHOST
	printf("(%s)",utbufp->ut_host);
#endif
	printf("\n");
}
