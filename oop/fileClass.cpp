#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class book{
  char name[20];
  int id;
  int price;
  public:
   void getdata(){
       cout<<"Enter name,id price\n";
       cin>>name>>id>>price;
   }
   book(){
       price = 0;
       id  = 0;

   }
   void print(){
       cout<<name<<" "<<id<<" "<<price;
   }
   void filewrite()
   {
       ofstream file1;
    file1.open("fileNew1.txt",ios::app|ios::binary);
    file1.write((char*)(this),sizeof(*this));
    file1.close();
   }
   void fileRead(){
       ifstream file2;
    file2.open("fileNew1.txt",ios::in|ios::binary);
    file2.read((char*)(this),sizeof(*this));
    while(!file2.eof()){
      print();
      file2.read((char*)(this),sizeof(*this));
    }
    
    file2.close();
   }
   void search(char *x){
        ifstream file2;
    file2.open("fileNew.txt",ios::in|ios::binary);
    file2.read((char*)(this),sizeof(*this));
    while(!file2.eof()){
        if(strcmp(x,name)==0);
         print();
        file2.read((char*)(this),sizeof(*this));
        
        
    }
   }
};
int main()
{
    book b1[3];
    for (int i=0;i<3;i++){
         b1[i].getdata();
        
    }
   
    for (int i=0;i<3;i++){
         
         b1[i].filewrite();
    }
    // for (int i=0;i<3;i++){
         
    //      b1[i].fileRead();
    // }
    b1[0].fileRead();
    // ofstream file1;
    // file1.open("fileNew.txt");
    // file1.write((char*)(&b1),sizeof(b1));
    // file1.close();
    
    // b2.filewrite();
    // ifstream file2;
    // file2.open("fileNew.txt");
    // file2.read((char*)(&b1),sizeof(b1));
    // b1.fileRead();
    // b1.fileRead();

    // b1.print();

    // file2.close();
    // b1.search("sunag");
}