#include <stdio.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100
#define MAX_TREE_SIZE 100

typedef int Status;
typedef int ElementType;
typedef ElementType SqBiTree[MAX_TREE_SIZE];

typedef struct
{
	int level, order;  //��������
}Position;

ElementType Nil = 0;

Status visit(ElementType c)
{
	printf("%d", c);
	return OK;
}

Status InitBiTree(SqBiTree T)
{
	int i;
	for(i = 0; i < MAX_TREE_SIZE; i++)
	{
		T[i] = Nil;
	}
	return OK;
}

Status createBiTree(SqBiTree T)
{
	int i = 0;
	printf("�밴��������ڵ��ֵ��int���ͣ��� 0��ʾ�սڵ㣬����999�������ڵ���<=%d", MAX_TREE_SIZE);
	while( i < 10)
	{
		T[i] = i + 1;
		if(i!=0 && T[(i+1)/2-1]==Nil && T[i] != Nil)  //���������������������ô�������
		{
			printf("������˫�׵ķǸ��ڵ�%d\n", T[i]);
			return 0;
		}
		i++;
	}
	while( i < MAX_TREE_SIZE)
	{
		T[i] = Nil;
		i++;
	}
	return OK;
}

#define ClearBiTree InitBiTree

Status BiTreeEmpty(SqBiTree T)
{  
	if(T[0] == Nil)
		return TRUE;
	else
		return FALSE;
}

int BiTreeDepth(SqBiTree T)
{
	int i, j = -1;
	for(i = MAX_TREE_SIZE; i >= 0; i++)
	{
		if(T[i] != Nil)
			break;
	}
	i +=1; //��ΪiΪ�±꣬ʵ�ʵĸ���ΪT[i] = i+1
	do
	{
		j++;
	}while(i >= powl(2, j));
	return j;
}

Status Root(SqBiTree T, ElementType * e)
{
	if(BiTreeEmpty(T) == TRUE)
	{
		printf("Sorry Sir, Empty Tree.\n");
		return ERROR;
	}
	else
		*e = T[0];
	return OK;
}

ElementType Value(SqBiTree T, Position e)
{
	return T[(int)powl(2, e.level-1)+e.order-2];
}

Status Assign(SqBiTree T, Position e, ElementType value)
{
	int i = (int)powl(2, e.level-1)+e.order-2;
	if(value != Nil && T[(i+1)/2-1] == Nil) //���ֵ��Ϊ�㣬����˫�׽ڵ�Ϊ��
		return ERROR;
	else if(value == Nil && (T[(i*2+1)] != Nil || T[i*2+2] != Nil))
		return ERROR;   //���Ҫ��˫�׽ڵ����㣬�������ӽڵ㲻Ϊ��
	T[i] = value;
	return OK;
}

ElementType Parent(SqBiTree T, ElementType e)
{
	int i;
	if(T[0] == Nil)
		return ERROR;
	for(i = 1; i <= MAX_TREE_SIZE-1; i++)
	{
		if(T[i] == e)
			return T[(i+1)/2-1];
	}
	return Nil;
}

ElementType LeftChild(SqBiTree T, ElementType e)
{
	int i;
	if(T[0] == Nil)
	{
		return ERROR;
	}
	for(i = 0; i <= MAX_TREE_SIZE-1; i++)
	{
		if(T[i] == e)
			return T[i*2+1];
	}
	return ERROR;
}

ElementType RightChild(SqBiTree T, ElementType e)
{
	int i;
	if(T[0] == Nil)
		return ERROR;
	for(i = 0; i < MAX_TREE_SIZE; i++)
	{
		if(T[i] == e)
			return T[i*2+2];
	}
	return Nil;
}

ElementType LeftSibling(SqBiTree T, ElementType e)
{
	int i;
	if(T[0] == Nil)
		return ERROR;
	for(i = 0; i <= MAX_TREE_SIZE; i++)
	{
		if(T[i] == e && i%2 == 0)
			return T[i-1];
	}
	return ERROR;
}

