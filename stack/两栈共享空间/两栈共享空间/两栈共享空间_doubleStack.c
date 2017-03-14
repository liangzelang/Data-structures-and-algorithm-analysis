#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElementType;

typedef struct{
	ElementType data[MAXSIZE];
	int top1;
	int top2;
}DoubleStack;

Status visit(ElementType c)
{
	printf("%d ", c);
	return OK;
}

//初始化顺序栈
Status InitStack(DoubleStack * S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}
//清空顺序栈
Status ClearStack(DoubleStack * S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

//判断栈是否为空
Status StackEmpty(DoubleStack S)
{
	if(S.top1 == -1 && S.top2 == MAXSIZE)
		return TRUE;
	else
		return FALSE;
}

Status DestroyStack(DoubleStack * S)
{
	free(S);
	return OK;
}

int StackLength(DoubleStack S)
{
	return MAXSIZE-(S.top2 - S.top1-1);
}

Status GetTop(DoubleStack S, ElementType * e, int StackNumber)
{
	if(StackNumber == 1)
	{
		if(S.top1 == -1)
		{
			printf("Sorry Sir, empty stack.\n");
			return ERROR;
		}
		else
			*e = S.data[S.top1];
	}
	else
	{
		if(S.top2 == MAXSIZE)
		{
			printf("Sorry Sir, empty stack.\n");
			return ERROR;
		}
		else 
			*e = S.data[S.top2];
	}
	return OK;
}

Status Push(DoubleStack *S, ElementType e, int StackNumber)
{
	if(S->top1 + 1 == S->top2)
	{
		printf("Sorry Sir, Stack is out of memory.\n");
		return ERROR;
	}
	if(StackNumber ==1)
	{
		S->data[++S->top1] = e;
	}
	else
	{
		S->data[--S->top2] = e;
	}
	return OK;
}

Status Pop(DoubleStack * S, ElementType * e,int StackNumber)
{
	if(StackNumber == 1)
	{
		if(S->top1 == -1)
		{
			printf("Sorry Sir, No Element.\n");
			return ERROR;
		}
		*e = S->data[S->top1--];
	}
	else if(StackNumber == 2)
	{
		if(S->top2 == MAXSIZE)
		{
			printf("Sorry Sir, No Element.\n");
			return ERROR;
		}
		*e = S->data[S->top2++];
	}
	return OK;
}

Status StackTraverse(DoubleStack S)
{
	
	int i = 0;
	while(i <= S.top1)
	{
		visit(S.data[i++]);
	}
	i = S.top2;
	while(i <= MAXSIZE-1)
	{
		visit(S.data[i++]);
	}
	printf("\n");
	return OK;
}

int main()
{
        int j;
        DoubleStack s;
        int e;
        if(InitStack(&s)==OK)
        {
                for(j=1;j<=5;j++)
                        Push(&s,j,1);
                for(j=MAXSIZE;j>=MAXSIZE-2;j--)
                        Push(&s,j,2);
        }

        printf("栈中元素依次为：");
        StackTraverse(s);
        printf("当前栈中元素有：%d \n",StackLength(s));

        Pop(&s,&e,2);
        printf("弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));

        for(j=6;j<=MAXSIZE-2;j++)
                Push(&s,j,1);

        printf("栈中元素依次为：");
        StackTraverse(s);

        printf("栈满否：%d(1:否 0:满)\n",Push(&s,100,1));

        
        ClearStack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        system("pause");
        return 0;
}