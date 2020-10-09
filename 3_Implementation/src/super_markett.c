#include<super_markett.h>
int ADD()
{
	int ch;
	FILE *fp;
	struct item c;

	system("cls");
	x: fp=fopen("item.dll","a");
	fflush(stdin);
	printf("\n\n\t..::ADD ITEM::..\t\n\nName ) : ");
	scanf("%[^\n]",&c.name);
	if(stricmp(c.name,"")==0 || stricmp(c.name," ")==0)
	fflush(stdin);
	printf("Code : ");
	scanf("%d",&c.code);
	fflush(stdin);
	printf("Quantity: ");
	scanf("%d",&c.Quantity);
	fflush(stdin);
	printf("Price: ");
	scanf("%d",&c.Price);

	fflush(stdin);

	printf("\n");
	fwrite(&c,sizeof(c),1,fp);
	printf("Item Added \n");
	printf("Want to add more items?\n[1]. Yes\n[2]. No\n");
	scanf("%d",&ch);
	if(ch==1)
		goto x;
	fclose(fp);
	getch();
}

int VIEW()
{
	int i,found;
	FILE *fp;
	struct item c;

	system("cls");
	printf("\n\t\t================================\n\t\t\tLIST OF Items\n\t\t================================\n\nName\t\tCode \t Quantity \t\tPrice\n=================================================================\n\n");
	for(i=97; i<=122; i=i+1)
	{
		fp=fopen("item.dll","r");
		fflush(stdin);
		found=0;
		while(fread(&c,sizeof(c),1,fp)==1)
		{
			if(c.name[0]==i || c.name[0]==i-32)
			{
				printf("\nName\t: %s\nCode\t: %d\nQuantity\t: %d\nPrice\t: %d\n",c.name,c.code,c.Quantity,c.Price);
				found++;
			}
		}
		if(found!=0)
		{
			printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
			getch();
		}
		fclose(fp);
	}
		getch();
}



int SEARCH()
{
	int found,l,i,ch;
	char query[20],name[20];
	FILE *fp;
	struct item c;

	system("cls");
	do
	{
		found=0;
		printf("\n\n\t..::Item SEARCH\n\t===========================\n\t..::Name of item to search: ");
		fflush(stdin);
		scanf("%[^\n]",&query);
		l=strlen(query);
		fp=fopen("item.dll","r");
		system("cls");
		printf("\n\n..::Search result for '%s' \n===================================================\n",query);
		while(fread(&c,sizeof(c),1,fp)==1)
		{
			for(i=0; i<=l; i++)
			      name[i]=c.name[i];
			name[l]='\0';
			if(stricmp(name,query)==0)
			{
				printf("\nName\t: %s\nCode\t: %d\nQuantity\t: %d\nPrice\t: %d\n",c.name,c.code,c.Quantity,c.Price);
				found++;
				if (found%4==0)
				{
					printf("..::Press any key to continue...");
					getch();
				}
			 }
		}
		if(found==0)
			printf("\n..::No match found!");
		else
			printf("\n..::%d match(s) found!",found);
		fclose(fp);
		printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
		scanf("%d",&ch);
	}
	while(ch==1);
	getch();
}



int EDIT()
{
	FILE *fp,*ft;
	char name[20];
	struct item c;

	system("cls");
	fp=fopen("item.dll","r");
	ft=fopen("temp.dat","w");
	fflush(stdin);
	printf("..::Edit \n===============================\n\n\t..::Enter the name of item to edit:");
	scanf("%[^\n]",name);
	while(fread(&c,sizeof(c),1,fp)==1)
	{
		if(stricmp(name,c.name)!=0)
			fwrite(&c,sizeof(c),1,ft);
	}
	fflush(stdin);
	printf("\n\n..::Editing '%s'\n\n",name);
	printf("..::Name):");
	scanf("%[^\n]",&c.name);
	printf("Code : ");
	scanf("%d",&c.code);
	fflush(stdin);
	printf("Quantity: ");
	scanf("%d",&c.Quantity);
	fflush(stdin);
	scanf("%d",&c.Price);
	fflush(stdin);

	printf("\n");
	fwrite(&c,sizeof(c),1,ft);
	fclose(fp);
	fclose(ft);
	remove("item.dll");
	rename("temp.dat","item.dll");
	printf("\t\t item edited");
	getch();
}

	/* ********************delete contacts**********************/

int DELETE()
{
	FILE *fp,*ft;
	struct item c;
	char name[20];

	system("cls");
	fflush(stdin);
	printf("\n\n\t..::DELETE \n\t==========================\n\t..::Enter the name of item to delete:");
	scanf("%[^\n]",&name);
	fp=fopen("item.dll","r");
	ft=fopen("temp.dat","w");
	while(fread(&c,sizeof(c),1,fp)!=0)
		if (stricmp(name,c.name)!=0)
			fwrite(&c,sizeof(c),1,ft);
	fclose(fp);
	fclose(ft);
	remove("item.dll");
	rename("temp.dat","item.dll");
	printf("\t\titem Deleted Successfully");
	getch();
}
