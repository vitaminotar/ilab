#ifndef CSTACK
#define CSTACK
#include<stddef.h>
#include<iostream>
#include<assert.h>
#include<cerrno>
#include<string.h>
#include<fstream>
#define DEBUG

template<typename myType>
class CStack
{
    myType *data_;
    int counter_;
    int size_st;
    int CStack_OK();
    int CStack_empty();
    CStack();
public:
    CStack(unsigned int size_s);
    ~CStack();
    int push(myType val);
    myType pop();
    void Stack_debug();
};

template<typename myType>
CStack<myType>::CStack(unsigned int size_s):
    data_ (new myType[size_s]),
    size_st (size_s),
    counter_ (0)
{
    assert(data_);
    memset(data_,0,sizeof(myType));
}
template<typename myType>
CStack<myType>::CStack():
        data_ (new myType[10]),
        size_st (10),
        counter_ (0)
{
            assert(data_);
            memset(data_, 0, sizeof(myType));
}

template<typename myType>
CStack<myType>::~CStack()
{
    delete [] data_;
    data_ = NULL;
}

template<typename myType>
int CStack<myType>::push(myType val)
{
    if(CStack_OK())
        data_[counter_++] = val;
    else
        std::cout << "Stack has errors";
    assert(data_);
}

template<typename myType>
myType CStack<myType>::pop()
{
    assert(data_);
    if(!CStack_empty() && CStack_OK())
        return data_[--counter_];
    else
        std::cout << "Stack has errors";
    Stack_debug();
}

template<typename myType>
int CStack<myType>::CStack_OK()
{
    myType DEL;
    int unmistakable = -1;
    if(!data_)
        {
            errno = ENOMEM;
            unmistakable  = 0;
        }
    if(counter_ >= size_st)
        {
            errno = EACCES;
            unmistakable = 0;
        }
    if(counter_ < 0)
        {
            errno = EINVAL;
            unmistakable  = 0;
        }
    return unmistakable ;
}
template <typename myType>
void CStack<myType>::Stack_debug()
{
    #ifdef DEBUG
    std::ofstream file_dbg("dump.txt");
    if(!CStack_OK())
    {
        if(!data_)
            {
                errno = ENOMEM;
                file_dbg << strerror(errno) << std::endl;
            }
        if(counter_ >= size_st)
            {
                errno = EACCES;
                file_dbg << strerror(errno) << std::endl;
            }
        if(counter_ < 0)
            {
                errno = EINVAL;
                file_dbg << strerror(errno) << std::endl;
            }
    }
    else
    {
        file_dbg << "SUCK\n";
        if(!CStack_empty())
            while(counter_--)
            {
                file_dbg << data_[counter_] << std::endl;
            }
        else
            file_dbg << "Stack is empty\n";
    }
    file_dbg.close();
    #endif // DEBUG
}

template<typename myType>
int CStack<myType>::CStack_empty()
{
    if (counter_ == 0)
        return -1;
    else
        return 0;
}
#endif // CSTACK
