#include "searchwords.h"
#include<malloc.h>
#include<errno.h>
#include<limits.h>
Word_String *res(char *name_of_file)
{
    if (!name_of_file)
        {
            errno = EFAULT;
            return -1;
        }
    Word_String *File_st = W_S_constructor();
    if (File_st == NULL)
        {
            errno = EFAULT;
            return -1;
        }
    file = fopen(name_of_file,"r");
    if (!file)
        {
            errno = ENOTEMPTY;
            return -1;
        }
    int c = 0,inside = 0;
       while(!feof(file))
    {
        c = fgetc(file);
        if(c == '\n')
            {
                File_st->Num_of_strings++;
                if (File_st->Num_of_strings >= LLONG_MAX)
                    {
                        errno = EPROTO;
                         return -1;
                    }
            }
        if((c == ' ') || (c == '\t') || (c == '\n') )
            inside = 0;
        else
            if (!inside)
            {
                inside = 1;
                ++File_st->Num_of_words;
                if (File_st->Num_of_words >= LLONG_MAX)
                    {
                        errno = EPROTO;
                         return -1;
                    }

            }
    }
    fclose(file);
    errno = 0;
    return File_st;
}

Word_String *W_S_constructor()
{
     Word_String *my_st = (Word_String*)(malloc(1*sizeof(Word_String)));
     if (my_st != NULL)
        {
            my_st->Num_of_words = -1;
            my_st->Num_of_strings = 0;
            return my_st;
        }
     else
        {
            errno = ENOMEM;
            return NULL;
        }
errno = 0;
}
int ERROR(FILE *fp)
{
    if (!fp)
        return -1;
    else
        {
            switch errno
            {
                case ENOTEMPTY:
                    printf("adress is wrong");
                    break;
                case ENOMEM:
                    printf("No memory");
                    break;
                case EFAULT:
                    printf("No memory for file");
                    break;
                case EPROTO:
                    printf("VERY LONG FOR GCC");
                    break;
                default:
                    printf("Unknown error");
                    break;
            }
        }
}
