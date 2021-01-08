 #include <iostream>
 #include<cmath>
 #include<cstring>
using namespace std;
class octa;
class hexa{
 char h[15];
  public:
   void gethex()
   {
    cout<<"enter hexadecimal number"<<endl;
    cin>>h;
    }
    friend void convert(hexa , octa);
    };
    
 class octa{
  int o;
  public:
  void getoct()
   {
    cout<<"enter octal number"<<endl;
    cin>>o;
    }
   friend void convert(hexa , octa);
    };
    
    void convert(hexa he , octa oc)
    {
    int d = 0, i = 0, rem;
    while (oc.o != 0)
    {
        rem = oc.o % 10;
        oc.o /= 10;
        d += rem * pow(8, i);
        ++i;
    }
    
    int j, r, len, hex1 = 0;
    len = strlen(he.h);
    for (j = 0; he.h[j] != '\0'; j++)
    {
        len--;
        if(he.h[j] >= '0' && he.h[j] <= '9')
            r = he.h[j] - 48;
        
        else if(he.h[j] >= 'A' && he.h[j] <= 'F')
            r = he.h[j] - 55;
        hex1 += r * pow(16,len);
    }
    cout<<"Decimal Value of given hexadecimal is :"<< hex1<<endl;
    cout<<"Decimal number of given octal is :"<<d<<endl;
    
}

int main()
{
   hexa hex;
   octa oct;
   hex.gethex();
   oct.getoct();
   convert(hex,oct);
   
   return 0;
   }
