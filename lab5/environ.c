#include <stdio.h>

int main(int argc, char **argv){
  extern char **environ;
  for(int i = 0; i < argc; i++){
    if(environ[argc] == NULL){
      return 0;
    }
    printf("%s", environ[agrc]);
  }
  return 1;
}
