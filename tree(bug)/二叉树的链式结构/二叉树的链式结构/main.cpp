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

//��ǰ������������н���ֵ
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


//�ݹ飬 ����Լ�д�϶�д������
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

//ǰ��ݹ����
void PreOrderTraverse(BiTree T)
{
	if(T == NULL)
		return ;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//�������
void InOrderTraverse(BiTree T)
{
	if(T == NULL)
		return ;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}

//�������
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
	printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	element = Root(T);
	printf("�������ĸ�Ϊ: %c\n", element);

	printf("\nǰ�����������:");
	PreOrderTraverse(T);
	printf("\n�������������:");
	InOrderTraverse(T);
	printf("\n�������������:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n�����������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("���գ��޸�\n");
	system("pause");
	return 0;
}
