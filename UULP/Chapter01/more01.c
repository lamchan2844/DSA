/* more01.c version0.1 of more 
 * read and print 24 lines the pause for a few special commands
 */
#include<stdio.h>
#include<stdlib.h>
#define PAGELEN 24 //ҳ����ʾ������
#define LINELEN 512 //һ�ζ�ȡ�ĳ���
void do_more(FILE * ); //��������ʾ����ʾ����
int see_more(); //�����û�������
int main(int ac,char *av[])
{
	FILE *fp;
	/*�жϽ�������Դ��1->�ӱ�׼���������� ������ļ��л������*/
	if (ac == 1)		
		do_more(stdin);
	else
		while(--ac)
			if((fp=fopen(*++av,"r"))!=NULL)//���δ��ļ�
			{
				do_more(fp);//��ʾ�ļ�����
				fclose(fp);
			}else
				exit(1);
	return 0;

}
void do_more(FILE *fp)
{
	char line[LINELEN];//��Ŷ�ȡ������
	int num_of_lines = 0;//��ǰ�����к�
	int see_more(),reply;//����
	while (fgets(line,LINELEN,fp)){//��fp�ж���LINELEN���ַ���line��
		if (num_of_lines == PAGELEN){//�ж��Ƿ񵽴ﵥҳ��ʾ�ĳ���
			reply = see_more();//�ȴ��û���������
			if (reply == 0){
				//�˳�
				break;
			}
			num_of_lines -=reply;//���¶�λ��ǰ�����к�
		}
		if (fputs(line,stdout)==EOF)//�ж��Ƿ������������
			exit(1);
		num_of_lines++;//���µ�ǰ�����к�
	}
}
int see_more()
{
	//�ȴ��û���������
	int c;
	printf("\033[7m more?\033[m");//����more?
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
