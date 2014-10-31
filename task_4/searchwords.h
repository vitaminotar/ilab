#ifndef SEARCHWORDS
#define SEARCHWORDS
#include<stdio.h>

typedef struct
{
    long long Num_of_words;
    long long Num_of_strings;
}Word_String;
/***********
*param: our
* if success : return our struct
*if fail : return -1
*/
Word_String *res(char *name_of_file);
/************
*if success : return *struct
*if fail : return -1
*/
Word_String *W_S_constructor();
#endif
