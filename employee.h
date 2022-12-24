#include<iostream>
// #include "person.h"
using namespace std;

class Employee:public Person
{
unsigned salary,ID;
char role[50];

public:
unsigned getId();
unsigned getSal();
string getRole();
void setEmployee();
void showEmployee();

};

// Employee Class Member Function........

void Employee::setEmployee(){
cout<<endl<<"Enter new Employee data.......... \n\n";
setPerson();

cout<<"Enter the salary : ";
cin>>salary;
cout<<"Enter the role : ";
cin.ignore();
cin.getline(role,49);
}
void Employee::showEmployee(){
cout<<endl<<endl;
cout<<"Employee Info........ \n\n";
showPerson();
cout<<"Salary : "<<salary<<endl;
cout<<"Role : "<<role<<endl;
}

unsigned Employee::getId() { return ID;}
unsigned Employee::getSal() { return salary;}
string Employee::getRole() {string r1 = role; return role;}
