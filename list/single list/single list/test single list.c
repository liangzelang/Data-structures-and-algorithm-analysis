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
		printf("Please choose which mode :\n��a������Ԫ��\n��b��ɾ��Ԫ��\n��c������Ԫ��\n��d��ɾ��List\n��e����ʾList\n��q���˳�\n ");
		mode = getchar();
		//getchar();  //����һ�����з�
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