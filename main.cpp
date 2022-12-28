#include<iostream>

//#include "employee.h"
#include "person.h"
#include "student.h"
#include "employee.h"
#include "messItems.h"
#include "hostelItems.h"
#include "filing.h"
//#include "admin.h"

using namespace std;




int main () {
    unsigned size = 2;

for(int i = 0; i < 1; i++) {
  size = writeFile("Student","test/");
}


//deleteFile("Student","test/",4545);
//searchById("Student","test/",1);
// cout<<endl<<"reading file" <<"i m size "<<size<<endl;

readFile("Student","test/");





// unsigned choise = 0;
// cout<<" ____________________________________________________________________"<<endl;
// cout<<"|_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_|"<<endl;

// cout<<"\t I I U I    H O S T E L     M A N A G E M E N T     S Y S T E M  \n\n\n";


// cout<<"\t\t 1. I am Student... \n"<<endl;
// cout << 
// cout<<"\t\t 2. I am Administrator...\n"<<endl;
// cout<<"\t\t 3. I Just Wanna Visit Hostels .....\n"<<endl;
// cout<<"\t\t 4. Close The Program....\n"<<endl;

// cout<<"Type Apropriate Number "<<endl;
// cin>>choise;
// switch(choise) {
//     case 1: {

//     } break;
//     case 2: {

//     } break;
//     case 3: {

//     } break;
//     case 4: {
//         break;
//     }
//     default: {

//     } break;
// }


}