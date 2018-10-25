#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Parser.h"
#include <signal.h>
#include <unistd.h>
#include "handlers.h"

extern int background;

int main(void) {
        void (*handler)(int);
        handler = SET_HANDLER();
        /*Terminal Command*/
        char** args =(char**)malloc(50);
        /*Initialize Array of strings that keep the parsed command*/
        char** parsed=(char**)malloc(50);
        args[0] = (char *)malloc(50);
    while (1) {
        scanf("%[^\n]%*c", args[0]);
        parsed = args_parser(args);
        pid_t pid = fork();
        if (pid == 0)
        {
            /*printf("CHILD\n");*/
            if (execvp(parsed[0], parsed) == -1) {
                _exit(-1);
            }
        }
        else if (pid > 0)
        {
            signal(SIGCHLD,handler);
            if(!background) {
                wait(0);
                background = 0;
            }
            if(strcmp(parsed[0],"exit")==0)
            {
                exit(0);
            }
            /*printf("PARENT\n");*/
        }
    }
    return 0;
}

