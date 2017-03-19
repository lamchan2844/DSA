/* echostate.c
 * reports current state of echo bit in tty driver for fd 0
 * shows how to read attributes from drirver and test a bit
 */
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
void main()
{
	struct termios info;
	int rv;
	rv = tcgetattr(0,&info);
	if(rv == -1){
		perror("tcgetattr");
		exit(1);
	}
	if (info.c_lflag & ECHO){
		printf("echos is on,since its bit is 1\n");
	}else{
		printf("echos is off,since its bit is 0\n");
	}
}
