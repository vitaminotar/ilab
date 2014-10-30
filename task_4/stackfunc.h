#ifndef STACKFUNC
#define STACKFUNC

typedef struct
{
    int size;// size of stack now
    double *data;//stack
    double  top; // head
    int  Max;// Max size of stack
} stack;

/*****************
*create stack
* param : size of our stack
* if success : return point to stack
* if fail : return NULL
*/
stack *Stack_Constructor(int Size);
/******************
* param : our stack
* if success : destoy our stack return 0
* if fail : return -1
*/
int Destroy(stack *my_stack);
/******************
* param : our stack
* if success : return 0
* if fail : overflow  return -1
*/
int full(stack *my_stack);
/******************
* param : our stack and number
* if success : add number return 0
* if fail : return -1
*/
int push (stack *my_stack, double i);
/******************
* param : our stack
* if success : move elements from stack and return 0
* if fail : stack full or invaild and return -1
*/
double pop(stack *my_stack);
/******************
* param : our stack
* if success : show last elements of our stack
* if fail : return -1
*/
double topp(stack *my_stack);
/******************
* param : our stack
* if success : delete all elements of stack return 0
* if fail : return -1
*/
int clear(stack *my_stack);
/******************
*param : our stack
* find fail in stack
*/
int Stack_OK(stack *my_stack);
/******************
*param : our stack
* if user want to debug then print errors
*/
int Stack_dump(stack *my_stack);
/******************
*param : our stack
* if success : size of stack less than Max size return 0
* if fail : return -1
*/
int empty(stack *my_stack);
 #endif

