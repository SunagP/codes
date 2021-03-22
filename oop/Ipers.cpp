// ipers.cpp
// reads person object from disk
#include <fstream>                //for file streams
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class person                      //class of persons
   {
   protected:
      char name[80];              //person's name
      short age;                  //person's age
   public:
      void showData()             //display person's data
         {
         cout << "Name: " << name << endl;
         cout << "Age: " << age << endl;
         }
         void getData()              //get person's data
         {
         cout << "Enter name: "; cin >> name;
         cout << "Enter age: "; cin >> age;
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   person pers; 
   pers.getData();    
                 //create person variable
                                  //create ofstream object
   ofstream outfile("PERSON1.txt", ios::binary);
                                  //write to it
   // outfile.write(reinterpret_cast<char*>(&pers), sizeof(pers));  
   outfile.write((char *)(&pers), sizeof(pers));  
   ifstream infile("PERSON1.txt", ios::binary); //create stream
                                               //read stream
   infile.read( reinterpret_cast<char*>(&pers), sizeof(pers) );  
   pers.showData();                            //display person
   return 0;
   }