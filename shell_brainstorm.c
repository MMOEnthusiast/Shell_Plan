/*What goes into a shell?
It must do 3 things.
1st, it must be able to read and execute its config files. Changes aspects of shell's behavior.
2nd, read commands from stdin and executes them.
3rd, It must be able to shutdown any command, free any memory, and terminate.*/

//The first part of the shell
#include <stdio.h>

int main(int argc, char **argv) {
    //This will load any config files that exist

    //Running a command loop
    c_loop();

    //any shutdowns/cleanups that exist will be performed

    return 0; //0 is supposed to be EXIT_SUCCESS, will fix later
}

/*We need the shell to:
Read: read the command from the standard input
Parse: Seperate the command string into a program and arguments
Execute: Run the parsed command.*/

void c_loop(void){ //We tell c that we
    char* lines;  /* These are all simply declarations.*/
    char* argus;
    int details;

    do {
    printf("> ");
    lines = c_read_lines();
    argus = c_split_lines(lines);
    details = c_execute(argus); 

    free(lines);
    free(argus);
} while(details);//do-while loop checks the details variable    
}

//Making it so that the shell can do the "reading"