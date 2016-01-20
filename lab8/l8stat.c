// $Id:

#include <errno.h>
#include <libgen.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <utime.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int exit_status = EXIT_SUCCESS;
char *progname = NULL;

void l8stat(char *filename){
  struct stat buffer;
  int info = lstat(filename, &buffer);
  if (info != 0) {
    fflush (NULL);
    fprintf (stderr, "%s: %s\n",
	     filename, strerror (errno));
    fflush (NULL);
    exit_status = EXIT_FAILURE;
  } 
  else{
    setlocale (LC_NUMERIC, "en_US");
    time_t now;
    time(&now);
    int time180 = 180 * 24 * 60 * 60;
    char *timeformat = NULL;
    char buff[256];
    struct tm *tm = localtime (&buffer.st_mtime);
    if(now - buffer.st_mtime > time180){
      timeformat = "%b %e  %Y";
      strftime (buff, sizeof buff, timeformat, tm);
      printf ("%16s %s\n", buff, filename);
    }
    else{
      timeformat = "%b %e %R";
      strftime (buff, sizeof buff, timeformat, tm);
      printf ("%16s %s\n", buff, filename);
    }
  }
}

int main (int argc, char **argv) {
  progname = basename(argv[0]);
  if(argc == 1){
    l8stat(".");
  }
  else{
    for(int i = 1; i < argc; i++){
      l8stat(argv[i]);
    }
  }
}


