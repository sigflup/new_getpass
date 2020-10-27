#include <stdio.h> 
#include <stdlib.h>
#include "new_getpass.h"

int main(void) { 
 char *password; 
 password = new_getpass("example");
 printf("ok, %s\n", password); 
 free(password);
}
