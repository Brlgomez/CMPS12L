// # $Id: exit255.java,v 1.2 2014-01-19 19:19:55-08 - - $
//Brandon Gomez brlgomez
import static java.lang.System.*;
class exit255{
    public static final int EXIT_FAILURE = 255;
    public static final int EXIT_SUCCESS = 0;
    public static int exit_status = EXIT_SUCCESS;
    
    public static void main (String[] args){
        err.printf("%s%n" , "EXIT 255");
        exit_status = EXIT_FAILURE;
        exit (exit_status);
    }
}
