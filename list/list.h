#ifndef _LIST_H
#define _LIST_H
#include <stdlib.h>
#include <stdio.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty(List L);
int IsEmpty( List L);
int IsLast( Position P, List L);
Position Find( ElementType X, List L);
Position FindPrevious( ElementType X, List L);
void Delete( ElementType X, List L);
void Insert( ElementType X, List L, Position P);
void DeleteList( List L);
void PrintList( const List L);
Position Header( List L);
Position First( List L);
Position Advance( Position P);
ElementType Retrieve( Position P);

#endif