/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100
typedef int Status;
typedef char ElementType;
typedef enum{Link, Thread} PointerTag;
//Link == 0 ��ʾ���Һ���ָ�� Thread == 1 ��ʾָ��ǰ���� ������
typedef struct BiThrNode
{
	ElementType data;
	struct BiThrNode * lchild, * rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode , *BiThrTree;

ElementType Nil = '#';

Status visit(ElementType e)
{
	printf("%c", e);
	return OK;
}

Status CreateBiThrTree(BiThrTree *T)
{
	ElementType h;
	scanf("%c", &h);

	if(h == Nil)
		*T = NULL;
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if(!*T)
			return ERROR;
		(*T)->data = h;
		CreateBiThrTree(&(*T)->lchild);
		if((*T)->lchild)
			(*T)->LTag = Link;
		CreateBiThrTree(&(*T)->rchild);
		if((*T)->rchild)
			(*T)->RTag = Link;
	}
	return OK;
}

BiThrTree pre;  //ȫ�ֱ����� ʼ��ָ��ոշ��ʹ��Ľڵ�

void InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild);
		if(!p->lchild)
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if(!p->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}

//��������㷨��Щ���裬�����ϵ�ɡ���
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	*Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)
		return ERROR;
	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = (*Thrt);

	if(!T)
		(*Thrt)->lchild =*Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		InThreading(T);
		pre->rchild = *Thrt;
		pre->RTag = Thread;
		(*Thrt)->rchild = pre;
	}
	return OK;
}

//�˴�TΪͷ�ڵ�
//�����������������  �ǵݹ��㷨
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;
	while(p != T)
	{
		while( p->LTag == Link)
			p = p->lchild;
		if(!visit(p->data))
			return ERROR;
		while(p->RTag==Thread && p->rchild != T)
		{
			p = p->rchild;
			visit(p->data);
		}
		p = p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree H, T;
	printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");
 	CreateBiThrTree(&T);  //��ǰ����������� 
	InOrderThreading(&H,T); // �������,������������������ 
	printf("�������(���)����������:\n");
	InOrderTraverse_Thr(H);//�������(���)���������� 
	printf("\n");
	system("pause");
	return 0;
}*/


#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0��ʾָ�����Һ���ָ��, */
										/* Thread==1��ʾָ��ǰ�����̵����� */
typedef  struct BiThrNode	/* ���������洢���ṹ */
{
	TElemType data;	/* ������� */
	struct BiThrNode *lchild, *rchild;	/* ���Һ���ָ�� */
	PointerTag LTag;
	PointerTag RTag;		/* ���ұ�־ */
} BiThrNode, *BiThrTree;

TElemType Nil='#'; /* �ַ����Կո��Ϊ�� */

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

/* ��ǰ����������������н���ֵ,�������������T */
/* 0(����)/�ո�(�ַ���)��ʾ�ս�� */
Status CreateBiThrTree(BiThrTree *T)   //�����һ����ѽ
{ 
	TElemType h;
	scanf("%c",&h);

	if(h==Nil)
		*T=NULL;
	else
	{
		*T=(BiThrTree)malloc(sizeof(BiThrNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=h; /* ���ɸ����(ǰ��) */
		CreateBiThrTree(&(*T)->lchild); /* �ݹ鹹�������� */
		if((*T)->lchild) /* ������ */
			(*T)->LTag=Link;
		CreateBiThrTree(&(*T)->rchild); /* �ݹ鹹�������� */
		if((*T)->rchild) /* ���Һ��� */
			(*T)->RTag=Link;
	}
	return OK;
}

BiThrTree pre; /* ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ�� */
/* ��������������������� */
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* �ݹ������������� */
		if(!p->lchild) /* û������ */
		{
			p->LTag=Thread; /* ǰ������ */
			p->lchild=pre; /* ����ָ��ָ��ǰ�� */
		}
		if(!pre->rchild) /* ǰ��û���Һ��� */
		{
			pre->RTag=Thread; /* ������� */
			pre->rchild=p; /* ǰ���Һ���ָ��ָ����(��ǰ���p) */
		}
		pre=p; /* ����preָ��p��ǰ�� */
		InThreading(p->rchild); /* �ݹ������������� */
	}
}

/* �������������T,����������������,Thrtָ��ͷ��� */
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{ 
	*Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)
		exit(OVERFLOW);
	(*Thrt)->LTag=Link; /* ��ͷ��� */
	(*Thrt)->RTag=Thread;
	(*Thrt)->rchild=(*Thrt); /* ��ָ���ָ */
	if(!T) /* ����������,����ָ���ָ */
		(*Thrt)->lchild=*Thrt;
	else
	{
		(*Thrt)->lchild=T;
		pre=(*Thrt);
		InThreading(T); /* ��������������������� */
		pre->rchild=*Thrt;
		pre->RTag=Thread; /* ���һ����������� */
		(*Thrt)->rchild=pre;
	}
	return OK;
}

/* �����������������T(ͷ���)�ķǵݹ��㷨 */
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; /* pָ������ */
	while(p!=T)
	{ /* �������������ʱ,p==T */
		while(p->LTag==Link)
			p=p->lchild;
		if(!visit(p->data)) /* ������������Ϊ�յĽ�� */
			return ERROR;
		while(p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;
			visit(p->data); /* ���ʺ�̽�� */
		}
		p=p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree H,T;
	printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");
 	CreateBiThrTree(&T); /* ��ǰ����������� */
	InOrderThreading(&H,T); /* �������,������������������ */
	printf("�������(���)����������:\n");
	InOrderTraverse_Thr(H); /* �������(���)���������� */
	printf("\n");
	
	return 0;
}


