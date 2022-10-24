#include"myheader1.h"
using namespace mylib;
int main()
{
	std::string k="..........project starting in...........";
	std::string command1="espeak \"" +k +"\"";
	const char*charCommand1=command1.c_str();
	system(charCommand1);
	for(int i=5;i>=0;i--)
	{
		gotoxy(35,10);
		printf("starting in...");
		gotoxy(50,10);
		Beep(750,800);
		printf("%d",i);
		for(long int k=1;k<=10000;k++)
		for(long int l=1;l<=100000;l++);
//		printf("Lets Start...");
		system("cls");
	}
	gotoxy(50,0);
	printf("......Hotel Luxary ......\n");
	std::string s="..........Welcome To Hotel Luxary...........";
	std::string command="espeak \"" +s +"\"";
	const char*charCommand=command.c_str();
	system(charCommand);
	menu();
	choose();
}
