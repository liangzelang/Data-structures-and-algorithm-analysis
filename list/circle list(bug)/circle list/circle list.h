#ifndef CIRCLE_LIST_H_
#define CIRCLE_LIST_H_
#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Rear;
typedef PtrToNode Position;
typedef int ElementType;
List CreateList();
void DeleteList(List L);
Position FindElement(List L, ElementType element);
void PrintList(List L);
void InsertElement(ElementType element, int p, List L);
void DeleteElement(ElementType element, List L);
#endif
