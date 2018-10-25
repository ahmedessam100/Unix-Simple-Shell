//
// Created by ahmed-essam100 on 25/10/18.
//

#ifndef UNTITLED_HANDLERS_H
#define UNTITLED_HANDLERS_H

/*
!Comment:
Description: this function handles the SEGCHLD signal
        Input: Nothing
        Output: Write history of child in child.log
*/
void SEG_HANDLE(void);

/*
!Comment:
Description: this Function returns the call back function that handles the SEGCHLD signal
        Input: Nothing
        Output: Write history of child in child.log
*/
void* SET_HANDLER(void);

#endif //UNTITLED_HANDLERS_H
