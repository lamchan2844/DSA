/*who1.c -a first version of the who program
 * 				open ,read UTMP file,and show results �򿪲��Ҷ���UTMP�ļ�����ʾ����
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
	struct utmp current_record;//����utmp�ṹ��current_record
	int utmpfd;//�ļ�����
	int reclen = sizeof(current_record);//utmp�ṹ�ĳ���
//	printf("reclen = %d \n",reclen);
//��UTMP_FILE�ļ�
	if ((utmpfd = open(UTMP_FILE,O_RDONLY)) == -1){
		perror(UTMP_FILE);
		exit(1);
	}
	//��ȡUTMP_FILE������
	while(read(utmpfd,&current_record,reclen) == reclen)
		show_info(&current_record);//�����ȡ������
	close(utmpfd);
	return 0;
}
//��ʾutmp�ṹ������
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
