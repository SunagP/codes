#include <bits/stdc++.h>
#include "Hyperloop.h"
using namespace std;
HyperLoop H;
map<string, pair<int, int>> m1;
class admin : public HyperLoop
{
private:
    map<passenger *, string> users;
    vector<convoy *> convoys;
    static int currentConvoy;
    static int maxConvoys;
    vector<string> stations;

public:
    string u = "admin";
    string ps = "password";
    admin()
    {
        // convoys=vector<convoy>(1);
        convoys = vector<convoy *>(3);
        convoy c;
        convoys.push_back(&c);
        currentConvoy = 0;
    }
    int login(string userName, string password);
    void registration();
    void displayStations();
    static vector<int> getCurrentDetails();
    static void allot(int source, int destination, int ticketID, string passengerId, ticket &t);
    bool verify(string userName, string password);
    friend class ticketIssuer;
};
admin A;
int admin::currentConvoy = -1;
int admin::maxConvoys = 1;

vector<int> admin::getCurrentDetails()
{
    vector<int> a(3);
    a[1] = A.convoys[currentConvoy]->getPod();
    if (currentConvoy == maxConvoys)
    {
        if (A.convoys[currentConvoy]->isFull())
        {
            if (A.convoys[currentConvoy]->pods[a[1]].isFull)
            {
                return {-1};
            }
        }
    }
    a[0] = currentConvoy;
    a[2] = A.convoys[currentConvoy]->pods[a[1]].currentSeat;
    return a;
}
string userId = "user1";
void admin::registration()
{
    string name, email, phoneNo, password, confirm;
    cout << " Enter name - ";
    cin >> name;
    cout << " Enter email - ";
    cin >> email;
    cout << " Enter phone number - ";
    cin >> phoneNo;
    bool matched = false;
    do
    {
        cout << " Enter password - ";
        cin >> password;
        cout << " Confirm password - ";
        cin >> confirm;
        if (password == confirm)
        {
            passenger *p = new passenger(name, email, password);
            users[p] = password;
            matched = true;
        }
        else
        {
            cout << " Passwords do not match " << endl;
        }
    } while (!matched);
}
int admin::login(string userName, string password)
{
    for (auto i : users)
    {
        passenger *p1 = i.first;
        string name = p1->getUserName();
        if (name == userName)
        {
            if (i.second == password)
            {
                userId = userName;
                cout << " Login successful!" << endl;
                return true;
            }
            else
            {
                cout << " Password incorrect" << endl;
                return false;
            }
        }
    }
    return 2;
}

void admin::allot(int source, int destination, int ticketId, string passengerId, ticket &t)
{
    vector<int> a = admin::getCurrentDetails();
    if (a[0] == -1)
    {
        cout << " Full" << endl;
        return;
        // return NULL;
    }
    t.ticketId = ticketId;
    t.source = source;
    t.destination = destination;
    t.convoyNo = a[0];
    t.podNo = a[1];
    t.seatNo = a[2];
    t.userName = passengerId;
}

class ticketIssuer
{
private:
    vector<pair<ticket *, string>> tickets;
    int ticketId;

public:
    ticketIssuer()
    {
        ticketId = 1;
    }
    void bookTicket(passenger p);
    // void confirmBooking();
    void acceptCancellation(ticket t);
    void showTickets();
    friend class admin;
};

void ticketIssuer::showTickets()
{
    for (auto i : tickets)
    {
        cout << i.second << " ";
    }
}
ticketIssuer T;

