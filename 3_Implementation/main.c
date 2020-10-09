#include<super_markett.h>
#include "test_super_markett.h"
int ADD();
int VIEW();
int SEARCH();
int EDIT();
int DELETE();
int test_main();

void main()
{
	int ch,y;
 lebel:	system("cls");
	printf("\n\t **** Welcome to Super Market Management System ****");
	printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add an item \n\t\t[2] List of all the items \n\t\t[3] Search for an item \n\t\t[4] Edit \n\t\t[5] Delete \n\t\t[6] Exit\n\t\t=================\n\t\t");
	printf("\n\t\tEnter the choice: ");
	scanf("%d",&ch);
	test_main();
    return 0;
	switch(ch)
	{
		case 1:
			ADD();
			break;
		case 2:
			VIEW();
			break;
		case 3:
			SEARCH();
			break;
		case 4:
			EDIT();
			break;
		case 5:
			DELETE();
			break;
		case 6:
			break;
		default:
			printf("..::Invalid Input::..");
			break;
    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&y);
    switch (y)
    {
	case 1: goto lebel; break;
	case 0: break;
	default: printf("Invalid choice"); break;
    }
getch();

}
