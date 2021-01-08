#include<iostream>
using namespace std;

class person{
 
  public:
  //char name[10],address[20];
  string name,address;
  float sal=10000.0;
  //void display();
  //void readPerson();

  private:
  char pin[5];

};

class Restaurent{

    private :
    int investment;
    float shares;
    public:
    //void recipe();

};

int main(){

  person p1,p2;

  p1.name="sunag";
  p1.address="Bangalore";
  cout<<p1.name<<endl<<p1.address<<endl;
  cout<<p1.sal;

}

