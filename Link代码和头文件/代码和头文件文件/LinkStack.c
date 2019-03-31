#include"LinkStack.h"

//链栈(基于链表的)
Status initLStack(LinkStack *s);   //初始化

Status isEmptyLStack(LinkStack *s);  //判断链栈是否为空

Status getTopLStack(LinkStack *s,ElemType *e);  //得到栈顶元素

Status clearLStack(LinkStack *s);   //清空栈

Status destroyLStack(LinkStack *s);   //销毁栈

Status LStackLength(LinkStack *s,int *length);    //检测栈长度

Status pushLStack(LinkStack *s,ElemType data);   //入栈

Status popLStack(LinkStack *s,ElemType *data);   //出栈


Status initLStack(LinkStack *s)
{
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!s)return ERROR;
    s->top->next=NULL;
    s->count = 0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)
{ if(s->count == 0)return SUCCESS;//链表为空返回真值，否则返回假
  else return ERROR;
}


Status getTopLStack(LinkStack *s,ElemType *e)
{
    if(isEmptyLStack(s))return ERROR;
    *e=s->top->data;
    return SUCCESS;
}

Status clearLStack(LinkStack *s)
{
    if(isEmptyLStack(s))return ERROR;
    LinkStackPtr p;
    while(s->count!=0)
    {
      p = s->top->next;
      free(s->top);
      s->top=p;
      s->count--;
    }
    return SUCCESS;
}

Status destroyLStack(LinkStack *s)
{
    if(isEmptyLStack(s))return ERROR;
    LinkStackPtr p;
    while(s->count!=0)
    {
      p = s->top->next;
      free(s->top);
      s->top=p;
      s->count--;
    }
    return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)
{
    *length=s->count;
    return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)
{
    LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
    p->data=data;
    p->next=s;
    s->top->next=p;
    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)
{   if(isEmptyLStack(s))return ERROR;
     LinkStackPtr p;
    *data=s->top->data;
    p=s->top->next;
    free(s->top);
    s->top=p;
    return SUCCESS;
}
