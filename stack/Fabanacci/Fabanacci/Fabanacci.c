#include <stdio.h>
#include <stdlib.h>
//test

int fab(int num)
{
	int result=0;
	if(num <= 2)
		result = 1;
	else
	{
		result = fab(num - 1) + fab(num - 2);
	}
	//printf("%d ", result);
	return result;
}

int main()
{
	int bitNumber;
	int i = 0;
	printf("ѡ��쳲���������λ���� ");
	scanf("%d", &bitNumber);
	printf("�������Ϊ�� ");
	for(i = 1; i <= bitNumber; i++)
	{
		printf("%d ", fab(i));
	}	
	system("pause");
	return 0;
}