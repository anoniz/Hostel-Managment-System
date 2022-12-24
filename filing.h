#include<iostream>
#include<fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
// Prototypes..............

void * sort(unsigned, string,void *);
void writeBackToFile(string path,string folder, unsigned size,void *sortedArr);

    
/////////////////////////////////////////////////////////////////////////////////
unsigned writeFile(string path,string folder) {
    //  findDucplicate(path, folder);
     ofstream file;
     const char * fileName = (folder + path + ".dat").c_str();
     string p = folder + path + ".dat";
     cout<<" i am p in write func "<<endl;    
     file.open(fileName,ios::app | ios::binary);
     if(!file.is_open()) { cout<<"Cant Open File "<<endl; return 0;}

     int size = 0;

       if(path == "Student"){
        // Student s1;
        //s1.setAll();
         //file.write(reinterpret_cast<char*>(&s1),sizeof(s1)); 
         size = file.tellp()/sizeof(Student);
         cout<<" i m size before file close "<<size<<endl;
          file.close();
         if(size <= 1) { cout<<"Only one obj in file cant sort \n"; return size;} 
         Student Arr[size]; 
         for(int i = 0; i < size; i++) {
              ifstream file;
              file.open(fileName, ios::binary);
              if(!file.is_open()) {cout<<"cant open file in read \n"; return size;}
              file.read(reinterpret_cast<char *>(&Arr[i]),sizeof(Student));
         }    
         void *any = &Arr;
         void *sortedArr = sort(size,path,any);
         writeBackToFile(path,folder,size,sortedArr);
     }
     else if(path == "Employee") {
        Employee s1;
       // s1.set();
        file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "HostelItems") {
        HostelItems s1;
        //s1.set();
        file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "MessItems") {
        // MessItems s1;
        // s1.set();
        //file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }    
        return size;
}

void* sort(unsigned size , string obj,void *any) {
    //assigning array with objs,,,,,,,
    cout<<"inside sort function  "<<endl;
    Student *std = new Student[size];
    Employee *emp = new Employee[size];
    Student *s1 = (Student *)any;
    Employee *p1 = (Employee *)any;

    for(int i = 0; i<size; i++) {
      cout<<" i  m III "<<i<<endl;
         std[i] = *(s1+i);
         std[i].showAll();
    }
    //sorting the array of objects,,,,
    
    void *ptr;
      for(int i = 0; i <size-1; i++) {
      for(int j = 0; j < size-1; j++) {
         if(obj == "Student") {
             cout<<endl<<endl<<"i am in sort "<<endl;
         Student temp = std[j];
         cout<<" i m reg no i "<<std[j].getRegNo().No<<"  --- i m reg no i+ "<<std[j+1].getRegNo().No<<endl;
         if(std[j].getRegNo().No > std[j+1].getRegNo().No) {
            
         std[j] = std[j+1];
         std[j+1] = temp;
        
         
         ptr = std;
      }
          else if(obj == "Employee") {
            Employee temp = emp[j];
            if(emp[j].getId() > emp[j+1].getId()) {
                emp[j] = emp[j+1];
                emp[j+1] = temp;
                

                ptr = emp;
            }
          }
      }
   }
       return ptr;      
}  
     return ptr;
}

void writeBackToFile(string path,string folder, unsigned size,void *sortedArr) {
      ofstream file;
      cout<<"inside writebacl file function  "<<endl;
      cout<<" i m  size inside write bak "<<size<<endl;
      const char * fileName = (folder + path + ".dat").c_str();
      string p = folder + path + ".dat";
      cout<<" i m p in  write back file "<<p<<endl;
      file.open(fileName,ios::app | ios::binary);
      if(!file.is_open()) { cout<<"Cant Open File "<<endl; return;}

     Student *s1 = (Student *)sortedArr;
     
      //(s1)->showAll();
     Employee *p1 = (Employee *)sortedArr;
     Student std[size];
     Employee emp[size];
     for(int i = 0; i < size; i++) {
        
        cout<<"write bakc file func   loop "<<endl;
        if(path == "Student") {
            (s1+i)->showAll();
            cout<<"after assin  "<<endl;
            file.write(reinterpret_cast<char *> (&std[i]),sizeof(Student));     
        }
          else if(path == "Employee") {
            emp[i] = *(p1+i);
            file.write(reinterpret_cast<char *> (&emp[i]),sizeof(Person)); 
          }
     }
}


unsigned readFile(string path,string folder,unsigned size) {
    
     ifstream file;
     const char * fileName = (folder + path + ".dat").c_str();
      string p = folder + path + ".dat";
     cout<<" i m file name in readfile "<<p<<endl;
     string k = fileName;
      cout<<" i m file name in readfile "<<k<<endl;

     file.open(fileName, ios::binary);
     if(!file.is_open()) {
        cout<<"cant open file "<<endl;
        return 0;
     }
     for(int i = 0; i < size; i++) {
      if(path == "Student"){
         Student s1;
        file.read(reinterpret_cast<char*>(&s1),sizeof(s1));
        s1.showAll();
        cout<<endl;
     }
     else if(path == "Employee") {
        Employee s1;
        file.read(reinterpret_cast<char*>(&s1),sizeof(s1));
       // return s1.getId();
     }
     else if(path == "HostelItems") {
        HostelItems s1;
       
        file.read(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "MessItems") {
      //  MessItems s1;
       
        //file.read(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
       }
       return 0;
}

bool findDucplicate(string path,string folder,string any,unsigned tellp) {
    //readFile(path, folder);
     return false;
}


void updateFile(string path,string folder) {
    //  findDucplicate(path, folder);
     ofstream file;
     const char * fileName = (folder + path + ".dat").c_str();
     file.open(fileName,ios::app | ios::binary);
     int size;
     if(path == "Student"){
         Student s1;
         //s1.set();
         file.write(reinterpret_cast<char*>(&s1),sizeof(s1)); 
        size = file.tellp()/sizeof(Student);
         Student Arr[size];
        // void *ptr = sort(size,"Student");
     }
     else if(path == "Employee") {
        Employee s1;
       // s1.set();
        file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "HostelItems") {
        HostelItems s1;
        //s1.set();
        file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "MessItems") {
        // MessItems s1;
        // s1.set();
        //file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }    
}



void deleteFile(string path,string folder) {
    //  findDucplicate(path, folder);
     ofstream file;
     const char * fileName = (folder + path + ".dat").c_str();
     file.open(fileName,ios::app | ios::binary);
     int size;
     if(path == "Student"){
         Student s1;
         //s1.set();
         file.write(reinterpret_cast<char*>(&s1),sizeof(s1)); 
        size = file.tellp()/sizeof(Student);
         Student Arr[size];
         //void *ptr = sort(size,"Student");
     }
     else if(path == "Employee") {
        Employee s1;
       // s1.set();
        file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "HostelItems") {
        HostelItems s1;
        //s1.set();
        file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "MessItems") {
        // MessItems s1;
        // s1.set();
        //file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }    
}


void searchFile(string path,string folder) {
    //  findDucplicate(path, folder);
     ofstream file;
     const char * fileName = (folder + path + ".dat").c_str();
     file.open(fileName,ios::app | ios::binary);
     int size;
      if(path == "Student"){
         Student s1;
         //s1.set();
         file.write(reinterpret_cast<char*>(&s1),sizeof(s1)); 
         size = file.tellp()/sizeof(Student);
         Student Arr[size];
         //void *ptr = sort(size,"Student");
     }
     else if(path == "Employee") {
        Employee s1;
       // s1.set();
        file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "HostelItems") {
        HostelItems s1;
        //s1.set();
        file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "MessItems") {
        // MessItems s1;
        // s1.set();
        //file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }    
}
