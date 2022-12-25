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

     file.open(fileName,ios::app | ios::binary);
     if(!file.is_open()) { cout<<"Cant Open File "<<endl; return 0;}
     int size = 0;

       if(path == "Student"){
         Student s1;
        
         s1.setRegNo();
         if(findDucplicate("Student","test/",s1.getRegNo().No)) {
            cout<<"Reg No Already Exists... "<<endl; return size;
         }
         cout<<" ok fine "<<endl; return size;
         s1.setAll();
         file.write(reinterpret_cast<char*>(&s1),sizeof(s1)); 
         size = file.tellp()/sizeof(Student);
          file.close();
         if(size <= 1) { cout<<"Only one obj in file cant sort \n"; return size;} 
         Student *Arr = new Student[size]; 
         ifstream file;
         file.open(fileName, ios::binary);
         if(!file.is_open()) {cout<<"cant open file in read \n"; return size;}
         for(int i = 0; i < size; i++) {
            file.read(reinterpret_cast<char *>(Arr+i),sizeof(Student));        
         } 
         
         void *any = Arr;
         void *sortedArr = sort(size,path,any);
        // return size;
         writeBackToFile(path,folder,size,sortedArr);
         return size;
     }

     else if(path == "Employee") {
        Employee s1;
       // s1.set();
        file.write(reinterpret_cast<char*>(&s1),sizeof(s1));

         size = file.tellp()/sizeof(Employee);
         cout<<" i m size before file close "<<size<<endl;
          file.close();
         if(size <= 1) { cout<<"Only one obj in file cant sort \n"; return size;} 
         Employee *Arr = new Employee[size]; 
         ifstream file;
         file.open(fileName, ios::binary);
         if(!file.is_open()) {cout<<"cant open file in read \n"; return size;}
         for(int i = 0; i < size; i++) {
            file.read(reinterpret_cast<char *>(Arr+i),sizeof(Employee));        
         } 
         
         void *any = Arr;
         void *sortedArr = sort(size,path,any);
        // return size;
         writeBackToFile(path,folder,size,sortedArr);
         return size;
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
   
    Employee *p1 = static_cast<Employee *>(any);
    Student *s1 = static_cast<Student *>(any);
    
     void *ptr;
      for(int i = 0; i <size-1; i++) {
      for(int j = 0; j < size-1; j++) {
         if(obj == "Student") {
         Student temp = *(s1+j);
         
         if((s1+j)->getRegNo().No > (s1+j+1)->getRegNo().No) {
            (*(s1+j)) = (*(s1+j+1));
            (*(s1+j+1)) = (temp);
                    
           ptr = s1;
      }
         //  else if(obj == "Employee") {
         //    Employee *temp = p1+j;
         //    if(emp[j].getId() > emp[j+1].getId()) {
         //        emp[j] = emp[j+1];
         //        emp[j+1] = temp;
            
         //        ptr = p1;
         //    }
         //  }
      }
   }     
}  
      return ptr;
}

void writeBackToFile(string path,string folder, unsigned size,void *sortedArr) {
      ofstream file;
      const char * fileName = (folder + path + ".dat").c_str();
      string p = folder + path + ".dat";

      file.open("test/s1.dat", ios::binary);
      if(!file.is_open()) { cout<<"Cant Open File "<<endl; return;}
      Student *s1 = static_cast<Student *>(sortedArr);
      Employee *p1 = static_cast<Employee *>(sortedArr);

     for(int i = 0; i < size; i++) {
        if(path == "Student") {
            file.write(reinterpret_cast<char *> (s1+i),sizeof(Student));     
        }
          else if(path == "Employee") {
            file.write(reinterpret_cast<char *> (p1+i),sizeof(Person)); 
          }
     }
}

