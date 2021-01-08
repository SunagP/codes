#include <iostream>
using namespace std;

class PersonData 
{
    public :
        string lastName, firstName, address, city, state;
        string phoneNo;
        void readData();
        void dispData();
};

void PersonData::readData()
{
    cout << "\n Enter details for the Person : ";
    cout << "\n First Name and Last Name : ";
    cin >> firstName >> lastName;
    cout << "Address, City, state : ";
    getline(cin, address);
    cin >> city >> state;
    cout << "Phone NO. : ";
    cin >> phoneNo;
}

void PersonData::dispData()
{
    cout << "\n First Name : " << firstName;
    cout << "\n Last Name  : " << lastName;
    cout << "\n Address    : " << address;
    cout << "\n City       : " << city;
    cout << "\n state      : " << state;
    cout << "\n Phone No.  : " << phoneNo;
}

class ConsumerData : public PersonData
{
    private :
        string emailId;
        int consumerNumber;
    
    public :
        void InData();
        void OutData();
};

void ConsumerData::InData()
{
    cout << "\n Enter Consumer details -> ";
    cout << "\n Enter Consumer NO. : ";
    cin >> consumerNumber;
    cout << "Enter Email ID : ";
    cin>>emailId;
}

void ConsumerData::OutData()
{
    cout << "\n Consumer Details : ";
    cout << "\n Enter Consumer NO. : " << consumerNumber;
    cout << "\n Email ID          : " << emailId;
}

int main()
{
    ConsumerData obj;
    obj.InData();
    obj.readData();
    obj.OutData();
    obj.dispData();
    return 0;
}