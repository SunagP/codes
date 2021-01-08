#include<iostream>
using namespace std;

class book{
    public:
    float price;
    int pages;
    book():price(0.00),pages(0){};
    book(float pr ,int pa):price(pr),pages(pa){}
    void show()
    {
        cout<<"price "<<price<<endl<<"pages "<<endl<<pages;
    }

};
int main()
{
   book b1(45.2,50);
   book b2(75.2,25);

   b1.show();
   b2.show();

   return 0;

}
