//������Գ�����Ϊ�˲���˫������
//�������⣺ �ڣ������д���ָ����һЩ���Ͻ����³���������,���ǵ�һ��Ԫ�ص�Front����ΪNULL����ָ��Header������
//ʱ�䣺2017/02/25
//���ߣ�738965460@qq.com
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