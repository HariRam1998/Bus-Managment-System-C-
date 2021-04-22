#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include <bits/stdc++.h>
#include <sstream>
#include<iomanip>
using namespace std;

class bus;

class income{
    protected:
int cash=0;
int cashcard=0;
string card = "0";
int passcode=0;
public:
virtual void deposit(int,int)=0;
virtual void show()=0;
};

class users:public income{
public:
    string id;
    string bid;
    string name;
    string address;
    string number;
    string gender;
    string age;
    void usershow();
    void deposit(int,int);
void show();
void userfill(string,int);
void insertnew(int);
void insertdeposit(int);
//int,string,string,string,string,string,string,string,int,int)
friend void ticketprinting(users,bus,int);
};

void users::show(){
    if(cash!=0){
    cout<<"\nPaid By Cash: "<<cash;
  }else{
      cout<<"\nPaid By Card With The Number"<<card<<" An Amount Of "<<cashcard<<" Was Paid";
  }
}

void users::deposit(int id,int k){
int i;
string ch;
start:
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYou Want To Pay By \n\n\t\t\t\t\t\t1. Cash\n\t\t\t\t\t\t2. Card";
cout<<"\n\n\t\t\t\t\t\tPlease Enter the method-> ";
cin>>i;
string back1="back";
string yes="yes";
 system("cls");
if(i==1){
        start1:
            system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tYou Have To Pay "<<k<<" By Cash then enter 'yes'\n\n\t\t\t\tIf you want to change the pay method then enter 'back'\n\t\t\t\t\t\t->";
cin>>ch;
if(ch==back1){
    goto start;
}else if(ch==yes){

cash=k;
fstream file;
  file.open ("cash.dat", ios::app);
  //cin.getline(text, sizeof(text));// Writing on file
  file <<id<<" "<<cash<<endl;
  file.close();
  cout<<"\n\t\t\t\tPayment Successfully....";Sleep(1500);
//totalcash+=k;
}else{
cout<<"Wrong input";
goto start1;
}
}else if(i==2){
    system("cls");
cout<<"\n\n\n\n\n\n\n\t\t\t\tYou have to Pay "<<k<<" By Card Please Enter the card Details\n\n\t\t\t\tIf you want to change the pay method then enter 'back'";
cout<<"\n\n\n\t\t\t\tPlease enter the card details: ";
cin>>card;
if(card==back1){
    goto start;
}
cout<<"\n\n\t\t\t\tPlease Enter The Passcode: ";
cin>>passcode;
cashcard=k;
fstream file;
  file.open ("card.dat", ios::app);
  //cin.getline(text, sizeof(text));// Writing on file
  file <<id<<" "<<card<<" "<<passcode<<" "<<cashcard<<endl;
  file.close();
  //cout<<"\n\t\t\t\tPayment Successfully....";Sleep(2000);
//totalcard+=k;
cout<<"\n\n\t\t\t\tPayment Successfull...";Sleep(1500);
}else{
cout<<"\n\n\t\t\tPlease Enter The Correct Mode Of Payment";
goto start;
}
}

void users::usershow(){
cout<<"\nUser id"<<id;
cout<<"\nBus id"<<bid;
cout<<"\nName "<<name;
cout<<"\nAddress "<<address;
cout<<"\nNumber "<<number;
cout<<"\nGender "<<gender;
cout<<"\nAge "<<age;
//void deposit();
}

void users::userfill(string biid,int iid){
stringstream ss;
ss<<iid;
string s,str;
ss>>s;
id=s;
bid=biid;
cout<<"\n\t\t\t\tEnter name: ";
cin>>name;
cout<<"\n\t\t\t\tEnter Address: ";
cin>>address;
were2:
cout<<"\n\t\t\t\tEnter Number: ";
cin>>str;
try{
for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            throw str;
}
catch(string str){
    cout<<"\n\t\t\t\t"<<str<<" Is Not A Number Please Type A Number\n";
    goto were2;
}
number=str;
cout<<"\n\t\t\t\tEnter Gender: ";
cin>>gender;
were3:
cout<<"\n\t\t\t\tEnter Age: ";
cin>>str;
try{
for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            throw str;
}
catch(string str){
    cout<<"\n\t\t\t\t"<<str<<" Is Not A Age Please Type A Number For Age\n";
    goto were3;
}
age=str;
fstream file;
  file.open ("users.dat", ios::app);
  //cin.getline(text, sizeof(text));// Writing on file
  file <<id<<" "<<bid<<" "<<name<<" "<<address<<" "<<number<<" "<<gender<<" "<<age<<endl;
  file.close();
  cout<<"\n\t\t\t\tAdded Successfully....\n";Sleep(2000);
}

