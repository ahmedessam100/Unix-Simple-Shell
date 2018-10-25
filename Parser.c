//
// Created by ahmed on 15/10/18.
//

#include "Parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int background = 0;

/*
!Comment:
Description: this Function Parse the entered command
        Input: 1) Terminal command array of string
        Output: Array of strings of Command and it's arguments
*/
char** args_parser(char** args)
{
    int i=0;
    char *tokens,*temp;
    char **script = (char**)malloc(100);
    script[0] = (char *)malloc(10* sizeof(char));
    script[1] = (char *)malloc(20* sizeof(char));
    script[2] = (char *)malloc(40);
    /*Spliting the String of command*/
    tokens = strtok(args[0]," ");
    while( tokens != NULL )
    {
        script[i] = tokens;
        //temp = script[i];
        tokens = strtok(NULL, " ");
        //Check if it is background executed in the background
        if((i==1)&&(strcmp(script[1],"&")==0))
        {
            script[1] = NULL;
            background = 1;
        }
        i++;
    }
    script[i] = NULL;
    return  script;
}