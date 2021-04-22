#include <conio.h>
#include <cstdio>
//#include "ticket.h"
//#include "pass.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

using namespace std;

void inter(){
 system("color 06");
 cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tPlease Wait While Loading...\n\n";
 char a=177, b=219;
 cout<<"\t\t\t\t\t";
 for (int i=0;i<=15;i++)
 cout<<a;
 cout<<"\r";
 cout<<"\t\t\t\t\t";
 for (int i=0;i<=15;i++)
 {
  cout<<b;
  for (int j=0;j<=1e8;j++);
 }

 cout<<"\n\n\n\t\t\t\t\tHELLO USER\n\n\t\t\t\t\tMade by Hariram(19MX106) :)";
 cout<<"\n\t\t\t\t\tSponsored By P.S.G TECH";

 Sleep(1500);
}

void pwellcome(){

system("cls");
	char welcome[50]="WELCOME";
	char welcome2[50]=" TO";
	char welcome3[50]="  BUS";
	char welcome4[50]=" MANAGEMENT SYSTEM";
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		printf(" %c",welcome[wlc]);
		Sleep(100);
	}

	printf("\n\n\t\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		printf(" %c",welcome2[wlc2]);
		Sleep(100);
	}

	printf("\n\n\t\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			printf(" %c",welcome3[wlc3]);
		}
		else{

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(100);
	}
		printf("\n\n\t\t\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			printf(" %c",welcome4[wlc3]);
		}
		else{

			printf(" %c",welcome4[wlc3]);
		}
		Sleep(100);
	}


}

void pre(int tab){

	for(int i=0; i<tab;i++){
		printf("\t");
	}

}

void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

int mainmenu(){

    string hjk;
    were9:
    system("cls");
    system("color 03");
    br(5); pre(4); cout<<"\n\n\n\n\t\t\t\t\t   Main Menu";Sleep(400);
    br(2); pre(4); cout<<"Press Any Of The Following Buttons:";Sleep(400);
    br(2); pre(7); cout<<"\n\n\t\t\t\t\t1. Bus Booking System";Sleep(400);
    br(2); pre(7);cout<<"\n\t\t\t\t\t2. Admin Panel ";Sleep(400);
    br(2); pre(7);cout<<"\n\t\t\t\t\t3. Exit ";Sleep(400);
    br(2); pre(7);cout<<"\n\t\t\t\t\tEnter your choice-> ";Sleep(400);
    cin>>hjk;
    try{
    for (int i = 0; i < hjk.length(); i++)
        if (isdigit(hjk[i]) == false)
            throw hjk;
}
catch(string hjk){
    cout<<"\n\t\t\t\t"<<hjk<<" Is Not A Number Please Type A Number\n";Sleep(1000);
    goto were9;
}
    stringstream geek(hjk);
    int x = 0;
    geek >> x;

  return x;
}

void ending(){

			system("cls");
			//middle1(); pre(3);
			 cout<<"\n\n\n\n\n\n\n\t\t\t Thank You For Using My System. \n\t\t\t Brought To You By R.Hariram(19MX106) P.S.G COLLEGE OF TECHNOLOGY \n\n\n\n\n\n\n";
			Sleep(1000);

			exit(1);
}

void loadingbar(void){

	for (int i=15;i<=100;i+=5){

		system("cls");

		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){

//			ccolor(160+j);
			printf(" ");
	//		ccolor(26);

		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

}

void intro(){
     system("color 03");
     system("cls");
  cout<<"\t\t\t\t*\t*";
  cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*****\t*****";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t*\t*";
}

int adminmenu(){
     system("cls");
    intro();
    were10:
    system("cls");
    string w;
cout<<"\n\n";
  cout<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
  cout<<"\t\t\t\t\t\t<--Drivers information-->\n\t\t\t\t\n";
  cout<<"\t\t>>1. Enter Driver Details\t";
  cout<<">>2. Show Driver Details \t";
  cout<<">>3. Remove Driver \n\n";
  cout<<"\t\t\t\t\t\t<--Bus information-->\n\n";
  cout<<"\t\t>>4. Enter Bus Details\t\t";
  cout<<">>5. Show Bus Details \t\t";
  cout<<">>6. Remove Bus \n\n";
  cout<<"<\t\t\t\t\t\t<--Income Details-->\n\n";
  cout<<"\t\t>>7. Total Income\t\t";
  cout<<">>8. All Card Details\n\n";
  cout<<"\t\t\t\t\t\t<--Other info-->\n\n";
  cout<<"\t\t>>9. Change Admin Password\t";
  cout<<">>10. Back To Main Menu\t\t";
  cout<<">>11. Exit\t\n";
  cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  cout<<"\n\t\t\t\t\t\tEnter your choice:-> ";
  cin>>w;
      try{
    for (int i = 0; i < w.length(); i++)
        if (isdigit(w[i]) == false)
            throw w;
}
catch(string w){
    cout<<"\n\t\t\t\t\t"<<w<<" Is Not A Number Please Type A Number\n";Sleep(1000);
    goto were10;
}
    stringstream geek(w);
    int x = 0;
    geek >> x;

  return x;
}

int passengermenu(){
    string w;
    were11:
system("cls");
    intro();

  cout<<"\n";
  cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  cout<<"\t\t\t>>1. Bus Reservation\n\t\t\t"
  <<">>2. Cancel Ticket\n\t\t\t"
  <<">>3. Show Bus Routes\n\t\t\t"
  <<">>4. Show Detailed Bus info\n\t\t\t"
  <<">>5. Back to main menu\n\t\t\t"
  <<">>6. Exit \n\t\t\t";
  //<<"5. Exit";
  cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  cout<<"\n\t\t\tEnter your choice:-> ";
 cin>>w;
      try{
    for (int i = 0; i < w.length(); i++)
        if (isdigit(w[i]) == false)
            throw w;
}
catch(string w){
    cout<<"\n\t\t\t"<<w<<" Is Not A Number Please Type A Number\n";Sleep(1000);
    goto were11;
}
    stringstream geek(w);
    int x = 0;
    geek >> x;

  return x;}