void users::insertnew(int line){
fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "users.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count2=0;
    int count4=0;
    //string count5="empty";
   // int line2=0;
    //cout<<line;
    while (file >> word)
    {

        if(line==0){

        if(count2==0)
        id=word;
        else if(count2==1)
        bid=word;
        else if(count2==2)
        name=word;
        else if(count2==3)
        address=word;
        else if(count2==4)
        number=word;
        else if(count2==5)
        gender=word;
        else if(count2==6)
        age=word;

//cout<<word<<"*";
        count2++;
        if(count2==7){
            count2=0;
            file.close();
            break;
        }
        }
        else{
  //              cout<<word<<" ";
            if(count4!=6){
                count4++;
            }else{
                count4=0;
            line--;
            }
        }

    }
     file.close();

}

void users::insertdeposit(int line){
fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "user.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count2=0;
    int count4=0;
    //string count5="empty";
   // int line2=0;
    //cout<<line;
    while (file >> word)
    {

        if(line==0){

        if(count2==0)
        id=word;
        else if(count2==1)
        name=word;
        else if(count2==2)
        address=word;
        else if(count2==3)
        number=word;
        else if(count2==4)
        gender=word;
        else if(count2==5)
        age=word;

//cout<<word<<"*";
        count2++;
        if(count2==6){
            count2=0;
            file.close();
            break;
        }
        }
        else{
  //              cout<<word<<" ";
            if(count4!=4){
                count4++;
            }else{
                count4=0;
            line--;
            }
        }

    }
     file.close();

}

class bus{
public:
string bid;
string did;
string arrival;
string depart;
string from;
string to;
int price;
int ocuppy = 0;
int insertbus();
void insertnew(int);
void busshow();
void busshow1();
friend void ticketprinting(users,bus,int);
};

class driver{
public:
 string did;
 string dname;
 string daddress;
 string dage;
 string dnumber;
void insertdriver(string);
void drivershow();
void drivershow1();
//int extractlines();
void insertnew(int);
};

void driver::drivershow(){

		cout<<"\n\t\t";
		cout<<"|      "<<did<<"      |     "<<dname<<"   |     "<<daddress<<"    |     "<<dnumber<<"    |      "<<dage<<"      |";
		cout<<"\n\t\t";
		cout<<"---------------------------------------------------------------------------";
//cout<<"\t\t|"<<setw(15)<<did<<"|"<<setw(15)<<dname<<"|"<<setw(15)<<daddress<<"|"<<setw(15)<<dnumber<<"|"<<setw(15)<<dage<<"|";
}

int findid(string solve){
    fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "driver.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    //cout<<solve;
    while (file >> word)
    {
        if(count3==0){

            if(solve==word){
                    //cout<<word;
                     file.close();
                return 1;

            }
        }
            count3++;
            if(count3==5){
                    //cout<<word;
                count3=0;

        }
    }
    file.close();
    return 0;

}

void driver::insertdriver(string solve){
string str;
did=solve;
cout<<"\n\t\t\t\t\tEnter name: ";
cin>>dname;
cout<<"\n\t\t\t\t\tEnter Address: ";
cin>>daddress;
were:
cout<<"\n\t\t\t\t\tEnter Number: ";
cin>>str;
try{
for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            throw str;
}
catch(string str){
    cout<<"\n\t\t\t\t\t"<<str<<"Is Not A Number Please Type A Number\n";
    goto  were;
}
dnumber=str;
were1:
cout<<"\n\t\t\t\t\tEnter Age: ";
cin>>str;
try{
for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            throw str;
}
catch(string str){
    cout<<"\n\t\t\t\t\t"<<str<<"Is Not A Age Please Type A Number For Age\n";
    goto  were1;
}
dage=str;
fstream file;
  file.open ("driver.dat", ios::app);
  //cin.getline(text, sizeof(text));// Writing on file
  file <<did<<" "<<dname<<" "<<daddress<<" "<<dnumber<<" "<<dage<<endl;
  file.close();
  cout<<"\n\t\t\t\t\tAdded Successfully....";Sleep(2000);
}

