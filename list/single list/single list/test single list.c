#include "single list.h"

int main()
{
	List L;
	char mode;
	int element,position;
	Position temp ;
	L = CreatList();
	ShowList(L);
	
	while(1)
	{
		printf("Please choose which mode :\n【a】插入元素\n【b】删除元素\n【c】查找元素\n【d】删除List\n【e】显示List\n【q】退出\n ");
		mode = getchar();
		//getchar();  //还有一个换行符
		switch(mode)
		{
		case 'a':
			printf("Enter your elements: ");
			scanf("%d",&element);
			printf("Enter your position: ");
			scanf("%d",&position);
			if(!InsertElement(L, position, element))
				printf("wrong position.\n");
			else 
				printf("Bingo.\n");
			break;
		case 'b':
			printf("Enter the element which you want to delete: ");
			scanf("%d",&element);
			if(!DeleteElement(L, element))
				printf("No this element.\n");
			else 
				printf("Bingo.\n");
			break;
		case 'c':
			printf("Enter the element which you want to find: ");
			scanf("%d",&element);
		
			temp =  FindElement(L,element);
			if(!temp)
				printf("No this element.\n");
			else 
				printf("%x.\n", temp);

			break;
		case 'd':
			printf("Sure to Del ('1' or '0'): ");
			scanf("%d",&element);
			if(element)
			{
				DeleteList(L);
				printf("Bingo.\n");
			}				
			else
				printf("Cancel delete.\n");
			
			break;
		case 'e':
			ShowList(L);
			printf("\nBingo.\n");
			break;
		case 'q':
			
			return 0;
			break;
		}
		getchar();
	}
}