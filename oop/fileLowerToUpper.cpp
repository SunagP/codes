#include<fstream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<conio.h>
using namespace std;
int main() {
    char c, u;
    char fname[10];
    
    ofstream out;
    // cout << "Enter File Name:";
    // cin>>fname;
    out.open("filetry.txt");
    cout << "Enter the text(Enter # at end)\n"; //write contents to file
    while ((c = getchar()) != '#') {
        // if(c>'a'&&c<'z')
          u = c - 32;
        //   else
        //    u = c;
        // out << u;
        out.write((char *)(&u),sizeof(u));
    }
    out.close();
    ifstream in("filetry.txt",ios::out); //read the contents of file
    cout << "\n\n\t\tThe File contains\n\n";
    while (!in.eof()) {
        // in.get(c);
        in.read((char *)(&c),sizeof(c));
        // if(c>'a' && c<'z')
        //  u = c-32;
        cout << c;
    }
    return 0;

}