int findid1(string solve){
    fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "driver.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    int count4=1;
    //cout<<solve;
    while (file >> word)
    {
        if(count3==0){

            if(solve==word){
                     file.close();
                   // cout<<count4;
                    return count4;
            }
        }
            count3++;
            if(count3==5){
                    //cout<<word;
                    count4++;
                count3=0;

        }
    }
    file.close();
    return 0;

}

int finduserid(string bid,string id){
    fstream file;
    string word, t, q, filename,s,d,e,f;
// filename of the file
    filename = "ticket.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    int count4=1;
    //cout<<solve;
while (file >> word)
{
        s=word;
        file>>word;
        d=word;
        file>>word;
        e=word;
        file>>word;
        f=word;
        if(s==bid && d==id)
        {
                file.close();
                return count4;
        }
        ++count4;
}
file.close();
return 0;
}

int findbusid2(string solve){
    fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "bus.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    int count4=1;
    //cout<<solve;
    while (file >> word)
    {
        if(count3==0){

            if(solve==word){
                   // cout<<count4;
                   file.close();
                    return count4;
            }
        }
            count3++;
            if(count3==7){
                    //cout<<word;
                    count4++;
                count3=0;

        }
    }
     file.close();
    return 0;

}

string findbusid3(string solve){
    fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "bus.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    int count4=1;
    string count5="Empty";
    //cout<<solve;
    while (file >> word)
    {
        if(count3==0){
            count5=word;
        }
        if(count3==5){

            if(solve==word){
                   // cout<<count4;
                   file.close();
                    return count5;
            }
        }
            count3++;
            if(count3==7){
                    //cout<<word;
                    count4++;
                count3=0;

        }
    }
     file.close();
    return 0;

}

int findbusid4(string solve){
    fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "bus.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    int count4=1;
    int count5=0;
    string count6="Empty";
    //cout<<solve;
    while (file >> word)
    {
        if(count3==6 && count5==1){
            count5=0;
                count6=word;
        stringstream geek(count6);
    int x = 0;
    geek >> x;
    file.close();
    return x;
        }
        if(count3==0){

            if(solve==word){
                    count5=1;

                   // cout<<count4;
                  // file.close();
                    //return count5;
            }
        }
            count3++;
            if(count3==7){
                    //cout<<word;
                    count4++;
                count3=0;

        }
    }
     file.close();
    return 0;

}

int findbusid1(string solve){
    fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "bus.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    //cout<<solve;
    while (file >> word)
    {
        if(count3==1){

            if(solve==word){
                    //cout<<word;
                     file.close();
                return 1;

            }
        }
            count3++;
            if(count3==7){
                    //cout<<word;
                count3=0;

        }
    }
     file.close();
    return 0;

}

void delete_line(const char *file_name, int n){
	// open file in read mode or in mode
	ifstream is(file_name);

	// open file in write mode or out mode
	ofstream ofs;
	ofs.open("temp.txt", ofstream::out);

	// loop getting single characters
	char c;
	int line_no = 1;
	while (is.get(c))
	{
		// if a newline character
		if (c == '\n')
		line_no++;

		// file content not to be deleted
		if (line_no != n)
			ofs << c;
	}

	// closing output file
	ofs.close();

	// closing input file
	is.close();

	// remove the original file
	remove(file_name);

	// rename the file
	rename("temp.txt", file_name);
	system("cls");
	system("color C");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tDatabase will be updated after a clean restart...";Sleep(2000);
}

int extractlines(string solve){
int count1=0;
string line;
ifstream file(solve);
while (getline(file,line))
    count1++;
return count1;
}

void driver::insertnew(int line){
fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "driver.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count2=0;
    int count4=0;
   // int line2=0;
    //cout<<line;
    while (file >> word)
    {

        if(line==0){

        if(count2==0)
        did=word;
        else if(count2==1)
        dname=word;
        else if(count2==2)
        daddress=word;
        else if(count2==3)
        dnumber=word;
        else if(count2==4)
        dage=word;
//cout<<word<<"*";
        count2++;
        if(count2==5){
            count2=0;
            file.close();
            break;
        }
        }
        else{
  //              cout<<word<<" ";
            if(count4!=4){
                count4++;
            }else{
                count4=0;
            line--;
            }
        }

    }
     file.close();

}

