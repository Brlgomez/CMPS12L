// # $Id$
//Brandon Gomez brlgomez
import static java.lang.System.*;
class exit1{
    public static final int EXIT_FAILURE = 1;
    public static final int EXIT_SUCCESS = 0;
    public static int exit_status = EXIT_SUCCESS;
    
    public static void main (String[] args){
        err.printf("%s%n" , "EXIT 1");
        exit_status = EXIT_FAILURE;
        exit (exit_status);
    }
}