#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status; 
typedef int ElementType; /* QElemType���͸���ʵ������������������Ϊint */

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
		printf("�ɹ��ع�����һ���ն���!\n");
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n",QueueLength(q));
	EnQueue(&q,-5);
	EnQueue(&q,5);
	EnQueue(&q,10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n",QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
	printf("���е�Ԫ������Ϊ��");
	QueueTraverse(q);
	i=GetHead(q,&d);
	if(i==OK)
	 printf("��ͷԪ���ǣ�%d\n",d);
	DeQueue(&q,&d);
	printf("ɾ���˶�ͷԪ��%d\n",d);
	i=GetHead(q,&d);
	if(i==OK)
		printf("�µĶ�ͷԪ���ǣ�%d\n",d);
	ClearQueue(&q);
	printf("��ն��к�,q.front=%u q.rear=%u \n",q.front,q.rear);
	system("pause");
	return 0;
}