int findbusid(string solve){
    fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "bus.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    //cout<<solve;
    while (file >> word)
    {
        if(count3==0){

            if(solve==word){
                    //cout<<word;
                     file.close();
                return 1;

            }
        }
            count3++;
            if(count3==7){
                    //cout<<word;
                count3=0;

        }
    }
     file.close();
    return 0;

}
int findbusid5(string solve){
    fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "bus.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    //cout<<solve;
    while (file >> word)
    {
        if(count3==0){
                file>>word;
        count3++;
            if(solve==word){
                    //cout<<word;
                     file.close();
                return 1;

            }
        }
            count3++;
            if(count3==7){
                    //cout<<word;
                count3=0;

        }
    }
     file.close();
    return 0;

}

int bus::insertbus(){
    string bbbb;
    string bbbk;
    string bbby="yes";
    string bbbn="no";
    start9:
        system("cls");
        system("color 03");
cout<<"\n\n\n\n\t\t\t\t\tEnter Bus's id: ";
cin>>bbbb;
int gk;
gk=findbusid(bbbb);
if(gk==1){
        system("color C");
    cout<<"\n\n\n\n\n\t\tBus's id is already present if you want to continue press 'yes' else 'no' to main menu\n\t\t\t\t-> ";
    cin>>bbbk;
    if(bbbk==bbby){
            goto start9;

    }else{
        system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tYou are being diverted to main menu...";Sleep(1000);
return 1;

    }
}
bid=bbbb;
start10:
    system("color 03");
cout<<"\n\t\t\t\t\tEnter Driver's id: ";
cin>>bbbb;
gk=findid(bbbb);
if(gk==0){
        system("color C");
    cout<<"\n\t\tDriver's id is not present if you want to continue press 'yes' else 'no' to main menu\n\t\t\t\t-> ";
    cin>>bbbk;
    if(bbbk==bbby){
            goto start10;

    }else{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tYou are being diverted to main menu...";Sleep(1000);
return 1;

    }
}
gk=findbusid5(bbbb);
if(gk==1){
        system("color C");
    cout<<"\n\t\tDriver is already allocated if you want to continue press 'yes' else 'no' to main menu\n\t\t\t\t-> ";
    cin>>bbbk;
    if(bbbk==bbby){
    goto start10;
    }else{
        system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tYou are being diverted to main menu...";Sleep(1000);
    return 1;
    }
}
system("color 03");
did=bbbb;
string str;
  cout<<"\n\t\t\t\t\tArrival time: ";
  cin>>arrival;
  cout<<"\n\t\t\t\t\tDeparture: ";
  cin>>depart;
  cout<<"\n\t\t\t\t\tFrom: ";
  cin>>from;
  cout<<"\n\t\t\t\t\tTo: ";
  cin>>to;
  were5:
  cout<<"\n\t\t\t\t\tPrice: ";
  cin>>str;
  try{
for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            throw str;
}
catch(string str){
    cout<<"\n\t\t\t\t\t"<<str<<" is not a price please type a number for price\n";
    goto  were5;
}
stringstream geek(str);
int xxxx = 0;
geek >> xxxx;
price=xxxx;
  fstream file;
    file.open ("bus.dat", ios::app);
  //cin.getline(text, sizeof(text));// Writing on file
  file <<bid<<" "<<did<<" "<<arrival<<" "<<depart<<" "<<from<<" "<<to<<" "<<price<<endl;
  file.close();
  cout<<"\n\t\t\t\t\tAdded Successfully....";Sleep(2000);
}

void bus::busshow(){

		cout<<"\n\t";
		cout<<"|      "<<bid<<"      |     "<<did<<"   |     "<<arrival<<"    |     "<<depart<<"    |      "<<from<<"      |      "<<to<<"      |      "<<price<<"      |";
		cout<<"\n\t";
		cout<<"--------------------------------------------------------------------------------------------------------";
//cout<<"\t\t|"<<setw(15)<<did<<"|"<<setw(15)<<dname<<"|"<<setw(15)<<daddress<<"|"<<setw(15)<<dnumber<<"|"<<setw(15)<<dage<<"|";
}

void bus::busshow1(){
cout<<"\n\t\t\t\t\tBus id: "<<bid;
cout<<"\tDriver's id: "<<did;
cout<<"\n\t\t\t\t\tArrival: "<<arrival;
cout<<"\tDepart: "<<depart;
cout<<"\n\t\t\t\t\tFrom: "<<from;
cout<<" | To: "<<to;
cout<<" | price: "<<price;
}

