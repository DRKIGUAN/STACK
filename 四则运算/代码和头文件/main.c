#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include"define.h"
#include"fiction.c"
int main()
{
   char str1[100];char str2[100];int a[50];
   printf("enter your calculated mode\n");
   gets(str1);
   int i=0,p=0,m=0,q=0;char*e,*out;
   LinkCStack n;
   LinkCStack*test=&n;
   Status initCStack(test);
   for(;str1[i]!='\0';i++,p++)
   {   if((str1[i]>='0'&&str1[i]<='9')||str1[i]=='.')str2[p]=str1[i];
       if(str1[i]=='-'&&(str1[i-1]!=')'||!(str1[i]>='0'&&str1[i]<='9'))){a[m++]=i++;continue;}
       else if(isdigit(str1[i])==0){
            if(str1[i]=='(') pushCStack(test,str1[i]);
            if(str1[i]==')')
            {
                if(!isEmptyLCStack(test))getTopLCStack(test,e);
                while(e!='(')
                {
                   popCStack(test,out);
                    str2[p]=out;
                    if(!isEmptyLCStack(test))getTopLCStack(test,e);
                    if(e=='(')popCStack(test,e);
                }
            }
            if(str1[i]=='+'||str1[i]=='-'||str1[i]=='/'||str1[i]=='*')
            {
                if(isEmptyLCStack(test))pushCStack(test,str1[i]);
                else{ getTopLCStack(test,e);
                    q=Precede(e,str1[i]);
                    if(q==1)pushCStack(test,str1[i]);
                    if(q==0)
                    {
                        while(!q)
                        {
                           popCStack(test,out);
                            str2[p++]=out;str2[p]=' ';
                            if(isEmptyLCStack(test)){getTopLCStack(test,e);q=Precede(e,str1[i]);}
                            else break;
                        }
                        pushCStack(test,str1[i]);
                    }
                }
            }
       }
     if(((str1[i]>='0'&&str1[i]<='9')||str1[i]=='.')!=((str1[i]>='0'&&str1[i]<='9')||str1[i+1]=='.'))str2[++p]=' ';
   }
    i=1;p=0;double co,sum;double flag=1;m=0;double c;double*record=&c;double before,after;
    LinkDStack k;
    LinkDStack*num=&k;
    initDStack(num);
    while(str2[p]!='\0')
    {   co=0;i=1;flag=1;
        if(isdigit(str2[p]))
        {   if(p==a[m]) flag=-1.0,m++;
            while(str2[p]!=' ')
            {if(str2[p++]=='.')
            {while(str2[p]!=' ')co=co+(str2[p++]-'\0')*pow(0.1,i);break;}
            else co=10.0*co+str2[p]-'\0',p++;
            }
            co=co*flag;
            pushDStack(num,co);
        }
        else if(str2[p]='+')popDStack(num,record),before=c,popDStack(num,record),after=c,sum=before+after, pushDStack(num,sum);
        else if(str2[p]='-')popDStack(num,record),before=c,popDStack(num,record),after=c,sum=before-after, pushDStack(num,sum);
        else if(str2[p]='*')popDStack(num,record),before=c,popDStack(num,record),after=c,sum=before*after, pushDStack(num,sum);
        else if(str2[p]='/')popDStack(num,record),before=c,popDStack(num,record),after=c,sum=before/after, pushDStack(num,sum);
        p++;
    }
    sum=num->top->data;
    printf("The result is %lf",sum);
    return 0;
}

