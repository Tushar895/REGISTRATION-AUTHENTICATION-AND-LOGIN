#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


void login();
void registration();
void forgot();


int main()
{
int c;
 cout<<"\t\t\t_______________________________________________ \n\n\n";
 cout<<"\t\t\t           Welcome to the login page           \n\n\n";
 cout<<"\t\t\t___________          MENU       _______________\n\n";
 cout<<"                                                      \n\n";
 cout<<"\t| press 1 to LOGIN                     |"<<endl;
 cout<<"\t| press 2 to REGISTER                  |"<<endl;
 cout<<"\t| press 3 If you Forgot your PASSWORD  |"<<endl;
 cout<<"\t| press 4 to EXIT                      |"<<endl;


cout<<"\n\t\t\t pls enter your choice :";
cin>>c;
cout<<endl;


switch(c)
{
    case 1: 
         login();
         break;

    case 2: 
         registration();
         break;

     case 3: 
         forgot();
         break;

     case 4: 
         cout<<"\t\t\t Thankyou! \n\n";
         break;

     default:
        system("cls");
        cout<<"\t\t\t please select from the options given below \n"<<endl;
        main();

     
}

}


void login()
{
  int count=0;
  string userID, password , id, pass;
  system("cls");
  cout<<"\t\t\t pls enter the username and password: "<<endl;
  cout<<"\t\t\t Username ";
  cin>>userID;
 cout<<"\t\t\t Password ";
  cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id==userID && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    
     input.close();

     if(count==1)
     {
         cout<<userID<<"\n Your login is successfull \n Thanks for login in ! \n";
         main();
     }
     else {
         cout<<" \n LOGIN ERROR \n please check your user name and password ";
         main();
     }
     
 }




     void registration()
     {
         string ruserID,rpassword,rid, rpass;
         system("cls");
         
         cout<<"\t\t\t Enter the username : ";
         cin>>ruserID;
         cout<<"\t\t\t Enter the password : ";
         cin>>rpassword;

         ofstream f1("records.txt", ios::app);
         //input output stream
          f1<<ruserID<<' '<<rpassword<<endl;
          system("cls");

          cout<<"\n\t\t\t Registration is successfull! \n";
          main();
        
     }



void forgot()
{
     int option ;
     system("cls");
     cout<<" \t\t\t you forgot the password ? No worries \n";
     cout<<" press 1 to search your id by username"<<endl;
     cout<<"press 2 to go back to main menu"<<endl;
     cout<<"\t\t\t Enter your choice :";
     cin>> option;


    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserID,sid,spass;
            cout<<"\n\t\t enter the username which you remembered :";
            cin>>suserID;


            ifstream f2("records.txt");
            while(f2>>sid>>spass)
            {
                  if(sid==suserID)
                  {
                    count =1;

                  }
            }

                    f2.close();
                    if(count==1)
                    {
                        cout<<"\n\n your account is found \n";
                        cout<<"\n\n Your password is: "<<spass;
                        main();
                    }
                    else{ 
                        cout<<"\n\t sorry! your account is not found \n";
                        main();
                    }

                    break;

        }


            case 2:
            {
                main();
            }


            default:
                cout<<" \t\t\t Wrong choice  ! please try again ";
                forgot();

             
    }


 }



