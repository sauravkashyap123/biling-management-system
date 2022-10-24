#ifndef mYLIBRARY_H_
#define mYLIBRARY_H_
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<windows.h>
namespace mylib{
	struct biling{
	float no_of_items;
	float price[16]={0,150,50,50,50,20,50,10,150,50,50,50,20,50,10};
	char name_of_food[30]; 
	double total;
	double price1;
};
void print();
void gotoxy(int x,int y);
static double amount=0.0;
void amnt(double price,float no_of_items)
{
	amount =amount + price * no_of_items;
}
	void menu()
{
	printf("\n 	Menu Card		\n");
	printf("\n...........VEG..........\n");
	printf("\nmenu				price\n");
	printf("\n0.Water				Rs 00.00/bottle\n");
	printf("1.Paneer			Rs 150/full\n");
	printf("2.MIX VEG			Rs 50/full\n");
	printf("3.Gobi				Rs 50/full\n");
	printf("4.Veg-Chowmin			Rs 50/full\n");
	printf("5.Tandori roti			Rs 20/piece\n");
	printf("6.Full plate lunch		Rs 50/full\n");
	printf("7.Roti				Rs 10/piece\n");
	
	printf("\n...........NON-VEG..........\n");
	printf("\n8.Chicken roll			Rs 150/full\n");
	printf("9.Chicken			Rs 50/full\n");
	printf("10.Egg				Rs 50/full\n");
	printf("11.Egg-Chowmin			Rs 50/full\n");
	printf("12.Tandori roti			Rs 20/piece\n");
	printf("13.Full plate lunch(with fish)	Rs 50/full\n");
	printf("14.Roti				Rs 10/piece\n");
}
void choose()
{
		FILE *fp;
		fp=fopen("recordsystem.txt","wb+");
	start:
	int n;
	printf("\n your order sir : ");
	scanf("%d",&n);
	switch(n,0)
	{
		case 0:
			{
				struct biling p;
				printf("\n Items name : ");
				getchar();
				gets(p.name_of_food);
				fflush(stdin);
//				printf(" \nPrice : ");
//				scanf("%f",&p.price);
				printf("\nenter number of item : ");
				scanf("%f",&p.no_of_items);
				amnt(p.price[n],p.no_of_items);
				p.total=p.price[n]*p.no_of_items;
				p.price1=p.price[n];
				fwrite(&p,sizeof(p),1,fp);
//				fclose(fp);
				printf("\n \n do you want any other items sir press y for YES and n for NO : ");
				char t;
				t=getch();
				if(t=='y')
				{
					system("cls");
					menu();
					goto start;
				}
				else
				{
					fclose(fp);
					print();
				}
			}
	}
}
void print()
{
	system("cls");
	gotoxy(50,0);
	printf("......Hotel Luxary ......\n");
	printf("\n...............................Bill......................................................\n");
	printf("------------------------------------------------------------------------------------------\n");
	std::string s="..........Please take Your Bill...........";
	std::string command="espeak \"" +s +"\"";
	const char*charCommand=command.c_str();
	system(charCommand);
	static int i=1;
	FILE *fp;
	fp=fopen("recordsystem.txt","rb+");
	struct biling p;
	rewind(fp);
	printf("\n \n S.No.		Items_Name		Price_per_Plate		Quantity	TOtal\n");
	printf("------------------------------------------------------------------------------------------------\n");
	while(fread(&p,sizeof(p),1,fp)==1)
	{
		printf("%2d %20s %22.2lf %21.2f %18.2lf",i,p.name_of_food,p.price1,p.no_of_items,p.total);
		printf("\n");
		i++;
	}
	
	gotoxy(80,7+i);
	std::cout<<"Amount : "<<amount;
	double gst=3;
	gotoxy(80,8+i);
	std::cout<<"GST Amount : "<<gst<<"% ="<<gst/100*amount;
	gotoxy(80,9+i);
	std::cout<<"Total Amount : "<<"Amount + GST =";
	gotoxy(80,10+i);
	std::cout<<amount+(gst/100*amount);
	printf("\nThanks For Visiting Us\n");
	printf("For More Details Contact Us : \n");
	printf("8210997961\n \n");
	printf("-------------------------------------------------Thank You----------------------------------------------------\n");
	fclose(fp);
}
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
}
#endif
