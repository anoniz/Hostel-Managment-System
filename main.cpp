#include<iostream>
//#include "employee.h"
#include "person.h"
#include "student.h"
#include "employee.h"
#include "messItems.h"
#include "hostelItems.h"
#include "filing.h"
using namespace std;

int main () {
    unsigned size = 2;

for(int i = 0; i < 2; i++) {
  size = writeFile("Student","test/");
}

cout<<endl<<"reading file" <<"i m size "<<size<<endl;

readFile("Student","test/",size);

}