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
	ElementType data[MAXSIZE];
	int front;
	int rear;
}Queue;

Status visit(ElementType C)
{
	printf("%d ", C);
	return OK;
}

Status InitQueue(Queue * Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

Status ClearQueue(Queue * Q)
{
	Q->front = Q->rear = 0;
	return OK;
}

Status QueueEmpty(Queue  Q)
{
	if(Q.front = Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(Queue Q)
{
	return (Q.rear - Q.front + MAXSIZE ) % MAXSIZE;
}

Status GetHead(Queue Q, ElementType * e)
{
	if(Q.front == Q.rear)   // BUG, we cannot determine whether is empty or not
		return ERROR;
	else
		*e = Q.data[Q.front];
	return OK;
}

Status EnQueue(Queue * Q, ElementType e)
{
	if((Q->rear+1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;  //Ϊ������ѭ��������һ��trick
	return OK;
}

Status DeQueue(Queue * Q, ElementType * e)
{
	if(Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1 ) % MAXSIZE;
	return OK;
}

Status QueueTraverse(Queue Q)
{
	int i;
	i = 0;
	while((Q.front + i)%MAXSIZE != Q.rear)
	{
		visit(Q.data[(Q.front + i)%MAXSIZE]);
		i++;
	}
	printf("\n");
	return OK;
}

int main()
{
	Status j;
	int i=0;
	int l;
	ElementType d;
	Queue Q;
	InitQueue(&Q);
	printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
	
	do
	{
		/* scanf("%d",&d); */
		d=i;		
		i++;
		EnQueue(&Q,d);
	}while(i<MAXSIZE-1);
	printf("���ڶ����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	printf("���г���Ϊ: %d\n",QueueLength(Q));
	printf("���ڶ��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));


	printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n",MAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("ɾ����Ԫ����%d,�����Ԫ��:%d \n",d,l+100);
		/* scanf("%d",&d); */
		d=l+100;
		EnQueue(&Q,d);
	}
	l=QueueLength(Q);

	printf("���ڶ����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("ɾ����Ԫ��ֵΪ%d\n",d);
	}

	j=GetHead(Q,&d);
	if(j)
		printf("���ڶ�ͷԪ��Ϊ: %d\n",d);
	ClearQueue(&Q);
	printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
	system("pause");
	return 0;
}