#include "SqStack.h"

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes);  //��ʼ��ջ

Status isEmptyStack(SqStack *s);   //�ж�ջ�Ƿ�Ϊ��

Status getTopStack(SqStack *s,ElemType *e);   //�õ�ջ��Ԫ��

Status clearStack(SqStack *s);   //���ջ

Status destroyStack(SqStack *s);  //����ջ

Status stackLength(SqStack *s,int *length);   //���ջ����

Status pushStack(SqStack *s,ElemType data);  //��ջ

Status popStack(SqStack *s,ElemType *data);   //��ջ


Status initStack(SqStack *s,int sizes)
{
    s->top= -1;
    s->size=sizes;
    s->elem=(int*)malloc(sizes*sizeof(int));
    return SUCCESS;
}

Status isEmptyStack(SqStack *s)
{
    if(s->top== -1) return SUCCESS;//��Ϊ��ջ������true
    else return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)
{
    if(isEmptyStack == SUCCESS)return ERROR; //��Ϊ��ջ����ô���ش���
    *e = s->elem[s->top];
    return SUCCESS;
}

Status clearStack(SqStack *s)
{
    if(isEmptyStack(s) == SUCCESS) return ERROR;
    s->top = -1; //��-1��ֵ��top�����ɽ�ջ���
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
    *length=s->top+1;//top��ʼʱ��ֵΪ-1����֪top+1����ջ�ĳ���
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
    *(s->elem)=data;//��Ҫ����ջ��ֵ����ջ��
    s->elem++;
    return SUCCESS;
}


Status popStack(SqStack *s,ElemType *data)
{   if(isEmptyStack(s) == SUCCESS) return ERROR;
    *data= *(s->elem);//��ջ����ֵ�����ⲿ����
    s->elem--;
    s->top--;
    return SUCCESS;
}







