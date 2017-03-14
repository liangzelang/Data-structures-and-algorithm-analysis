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
	printf("选择斐波那契数列位数： ");
	scanf("%d", &bitNumber);
	printf("相关数列为： ");
	for(i = 1; i <= bitNumber; i++)
	{
		printf("%d ", fab(i));
	}	
	system("pause");
	return 0;
}