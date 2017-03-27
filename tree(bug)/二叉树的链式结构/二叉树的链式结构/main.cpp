#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;

int index = 1;
typedef char String[24];
String str;

Status StrAssign(String T, char * chars)
{
	int i;
	if( strlen(chars) > MAXSIZE)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for(i = 1; i <= T[0]; i++)
		{
			T[i] = *(chars+i-1);
		}
	}
}

typedef char ElementType;
ElementType Nil = ' ';

Status visit(ElementType e)
{
	printf("%c", e);
	return OK;
}

typedef struct BiTNode
{
	ElementType data;
	struct BiTNode * lchild, * rchild;
}BiTNode, *BiTree;

Status InitBiTree(BiTree * T)
{
	*T = NULL;
	return OK;
}

void DestroyBiTree(BiTree *T)
{
	if(*T)
	{
		if((*T)->lchild)
			DestroyBiTree(&(*T)->lchild);
		if((*T)->rchild)
			DestroyBiTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}

//按前序输入二叉树中结点的值
void CreateBiTree( BiTree *T)
{
	ElementType ch;
	ch = str[index++];
	if(ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			return ;
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

Status BiTreeEmpty(BiTree T)
{
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree


//递归， 如果自己写肯定写不出来
int BiTreeDepth(BiTree T)
{
	int i, j;
	if(!T)
		return 0;
	if(T->lchild)
		i = BiTreeDepth(T->lchild);
	else i = 0;

	if(T->rchild)
		j = BiTreeDepth(T->rchild);
	else 
		j = 0;
	return i > j ? i+1 : j+1;
}

ElementType Root(BiTree T)
{
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

ElementType Value(BiTree p)
{
	return p->data;	
}

void Asssign(BiTree p, ElementType Value)
{
	p->data = Value;
}

//前序递归遍历
void PreOrderTraverse(BiTree T)
{
	if(T == NULL)
		return ;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//中序遍历
void InOrderTraverse(BiTree T)
{
	if(T == NULL)
		return ;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}

//后序遍历
void PostOrderTraverse(BiTree T)
{
	if(T == NULL)
		return ;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}


int main()
{
	int i;
	BiTree T;
	ElementType element;
	InitBiTree(&T);
	StrAssign(str, "ABDH#K###E##CFI###G#J##");
	CreateBiTree(&T);
	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	element = Root(T);
	printf("二叉树的根为: %c\n", element);

	printf("\n前序遍历二叉树:");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树:");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("树空，无根\n");
	system("pause");
	return 0;
}
