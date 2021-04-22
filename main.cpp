#include <conio.h>
#include <cstdio>
#include "classrelated.h"
#include "design.h"
#include "pass.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include <bits/stdc++.h>
#include <sstream>
#include<iomanip>
using namespace std;

static int kjkj = 0;
static int kjkj1 = 0;
static int kjkj2 = 0;

int main(){
driver dd[50];
bus bb[100];
users uu[100];
inter();
pwellcome();

if(kjkj==0){
string so="driver.dat";
int kp = extractlines(so);
kjkj=kp;
int kh=0;
while(kp){
dd[kh].insertnew(kh);
--kp;
++kh;
}
}

if(kjkj1==0){
string so="bus.dat";
int kp1 = extractlines(so);
kjkj1=kp1;
int kh1=0;
while(kp1){
bb[kh1].insertnew(kh1);
--kp1;
++kh1;
}
}

if(kjkj2==0){
string so="users.dat";
int kp2 = extractlines(so);
kjkj2=kp2;
int kh2=0;
while(kp2){
uu[kh2].insertnew(kh2);
--kp2;
++kh2;
}
}

int hjk;
start:
hjk = mainmenu();
if(hjk==1){
while(1){
int w = passengermenu();
switch(w){

case 1:{

int k,we,we1=0;
int ui,uj;
string cccc;
cout<<"\n\t\t\tEnter the Destination or Bus Id: ";
cin>>cccc;
we=0;
while(we!=kjkj1){
if(cccc == bb[we].to || cccc == bb[we].bid)
{
we1=1;
break;
}
++we;
}
cccc=bb[we].to;
if(we1 == 1){
system("cls");
cout<<"\n\n\t\t\t\tBus to "<<cccc<<" is available\n";
system("color 02");
string uk=findbusid3(cccc);
ui=countbooking1(uk);
if(ui==0){ cout<<"\n\n\t\t\tSorry No Seat Is Available..";Sleep(2000);
break;
}
int rr=findbusid4(uk);
uu[kjkj2].userfill(uk,kjkj2);
countbooking(uk);
sat:
cout<<"\n\n\t\t\tPlease enter the seat number from 1 to 32 : ";
cin>>k;
if(k>32)
goto sat;
int j = seatpresent(uk,k);
if(j==1){
cout<<"\n\t\t\tThis Seat is already booked by someone: ";
cout<<"\n\t\t\tPlease enter another seat number";Sleep(1500);
system("cls");
goto sat;
}
seatnumber(uk,kjkj2,uu[kjkj2].name,k);
uu[kjkj2].deposit(kjkj2,rr);
ticketprinting(uu[kjkj2],bb[we],k);
++kjkj2;

}
else{
system("cls");
cout<<"\n\t\t\t No bus is available to that "<<cccc<<" place";Sleep(1500);
}
break;
}
case 2:{
start19:
system("cls");
system("color 03");
string dlf;
cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter The Phone Number: ";
cin>>dlf;
int ass = 0;
while(ass!= kjkj2){
if(uu[ass].number==dlf)
    break;
++ass;
}
int qw = finduserid(uu[ass].bid,uu[ass].id);
if(qw!=0){
delete_line("ticket.dat",qw);
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tDeleted Successfully...";Sleep(1500);
}else{
string bnby="yes";
system("color C");
cout<<"\n\n\t\tNo such type of user exists or can't be deleted press 'yes' to continue or 'no' to exit\n\t\t\t\t\t\t->";
cin>>dlf;
if(dlf==bnby){
goto start19;
}
else
{
break;
}
}
break;
}
case 3:{
int k=kjkj1-1;
system("cls");
system("color 02");
cout<<"\n\n\n\t\t\t\t\tBus's Details\n";
cout<<"_____________________________________________________________________________________________________________________\n";
cout<<"|   Id   |    Did     |    Arrival    |     Depart     |     From      |     To      |   Price    |   Seat's left   |\n";
cout<<"---------------------------------------------------------------------------------------------------------------------";
while(k!=-1){
int har=countbooking1(bb[k].bid);
if(bb[k].bid!="empty"){
cout<<"\n";
cout<<"|   "<<bb[k].bid<<"   |     "<<bb[k].did<<"     |     "<<bb[k].arrival<<"     |      "<<bb[k].depart<<"     |      "<<bb[k].from<<"      |      "<<bb[k].to<<"      |    "<<bb[k].price<<"    |     "<<har<<"     |";
cout<<"\n";
cout<<"---------------------------------------------------------------------------------------------------------------------";
}
k--;
}
getch();
break;
}
case 4:{
system("cls");
system("color 02");
string ke;
int kf=0;
cout<<"\n\t\t\t\t\tEnter the bus id: ";
cin>>ke;
int bj=kjkj1-1;
while(bj!=-1){
string kr;
kr=bb[bj].bid;
if(ke==kr){
bb[bj].busshow1();
cout<<"\n\t\t\t\t\t*********************************";
ticketdetails(kr);
getch();
kf=1;
break;
}
--bj;
}
if(kf==0)
cout<<"\nNo such bus is available..";Sleep(2500);
break;
}//bus[0].show_bus();
case 5:{
goto start;
break;
}
case 6:{
    ending();
break;
}
}
}
}
else if(hjk==2){
loadingbar();
int pass=password();
if(pass==2)
goto start;

while(1){
admin:
int w = adminmenu();
switch(w)
   {
       case 1:{
    string dlf,dlf1;
    string yes="yes";
    driver:
        system("color 03");
        system("cls");
cout<<"\n\n\n\n\n\t\t\t\t\tEnter Driver's id: ";
cin>>dlf;
int jjk=0;
    while(jjk!=kjkj){
     if(dlf==dd[jjk].did){
            system("color C");
            cout<<"\n\n\n\n\n\t\t\tThis Driver id is already present and his name is "<<dd[jjk].dname;
            cout<<"\n\tIf you want to try again then then type 'yes' or 'no' then it will be diverted to main menu ";
            cin>>dlf1;
            if(yes==dlf1)
                goto driver;
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tYou are being diverted to main menu...";
     Sleep(1500);
        goto admin;
     }
     ++jjk;
    }
    dd[kjkj].insertdriver(dlf);
    kjkj++;
       break;
       }
       case 2:{
           system("cls");
        system("color C");
        int k=kjkj-1;
         int kv = 0;
         int jjk = 0;
       while(jjk!=kjkj){
          if(dd[jjk].did != "empty"){
             kv=1;
             break;
     }
     ++jjk;
     }
        if(kv==0)
        {
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry No Driver's Have Still Yet Registered......";Sleep(2000);
            break;
        }
        system("color 02");
        cout<<"\n\n\n\t\t\t\t\tDriver's Details\n\t\t";
        cout<<"___________________________________________________________________________ \n\t\t";
	    cout<<"|    Id    |     Name     |    Address    |     Number     |     Age      |\n\t\t";
        cout<<"---------------------------------------------------------------------------";
        //cout<<setw(10)<<"id"<<setw(15)<<"name"<<setw(17)<<"address"<<setw(15)<<"number"<<setw(15)<<"age\n\n";
        while(k!=-1){
                if(dd[k].did != "empty"){
                    dd[k].drivershow();
                    cout<<"\n";
        }
        k--;}
        getch();
            break;
        }
       case 3:{

        start7:
             system("cls");
             system("color 03");
        string dlf;
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter the driver's id: ";
    cin>>dlf;
    int qw=findid1(dlf);
    if(qw!=0){
        delete_line("driver.dat",qw);
    int jjk=0;
    while(jjk!=kjkj){
     if(dlf==dd[jjk].did){
         dd[jjk].did = "empty";
     }
     ++jjk;
     }
     jjk=0;
     int kv = 0;
    while(jjk!=kjkj){
     if(dd[jjk].did != "empty"){
         kv=1;
         break;
     }
     ++jjk;
     }
     if(kv==0)
        remove("driver.dat");
    }else{
        string bnby="yes";
        system("color C");
    cout<<"\n\n\t\tNo such type of driver exists or can't be deleted press 'yes' to continue or 'no' to exit\n\t\t\t\t\t\t->";
    cin>>dlf;
    if(dlf==bnby){
    goto start7;
    }
    else
    {
    break;
    }
    }
    break;
    }
       case 4:{
    int jjkk=bb[kjkj1].insertbus();
    if(jjkk==1)
        break;
    ++kjkj1;
            break;
        }
       case 5:{
        system("cls");
        system("color C");
        //cout<<kjkj1;
        int k=kjkj1-1;
         int kv = 0;
         int jjk = 0;
       while(jjk!=kjkj1){
          if(bb[jjk].bid != "empty"){
             kv=1;
             break;
     }
     ++jjk;
     }
        if(kv==0)
        {
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry No Bus Have Still Yet Inserted......";Sleep(2000);
            break;
        }
        system("color 02");
        cout<<"\n\n\n\t\t\t\t\t\t Bus Details\n\t";
        cout<<"________________________________________________________________________________________________________\n\t";
	    cout<<"|    Bid    |     Did     |    Arrival    |    Depart    |     From     |     To      |     Price      |\n\t";
        cout<<"--------------------------------------------------------------------------------------------------------";
        //cout<<setw(10)<<"id"<<setw(15)<<"name"<<setw(17)<<"address"<<setw(15)<<"number"<<setw(15)<<"age\n\n";
        while(k!=-1){
                if(bb[k].bid != "empty"){
                    bb[k].busshow();
                    cout<<"\n";
        }
        k--;}
        getch();
            break;

            break;
        }
       case 6:{
            startbus:
             system("cls");
             system("color 03");
        string dlf;
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter the Bus Id: ";
    cin>>dlf;
    int qw = findbusid2(dlf);
    if(qw!=0){
        delete_line("bus.dat",qw);
    int jjk=0;
    while(jjk!=kjkj1){
     if(dlf==bb[jjk].bid){
         bb[jjk].bid = "empty";
     }
     ++jjk;
     }
     jjk=0;
     int kv = 0;
    while(jjk!=kjkj1){
     if(bb[jjk].bid != "empty"){
         kv=1;
         break;
     }
     ++jjk;
     }
     if(kv==0)
        remove("bus.dat");
    }else{
        string bnby="yes";
        system("color C");
    cout<<"\n\n\t\tNo such type of Bus exists or can't be deleted press 'yes' to continue or 'no' to exit\n\t\t\t\t\t\t->";
    cin>>dlf;
    if(dlf==bnby){
    goto startbus;
    }
    else
    {
    break;
    }
    }
break;
        }
       case 7:{
           system("cls");
           system("color 02");
           cout<<"\n\n\n\n\n\n\t\t\t\t\t";
           int ij=0;
           int i=0;
           while(i!=kjkj1){
            int inc = totalincome(bb[i].bid);
            inc = inc*bb[i].price;
            ij+=inc;
            cout<<"The total income from bus id "<<bb[i].bid<<" is $"<<inc;
            cout<<"\n\t\t\t\t\t";
            ++i;
           }
           cout<<"THE OVERALL INCOME IS $"<<ij;
           getch();
         break;
         }
       case 8:{
           system("cls");
           system("color 02");
           cout<<"\n\n\n\t\t\t\t\t\tAll card details\n\n";
       printcarddetails();
       getch();
       break;
       }
       case 9:{
   int pass=changepass();
    if(pass==1){
        goto start;
    }
    break;
        }
       case 10:{
                goto start;
            }
       case 11:{

             ending();

            }
   }
}
}
else
{
ending();
}
return 1;
}
