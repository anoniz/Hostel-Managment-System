#include<iostream>

using namespace std;

// Prototypes..........
void allotSeat(Student s1);

////////////////////////////////////////////////////////////////////////////////////



void allotSeat(Student s1) {
    ifstream file;
    Student s2;
    file.open("test/Student",ios::binary);
    if(!file.is_open()) {cout<<"Cant Open File For Seat Allocation..\n";}
    int r = 1, s= 1;
    int chosRoom, chosSeat;
    cout<<"Please Give Room No, Where You Want Seat = "; cin>>chosRoom;
    cout<<"Please Give Seat No You Want = "; cin>>chosSeat;
    while(file.read(reinterpret_cast<char *> (&s2),sizeof(Student))) {
        // chechking for that seats availiblity
        if(s2.getRoomNo() == chosRoom && s2.getSeatNo() == chosSeat) {
            cout<<"Sorry Request Seat is Already Occupied.."<<endl;
            cout<<"Giving You "
        }
    }      s2.setRoomNo(chosRoom); s1.setSeatNo(chosSeat);
           cout<<"Seat Have Been Allocated Successfully \n";
        
}