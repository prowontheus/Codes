/*将栈S中的元素逆置，使用额外的一个栈L和非数组变量*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
}Sqstack;


//顺序栈的初始化
Status InitSqstack(Sqstack * S)
{
    S->top=-1;
    return OK;
}

//顺序栈的建立
Status Create(Sqstack * S,int n)
{
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        S->data[++S->top]=rand()%100+1;
    }
    return OK;
}

//顺序栈的出栈
Status Pop(Sqstack * S,ElemType * e)
{
    *e=S->data[S->top--];
    return OK;
}


//顺序栈的入栈
Status Push(Sqstack * S,ElemType e)
{
    S->data[++S->top]=e;
    return OK;
}


//顺序栈输出
void Print(Sqstack * S)
{
    printf("输出元素：\n");
    for(int i=S->top;i>=0;i--)
    {
        printf("%d ",S->data[i]);
    }
    printf("\n");
}


//利用非数组变量逆置栈S里的元素
Status Invers(Sqstack * S,Sqstack *L,int n)
{
    ElemType DeElem,temp;
    for(int k=0;k<n-1;k++)
    {
        temp=S->data[S->top--];
        for(int i=n-k-2;i>=0;i--)
        {
            Pop(S,&DeElem);
            Push(L,DeElem);
        }
        Push(S,temp);
        for(int j=n-k-2;j>=0;j--)
        {
            Pop(L,&DeElem);
            Push(S,DeElem);
        }
    }
    return OK;
}

int main()
{
    int ElemNumber;
    Sqstack S,L;
    InitSqstack(&L);
    InitSqstack(&S);
    printf("请输入元素个数：\n");
    scanf("%d",&ElemNumber);
    Create(&S,ElemNumber);
    Print(&S);
    Invers(&S,&L,ElemNumber);
    printf("逆置后：\n");
    Print(&S);
    return OK;
}
