#include <iostream>
#include <fstream>

using namespace std;

int main(){

  char text[200];

  ofstream file1;
  file1.open ("example1.txt");

  cout << "Write text to be written on file." << endl;
  cin.getline(text, sizeof(text));
  // cin>>text;
  // file1<<text << endl;
  // Writing on file
  file1 << text << endl;
  cout<<"enter age\n";
  cin>>text;
  file1<<text << endl;
  cout<<"enter height\n";
  cin>>text;
  file1<<text;
  file1.close();
  // Reding from file
  ifstream file2;
  file2.open ("example1.txt");
  file2 >> text;
  cout << text << endl;
  file2 >> text;
  cout << text << endl;
  file2 >> text;
  cout << text << endl;

  //closing the file
  file2.close();
  return 0;
}