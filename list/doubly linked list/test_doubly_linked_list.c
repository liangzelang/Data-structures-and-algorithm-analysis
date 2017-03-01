//这个测试程序是为了测试双向链表
//存在问题： 在）函数中处理指针有一些不严谨导致程序有问题,就是第一个元素的Front设置为NULL还是指向Header的问题
//时间：2017/02/25
//作者：738965460@qq.com
#include "doubly_linked_list.h"
int main()
{
	List L;
	Position P;
	int i;
	
	L = MakeEmpty( NULL);
	P = Header(L);
	PrintList(L);

	for(i =0; i< 10; i++)
	{
		Insert(i, L ,P);
		PrintList(L);
		P = Advance(P);
	}
	for(i= 0;i<10;i+=2)
	{
		Delete(i,L);
	}
  	for( i = 0; i < 10; i++ )
        if( ( i % 2 == 0 ) == ( Find( i, L ) != NULL ) )
            printf( "Find fails\n" );

    printf( "Finished deletions\n" );

    PrintList( L );

    DeleteList( L );
	system("pause");
    return 0;
}