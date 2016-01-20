#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int main(){
  for(int argi = 1; ; argi++){
    if(environ[argi] == NULL){
      return 0;
    }
    printf("%s", environ[argi]);
  }
  return 0;
}
