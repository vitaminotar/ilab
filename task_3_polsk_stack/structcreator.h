#ifndef structcreator
#define structcreator
typedef struct
{
    int size;
    int *data;
    int head;
    int *top;
    int MAX_SIZE;
    char *ERR; // символ Е - error;

}stack;
// create stack
stack *constructor(int Size, int type)
{
    stack *my_stack=malloc((Size) * (type));
    my_stack->data = malloc((Size) * (type)); // типа void получаем память...
    if (my_stack->data!=0)
    {
        my_stack->MAX_SIZE=Size;
        my_stack->size = 0;
        my_stack->top = my_stack->data;

        my_stack->ERR ="E";
    }
    return my_stack;
}

// delete stack
void delete(stack *my_stack)
{
    free(my_stack->data);
}
// получить размер стека
int  stack_size(stack *my_stack)
{
    return my_stack-> size;
}
//переполнение
int full(stack *my_stack)
{
    if (my_stack->size > my_stack->MAX_SIZE)
    return -1;
}
void push (stack *my_stack, int i)
{
    if (full(my_stack) == -1)
    {
        printf("ERROR");
    }
    else
    {
        my_stack->data[(my_stack->size)++] = i;//вставить и  увеличить стек

    }
}
//проверка на полноту
int empty(stack *my_stack)
{
    if (my_stack->size==0)
        return 0;
}
// добавление элемента
int pop(stack *my_stack)
{
    if (empty(my_stack) != 0)
        return my_stack->data[--my_stack->size];
    else
        return 0;
}

#endif

