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
	Q->rear = (Q->rear + 1) % MAXSIZE;  //为了数组循环，这是一个trick
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
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
	
	do
	{
		/* scanf("%d",&d); */
		d=i;		
		i++;
		EnQueue(&Q,d);
	}while(i<MAXSIZE-1);
	printf("现在队列中的元素为: \n");
	QueueTraverse(Q);
	printf("队列长度为: %d\n",QueueLength(Q));
	printf("现在队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));


	printf("连续%d次由队头删除元素,队尾插入元素:\n",MAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("删除的元素是%d,插入的元素:%d \n",d,l+100);
		/* scanf("%d",&d); */
		d=l+100;
		EnQueue(&Q,d);
	}
	l=QueueLength(Q);

	printf("现在队列中的元素为: \n");
	QueueTraverse(Q);
	
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("删除的元素值为%d\n",d);
	}

	j=GetHead(Q,&d);
	if(j)
		printf("现在队头元素为: %d\n",d);
	ClearQueue(&Q);
	printf("清空队列后, 队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
	system("pause");
	return 0;
}