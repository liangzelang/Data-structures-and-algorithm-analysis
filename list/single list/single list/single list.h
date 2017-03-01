#ifndef SINGLE_LIST_H_
#define SINGLE_LIST_H_
#include <stdlib.h>
#include <stdio.h>
struct Node;
typedef int ElementType;
typedef struct Node * PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;
typedef char Status;

List CreatList();  //�����ձ�
Status InsertElement(List L,int P, ElementType element); //����Ԫ��
Status DeleteElement(List L, ElementType element);
Position FindElement(List L, ElementType element);
void DeleteList(List L);
void ShowList(const List L);

#endif