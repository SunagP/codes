#include <iostream>
using namespace std;
class Shape
{
   public:
        float width, height;
        void set_data (float w, float h)
        {
            width = w;
            height = h;
        }
};
class Rectangle: public Shape
{
    public:
        float area()
        {
            return (width * height);
        }
};
class Triangle: public Shape
{
    public:
        float area()
        {
            return (width * height / 2);
        }
};
class Right: public Triangle
{
    public:
        int check(int h)
        {
            if((h*h)==((width*width)+(height*height)))
                return 1;
            else
                return 0;
        }
};
class Square: public Rectangle
{
    public:
        int check()
        {
            if(width==height)
                return 1;
            else
                return 0;
        }
};
int main()
{
    int h=5;
    Rectangle r;
    Triangle t;
    Right r1;
    Square s;
    s.set_data(4,4);
    r.set_data (4,4);
    t.set_data (3,4);
    r1.set_data(3,4);
    cout << "Area of Rectangle : "<<r.area() << endl;
    if(s.check()==1)
        cout<<"It is also a square"<<endl;
    else
        cout<<"Not a square"<<endl;
    cout << "Area of Triangle : "<<t.area() << endl;
    if(r1.check(h)==1)
        cout<<"It is also right angled"<<endl;
    else
        cout<<"Not right angled"<<endl;
    return 0;
}