#include<iostream>  //its like preprocessidure directives
#include<fstream>   //without using that header file we can't use classes like ofstream and ifstream
#include <string.h>
#define MAX 20
using namespace std;
class Student
{
    private:
int roll;
char name[MAX];
float percentage;
public:
 void get_data();
 void showdata();

};//class

void Student::get_data(){
    fstream f;
    f.open("abc.txt",ios::out|ios::app);

    if(!f)
    {
        std::cout<<"file creation failed..!!";
    }else{
        cout<<"Enter name : "<<endl;
        cin>>name;
        cout<<"Enter roll no. : "<<endl;
        cin>>roll;
        cout<<"Enter percentage : "<<endl;
        cin>>percentage;

        f<<name<<" ";
        f<<roll<<"\n ";
        f<<percentage<<"\n"<<endl;
        f.close();
    }
}

void Student::showdata(){
    fstream f1;
    f1.open("abc.txt",ios::in);  //opening file in input mode

    if(!f1)
    {
        cout<<"NO such file..!!";
    }else{
         f1>>name;
        f1>>roll;
        f1>>percentage;
      while(!f1.eof())  {

        cout<<name<<" \n";
        cout<<roll<<"\n ";
        cout<<percentage<<"\n"<<endl;

        f1>>name;
        f1>>roll;
        f1>>percentage;

      //  cout<<name<<" \n";
      //  cout<<roll<<"\n ";
      //  cout<<percentage<<"\n"<<endl;
      }
        f1.close();
    }
}

int main()
{
    Student s;
    fstream f;
    char c;
    do{
        cout<<"List : "<<endl;
        cout<<"\n1)write data into file  "<<endl;
        cout<<"\n2)read data from file  "<<endl;
        cout<<"\n3)Exit "<<endl;
        
        int choice;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"Student Information : "<<endl;
            cout<<"**********************"<<endl;
            s.get_data();
            cout<<"**********************"<<endl;
            break;

            case 2:
            cout<<"Student Information : "<<endl;
            cout<<"**********************"<<endl;
            s.showdata();
            cout<<"**********************"<<endl;
            break;

            case 3:
            exit(0);
            break;

            default :
            cout<<"Plz : Enter valid choice...";
            
        }
        cout<<"Do you want to continue...??";
        cin>>c;
    }while(c=='y');

 return 0;
}