#include"LinkStack.h"

//��ջ(���������)
Status initLStack(LinkStack *s);   //��ʼ��

Status isEmptyLStack(LinkStack *s);  //�ж���ջ�Ƿ�Ϊ��

Status getTopLStack(LinkStack *s,ElemType *e);  //�õ�ջ��Ԫ��

Status clearLStack(LinkStack *s);   //���ջ

Status destroyLStack(LinkStack *s);   //����ջ

Status LStackLength(LinkStack *s,int *length);    //���ջ����

Status pushLStack(LinkStack *s,ElemType data);   //��ջ

Status popLStack(LinkStack *s,ElemType *data);   //��ջ


Status initLStack(LinkStack *s)
{
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!s)return ERROR;
    s->top->next=NULL;
    s->count = 0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)
{ if(s->count == 0)return SUCCESS;//����Ϊ�շ�����ֵ�����򷵻ؼ�
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
