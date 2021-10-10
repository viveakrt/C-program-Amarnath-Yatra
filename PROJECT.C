//By VIVEK @2017         

// compiler DOS turbo c++ only

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
void outline();
void touristinfo();
void password();
void clralldata();
void mainmenu();
void record();
struct tourist
	{
		char name[20];
		char fname[20];
		char mobile[10];
		int age;

	};
struct tourist info; FILE *ti;
int main()
{    	password();
	getch();
	return 0;
}
void record()
{       char ch;
	int c1=0,c2,c3,n=10,a; //color1//color2
	while

	(c1==0||c2==0||c3==0)
	{
	time_t t;
	srand((unsigned)time(&t));
	c1=rand()%16;
	c3=rand()%16;
	c2=rand()%16;
	}
	system("cls");
	outline(c1,c2,c3);
	ti=fopen("yatralog.txt","r");
	gotoxy(33,6);textcolor(c1);cprintf("%cOld Record%c",177,177);
	gotoxy(17,8);printf("Name   SoF    Age     Mobile No.   Eligibility");
	gotoxy(17,9);
	do
	{
		ch=getc(ti);
		putchar(ch);
		if(ch=='\n')
		{gotoxy(17,n++);}
		}while(ch!=EOF);
		gotoxy(20,15);printf("Press Any Key.. For Main Menu");
		getch();mainmenu();
}
void touristinfo()
{
	int c1=0,c2,c3,n,a; //color1//color2
	while(c1==0||c2==0||c3==0)
	{
	time_t t;
	srand((unsigned)time(&t));
	c1=rand()%16;
	c3=rand()%16;
	c2=rand()%16;
	}
	system("cls");
	outline(c1,c2,c3);
	ti=fopen("yatralog.txt","a+");
	gotoxy(31,6);textcolor(c1);cprintf("%cTourist Information%c",177,177);
	gotoxy(23,8);printf("Name              = ");scanf("%s",&info.name);
	fprintf(ti,"\n%s\t",info.name);
	gotoxy(23,9);printf("Father's Name     = ");scanf("%s",&info.fname);
	fprintf(ti,"%s\t",info.fname);
	gotoxy(23,10);printf("Age               = ");scanf("%d",&info.age);a=info.age;
	fprintf(ti,"%d\t",info.age);
	gotoxy(23,11);printf("Mobile No.        = ");scanf("%s",&info.mobile);
	while(strlen(info.mobile)!=10)
	{
		scanf("%s",&info.mobile);
		if(strlen(info.mobile)!=10)
			{
				gotoxy(25,15);printf("Wrong format");
				gotoxy(20,16);printf("for Enter mobile no. again press 1");
				gotoxy(20,17);printf("for Mainmenu press any other key");
				scanf("%d",&n);
				if(1!=n)
				{
				 mainmenu();
				}gotoxy(43,11);
			}
	}
	fprintf(ti,"%s\t",info.mobile);

	if(13<a)
	{
		if(75>a)
		{
			gotoxy(18,15);printf("You are eligible Pay 150 Rs. at Counter");
			fprintf(ti,"Yes");
		}
		else
		{
			gotoxy(18,15);printf("Not eligible for Yatra You Must Be less than 75");
			fprintf(ti,"\b\bNo");
		}
	}  else
		{
			gotoxy(18,15);printf("Not eligible for Yatra You Must Be more than 13");
			fprintf(ti,"\b\bNo");
		}
	fclose(ti);
	gotoxy(20,17);printf("Press Any Key.. For Main Menu");
	getch();mainmenu();

}

void mainmenu()
{       int c1=0,c2,c3,n; //color1//color2
	while(c1==0||c2==0||c3==0)
	{
	time_t t;
	srand((unsigned)time(&t));
	c1=rand()%16;
	c3=rand()%16;
	c2=rand()%16;
	}
	system("cls");
	outline(c1,c2,c3);
	gotoxy(35,6);textcolor(c1);cprintf("%cMAIN MENU%c",177,177);
	gotoxy(25,8);printf("1.Add Tourist Information");
	gotoxy(25,9);printf("2.See Old Record");
	gotoxy(25,10);printf("3.Clean All Old Record");
	gotoxy(25,11);printf("4.Exit");
	gotoxy(25,15);printf("Enter number for option");
	scanf("%d",&n);
	switch(n)
	{
		case 1:touristinfo();break;
		case 2:record();break;
		case 3:clralldata();
		case 4:exit(1);
	}

}
void clralldata()
{ 	int c1=0,c2,c3,n,a; //color1//color2
	while(c1==0||c2==0||c3==0)
	{
	time_t t;
	srand((unsigned)time(&t));
	c1=rand()%16;
	c3=rand()%16;
	c2=rand()%16;
	}
	system("cls");
	outline(c1,c2,c3);

 ti=fopen("yatralog.txt","w");
 fprintf(ti," ");
 gotoxy(32,12);printf("All Data Is Deleted");
 fclose(ti);
 gotoxy(20,15);printf("Press Any Key.. For Main Menu");
 getch();mainmenu();
}
void outline(int x,int y,int z)
{
	int i,j;
	clrscr();
	gotoxy(32,2);for(i=0;i<17;i++){printf("%c",15);}
	gotoxy(32,3);textcolor(z);cprintf("%cAMARNATH YARTRA%c",16,17);
	gotoxy(32,4);for(i=0;i<17;i++){printf("%c",15);}
	gotoxy(15,5);
	for(i=0;i<52;i++)
	{       textcolor(x);
		cprintf("%c",177);
		delay(10);
	}
	for(i=0;i<15;i++)
	{
		gotoxy(65,i+6);
		textcolor(y);
		cprintf("%c",177);
		gotoxy(66,i+6);
		textcolor(y);
		cprintf("%c",177);
		delay(10);
	}
	for(i=50;i>0;i--)
	{
		gotoxy(i+14,20);
		textcolor(x);
		cprintf("%c",177);
		delay(10);
	}
	for(i=15;i>0;i--)
	{
		gotoxy(15,i+5);
		textcolor(y);
		cprintf("%c",177);
		gotoxy(16,i+5);
		textcolor(y);
		cprintf("%c",177);
		delay(10);
	}

	gotoxy(53,21);printf("By Vivek @2017");

}
void password()
{       char password[8]="mahadev";
	char check[8];
	int c1=0,c2,c3,n; //color1//color2
	while(c1==0||c2==0||c3==0)
	{
	time_t t;
	srand((unsigned)time(&t));
	c1=rand()%16;
	c3=rand()%16;
	c2=rand()%16;
	}
	system("cls");
	outline(c1,c2,c3);

	gotoxy(35,6);
	textcolor(c1);
	cprintf("%cPASSWORD%c",177,177);
	textcolor(c2);
	gotoxy(20,8);
	cprintf("\nEnter Password:");
	scanf("%s",&check);
	gotoxy(20,11);
	if(strcmp(password,check)==0)
	{      textbackground(2);textcolor(15);
	       cprintf("Password Matched\n\n\n");
	       textbackground(0);
	       printf("\b\b\bEnter any key to procced...");
	       getch();
	       mainmenu();
	}
	else
	{      textbackground(4);textcolor(15);
	       cprintf("Worng input\n\n\n");
	       printf("\b\b\bPress any key to exit ");
	       getch();
	       exit(1);
	}

}


