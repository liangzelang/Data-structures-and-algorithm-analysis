#include "single list.h"

struct Node{
	ElementType element;
	Position next;
};

//表头元素存储链表长度
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
	temp = L;                                      //位置临时变量
	if( pos > L->element)   //如果插入的位置大于链表长度，则返回
	{
		printf("Please choose right position.\n");
		return 0;
	}
	for( i = 0; i < pos; i++ )    //找到要插入位置前一个元素
	{
		temp = temp->next;
	}
	TmpCell = malloc(sizeof(struct Node));  //创建一个链表节点
	TmpCell->next = temp->next;    //把欲插入位置前元素的后继赋值给插入节点；
	temp->next = TmpCell;  //将插入节点赋值给前元素的后继
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