unsigned readFile(string path,string folder) {
    
     ifstream file;
     const char * fileName = (folder + path + ".dat").c_str();
      string p = folder + path + ".dat";

     file.open(fileName, ios::binary);
     if(!file.is_open()) {
        cout<<"cant open file "<<endl;
        return 0;
     }
    
      if(path == "Student"){
         Student s1;
       while(file.read(reinterpret_cast<char*>(&s1),sizeof(s1))) {
            s1.showAll();
            cout<<endl;
       }
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
       
       return 0;
}

bool findDucplicate(string path,string folder,unsigned No) {
     ifstream file;
     const char * fileName = (folder + path + ".dat").c_str();
     string p = folder + path + ".dat";
     
     file.open(fileName,ios::app | ios::binary);
     if(!file.is_open()) {cout<< "cant open file "<<endl; return true;}
     if(path == "Student") {
         Student s1;
         while(file.read(reinterpret_cast<char *> (&s1),sizeof(Student))) {
            if(s1.getRegNo().No == No) {return true;}
        } 
           return false;
     }
   return false;
}

void updateFile(string path,string folder) {
    //  findDucplicate(path, folder);
     ofstream file;
     const char * fileName = (folder + path + ".dat").c_str();
     string p = folder + path + ".dat";

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

void deleteFile(string path,string folder,unsigned id) {
   
    //  findDucplicate(path, folder);
     ifstream file;
     ofstream file1;
     const char * fileName = (folder + path + ".dat").c_str();
     string p = folder + path + ".dat";

     file.open(fileName, ios::binary);
     file1.open("test/temp.dat", ios::app | ios::binary);
     int match = 0;
     if(path == "Student"){
         Student s1;

         while(file.read(reinterpret_cast<char*>(&s1),sizeof(s1))) {
            if(s1.getRegNo().No != id) {
               s1.showAll();
              file1.write(reinterpret_cast<char*>(&s1),sizeof(s1));
            }
         }
         file.close();
         if(match) {
            ofstream file;
            // file.open();
         }
        
        // Student Arr[size];
         //void *ptr = sort(size,"Student");
     }
     else if(path == "Employee") {
        Employee s1;
       // s1.set();
        file1.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "HostelItems") {
        HostelItems s1;
        //s1.set();
        file1.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }
     else if(path == "MessItems") {
        // MessItems s1;
        // s1.set();
        //file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
     }    
}

void searchById(string path,string folder,unsigned id) {
    //  findDucplicate(path, folder);
     ifstream file;
     const char * fileName = (folder + path + ".dat").c_str();
     string p = folder + path + ".dat";

     file.open("test/Student.dat", ios::binary);
     int size;
      if(path == "Student"){
        Student s1;
         while(file.read(reinterpret_cast<char*>(&s1),sizeof(s1))) {
            if(s1.getRegNo().No == 3) {s1.showAll(); return;}
         }
           cout<<"Student Not Found "<<endl;
    }

     else if(path == "Employee") {
        Employee s1;
         while(file.read(reinterpret_cast<char*>(&s1),sizeof(s1))) {
            if(s1.getId() == 3) {s1.showEmployee(); return;}
         }
           cout<<"Employee Not Found "<<endl;
    }

   //   else if(path == "HostelItems") {
   //      HostelItems s1;
   //      //s1.set();
   //      file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
   //   }
   //   else if(path == "MessItems") {
   //      // MessItems s1;
   //      // s1.set();
   //      //file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
   //   }    
}


void searchByRoom(string path,string folder,unsigned roomNo) {
    //  findDucplicate(path, folder);
     ifstream file;
     const char * fileName = (folder + path + ".dat").c_str();
     string p = folder + path + ".dat";

     file.open("test/Student.dat", ios::binary);
     int size;
      if(path == "Student"){
        Student s1;
         while(file.read(reinterpret_cast<char*>(&s1),sizeof(s1))) {
            if(s1.getRoomNo() == roomNo) {s1.showAll();}
         }
           cout<<"No One Found, Room is Empty "<<endl;
    }
}