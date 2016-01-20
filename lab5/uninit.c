// $Id: uninit.c,v 1.1 2014-02-09 16:49:34-08 - - $

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
   int foo;
   printf ("%d\n", foo);
   int *pointer;
   printf ("%d\n", *pointer);
}
