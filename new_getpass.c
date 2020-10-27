#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>


char *new_getpass(char *name) {
#define CHUNK	10	
 char *ret;
 char data;
 unsigned int done, pos = 0;
 struct termios ios;
 tcflag_t old_lflag;
 tcgetattr(fileno(stdin), &ios);
 old_lflag = ios.c_lflag;
 ios.c_lflag &= ~ICANON;
 ios.c_lflag &= ~ECHO;
 tcsetattr(fileno(stdin), TCSANOW, &ios);

 ret = (char *)malloc(CHUNK);
 *ret = 0;
 printf("%s's password (0_o):", name);
 fflush(stdout);
 for(done=0;done!=1;) 
  while(read(fileno(stdin), &data, 1) !=0) {
   if(data == '\n') {done = 1; break; }
   ret[pos++] = data;
   if((pos%CHUNK)==0) 
    ret = realloc(ret, pos+CHUNK);
   
   printf("\33[5D%s):", ((pos&1)==1 ? "o_O" : "O_o"));
   fflush(stdout);
  } 

 ret[pos] = 0;

 ios.c_lflag = old_lflag;
 tcsetattr(fileno(stdin), TCSANOW, &ios);
 putchar('\n');
 return ret;
#undef CHUNK
}

