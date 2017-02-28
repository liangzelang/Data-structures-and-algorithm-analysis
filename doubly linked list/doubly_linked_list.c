#include "doubly_linked_list.h"


struct Node
{
	ElementType Element;
	Position Next;
	Position Front;
};



List MakeEmpty(List L)
{
	if( L!= NULL)
		DeleteList(L);
	L = malloc(sizeof(struct Node));
	if( L == NULL)
		printf("Out of Memory!\n");
	L->Next = NULL;
	L->Element = 0;
	L->Front = NULL;
	return L;
}

int IsEmpty( List L)
{
	return L->Next == NULL;
}

int IsLast( Position P, List L)
{
	return P->Next == NULL;
}

int IsHead( Position P, List L)
{
	return P->Front == NULL;
}
Position Find( ElementType X, List L)
{
	Position P;
	if( L->Next == NULL )
		printf("Empty List.\n");
	P = L->Next;
	while( P == NULL && P->Element != X )
	{
		P = P->Next;
	}
	return P;
}

Position Get_Last( List L)
{
	Position P;
	P = L->Next;
	while( P->Next != NULL)
		P = P->Next;
	return P;
}

//双链表需要加一个从后面搜索的函数
Position Find_From_Back( ElementType X, List L)
{
	Position Last;
	if( L->Next == NULL )
	{
		printf("Empty List.\n");
		return 0;
	}		
	Last = Get_Last(L);  //自己写的时候，有可能是NULL
	while( Last != NULL && Last->Element != X )
		Last = Last->Front;
	return Last;
}

Position FindPrevious( ElementType X, List L)
{
	//return Find(X,L)->Front;  //这将导致产生NULL的情况
	Position P;
	P = L;
	while( P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
	//这个函数现在有一个BUG， 就是漏掉第一个元素就是X的情况:原因是我应该把P=L，NOT，L->Next
}

//双链表新增搜索元素前一个位置
Position FindPrevious_Back( ElementType X, List L)
{
	Position Last;
	if( L->Next == NULL )
	{
		printf("Empty List.\n");
		return 0;
	}		
	Last = Get_Last(L);  //自己写的时候，有可能是NULL
	while( Last != NULL && Last->Element != X )
		Last = Last->Front;
	return Last;
}

void Delete( ElementType X, List L)
{
	Position P,TmpCell;
	P = FindPrevious(X,L);   //这里有一个问题，列表为 0012345678  ，找到的P为NULL ，原因是使用了Front
	if(!IsLast( P,L ))
	{
		TmpCell = P->Next;
		TmpCell->Next->Front = TmpCell->Front;
		P->Next = TmpCell->Next;
		free( TmpCell);
	}
}
void Insert( ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Out of Memory!\n");
	if( P == L)
	{
		TmpCell->Element = X;
		TmpCell->Front = NULL;
		TmpCell->Next = P->Next;
		P->Next = TmpCell;
	}
	else
	{
		TmpCell->Element = X;
		TmpCell->Front = P;
		TmpCell->Next = P->Next;
		P->Next = TmpCell;
	}	
}
void DeleteList( List L)
{
	Position P,TmpCell;
	P = L->Next;
	L->Next = NULL;
	while( P != NULL)
	{
		TmpCell = P->Next;
		//TmpCell->Front = NULL;  //这个是多余的，无谓的引入了一个BUG，就是如果TmpCell是NULL了，这就很危险
		free(P);
		P = TmpCell;
	}
}

void PrintList( const List L)
{
	Position P = Header(L);
	if( IsEmpty(L))
		printf("Empty List.\n");
	else
	{
		do{
			P = Advance(P);
			printf("%d,", Retrieve(P));
		} while( !IsLast(P, L));
		printf("\n");
	}
}

Position Header( List L)
{
	return L;
}

Position Advance( Position P)
{
	return P->Next;
}
ElementType Retrieve( Position P)
{
	return P->Element;
}
