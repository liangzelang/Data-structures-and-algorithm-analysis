#include "list.h"


struct Node
{
	ElementType Element;
	Position Next;
};

List MakeEmpty(List L)
{
	if(L != NULL)
		DeleteList(L);
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		printf(" Out of Memory");
	L->Next = NULL;
	return L;
}
int IsEmpty( List L)
{
	return L->Next == NULL;
}

int IsLast( Position P, List L)
{
	if(L->Next == NULL)
		printf("This is NULL List.\n");
	return P->Next == NULL;
}

Position Find( ElementType X, List L)
{
	Position P;
	if(L->Next == NULL)
	{
		printf("This is NULL list.\n");
	}
	P = L->Next;
	while(P->Next != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;

}

Position FindPrevious( ElementType X, List L)
{
	Position P;
	P = L->Next;
	while(P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	return P;
}
void Delete( ElementType X, List L)
{
	Position P,TmpCell;
	P = FindPrevious(X,L);
	if(!IsLast(P,L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free( TmpCell );  //这个非常重要，在C中 malloc和free是基友
	}
}

void Insert( ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Out of Memory");
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
void DeleteList( List L)
{
	Position P,TmpCell;
	P = L->Next;
	L->Next = NULL;
	if(!IsLast(P,L))
	{
		TmpCell = P->Next;
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
			printf("%d", Retrieve(P));
		} while( !IsLast(P, L));
		printf("\n");
	}
}

Position Header( List L)
{
	return L;
}

Position First( List L)
{
	Position P;
	P = L->Next;
	return P;
}
Position Advance( Position P)
{
	return P->Next;
}
ElementType Retrieve( Position P)
{
	return P->Element;
}
