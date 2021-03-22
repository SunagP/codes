#include <iostream> 
using namespace std; 

class Test { 
private: 
	int data,x; 

public: 
	Test() { data = 0;x=0; } 
	int getData() { return data+x; } 
}; 

int main() 
{ 
	Test t; 
	int *ptr = (int*)&t; 
	*ptr = 10; 
    ptr++;
    *ptr = 20;
	cout << t.getData(); 
	return 0; 
}
