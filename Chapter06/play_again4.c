/* play_again4.c
 * purpose : 	ask if user wants another transaction
 * method : 	set tty into char-by-char mode and no echo mode,
 * 		set tty into no-delay mode
 * 		read char,return result
 * 		resets terminal modes on SIGINT , ignores SIGQUIT
 * return : 	0=>yes,1=>no 2=>timeout
 * better: 	reset terminal mode on Interrupt
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>

#define QUESTION "Do you want another transaction"
#define TRIES 3
#define SLEEPTIME 2
#define BEEP putchar('\a')


int get_response( char * ,int);
void set_cr_noecho_mode();
void tty_mode(int);
void set_nodelay_mode();
void ctrl_c_handler(int);
int get_ok_char();
int main()
{
	int response ;
	tty_mode(0);	//save tty mode
	set_cr_noecho_mode();
	set_nodelay_mode();
	signal(SIGINT,ctrl_c_handler);
	signal(SIGQUIT,SIG_IGN);
	response = get_response(QUESTION,TRIES);
	tty_mode(1);	//restore tty mode
	printf("response =%d \n",response);
	return response;
}


int get_response(char * question,int maxtries)
{
	int input;
	printf("%s(y/n)?",question);
	fflush(stdout);
	while(1){
		sleep(SLEEPTIME);
		//printf ("wait");
		input = tolower(get_ok_char());
		if (input == 'y')
			return 0;
		if (input == 'n')
			return 1;
		if (maxtries -- == 0)
			return 2;
		BEEP;
	}
}

int get_ok_char()
{
	int c;
	while ((c= getchar())!=EOF && strchr("yYnN",c) == NULL )
	       ;
	return c;
}

void set_nodelay_mode()
{
	int termflags;
	termflags = fcntl(0,F_GETFL);
	termflags |= O_NDELAY;
	fcntl(0,F_SETFL,termflags);
}

void set_cr_noecho_mode()
{
	struct termios ttystate;
	tcgetattr(0,&ttystate);
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_lflag &= ~ECHO;
	ttystate.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&ttystate);
}
void tty_mode(int how)
{
	static struct termios original_mode;
	static int original_flags;
	static int stored = 0;
	if (how == 0)
	{
		tcgetattr(0,&original_mode);
		original_flags = fcntl(0,F_GETFL);
		stored = 1;
	}
	else{
		tcsetattr(0,TCSANOW,&original_mode);
		fcntl(0,F_SETFL,original_flags);
	}
}
void ctrl_c_handler(int signum)
{
	tty_mode(1);
	exit(1);
}
