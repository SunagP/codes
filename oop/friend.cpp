#include <iostream>
   using namespace std;
   class loc {
     int longitude, latitude;
   public:
     loc() {}
     loc(int lg, int lt) {
       longitude = lg;
       latitude = lt;
     }
     void show() {
       cout << longitude << " ";
       cout << latitude << "\n";
    }
     loc operator=(loc op2);
   // friend void operator++(loc &op);
    friend loc operator++(loc &op);
    // friend loc operator--(loc &op);
      friend void operator--(loc &op);
      friend loc operator++(loc &op,int);
};

// Overload assignment for loc.
   loc loc::operator=(loc op2)
   {
     longitude = op2.longitude;
     latitude = op2.latitude;
     return *this; // i.e., return object that generated call
   }
   
   // Now a friend; use a reference parameter.
     
      loc operator++(loc &op)
      {
      ++op.longitude;
      ++op.latitude;
      return op; 
      
    }
    loc operator++(loc &op,int)
      {
     // op.longitude++;
      //op.latitude++;
      return loc(op.longitude++,op.latitude++); 
      
    }


   // Make op-- a friend; use reference.
  void operator--(loc &op)
  // loc operator--(loc &op)
   {
     op.longitude --;
     op.latitude--;
   //  return op; 

 }

int main() {
    loc ob1(10,20);
     loc ob2;
     ob1.show();// displays 10 20
     ++ob1;
     
      ob1.show();// displays 11 21
      ob2=ob1++;
      ob2.show();// displays 11 21
      ob2 = ++ob1;
     ob2.show(); // displays 13 23
    --ob2;
   ob2.show(); // displays 12 22
     return 0;
 
 }