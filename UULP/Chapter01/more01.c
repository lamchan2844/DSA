/* more01.c version0.1 of more 
 * read and print 24 lines the pause for a few special commands
 */
#include<stdio.h>
#include<stdlib.h>
#define PAGELEN 24 //页面显示的行数
#define LINELEN 512 //一次读取的长度
void do_more(FILE * ); //将数据显示在显示器上
int see_more(); //接收用户的输入
int main(int ac,char *av[])
{
	FILE *fp;
	/*判断接收数据源，1->从标准输入获得数据 否则从文件中获得数据*/
	if (ac == 1)		
		do_more(stdin);
	else
		while(--ac)
			if((fp=fopen(*++av,"r"))!=NULL)//依次打开文件
			{
				do_more(fp);//显示文件内容
				fclose(fp);
			}else
				exit(1);
	return 0;

}
void do_more(FILE *fp)
{
	char line[LINELEN];//存放读取的内容
	int num_of_lines = 0;//当前所在行号
	int see_more(),reply;//声明
	while (fgets(line,LINELEN,fp)){//从fp中读入LINELEN个字符到line中
		if (num_of_lines == PAGELEN){//判断是否到达单页显示的长度
			reply = see_more();//等待用户输入命令
			if (reply == 0){
				//退出
				break;
			}
			num_of_lines -=reply;//重新定位当前所在行号
		}
		if (fputs(line,stdout)==EOF)//判断是否读完所有内容
			exit(1);
		num_of_lines++;//更新当前所在行号
	}
}
int see_more()
{
	//等待用户输入命令
	int c;
	printf("\033[7m more?\033[m");//反显more?
	while((c=getchar())!=EOF)
	{
		if (c=='q')
			return 0;
		if (c==' ')
			return PAGELEN;
		if (c=='\n')
			return 1;
	}
	return 0;
}
