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
	int top;
}SqStack;

Status visit(ElementType c)
{
	printf("%d", c);
	return OK;
}

//��ʼ��˳��ջ
Status InitStack(SqStack * S)
{
	S->top = -1;
	return OK;
}
//���˳��ջ
Status ClearStack(SqStack * S)
{
	S->top = -1;
	return OK;
}
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack * S)
{
	//return S->top == -1 ? TRUE : FALSE;
	if(S->top == -1)
		return TRUE;
	else
		return FALSE;
}

Status DestroyStack(SqStack * S)
{
	free(S);
	return OK;
}

int StackLength(SqStack S)
{
	return S.top+1;
}

Status GetTop(SqStack S, ElementType * e)
{
	if(S.top == -1)
	{
		printf("Empty Stack. \n");
		return ERROR;
	}
	*e = S.data[S.top];
	return OK;
}

Status Push(SqStack *S, ElementType e)
{
	if(S == NULL)
	{
		printf("No Stack.\n");
		return ERROR;
	}
	if(S->top == MAXSIZE -1 )
	{
		printf("Stack is FULL");
		return ERROR;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}

Status Pop(SqStack * S, ElementType * e)
{
	if(S->top == -1)
	{
		printf("Sorry Sir, No Element.\n");
		return ERROR;
	}
	*e = S->data[S->top];
	S->top--;
	return OK;
}

Status StackTraverse(SqStack S)
{
	int i ;
	i = 0;
	while(i <= S.top)
	{
		visit(S.data[i]);
		i++;
	}
	printf("\n");
	return OK;
}

int main()
{
	SqStack S;
	int j; 
	int e; //Ԫ�ر���
	if(InitStack(&S) == OK)
	{
		for(j = 0 ; j < 10; j++)
			Push(&S, j);
	}

	printf("ջ��Ԫ��Ϊ�� ");
	StackTraverse(S);
	Pop(&S, &e);
	printf("������ջ��Ԫ�� e = %d \n", e);
	printf("ջ�Ƿ�Ϊ�գ� %d (1: �� 0������)\n", StackEmpty(&S));
	GetTop(S, &e);
	printf("ջ��Ԫ��Ϊ  e = %d, ջ�����Ϊ %d  \n", e, StackLength(S));
	ClearStack(&S);
	printf("���ջż�� ջ�Ƿ�Ϊ�գ� %d\n", StackEmpty(&S));
	system("pause");
	return 0;
}