// $Id: nsort.c,v 1.1 2014-02-26 11:43:51-08 - - $
#include <assert.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define STDIN_NAME "-"
int exit_status = EXIT_SUCCESS;
char *prog_name = NULL;

typedef struct node node;
struct node {
   double item;
   node *link;
};

typedef struct options {
   bool print_debug;
} options;

 node *head = NULL;
void insertascending (double newitem);
/*   
   // Free up all of the nodes.
   //
   while (head != NULL) {
      node *old = head;
      head = head->link;
      free (old);
   }
*/
//scanNum(FILE *input, char *filename, char *progname)
void scanNum(){
   for (;;) {
      // Try to read a double number.  Print an error message if a
      // word is not recognized as a number.  Stop at end of file.
      double number;
      int scancount = scanf ("%lg", &number);
      if (scancount == EOF || scancount !=1) {
         printf ("EOF\n");
         break;
      }else{
		 insertascending(number);
      }
   };
}

void insertascending (double newitem) {
   node *prev = NULL;
   node *curr = head;
   while(curr != NULL){
     if(curr->item > newitem) break;
	 prev = curr;
	 curr = curr->link;
   }
   
   node *tmp = malloc (sizeof (struct node));
   assert (tmp != NULL);
   tmp->item = newitem;
   tmp->link = curr;
   if(prev == NULL) head = tmp;
         else prev->link = tmp;
}

void print_nodes(node *head, options *opts){
   if(opts->print_debug == false) {
      for(node *curr = head; curr!= NULL; curr = curr->link){
         printf("%24.15g\n", curr->item);
      }
   }
   else{
      printf ("&head= %p\n", &head);
      printf ("head= %p\n", head);
      for (node *curr = head; curr != NULL; curr = curr->link) {
         printf ("%p -> struct node {item= %.15g, link= %p}\n",
                 curr, curr->item, curr->link);
      }
      printf ("NULL= %p\n", NULL);
   }
}

void scan_options (int argc, char **argv, options *opts) {
   opts->print_debug = false;
   opterr = false;
   for (;;) {
      int opt = getopt (argc, argv, "d");
      if (opt == EOF) break;
      switch (opt) {
         case 'd':
            opts->print_debug = true;
            break;
         default:
            exit_status = EXIT_FAILURE;
            fflush (NULL);
            fprintf (stderr, "%s: -%c: invalid option\n",
                             prog_name, optopt);
            break;
      }
   }
}

int main (int argc, char **argv) { 
   options opts;
   prog_name = basename (argv[0]);
   int check = 1;
   scan_options(argc, argv, &opts);
   if(opts.print_debug == true) check = 2;
   if(argc == check){
      scanNum();
	  print_nodes(head, &opts);
   }
   else{
      for (int argi = check; argi < argc; ++argi) {
	  char *filename = argv[argi];
         if (strcmp (filename, STDIN_NAME) == 0) {
	        scanNum();
			print_nodes(head, &opts);
         }else {
            FILE *input = fopen (filename, "r");
            if (input != NULL) {
		       scanNum();
			   print_nodes(head, &opts);
               fclose (input);
            }else {
               //If the file is empty
               //Print error message
               exit_status = EXIT_FAILURE;
               fflush (NULL);
               fprintf (stderr, "%s: %s: %s\n", prog_name,
                        filename, strerror (errno));
               fflush (NULL);
            }
         }
      }
   }
   return exit_status;
}



