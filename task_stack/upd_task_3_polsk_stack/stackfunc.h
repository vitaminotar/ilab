#ifndef stackfunc
#define stackfunc
typedef struct
{
    int size;// size of stack
    int *data;//stack
    int *top; // head
    int MAX_SIZE;

}stack;
// create stack
stack *constructor(int Size, int type);
// delete stack
void Delete(stack *my_stack);
//overflow
int full(stack *my_stack);
// get last element
void push (stack *my_stack, int i);
//is empty
int empty(stack *my_stack);
// add element
int pop(stack *my_stack);
//show last element
int top(stack *my_stack);
// delete all elements
void clear(stack *my_stack);
 #endif