void bus::insertnew(int line){
fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "bus.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count2=0;
    int count4=0;
   // int line2=0;
    //cout<<line;
    while (file >> word)
    {

        if(line==0){

        if(count2==0)
        bid=word;
        else if(count2==1)
        did=word;
        else if(count2==2)
        arrival=word;
        else if(count2==3)
        depart=word;
        else if(count2==4)
        from=word;
        else if(count2==5)
        to=word;
        else if(count2==6){
            stringstream geek(word);

    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    geek >> x;
    price=x;
        }

//cout<<word<<"*";
        count2++;
        if(count2==7){
            count2=0;
            file.close();
            break;
        }
        }
        else{
  //              cout<<word<<" ";
            if(count4!=6){
                count4++;
            }else{
                count4=0;
            line--;
            }
        }

    }
 file.close();
}

void countbooking(string solve){
 fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "ticket.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    int count4=0;
    //cout<<solve;
    while (file >> word)
    {
        if(solve==word){
            file>>word;
       // cout<<"\nUser id: "<<word;
        file>>word;
        //cout<<"\nName: "<<word;
        file>>word;
        //cout<<"\tSeat no: "<<word;
          count4++;         // cout<<count
            }else{
            file>>word;
            file>>word;
            file>>word;

            }
        }

     file.close();
     count3=32-count4;
     cout<<"\n\t\t\t\tThe number of seats left are "<<count3;//getch();
     //return count4;
}

int countbooking1(string solve){
 fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "ticket.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    int count4=0;
    //cout<<solve;
    while (file >> word)
    {
        if(solve==word){
            file>>word;
       // cout<<"\nUser id: "<<word;
        file>>word;
        //cout<<"\nName: "<<word;
        file>>word;
        //cout<<"\tSeat no: "<<word;
          count4++;         // cout<<count
            }else{
            file>>word;
            file>>word;
            file>>word;

            }
        }

     file.close();
     count3=32-count4;
     return count3;
     //return count4;
}

void seatnumber(string uk,int i,string name,int seat){
    fstream file;
file.open ("ticket.dat", ios::app);
  //cin.getline(text, sizeof(text));// Writing on file
  file <<uk<<" "<<i<<" "<<name<<" "<<seat<<endl;
  file.close();
//cout<<"\n\t\t\t\tAdded Successfully....";Sleep(2000);

}

int seatpresent(string bid,int seat){
fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "ticket.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    //cout<<solve;
    while (file >> word)
    {

            if(bid==word){
            file>>word;
            file>>word;
            file>>word;
            stringstream geek(word);
    int x = 0;
    geek >> x;
                 if(x==seat){
                    cout<<x;
                    file.close();
                    return 1;
                            }

            }else{
            file>>word;
            file>>word;
            file>>word;
        }
    }
    file.close();
    return 0;

}

void ticketdetails(string solve){
    fstream file;
    string word, t, q, filename;
// filename of the file
    filename = "ticket.dat";
    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    //line=line*5;
    int count3=0;
    int count4=1;
    //cout<<solve;
    while (file >> word)
    {
        if(solve==word){
            file>>word;
       // cout<<"\nUser id: "<<word;
        file>>word;
        cout<<"\n\t\t\t\t\tName: "<<word;
        file>>word;
        cout<<"\tSeat no: "<<word;
                   // cout<<count
            }else{
            file>>word;
            file>>word;
            file>>word;

            }
        }

     file.close();
   // return 0;
}

