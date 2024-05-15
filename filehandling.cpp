
#include <iostream>
#include <fstream>
#include <windows.h>
// windows.h -> we are going to use sleep function from headerfile
/* sleep -> pause execution of current thread for specific time*/
using namespace std;

class Student
{
private:
    string Rollno, Name, Grade;

public:
    // default ctor

    Student() : Rollno(""), Name(""), Grade("") {}

    setrollno(string rollno)
    {
        Rollno = rollno;
    }

    setname(string name)
    {
        Name = name;
    }

    setgrade(string grade)
    {
        Grade = grade;
    }

    string getrollno()
    {
        return Rollno;
    }

    string getname()
    {
        return Name;
    }

    string getgrade()
    {
        return Grade;
    }
};

int main()
{
    Student s;
    bool exit = false;

    while(!exit)
    {
        system("cls");
/*The system("cls"); command in C++ is used to clear the console screen on
 Windows operating systems. It’s a way to refresh the console window by removing all the previous output*/
    
    int choice;

    cout<<"\tWelcome to Student Report Card System"<<endl;
    cout<<"\t*****************"<<endl;
    cout<<"\t1.Report card"<<endl;
    cout<<"\t2.Exit"<<endl;
    cout<<"\tenter the choice"<<endl;
    cin>>choice;

    if(choice==1){
        system("cls");
        string rollno,name;

        cout<<"\tenter the roll no of student"<<endl;
        cin>>rollno;
        s.setrollno(rollno);

        cout<<"\tenter the Name of student"<<endl;
        cin>>name;
        s.setname(name);

        int maths,english,science,total,avg;
        cout<<"\tenter the mark in maths : ";
        cin>>maths;
        cout<<"\tenter the mark in english : ";
        cin>>english;
        cout<<"\tenter the mark in science : ";
        cin>>science;

        system("cls");  //prev op display na ho isiliye

        cout<<"\t Student Report card"<<endl;
        cout<<"\t********************"<<endl;

        total = maths+science+english;
        cout<<"\ttotal marks of student is : "<<total<<endl;
        avg = total/3;        
        cout<<"\tavg marks of student is : "<<avg<<endl;   

        if(avg>=90 && avg<=100){
            s.setgrade("A+");
        } 
        else if(avg>=75 && avg<90){
            s.setgrade("A");
        }
        else if(avg>=60 && avg<75){
            s.setgrade("B");
        }    
        else if(avg>=38 && avg<60){
            s.setgrade("c");
        }
        else{
            s.setgrade("F");
        }
        
        cout<<"\t the grade of student : "<<s.getgrade()<<endl;

        ofstream out("E:/student.txt",ios::app);//file name ->out
        //ios::app(append) -> if not included ,the prev student record get deleted and save curr one
        
        out<<"\t"<<s.getrollno()<<" : "<<s.getname()<<" : "<<s.getgrade()<<endl<<endl;
        out.close();
        cout<<"\t report card is saved to file"<<endl;
        Sleep(10000);//pause of 10 sec[enter value in milsecond]
    } 
    else if(choice==2){
        system("cls");
        exit = true;
        cout<<"\tEXITING............"<<endl;
        Sleep(3000);
    }   

    
    }
}