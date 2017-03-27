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
	int level, order;  //满二叉树
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
	printf("请按层序输入节点的值（int类型）， 0表示空节点，输入999结束。节点数<=%d", MAX_TREE_SIZE);
	while( i < 10)
	{
		T[i] = i + 1;
		if(i!=0 && T[(i+1)/2-1]==Nil && T[i] != Nil)  //这种情况在满二叉树中怎么会出现呢
		{
			printf("出现无双亲的非根节点%d\n", T[i]);
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
	i +=1; //因为i为下标，实际的个数为T[i] = i+1
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
	if(value != Nil && T[(i+1)/2-1] == Nil) //如果值不为零，而且双亲节点为空
		return ERROR;
	else if(value == Nil && (T[(i*2+1)] != Nil || T[i*2+2] != Nil))
		return ERROR;   //如果要把双亲节点置零，但是其子节点不为空
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

//返回右兄弟
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
//先序遍历
Status PreOrderTraverse(SqBiTree T)
{
	if(!BiTreeEmpty(T))
		PreTraverse(T, 0);
	printf("\n");
	return OK;
}
//中序遍历
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

//后序遍历
void PostTraverse(SqBiTree T, int e)
{
	if(T[2*e+1]!=Nil) /* 左子树不空 */
		PostTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* 右子树不空 */
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

//层序遍历二叉树
void LevelOrderTraverse(SqBiTree T)
{
	int i=MAX_TREE_SIZE-1,j;
	while(T[i]==Nil)
		i--; /* 找到最后一个非空结点的序号 */
	for(j=0;j<=i;j++)  /* 从根结点起,按层序遍历二叉树 */
		if(T[j]!=Nil)
			visit(T[j]); /* 只遍历非空的结点 */
	printf("\n");
}


/* 逐层、按本层序号输出二叉树 */
void Print(SqBiTree T)
{ 
	int j,k;
	Position p;
	ElementType e;
	for(j=1;j<=BiTreeDepth(T);j++)
	{
		printf("第%d层: ",j);
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
	printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("二叉树的根为：%d\n",e);
	else
		printf("树空，无根\n");
	printf("层序遍历二叉树:\n");
	LevelOrderTraverse(T);
	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T);
	printf("中序遍历二叉树:\n");
	InOrderTraverse(T);
	printf("后序遍历二叉树:\n");
	PostOrderTraverse(T);
	printf("修改结点的层号3本层序号2。");
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("待修改结点的原值为%d请输入新值:50 ",e);
	e=50;
	Assign(T,p,e);
	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T);
	printf("结点%d的双亲为%d,左右孩子分别为",e,Parent(T,e));
	printf("%d,%d,左右兄弟分别为",LeftChild(T,e),RightChild(T,e));
	printf("%d,%d\n",LeftSibling(T,e),RightSibling(T,e));
	ClearBiTree(T);
	printf("清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("二叉树的根为：%d\n",e);
	else
		printf("树空，无根\n");
	system("pause");
	return 0;
}