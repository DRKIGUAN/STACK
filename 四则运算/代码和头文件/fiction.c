#include"define.h"
Status initDStack(LinkDStack *s);
Status pushDStack(LinkDStack *s,double data);
Status popDStack(LinkDStack *s,double *data);
int isEmptyLDStack(LinkDStack *s);
Status getTopLDStack(LinkDStack *s,double *e);
Status initCStack(LinkCStack *s);
Status pushCStack(LinkCStack *s,char*data);
Status popCStack(LinkDStack *s,char *data);
int isEmptyLCStack(LinkCStack *s);
Status getTopLCStack(LinkCStack *s,char*e);
int Precede(char a,char b);

int Precede(char a,char b)//a为符号栈栈顶元素,b为待插入的元素
{
      int i;//i=1入栈,i=0弹出操作符以及操作数进行计算
      if((a=='+'||a=='-')&&(b=='*'||b=='/')) i=1;
      if((a=='+'||a=='-')&&(b=='+'||b=='-')) i=0;
      if((a=='*'||a=='/')&&(b=='*'||b=='/')) i=0;
      if((a=='*'||a=='/')&&(b=='+'||b=='-')) i=0;
      if(a=='('||a==')') i=1;return i;
}

Status initDStack(LinkDStack *s)
{
    s->top = (LinkDStackPtr)malloc(sizeof(DStackNode));
    if(!s)return ERROR;
    s->top->next=NULL;
    s->count = 0;
    return SUCCESS;
}

Status pushDStack(LinkDStack *s,double data)
{
    LinkDStackPtr p=(LinkDStackPtr)malloc(sizeof(DStackNode));
    p->data=data;
    p->next=s;
    s->top->next=p;
    s->count++;
    return SUCCESS;
}


Status popDStack(LinkDStack *s,double *data)
{   if(isEmptyLDStack(s))return ERROR;
     LinkDStackPtr p;
    *data=s->top->data;
    p=s->top->next;
    free(s->top);
    s->top=p;
    s->count--;
    return SUCCESS;
}

int isEmptyLDStack(LinkDStack *s)
{ if(s->count == 0)return 1;//链表为空返回真值，否则返回假
  else return 0;
}

Status getTopLDStack(LinkDStack *s,double *e)
{
    if(isEmptyLDStack(s))return ERROR;
    *e=s->top->data;
    return SUCCESS;
}

Status initCStack(LinkCStack *s)
{
    s->top = (LinkCStackPtr)malloc(sizeof(CStackNode));
    if(!s)return ERROR;
    s->top->next=NULL;
    s->count = 0;
    return SUCCESS;
}

Status pushCStack(LinkCStack *s,char*data)
{
    LinkCStackPtr p=(LinkCStackPtr)malloc(sizeof(CStackNode));
    p->data=data;
    p->next=s;
    s->top->next=p;
    s->count++;
    return SUCCESS;
}


Status popCStack(LinkDStack *s,char *data)
{   if(isEmptyLCStack(s))return ERROR;
     LinkCStackPtr p;
    *data=s->top->data;
    p=s->top->next;
    free(s->top);
    s->top=p;
    s->count--;
    return SUCCESS;
}

int isEmptyLCStack(LinkCStack *s)
{ if(s->count == 0)return 1;//链表为空返回真值，否则返回假
  else return 0;
}

Status getTopLCStack(LinkCStack *s,char*e)
{
    if(isEmptyLCStack(s))return ERROR;
    e=s->top->data;
    return SUCCESS;
}
