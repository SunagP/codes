#include<iostream>
#include<math.h>
using namespace std;
class HyperLoop
{
    public:
        int convoyFrequency=2; 
        int normalFrequency=2; 
        int curPassengers=0;
        float passengersPerFrequency=2;
        int passengerMinThreshold=3;
        int passengerMaxThreshold=5;
        void changeFrequency();

};
void HyperLoop::changeFrequency()
{
    int temp=convoyFrequency;
    if(curPassengers>passengerMaxThreshold)
    {
        temp = normalFrequency+ceil((curPassengers-passengerMaxThreshold)/passengersPerFrequency);
    }
    if(convoyFrequency>normalFrequency)
    {
        if(curPassengers<passengerMaxThreshold+(convoyFrequency-normalFrequency)*passengersPerFrequency)
        {
            temp=convoyFrequency-floor(passengerMaxThreshold+(convoyFrequency-normalFrequency)*passengersPerFrequency-curPassengers)/passengersPerFrequency;
        }
    }
    else if(convoyFrequency<normalFrequency)
    {
        if(curPassengers>=passengerMinThreshold)
        {
            temp=normalFrequency;
        }
    }
    if(temp!=convoyFrequency)
    {
        if(temp<2)
        {
            convoyFrequency=2;
        }
        else
        {
            convoyFrequency=temp;
        }
        cout<<" Frequency changed to - "<<convoyFrequency<<endl;
    }
}
struct pod
{
    vector<string> seats;
    int maxSeats=1;
    int currentSeat=-1;
    bool isFull=false;
    pod()
    {
        seats = vector<string>(2);
    }
};

struct ticket
{
    int ticketId=-1;
    int source=-1,destination=-1;
    int convoyNo=-1,podNo=-1,seatNo=-1;
    string userName="";
    ticket()
    {

    }
    ticket(int id,int s,int d,int cn,int pn,int sn,string userName)
    {
        ticketId=id;
        source=s;
        destination=d;
        convoyNo=cn;
        podNo=pn;
        seatNo=sn;
        this->userName=userName;
    }
};

class convoy
{
    private:
        int currentPod;
        int maxPod;
    public:
        vector<pod> pods;
        convoy()
        {
            currentPod=-1;
            maxPod=2;
            pods=vector<pod>(3);
        } 
        int getPod()
        {
            if(pods[currentPod].isFull)
            {
                currentPod++;
                pod p=pod();
                pods[currentPod]=p;
                pods[currentPod].currentSeat++;
                if(pods[currentPod].currentSeat==pods[currentPod].maxSeats)
                {
                    pods[currentPod].isFull=true;
                }
            }
            else if(!pods[currentPod].isFull)
            {
                pods[currentPod].currentSeat++;
                if(pods[currentPod].currentSeat==pods[currentPod].maxSeats)
                {
                    pods[currentPod].isFull=true;
                }
            }
            //cout<<"hi"<<endl;
            return currentPod;
        }
        bool isFull()
        {
            if(currentPod==maxPod-1)
            {
                return true;
            }
            return false;
        }
};

class passenger
{
    private:
        string userName;
        string email;
        string phoneNo;
        string cardId="";
        int cardAmt;
        vector<ticket*> tickets;
        // ticket tickets[5];
    public:
    passenger()
    {
        tickets=vector<ticket*>(5);
    }
        passenger(string name,string email,string phoneNo)
        {
            tickets=vector<ticket*>(5);
            this->userName=name;
            this->email=email;
            this->phoneNo=phoneNo;
        }
        string getUserName()
        {
            return userName;
        }
        void swipe();
        bool reqCancelTicket(int ticketId);
};