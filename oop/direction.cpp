    #include <iostream>
    using namespace std;

    int main()

    {
    int x=10,y=10;

    char direction;
    while(direction!='t')
    {
        cout<<"Enter n for north s for south e for east and w for west and t to terminate"<<endl;
        cin>>direction;
        
        switch(direction)
            {
                case 'n': 
                    y++;
                    break;
                case 's': 
                    y--;
                    break;
                case 'w': 
                    x--;
                    break;
                case 'e':
                    x++;
                    break;
                default :
                    break;
                
            }
            char ch;
            if(x==7&&y==11)
                {
                    cout<<"treasure found!!"<<endl;
                   // break;
                   cout<<"to continue press y"<<endl;
                   if(ch=='y')
                     main();
                   
                   
                }
                if(x==5&&y==11)
                {
                    cout<<"maneater found!!"<<endl;
                    break;
                }

    }
    cout<<"the final position is : "<<endl;
    cout<<"x coordinate : "<<x<<endl;
    cout<<"y coordinate : "<<y<<endl;

    return 0;

    }