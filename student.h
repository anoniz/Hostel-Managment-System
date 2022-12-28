#include<iostream>
#include<fstream>

// #include "person.h"

using namespace std;

// Prototypes........
bool findDucplicate(string path,string folder,unsigned No);

//////////////////////////////////////////////////////////////////

struct reg {
     unsigned int No = 000; 
     char degree[50],batch[10];
};

class Student:public Person {
     reg regNo;
     bool haveMess = false;
     unsigned roomNo = 0,seatNo = 0;
     public:
     //void pure(){};
     void setAll();
     void showAll();
     void setMess(bool);
     void setRoomNo(unsigned);
     void setSeatNo(unsigned);
     void setRegNo();
     reg getRegNo();
     bool getMess();
     unsigned getRoomNo();
     unsigned getSeatNo();
};

// SOME IMPORTANT STUDENT FUNCTIONS.......

void Student::setRegNo() {
    
    cout<<"Please Give Reg Number, Only: ";
    cin>>regNo.No;
}
void Student::setAll() {
      setPerson();
    cout<<"Hit Enter .....";
    cin.ignore();
    cin.clear();

    cout<<"Please Give your Degree like BSCS: ";
    cin.getline(regNo.degree,49);
    
    cout<<"Please give Your Batch, Like F21: ";
    cin.getline(regNo.batch, 9);
    
    // Setting Mess as false by defualt
    // haveMess = false;
    // roomNo = 0000;
}

void Student::showAll() {
     showPerson();
     cout<<"The Reg No is = ";
     cout<<getRegNo().No<<"-"<<getRegNo().degree<<"-"<<getRegNo().batch<<endl;
     cout<<"The Room No is = "<<getRoomNo()<<endl;
     cout<<"The Seat No is = "<<getSeatNo()<<endl;
}

void Student::setMess(bool mess) {haveMess = mess;}
void Student::setRoomNo(unsigned r) {roomNo = r;}
void Student::setSeatNo(unsigned s) { seatNo = s; }
reg Student::getRegNo() {return regNo;}
bool Student::getMess() {return haveMess;}
unsigned Student::getRoomNo() {return roomNo;}
unsigned Student::getSeatNo() {return seatNo;}




