#include "single list.h"

struct Node{
	ElementType element;
	Position next;
};

//��ͷԪ�ش洢������
List CreatList()
{
	List L;
	L = malloc(sizeof(struct Node));
	L->element = 0;
	L->next = NULL;
	return L;
}
Status InsertElement(List L,int pos, ElementType element)
{
	Position temp,TmpCell;
	int i;
	temp = L;                                      //λ����ʱ����
	if( pos > L->element)   //��������λ�ô��������ȣ��򷵻�
	{
		printf("Please choose right position.\n");
		return 0;
	}
	for( i = 0; i < pos; i++ )    //�ҵ�Ҫ����λ��ǰһ��Ԫ��
	{
		temp = temp->next;
	}
	TmpCell = malloc(sizeof(struct Node));  //����һ������ڵ�
	TmpCell->next = temp->next;    //��������λ��ǰԪ�صĺ�̸�ֵ������ڵ㣻
	temp->next = TmpCell;  //������ڵ㸳ֵ��ǰԪ�صĺ��
	TmpCell->element = element;
	L->element += 1;
	return 1;
}

Status DeleteElement(List L, ElementType element)
{
	Position TmpCell;
	Position P;
	TmpCell = L;
	while( TmpCell->next != NULL && TmpCell->next->element != element)
	{
		TmpCell = TmpCell->next;
	}
	if(TmpCell->next == NULL)
	{
		printf("Do not find the element # %d ",element);
		return 0;
	}		
	else
	{
		P = TmpCell->next;
		TmpCell->next = P->next;
		free(P);
		L->element -=1;
	}
	return 1;
}
Position FindElement(List L, ElementType element)
{
	Position TmpCell;
	TmpCell = L->next;
	while( TmpCell != NULL && TmpCell->element != element)
	{
		TmpCell = TmpCell->next;
	}
	return TmpCell;
}
void DeleteList(List L)
{
	Position P,TmpCell;
	P = L->next;
	while( P != NULL )
	{
		TmpCell = P->next;
		free(P);
		P = TmpCell;
	}
	L->element = 0;
	L->next = NULL;
}
void ShowList(const List L)
{
	Position TmpCell;
	TmpCell = L->next;
	if(!TmpCell)
	{
		printf("Empty List.\n");
	}
	while( TmpCell != NULL)
	{
		printf( "%d ", TmpCell->element);
		TmpCell = TmpCell->next; 
	}	
}