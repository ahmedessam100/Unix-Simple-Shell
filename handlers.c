//
// Created by ahmed-essam100 on 25/10/18.
//


#include <bits/types/FILE.h>
#include <stdio.h>
#include "handlers.h"

static int first=0;

/*
!Comment:
        Input: Nothing
        Output: Write history of child in child.log
*/
void SEG_HANDLE(void)
{
    FILE *f;
    if(first==0) {
        f = fopen("../child.log", "w");
        fprintf(f,"%s","CHILD TERMINATED\n");
        first = 1;
        fclose(f);
    }
    else
    {
        f = fopen("../child.log", "a");
        fprintf(f,"%s","CHILD TERMINATED\n");
        fclose(f);
    }
}

/*
!Comment:
Description: this Function returns the call back function that handles the SEGCHLD signal
        Input: Nothing
        Output: Write history of child in child.log
*/
void*  SET_HANDLER(void)
{
    return SEG_HANDLE;
}
