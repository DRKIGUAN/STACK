#include <stdio.h>
#include "SqStack.c"
#include "SqStack.h"
int main()
{   SqStack p;
    SqStack*test=&p;//创建一个栈类型的变量test
    Status respond;//变量respond用于检测各函数是否执行成功
    int sizes,flag = 1;int point,record;int*e= &record;//point用来确认用户需要进行什么操作,record用来记录对栈顶进行操作时的值
    printf("Please enter the size of your stack\n");
    scanf("%d",&sizes);
    respond=initStack(test,sizes);
    if(respond == SUCCESS)printf("You have created a stack successfully\n");
    else {printf("ERROR");return 0;}
    printf("What do you want to do?\n");
    printf("If you want to check whether your stack is empty, enter 1\n");
    printf("If you want to get the top of the stack, enter 2\n");
    printf("If you want to destroy your stack, enter 3\n");
    printf("If you want to clear your stack, enter 4\n");
    printf("If you want to push a number into the stack, enter 5\n");
    printf("If you want to pop the top, enter 6\n");
    printf("IF you want to know the length of your stack, enter 7\n");
    printf("If you want to stop the operation, enter 8\n");
    while(flag)
    {   scanf("%d",&point);
        switch(point){
        case 1:{respond = isEmptyStack(test);
                if(respond == SUCCESS) printf("Your stack is empty\n");
                else printf("Your stack isn't empty\n");
                };break;
        case 2:{ respond = getTopStack(test,e);
                 if(respond == SUCCESS)printf("The number on the top is %d\n",*e);
                 else printf("The stack is empty\n");
                  };break;
        case 3:{ respond = destroyStack(test);
                 if(respond == SUCCESS) printf("Your stack has been destroyed\n");
                 else printf("ERROR\n");
               };break;
        case 4:{ respond = clearStack(test);
                 if(respond == SUCCESS) printf("Your stack has been cleared\n");
                 else printf("ERROR\n");
               };break;
        case 5:{  printf("enter the number you want to push into the stack\n");
                  scanf("%d",&record);
                  respond = pushStack(test,record);
                  if(respond == SUCCESS)printf("SUCCESS!\n");
                  else printf("ERROR\n");
               };break;
        case 6:{ respond = popStack(test,e);
                 if(respond == SUCCESS)printf("SUCCESS!The number on the top is %d\n",*e);
                  else printf("ERROR\n");
               };break;
        case 7:{respond = stackLength(test,e);
                printf("The length of the stack is %d\n",*e);};
                break;
        case 8:flag = 0;break;
        default:printf("Your order is WRONG!\n");break;
        }
    }
    return 0;
}
