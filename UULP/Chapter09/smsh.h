//#include <stddef.h>
#define YES 1
#define NO 0
char *next_cmd();
char ** splitline(char *);
void freelist(char **);
int execute(char **);
void fatal(char *,char *,int);
void * erealloc(void * p,size_t n);
void * emalloc(size_t);
