#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
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
int IsHead( Position P, List L);
Position Find( ElementType X, List L);
//˫������Ҫ��һ���Ӻ��������ĺ���
Position Find_From_Back( ElementType X, List L);//useless
Position FindPrevious( ElementType X, List L);
//˫������������Ԫ��ǰһ��λ��
Position FindPrevious_Back( ElementType X, List L);//useless
Position Get_Last( List L);
void Delete( ElementType X, List L);
void Insert( ElementType X, List L, Position P);
void DeleteList( List L);
void PrintList( const List L);
Position Header( List L);
Position Advance( Position P);
ElementType Retrieve( Position P);

#endif