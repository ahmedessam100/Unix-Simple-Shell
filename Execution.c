#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Parser.h"
#include <signal.h>
#include <unistd.h>
#include "handlers.h"

/*Background flag referenced from Parser.c*/
extern int background;

int main(void) {
    /*Initializing Call Back Function*/
    void (*handler)(int);
    handler = SET_HANDLER();
    /*Setting the handler of SIGCHLD signal*/
    signal(SIGCHLD,handler);
    /*Terminal Command*/
    char** args =(char**)malloc(50);
    /*Initialize Array of strings that keep the parsed command*/
    char** parsed=(char**)malloc(50);
    args[0] = (char *)malloc(50);
    while (1) {
	printf("User:$ ");
	/*Scanning the command*/
        scanf("%[^\n]%*c", args[0]);
	/*Parsing the command*/
        parsed = args_parser(args);
	/*Forking a process*/
        pid_t pid = fork();
	/*CHILD*/        
	if (pid == 0)
        {
            if (execvp(parsed[0], parsed) == -1) {
                _exit(-1);
            }
        }
	/*PARENT*/
        else if (pid > 0)
        {
	    /*If the command is to run in foreground*/
            if(!background) {
		/*The Parent Waits the child to finish*/
                wait(0);
                background = 0;
            }
    	    /*If the command is Exit*/
            if(strcmp(parsed[0],"exit")==0)
            {
                exit(0);
            }
        }
    }
    return 0;
}