void ticketprinting(users obj,bus obj1,int k){
remove("ticket.docx");
string h = obj1.did;
string h1,h2,h3,h4;
fstream file;
string word, t, q, filename;
filename = "driver.dat";
file.open(filename.c_str());
int count3=0;
while (file >> word)
{
if(word==h){
file>>word;
h1=word;
file>>word;
h2=word;
file>>word;
h3=word;
file>>word;
h4=word;
}else{
file>>word;
file>>word;
file>>word;
file>>word;
}
}
file.close();
string k2=obj.name;
//string k4=obj.name;
string k3=".docx";
//string k5=".txt";
//k5=k2+k5;
k2=k2+k3;
file.open (k2, ios::app);
  //cin.getline(text, sizeof(text));// Writing on file
  file<<"\t\t\t\t\t\t\tBUSTICKET\n";
  file<<"****************************************************************************\n";
  file<<"\t\t\t\t\t\t\tBUSDETAILS\n\n";
  file<<"Bus id: "<<obj1.bid<<"\t\t\tArrival: "<<obj1.arrival<<"\t\t\tDepart: "<<obj1.depart<<"\n";
  file<<"From: "<<obj1.from<<"\t\t\tTo: "<<obj1.to<<"\t\t\tPrice: "<<obj1.price<<"\n";
  file<<"****************************************************************************\n";
  file<<"\t\t\t\t\t\t\tDRIVERDETAILS\n\n";
  file<<"Driver id: "<<obj1.did<<"\t\t\tName: "<<h1<<"\t\t\tNumber: "<<h3<<"\n";
  file<<"\t\t\t<---ONLY USE THE DRIVER NUMBER FOR DETAILS--->\n";
  file<<"****************************************************************************\n";
  file<<"\t\t\t\t\t\t\tUSERINFO\n\n";
  file<<"User id: "<<obj.id<<"\t\t\tName: "<<obj.name<<"\t\t\tAddress: "<<obj.address<<"\n";
  file<<"Number: "<<obj.number<<"\t\t\tGender: "<<obj.gender<<"\t\t\tAge: "<<obj.age<<"\n";
  file<<"Seat: "<<k<<"\n";
  file<<"******************************************************************************\n";
  file<<"\t\t\tIT WILL BE VALID TILL THE THE DEPART TIME OF THE BUS\n";
  file<<"\t\t\t\tMAKE SURE TO GET ON THE BUS ON TIME\n";
  file.close();
  cout<<"\n\n\t\t\t\tTicket has been generated....\n";
  int yy;
cout<<"\n\t\t\tYou want to print the ticket press '0' or else press any number: ";
cin>>yy;
if(yy==0){
file.open ("ticket.docx", ios::app);
  //cin.getline(text, sizeof(text));// Writing on file
  file<<"\t\t\t\t\t\t\tBUSTICKET\n";
  file<<"****************************************************************************\n";
  file<<"\t\t\t\t\t\t\tBUSDETAILS\n\n";
  file<<"Bus id: "<<obj1.bid<<"\t\t\tArrival: "<<obj1.arrival<<"\t\t\tDepart: "<<obj1.depart<<"\n";
  file<<"From: "<<obj1.from<<"\t\t\tTo: "<<obj1.to<<"\t\t\tPrice: "<<obj1.price<<"\n";
  file<<"****************************************************************************\n";
  file<<"\t\t\t\t\t\t\tDRIVERDETAILS\n\n";
  file<<"Driver id: "<<obj1.did<<"\t\t\tName: "<<h1<<"\t\t\tNumber: "<<h3<<"\n";
  file<<"\t\t\t<---ONLY USE THE DRIVER NUMBER FOR DETAILS--->\n";
  file<<"****************************************************************************\n";
  file<<"\t\t\t\t\t\t\tUSERINFO\n\n";
  file<<"User id: "<<obj.id<<"\t\t\tName: "<<obj.name<<"\t\t\tAddress: "<<obj.address<<"\n";
  file<<"Number: "<<obj.number<<"\t\t\tGender: "<<obj.gender<<"\t\t\tAge: "<<obj.age<<"\n";
  file<<"Seat: "<<k<<"\n";
  file<<"******************************************************************************\n";
  file<<"\t\t\tIT WILL BE VALID TILL THE THE DEPART TIME OF THE BUS\n";
  file<<"\t\t\t\tMAKE SURE TO GET ON THE BUS ON TIME\n";
  file.close();

system("notepad /p ticket.docx");
}
system("cls");
system("color C");
cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tYou are being diverted to main menu..";Sleep(1500);
}

int totalincome(string solve){
fstream file;
string word, t, q, filename;
filename = "ticket.dat";
file.open(filename.c_str());
int count3=0;
int count4=0;
while (file >> word)
{
if(solve==word){
file>>word;
file>>word;
file>>word;
count4++;
}else{
file>>word;
file>>word;
file>>word;
}
}
file.close();
return count4;

}

void finduserdetails(string solve){
fstream file;
string word, t, q, filename;
filename = "users.dat";
file.open(filename.c_str());
int count3=0;
int count4=0;
while (file >> word)
{
if(solve==word){
file>>word;
cout<<"\t\t\tBus id: "<<word;
file>>word;
cout<<"\tName: "<<word;
}
else{
    file>>word;
    file>>word;
}
file>>word;
file>>word;
file>>word;
file>>word;
}
file.close();
}

void printcarddetails(){
fstream file;
string word, t, q, filename;
filename = "card.dat";
file.open(filename.c_str());
int count3=0;
int count4=0;
while (file >> word)
{
finduserdetails(word);
file>>word;
cout<<"\tcard no: "<<word;
file>>word;
file>>word;
cout<<"\tAmount paid: "<<word;
cout<<"\n";
}
file.close();
}

