/*What goes into a shell?
It must do 3 things.
1st, it must be able to read and execute its config files. Changes aspects of shell's behavior.
2nd, read commands from stdin and executes them.
3rd, It must be able to shutdown any command, free any memory, and terminate.*/

//The first part of the shell
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    //This will load any config files that exist
    //Running a command loop
    c_loop(); // Implicit declaration...brainstorming how to resolve.

    //any shutdowns/cleanups that exist will be performed

    return EXIT_SUCCESS; //0 is supposed to be EXIT_SUCCESS, will fix later
}

/*We need the shell to:
Read: read the command from the standard input
Parse: Seperate the command string into a program and arguments
Execute: Run the parsed command.*/

void c_loop(void){ //We tell c that we
    char *lines;  /* These are all simply declarations.*/
    char **argus;
    int details;

    do {
    printf("> ");
    lines = (char)c_read_lines();
    argus = c_split_lines(lines);
    details = c_execute(argus); 

    free(lines);
    free(argus);
} while(details);//do-while loop checks the details (integer) variable    
}

//Making it so that the shell can do the "reading"
#define C_RL_BUFSIZE 1024
char *c_read_lines(void)
{
    int bufsize = C_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "c_loop: allocation error\n");
        exit(EXIT_FAILURE);
    }

while (1) //while loop needs a declaration, I'll get back to that later
{   //The character is read
    c = getchar();

    //If we reach the end of the file, we replace c with a null character and return it
    if (c == EOF || c == '\n') {
        buffer[position] = '\0';
        return buffer;
    } else {
        buffer[position] = c;
    };
}
position++;

//If the buffer's been executed, memory will be reallocated.
if (position >= bufsize) {
        bufsize += C_RL_BUFSIZE;
        buffer = realloc(buffer, bufsize);
        if (!buffer) {
            fprintf(stderr, "c_loop: allocation error!");
            exit(EXIT_FAILURE);
        }
    }

}