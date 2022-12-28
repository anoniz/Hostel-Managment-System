#include<iostream>
using namespace std;

class Person {
    protected:
    char name[50] ,gender[10];
    unsigned age; unsigned long cnic;
    public:
   // void virtual pure() {};
    void setPerson();
      string  getName();
      string  getGender();
     unsigned getAge();
     unsigned long getCnic();
     void showPerson();

};
// Person Class Member Functions....

void Person::setPerson() {
    cout<<"Hit Any Key........ "<<endl;
    cin.ignore();
    cin.clear();
    
    cout<<"Enter Name: ";
    cin.getline(name,49);
    cout<<"Enter Gender: ";
    cin.getline(gender,9);
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter CNIC: ";
    cin>>cnic;
}

void Person::showPerson() {
    cout<<"The Name is = "<<name<<endl;
    cout<<"The Age is = "<<age<<endl;
    cout<<"The Gender is = "<<gender<<endl;
    cout<<"The CNIC is = "<<cnic<<endl;
}
string Person::getName() { string s1 = name; return s1;}
string Person::getGender() {string s1 = gender; return s1;}
unsigned Person::getAge() {return age;}
unsigned long Person::getCnic() {return cnic;}