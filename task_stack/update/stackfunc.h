#ifndef STACKFUNC
#define STACKFUNC
typedef struct
{
    int size;// size of stack now
    int *data;//stack
    int  top; // head
    int  Max;// Max size of stack
    int Exist_of_error; // do you have error?
}stack;

typedef struct{
    int stack_undefinded;
    int stack_size_negative;
    int stack_size_big;
    int stack_push_pop;
}Error;


// create stack
stack *constructor(int Size);
// delete stack
int Destroy(stack *my_stack);
//overflow
int full(stack *my_stack);
// get last element
int push (stack *my_stack, int i);
// add element
int pop(stack *my_stack);
//show last element
int topp(stack *my_stack);
// delete all elements
int clear(stack *my_stack);
///////
int Stack_OK(stack *my_stack);
// print errors
int Stack_dump(stack *my_stack, Error Error_stack);
 #endif