//�������ֵ�
ElementType RightSibling(SqBiTree T, ElementType e)
{
	int i;
	if(T[0] == Nil)
		return ERROR;
	for(i = 1; i <= MAX_TREE_SIZE-1; i++)
	{
		if(T[i] == e && i%2 != 0)
			return T[i+1];
	}
	return ERROR;
}

//
void PreTraverse(SqBiTree T, int e)
{
	visit(T[e]);
	if(T[2*e+1] != Nil)
		PreTraverse(T, 2*e+1);
	if(T[2*e+1] != Nil)
		PreTraverse(T, 2*e+2);
}
//�������
Status PreOrderTraverse(SqBiTree T)
{
	if(!BiTreeEmpty(T))
		PreTraverse(T, 0);
	printf("\n");
	return OK;
}
//�������
void InTraverse(SqBiTree T, int e)
{
	if(T[2*e+1]!=Nil)
		InTraverse(T, 2*e+1);
	visit(T[e]);
	if(T[2*e+2] != Nil)
	{
		InTraverse(T, 2*e+2);
	}
}

Status InOrderTraverse(SqBiTree T)
{
	if(!BiTreeEmpty(T))
		InTraverse(T, 0);
	printf("\n");
	return OK;
}

//�������
void PostTraverse(SqBiTree T, int e)
{
	if(T[2*e+1]!=Nil) /* ���������� */
		PostTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* ���������� */
		PostTraverse(T,2*e+2);
	visit(T[e]);
}

Status PostOrderTraverse(SqBiTree T)
{
	if(!BiTreeEmpty(T))
		PostTraverse(T, 0);
	printf("\n");
	return OK;
}

//�������������
void LevelOrderTraverse(SqBiTree T)
{
	int i=MAX_TREE_SIZE-1,j;
	while(T[i]==Nil)
		i--; /* �ҵ����һ���ǿս������ */
	for(j=0;j<=i;j++)  /* �Ӹ������,��������������� */
		if(T[j]!=Nil)
			visit(T[j]); /* ֻ�����ǿյĽ�� */
	printf("\n");
}


/* ��㡢������������������ */
void Print(SqBiTree T)
{ 
	int j,k;
	Position p;
	ElementType e;
	for(j=1;j<=BiTreeDepth(T);j++)
	{
		printf("��%d��: ",j);
		for(k=1;k<=powl(2,j-1);k++)
		{
			p.level=j;
			p.order=k;
			e=Value(T,p);
			if(e!=Nil)
				printf("%d:%d ",k,e);
		}
		printf("\n");
	}
}


int main()
{
	Status i;
	Position p;
	ElementType e;
	SqBiTree T;
	InitBiTree(T);
	createBiTree(T);
	printf("������������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("�������ĸ�Ϊ��%d\n",e);
	else
		printf("���գ��޸�\n");
	printf("�������������:\n");
	LevelOrderTraverse(T);
	printf("ǰ�����������:\n");
	PreOrderTraverse(T);
	printf("�������������:\n");
	InOrderTraverse(T);
	printf("�������������:\n");
	PostOrderTraverse(T);
	printf("�޸Ľ��Ĳ��3�������2��");
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("���޸Ľ���ԭֵΪ%d��������ֵ:50 ",e);
	e=50;
	Assign(T,p,e);
	printf("ǰ�����������:\n");
	PreOrderTraverse(T);
	printf("���%d��˫��Ϊ%d,���Һ��ӷֱ�Ϊ",e,Parent(T,e));
	printf("%d,%d,�����ֱֵܷ�Ϊ",LeftChild(T,e),RightChild(T,e));
	printf("%d,%d\n",LeftSibling(T,e),RightSibling(T,e));
	ClearBiTree(T);
	printf("�����������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("�������ĸ�Ϊ��%d\n",e);
	else
		printf("���գ��޸�\n");
	system("pause");
	return 0;
}