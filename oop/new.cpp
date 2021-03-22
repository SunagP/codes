#include<iostream>
#include<fstream>
// #include<cv.h>
// #include<highgui.h>


#include"projectTry1.h"
// using namespace cv;
using namespace std;
namespace login
{
    class regist
    {
        public:string userName,password;
    };
    
    class driver:public regist 
    { public:
        
        int files1();

    };
    class passenger:public regist
    {   public:
        
        int files2();
         
    
    };
int driver ::files1(){
    {
    string command, name, password, inName, inPassword, 
    registerName, registerPassword; 
    
    cout<<"1. register\n2. login\n3. Exit\n"
            <<"Command: ";
    while (1)
    {
        // cout<<"(register/exit/login)\n"
        //     <<"Command: ";
        
        getline(cin, command);
        
        if (command=="3") 
        {
            return 1;
        }
        if (command=="1") 
        {
           
            ofstream g("registration.txt"); 
            if (!g.is_open()) 
            {
                cout<<"could not open file\n"; 
                return 0;
            }
            cout<<"\n\n" <<"New Username: ";
            getline(cin, registerName);
            cout<<"New Password: ";
            getline(cin, registerPassword); 
            g<<registerName; 
            g<<'\n'; 
            g<<registerPassword; 
            cout<<"Registered successfully..\n1. register\n2. login\n3. Exit\n";
            g.close(); 
        }
        if (command=="2")
        {
            
            ifstream f("registration.txt"); 
            if (!f.is_open()) 
            {
                cout<<"could not open file\n"; 
                return 0;
            }
            getline(f, name, '\n'); 
            getline(f, password, '\n'); 
            
            f.close(); 

            //login
            while (1)
            {
                
                cout<<"\n\n\n"
                    <<"Enter Username: ";
                getline(cin, inName);
                cout<<"Enter Password: ";
                getline(cin, inPassword);
                if (inName==name && inPassword==password)
                {
                    cout<<"Login Successful\n" <<"Welcome, "<<inName;
                            
                                                
                   break;
                }
                cout<<"incorrect name or password\n"; 
            }
           
        }
        cout<<"\n\n";
      if(command=="2") break;
    }
    return 0;
}
}
int passenger ::files2(){
    {
    string command, name, password, inName, inPassword, 
    registerName, registerPassword; 
    
    cout<<"1. register\n2. login\n3. Exit\n"
            <<"Command: ";
    while (1)
    {  
        // 2cout<<"(register/exit/login)\n"
    //         <<"Command: ";
        
        getline(cin, command);
        
        if (command=="3") 
        {
            return 1;
        }
        if (command=="1") 
        {
           
            ofstream g("registrationP.txt"); 
            if (!g.is_open()) 
            {
                cout<<"could not open file\n"; 
                return 0;
            }
            cout<<"\n\n" <<"New Username: ";
            getline(cin, registerName);
            cout<<"New Password: ";
            getline(cin, registerPassword); 
            g<<registerName; 
            g<<'\n'; 
            g<<registerPassword; 
            cout<<"Registered successfully..\n1. register\n2. login\n3. Exit\n";
            g.close(); 
        }
        if (command=="2")
        {
            
            ifstream f("registrationP.txt"); 
            if (!f.is_open()) 
            {
                cout<<"could not open file\n"; 
                return 0;
            }
            getline(f, name, '\n'); 
            getline(f, password, '\n'); 
            
            f.close(); 

            //login
            while (1)
            {
                
                cout<<"\n\n\n"
                    <<"Enter Username: ";
                getline(cin, inName);
                cout<<"Enter Password: ";
                getline(cin, inPassword);
                if (inName==name && inPassword==password)
                {
                    cout<<"Login Successful\n" <<"Welcome, "<<inName;
                            
                                                
                    break; 
                }
                cout<<"incorrect name or password\n"; 
            }
           
        }
        cout<<"\n\n";

       if(command=="2") break;
    }
    return 0;
}
}
}
using namespace login;

int main()
{
  using namespace login;
  driver d;
  passenger p;
  int x;
  cout<<"\n         ************Welcome to Carzy Taxi**************\n";
  cout<<"                   1. Driver\n                  2. Passenger\n";
  cin>>x;
   graph<string> g(5);
    g.addEdge("A","B",6);
    g.addEdge("C","B",5);
    g.addEdge("A","D",1);
    g.addEdge("D","E",1);
    g.addEdge("B","D",2);
    g.addEdge("E","C",5);
    g.addEdge("B","E",2);
 // g.adjList();
    g.places[0]="A";
    g.places[1]="B";
    g.places[2]="C";
    g.places[3]="D";
    g.places[4]="E";
    for(int i=0;i<5;i++)
   {
    g.value[i]=INT16_MAX;
    g.temp[i]="A";
    
    }
    if(x==1)
    {
        d.files1();
        int y;
                            string a,b;
                            do
                            {
                                cout<<"\n\nenter 1 to travel\nenter 0 to exit"<<endl;
                                cin>>y;
                                if(y==1)
                                {
                                    cout<<"places--"<<endl;
                                    for(int i=0;i<5;i++)
                                    {
                                    
                               cout<<g.places[i]<<endl;
                                    }
                                    cout<<"enter starting point--";
                                    cin>>a;
                                    cout<<"enter destination--";
                                    cin>>b;
                                    try {
                                    
                                    if (a != b) {
                                        cout<<"shortest path is--"<<endl;
                                        g.findShortPath(a,b);
                                    
                                    } 
                                    else {
                                    throw (a);
                                    }
                                    }
                                    catch (string myStr) {
                                    cout << "Source and Destination cannot be same\n";
                                    cout << "your entry : " << myStr;
                                    cout<<"\nPlease Enter a valid source and destination\n";
                                    }
                                    
                                    // cout<<"cost of ride is is--"<<endl;
                                }}
                                while(y);
    }
    if(x==2)
    {
                           p.files2();
                           int y;
                           string a,b;
                            do
                            {
                                cout<<"\n\nenter 1 to travel\nenter 0 to exit"<<endl;
                                cin>>y;
                                if(y==1)
                                {
                                    cout<<"places--"<<endl;
                                    for(int i=0;i<5;i++)
                                    {
                                    
                               cout<<g.places[i]<<endl;
                                    }
                                    cout<<"enter starting point--";
                                    cin>>a;
                                    cout<<"enter destination--";
                                    cin>>b;
                                    try {
                                    
                                    if (a != b) {
                                        cout<<"Minimum Cost to travel between "<<a<<"and "<<b<<" is--"<<endl;
                                        g.calculatePrice(a,b);
                                    
                                    } 
                                    else {
                                    throw (a);
                                    }
                                    }
                                    catch (string myStr) {
                                    cout << "Source and Destination cannot be same\n";
                                    cout << "your entry : " << myStr;
                                    cout<<"\nPlease Enter a valid source and destination\n";
                                    }
                                    
                                    // cout<<"cost of ride is is--"<<endl;
                                }}
                                while(y);
    }
  




// Mat im = imread("image.jpg", CV_LOAD_IMAGE_COLOR);
// namedWindow("image");
// imshow("image", im);
// waitKey(0);
                          main();
   
                            }