void ticketIssuer::bookTicket(passenger p)
{
    int source, destination, passengers = 1;
    cout << " Enter Source : " << endl;
    cin >> source;
    cout << " Enter Destination : " << endl;
    cin >> destination;
    ticket t;
    admin::allot(source, destination, ticketId, p.getUserName(), t);
    if (t.seatNo != -1)
    {
        ticketId++;
        tickets.push_back({&t, p.getUserName()});
    }
}
vector<convoy> convoys1(3);
int mP = 3, mC = 3, mS = 2, c = -1, p = -1, s = -1;
vector<vector<int>> cancelled;
int getSeat(string id)
{
    if (cancelled.size() > 0)
    {
        auto i = cancelled[cancelled.size() - 1];
        cancelled.pop_back();
        convoys1[i[0]].pods[i[1]].seats[i[2]] = id;
        m1[id] = {i[0], i[1]};
        cout << i[0] << " " << i[1] << " " << i[2] << " "
             << "is booked" << endl;
        H.curPassengers++;
        return 1;
    }

    bool found = false;
    if (s != mS - 1)
    {
        if (c == -1)
        {
            c++;
        }
        if (p == -1)
        {
            p++;
        }
        s = (s + 1) % mS;
        cout << c << " " << p << " " << s << " "
             << "is booked" << endl;
        convoys1[c].pods[p].seats[s] = id;
        m1[id] = {c, p};
    }
    else
    {
        if (p != mP - 1)
        {
            p = (p + 1) % mP;
            s = 0;
            cout << c << " " << p << " " << s << " "
                 << "is booked" << endl;
            convoys1[c].pods[p].seats[s] = id;
            m1[id] = {c, p};
        }
        else if (c != mC - 1)
        {
            c = (c + 1) % mC;
            p = 0;
            s = 0;
            cout << c << " " << p << " " << s << " "
                 << "is booked" << endl;
            convoys1[c].pods[p].seats[s] = id;
            m1[id] = {c, p};
        }
        else
        {
            cout << "full" << endl;
            return -1;
        }
    }
    H.curPassengers++;
    return 1;
}
int book2(string id)
{
    if (s == mS && p == mP && c == mC)
    {
        cout << "full" << endl;
        return -1;
    }
    else
    {
        H.changeFrequency();
        return getSeat(id);
    }
    return 0;
}
void cancel(string id)
{
    bool found = false;
    for (int i = 0; i < convoys1.size(); i++)
    {
        for (int j = 0; j < convoys1[i].pods.size(); j++)
        {
            for (int k = 0; k < convoys1[i].pods[j].seats.size(); k++)
            {
                if (convoys1[i].pods[j].seats[k] == id)
                {
                    convoys1[i].pods[j].seats[k] = "";
                    cancelled.push_back({i, j, k});
                    cout << "cancellation successful" << endl;
                    H.curPassengers--;
                    H.changeFrequency();
                    found = true;
                }
            }
        }
    }
    if (!found)
    {
        cout << "wrong id" << endl;
    }
}
void reBook(string id)
{
    cout << "seat status of passenger-" << id << endl;
    int f = book2(id);
    if (f == -1)
    {
        cout << "hyperLoop is full" << endl
             << "sorry for the inconvinience caused" << endl;
    }
    else
    {
        cout << "is ypur new allocated seat" << endl;
    }
}
void podEmergency(int c1, int p1)
{
    auto i = convoys1[c1].pods[p1].seats;
    for (auto j : i)
    {
        reBook(j);
    }
}
void userMenu();
void adminMenu();
void swipe(string id);
void loginMenu()
{
    int option;
    cout << "   Please Choose your Interface : " << endl;
    cout << "   1. Passenger" << endl;
    cout << "   2. Admin" << endl;
    cout << "   3. New Registration" << endl;
    cout << "   0. Exit" << endl;
    cin >> option;

    string userName = "";
    string password = "";
    int a = 0;
    switch (option)
    {
    case 0:
        return;
    case 1:
        cout << "enter userName and password" << endl;
        cin >> userName >> password;
        a = A.login(userName, password);
        if (a == 1)
        {
            userMenu();
        }
        else
        {
            cout << "login fail" << endl;
            loginMenu();
        }
        break;
    case 2:
        cout << "enter userName" << endl;
        cin >> userName;
        cout << "enter password" << endl;
        cin >> password;
        adminMenu();
        break;
    case 3:
        A.registration();
        loginMenu();
        break;

    default:
        cout << " Please Enter correct choice !!!!" << endl;
        loginMenu();
        break;
    }
    return;
}
void userMenu()
{
    int option;
    cout << "   Welcome, Please Choose your options : " << endl;
    cout << "   1. Book Seats" << endl;
    cout << "   2. Swipe and Enter " << endl;
    cout << "   3. Cancellation" << endl;
    cout << "   0. Logout" << endl;
    cin >> option;
    switch (option)
    {
    case 0:
        cout << "logged out" << endl;
        loginMenu();
        break;
    case 1:
        book2(userId);
        userMenu();
        break;
    case 2:
        swipe(userId);
        userMenu();
        break;
    case 3:
        cancel(userId);
        userMenu();
        break;
    default:
        cout << " Please Enter correct choice !!!!" << endl;
        userMenu();
        break;
    }
    return;
}

void adminMenu()
{
    int option;
    cout << "   Welcome, Please Choose your options : " << endl;
    cout << "   1. Alter Frequency " << endl;
    cout << "   2. Pod Emergency " << endl; // Changing the Pod in case of some malfunctioning in the pod
    // cout << "   3. Update Details ";
    cout << "   0. Logout " << endl;
    cin >> option;
    int c = 0;
    int p = 0;
    switch (option)
    {
    case 0:
        loginMenu();
        break;
    case 1:
        for (int i = 0; i < 14; i++)
        {
            book2(to_string(i));
        }
        adminMenu();
        break;
    case 2:
        cout << "enter convoy and pod number under maintainance" << endl;
        cin >> c >> p;
        podEmergency(c, p);
        adminMenu();
        break;

    default:
        cout << " Please Enter correct choice !!!!" << endl;
        adminMenu();
        break;
    }
    return;
}

void swipe(string id)
{
    if (m1.find(id) == m1.end())
    {
        cout << "wrong id" << endl;
        return;
    }
    auto i = m1[id];
    int cv, pd;
    cout << "enter convoy and pod(space seperated)" << endl;
    cin >> cv >> pd;
    if (i.first == cv && i.second == pd)
    {
        cout << "you can enter" << endl;
    }
    else
    {
        if (i.first != cv && i.second != pd)
        {
            cout << "wrong pod and convoy" << endl;
        }
        else if (i.second != pd)
        {
            cout << "wrong pod" << endl;
        }
        else if (i.first != cv)
        {
            cout << "wrong convoy" << endl;
        }
        if (cancelled.size() > 0)
        {
            vector<int> k;
            int it = 0;
            for (it = 0; it < cancelled.size(); it++)
            {
                if (cancelled[it][0] == i.first && cancelled[it][1] == i.second)
                {
                    k = cancelled[it];
                }
            }
            cancelled.erase(cancelled.begin() + it);
            convoys1[k[0]].pods[k[1]].seats[k[2]] = id;
            m1[id] = {k[0], k[1]};
            cout << "new allotment->" << endl;
            cout << k[0] << " " << k[1] << " " << k[2] << " " << endl;
            for (int j = 0; j < convoys1[i.first].pods[i.second].seats.size(); j++)
            {
                if (convoys1[i.first].pods[i.second].seats[j] == id)
                {
                    convoys1[i.first].pods[i.second].seats[j] = "";
                    cancelled.push_back({i.first, i.second, j});
                }
            }
        }
    }
}
int main()
{
    loginMenu();
    return 0;
}