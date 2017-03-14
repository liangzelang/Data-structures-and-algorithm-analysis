// 循环链表，采用单链表的形式，不要表头，只要表尾,
// 表尾指向表头， 如果只有一个元素，则指向自己
#include "circle list.h"

struct Node
{
	ElementType element;
	Position next;
};

List CreateList()
{
	List L;
	L = malloc(sizeof(struct Node));
	if(!L)
		printf("memory is out");
	L->next = NULL;
	L->element = 0;
	return L;
}
void DeleteList(List L)
{
	Position P,tmpCell;
	P = L->next;
	if(!P)
	{
		printf("It is an empty list.\n");
		return ;
	}
	while(P)
	{
		tmpCell = P;
		P = P->next;
		free(tmpCell);
	}
}
Position FindElement(List L, ElementType element)
{
	Position P;
	int flag = 0;
	P = L->next;
	if(!P)
	{
		printf("It is an empty lis.\n");
		return NULL;
	}
	while(P->element != element && flag <= 1)
	{
		P = P->next;
		if(P == L->next)
			flag++;
	}
	return P;
}
void PrintList(List L)
{
	Position P, tmpCell;
	P = L->next;
	if(!P)
	{
		printf("It is an empty list . \n");
		return ;
	}
	printf("%d ",P->element);
	if (P == P->next)
	{
		return ;
	}
	P = P->next;  //到头
	while(P != L->next)
	{
		printf("%d ", P->element);
		P = P->next;
	}
}
void InsertElement(ElementType element, int p, List L)
{
	Position tmpCell,P;
	int i=0;
	P = L->next;	
	tmpCell = malloc(sizeof(struct Node));
	tmpCell->element = element;
	if(!P)
	{
		tmpCell->next=tmpCell;
		L->next = tmpCell;
		return;
	}
	for(i=1; i < p; i++)
	{
		P = P->next;
	}	
	tmpCell->next = P->next;
	P->next = tmpCell;
}
void DeleteElement(ElementType element, List L)
{
	Position P,tmpCell;
	P = L->next;
	if(!P)
	{
		printf("It is an empty list.\n");
		return;
	}
	P = FindElement( L, element);
	tmpCell = P;
	P = P->next;
	free(tmpCell);
}