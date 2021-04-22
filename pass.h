#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
//#include "welcome
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include <bits/stdc++.h>
#include <sstream>


using namespace std;
static int kkk=5;

string getfilepass(){

 // filestream variable file
    fstream file;
    string word, t, q, filename;

    // filename of the file
    filename = "password.dat";

    // opening file
    file.open(filename.c_str());

    // extracting words from the file
    while (file >> word)
    {
        // displaying content
        return word;
    }

}
string getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=8;
  const char RETURN=13;

  string password;
  unsigned char ch=0;

  //cout <<prompt<<"\t\t\t\t";

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else if(ch==0 || ch==224) // handle escape sequences
         {
             getch(); // ignore non printable chars
             continue;
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

int password(){
    int jjj=1;
const string correct_password=getfilepass();
const char *yes="yes";
    while(jjj){
    system("color 03");
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tPlease enter the password or 'yes' to go back to main menu\n\t\t\t\t\t\t->";
    start1:
  string password=getpass("",true); // Show asterisks
  if(password==yes){
        kkk=5;
    return 2;
  }
  if(password==correct_password){
      //cout <<"Correct password"<<endl;
      kkk=5;
      //jjj=0;
      return 1;
      //inter();
      }
  else{

        while(kkk){
      cout <<"\n\n\n\t\t\t\tIncorrect password.";Sleep(1000);
      system("cls");
      --kkk;
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t If You Want to Quit then type: yes or you have only "<<kkk<<" chances \n\t\t\t\t\t\t->";
      if(kkk==0){
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t You have entered the password 5 times wrong ";
      cout<<"\n\n\t\t\t You are going to be diverted to main menu";Sleep(3000);
      kkk=5;
        return 2;
      }
      goto start1;

      //if(jkl=='1')
        //ending();
  }

    }


}
}

int changepass(){
    start2:
        system("cls");
        system("color C");
cout<<"\n\n\n\n\n\t\t\t\tPlease enter the password for confirmation \n\t\t\t\t\t\t->";Sleep(400);
const string passwordconfirm=getpass("",true);
const string passwordconfirm1=getfilepass();
if(passwordconfirm==passwordconfirm1){

    cout<<"\n\t\t\t\tYour Current Password is: "<<passwordconfirm1<<"\n";
    Sleep(400);
    cout<<"\n\t\t\t\tEnter The New Password:";
    char text[200];
    cin>>text;
     fstream file;
  file.open ("password.dat", ios::out);
  //cin.getline(text, sizeof(text));// Writing on file
  file << text << endl;
  file.close();
  system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tPassword has been changed";Sleep(400);
  cout<<"\n\t\t\t\tYou Will Be Diverted To Main Menu";Sleep(3000);
  return 1;
}else{
    system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tPassword is Wrong Please Try Again:";Sleep(3000);
goto start2;
return 0;
}
}


