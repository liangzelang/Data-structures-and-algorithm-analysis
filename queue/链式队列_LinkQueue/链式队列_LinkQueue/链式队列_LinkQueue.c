#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int ElementType; /* QElemType类型根据实际情况而定，这里假设为int */

typedef struct{
	ElementType data;
	struct QueueNode *next;
}QueueNode, *QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
	int count;
}LinkQueue;

Status visit(ElementType C)
{
	printf("%d ", C);
	return OK;
}

Status InitQueue(LinkQueue * Q)
{
	Q->front = malloc(sizeof(QueueNode));
	Q->rear = malloc(sizeof(QueueNode));
	Q->front = NULL;
	Q->rear = NULL;
	Q->count = 0;
	return OK;
}

Status ClearQueue(LinkQueue * Q)
{
	QueuePtr tmpCell,p;
	if(Q->count == 0)
	{
		printf("Sorry Sir, No Element.\n");
		return ERROR;
	}
	while(Q->front)
	{
		tmpCell = Q->front;
		Q->front = Q->front->next;
		free(tmpCell);
	}
	Q->front = NULL;
	Q->rear = NULL;
	Q->count = 0;
	return OK;
}

Status QueueEmpty(LinkQueue  Q)
{
	return (Q.count == 0 ? TRUE : FALSE);
}

int QueueLength(LinkQueue Q)
{
	return Q.count;
}

Status GetHead(LinkQueue Q, ElementType * e)
{
	if(Q.front == NULL)
	{
		printf("Sorry Sir, No Element\n");
		return ERROR;
	}
	*e = Q.front->data;
	return OK;
}

Status EnQueue(LinkQueue * Q, ElementType e)
{
	QueuePtr tmpCell;
	tmpCell = malloc(sizeof(QueueNode));
	tmpCell->data = e;
	tmpCell->next = NULL;
	if(!Q->count)
	{
		Q->rear = tmpCell;
		Q->front = tmpCell;
	}		
	else
		Q->rear->next = tmpCell;
	Q->count++;
	return OK;
}

Status DeQueue(LinkQueue * Q, ElementType * e)
{
	QueueNode * tmpCell;
	if(Q->count == 0)
	{
		printf("Sorry Sir, No Element. \n");
		return ERROR;
	}
	*e = Q->front->data; 
	tmpCell = Q->front;
	Q->front = tmpCell->next;
	free(tmpCell);
	Q->count--;
	return OK;
}

Status QueueTraverse(LinkQueue Q)
{
	QueueNode * tmpCell;
	int k = Q.count;
	if(Q.count == 0)
	{
		printf("Sorry Sir, No Element. \n");
		return ERROR;
	}
	tmpCell = Q.front;
	while(--k)
	{
		visit(tmpCell->data);
		tmpCell = tmpCell->next;
	}
	return OK;
}


int main()
{
	int i;
	ElementType d;
	LinkQueue q;
	i=InitQueue(&q);
	if(i)
		printf("成功地构造了一个空队列!\n");
	printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
	printf("队列的长度为%d\n",QueueLength(q));
	EnQueue(&q,-5);
	EnQueue(&q,5);
	EnQueue(&q,10);
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n",QueueLength(q));
	printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
	printf("队列的元素依次为：");
	QueueTraverse(q);
	i=GetHead(q,&d);
	if(i==OK)
	 printf("队头元素是：%d\n",d);
	DeQueue(&q,&d);
	printf("删除了队头元素%d\n",d);
	i=GetHead(q,&d);
	if(i==OK)
		printf("新的队头元素是：%d\n",d);
	ClearQueue(&q);
	printf("清空队列后,q.front=%u q.rear=%u \n",q.front,q.rear);
	system("pause");
	return 0;
}