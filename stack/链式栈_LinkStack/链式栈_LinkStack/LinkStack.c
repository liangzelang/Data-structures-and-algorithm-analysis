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
	ElementType data;
	struct StackNode * next;
}StackNode , *LinkStackPtr;

typedef struct{
	LinkStackPtr top;
	int cout;
}LinkStack;

Status visit(ElementType c)
{
	printf("%d ", c);
	return OK;
}

Status InitStack(LinkStack * S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!S->top)
	{
		printf("Sorry Sir, No memory.\n");
		return ERROR;
	}
	S->top = NULL;
	S->cout = 0;
	return OK;
}

Status ClearStack(LinkStack * S)
{
	LinkStackPtr tmpCell;
	while(S->top)
	{
		tmpCell = S->top;
		S->top = S->top->next;		
		free(tmpCell);
	}
	S->cout = 0;
	return OK;
}	

Status StackEmpty(LinkStack S)
{
	//return S.count == 0 ? TRUE : FALSE;
	return S.top == NULL ? TRUE : FALSE;
}

Status GetTop(LinkStack S, ElementType * e)
{
	if(S.top == NULL)
	{
		printf("Sorry Sir, No Element. \n");
		return ERROR;
	}
	*e = S.top->data;
	return OK;
}

int StackLength(LinkStack S)
{
	return S.cout;
}

Status Push(LinkStack * S, ElementType e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S->top;
	S->top = p;
	S->cout++;
	return OK;
}

Status Pop(LinkStack * S, ElementType *e)
{
	LinkStackPtr tmpCell;
	if(S->top == NULL)
	{
		printf("Sorry Sir, No Element.\n");
		return ERROR;
	}
	*e = S->top->data;
	tmpCell = S->top;
	S->top = S->top->next;
	S->cout--;
	free(tmpCell);
	return OK;
}

Status StackTraverse(LinkStack S)
{
	LinkStackPtr p;
	p = S.top;
	while(p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main()
{
	int j;
        LinkStack s;
        int e;
        if(InitStack(&s)==OK)
                for(j=1;j<=10;j++)
                        Push(&s,j);
        printf("Õ»ÖÐÔªËØÒÀ´ÎÎª£º");
        StackTraverse(s);
        Pop(&s,&e);
        printf("µ¯³öµÄÕ»¶¥ÔªËØ e=%d\n",e);
        printf("Õ»¿Õ·ñ£º%d(1:¿Õ 0:·ñ)\n",StackEmpty(s));
        GetTop(s,&e);
        printf("Õ»¶¥ÔªËØ e=%d Õ»µÄ³¤¶ÈÎª%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("Çå¿ÕÕ»ºó£¬Õ»¿Õ·ñ£º%d(1:¿Õ 0:·ñ)\n",StackEmpty(s));
		system("pause");
        return 0;
}
