#include "SqStack.h"

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes);  //初始化栈

Status isEmptyStack(SqStack *s);   //判断栈是否为空

Status getTopStack(SqStack *s,ElemType *e);   //得到栈顶元素

Status clearStack(SqStack *s);   //清空栈

Status destroyStack(SqStack *s);  //销毁栈

Status stackLength(SqStack *s,int *length);   //检测栈长度

Status pushStack(SqStack *s,ElemType data);  //入栈

Status popStack(SqStack *s,ElemType *data);   //出栈


Status initStack(SqStack *s,int sizes)
{
    s->top= -1;
    s->size=sizes;
    s->elem=(int*)malloc(sizes*sizeof(int));
    return SUCCESS;
}

Status isEmptyStack(SqStack *s)
{
    if(s->top== -1) return SUCCESS;//若为空栈，返回true
    else return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)
{
    if(isEmptyStack == SUCCESS)return ERROR; //若为空栈，那么返回错误
    *e = s->elem[s->top];
    return SUCCESS;
}

Status clearStack(SqStack *s)
{
    if(isEmptyStack(s) == SUCCESS) return ERROR;
    s->top = -1; //将-1赋值给top，即可将栈清空
    return SUCCESS;
}

Status destroyStack(SqStack *s)
{
    if(isEmptyStack(s) == SUCCESS) return ERROR;
    s->top = -1;
    return SUCCESS;
}

Status stackLength(SqStack *s,int *length)
{
    *length=s->top+1;//top初始时赋值为-1，易知top+1就是栈的长度
    return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)
{
    if(s->top == s->size-1)
        {
         printf("The stack is full\n");
         return ERROR;
        }
    s->top++;
    *(s->elem)=data;//将要加入栈的值传给栈顶
    s->elem++;
    return SUCCESS;
}


Status popStack(SqStack *s,ElemType *data)
{   if(isEmptyStack(s) == SUCCESS) return ERROR;
    *data= *(s->elem);//将栈顶的值传给外部变量
    s->elem--;
    s->top--;
    return SUCCESS;
}







