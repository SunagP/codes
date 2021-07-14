// city names
public class cities {
    public String C[]=new String[32];
    public cities(){
    C[0]="Go";
    C[1]="Mediteranian Avenue";
    C[2]="Community Chest";
    C[3]="Italic Avenue";
    C[4]="Income Tax";
    C[5]="Reading Railroad";
    C[6]="Oriental Avenue";
    C[7]="Chance";
    C[8]="Jail";
    C[9]="St.Charle's Place";
    C[10]="Electric Company";
    C[11]="States Avenue";
    C[12]="Viriginiya Avenue";
    C[13]="Peninsylvenia Railroad";
    C[14]="St.James' Place";
    C[15]="Community Chest";
    C[16]="Free Parking";
    C[17]="Kentucky Avenue";
    C[18]="Chance";
    C[19]="Indiana Avenue";
    C[20]="Illinors Avenue";
    C[21]="B&O Railroad";
    C[22]="Atlantic Avenue";
    C[23]="Community Chest";
    C[24]="Go to Jail";
    C[25]="Pacific Avenue";
    C[26]="North Carolina Avenue";
    C[27]="Ventinor Avenue";
    C[28]="Peninsylvenia Avenue";
    C[29]="Short Line";
    C[30]="Park Place";
    C[31]="Chance";
    }
    
    
}
// coordinates for pieces x[i][j] => x coordinate for piece of player i in city j 
//                        y[i][j] => y coordinate for piece of player i in city j 
class coordinates{
    public int x[][]=new int[4][32];
    public int y[][]=new int[4][32];
    // public int z[][]=new int[4][32];

    public coordinates(){
    x[0][0]=485;
    x[0][1]=555;
    x[0][2]=625;
    x[0][3]=695;
    x[0][4]=765;
    x[0][5]=835;
    x[0][6]=905;
    x[0][7]=975;
    x[0][8]=1075;
    x[0][9]=1090;
    x[0][10]=1090;
    x[0][11]=1090;
    x[0][12]=1090;
    x[0][13]=1090;
    x[0][14]=1090;
    x[0][15]=1090;
    x[0][16]=1090;
    x[0][17]=920;
    x[0][18]=850;
    x[0][19]=780;
    x[0][20]=710;
    x[0][21]=640;
    x[0][22]=570;
    x[0][23]=500;
    x[0][24]=400;
    x[0][25]=385;
    x[0][26]=385;
    x[0][27]=385;
    x[0][28]=385;
    x[0][29]=385;
    x[0][30]=385;
    x[0][31]=385;
    x[1][0]=470;
    x[1][1]=540;
    x[1][2]=610;
    x[1][3]=680;
    x[1][4]=750;
    x[1][5]=820;
    x[1][6]=890;
    x[1][7]=960;
    x[1][8]=1030;
    x[1][9]=1090;
    x[1][10]=1090;
    x[1][11]=1090;
    x[1][12]=1090;
    x[1][13]=1090;
    x[1][14]=1090;
    x[1][15]=1090;
    x[1][16]=1090;
    x[1][17]=935;
    x[1][18]=865;
    x[1][19]=795;
    x[1][20]=725;
    x[1][21]=655;
    x[1][22]=585;
    x[1][23]=515;
    x[1][24]=415;
    x[1][25]=385;
    x[1][26]=385;
    x[1][27]=385;
    x[1][28]=385;
    x[1][29]=385;
    x[1][30]=385;
    x[1][31]=385;
    //FOR THIRD PLAYER
    for(int i=0;i<=8;i++)
    {
        x[2][i]=x[1][i]-15;
    }
    for(int i=9;i<=16;i++)
    {
        x[2][i]=x[1][i];
    }
    for(int i=17;i<=24;i++)
    {
        x[2][i]=x[1][i]+15;
    }
    for(int i=25;i<32;i++)
    {
        x[2][i]=x[1][i];
    }
    
    // FOR 4th PLAYER
    for(int i=0;i<=8;i++)
    {
        x[3][i]=x[2][i]-15;
    }
    for(int i=9;i<=16;i++)
    {
        x[3][i]=x[2][i];
    }
    for(int i=17;i<=24;i++)
    {
        x[3][i]=x[2][i]+15;
    }
    for(int i=25;i<32;i++)
    {
        x[3][i]=x[2][i];
    }
    y[0][0]=85;
    y[0][1]=85;
    y[0][2]=85;
    y[0][3]=85;
    y[0][4]=85;
    y[0][5]=85;
    y[0][6]=85;
    y[0][7]=85;
    y[0][8]=85;
    y[0][9]=255;
    y[0][10]=325;
    y[0][11]=395;
    y[0][12]=465;
    y[0][13]=535;
    y[0][14]=605;
    y[0][15]=675;
    y[0][16]=775;
    y[0][17]=790;
    y[0][18]=790;
    y[0][19]=790;
    y[0][20]=790;
    y[0][21]=790;
    y[0][22]=790;
    y[0][23]=790;
    y[0][24]=790;
    y[0][25]=620;
    y[0][26]=550;
    y[0][27]=480;
    y[0][28]=410;
    y[0][29]=340;
    y[0][30]=270;
    y[0][31]=200;
    y[1][0]=85;
    y[1][1]=85;
    y[1][2]=85;
    y[1][3]=85;
    y[1][4]=85;
    y[1][5]=85;
    y[1][6]=85;
    y[1][7]=85;
    y[1][8]=85;
    y[1][9]=240;
    y[1][10]=310;
    y[1][11]=380;
    y[1][12]=450;
    y[1][13]=520;
    y[1][14]=590;
    y[1][15]=660;
    y[1][16]=760;
    y[1][17]=790;
    y[1][18]=790;
    y[1][19]=790;
    y[1][20]=790;
    y[1][21]=790;
    y[1][22]=790;
    y[1][23]=790;
    y[1][24]=790;
    y[1][25]=635;
    y[1][26]=565;
    y[1][27]=495;
    y[1][28]=425;
    y[1][29]=355;
    y[1][30]=285;
    y[1][31]=215;
    // FOR THIRD PLAYER
    for(int j=0;j<9;j++)
    {
       y[2][j]=y[1][j];
    }
    for(int j=9;j<16;j++)
    {
       y[2][j]=y[1][j]-15;
    }
    for(int j=16;j<24;j++)
    {
       y[2][j]=y[1][j];
    }
    for(int j=24;j<32;j++)
    {
       y[2][j]=y[1][j]+15;
    }

    // For 4th player
    for(int j=0;j<9;j++)
    {
       y[3][j]=y[2][j];
    }
    for(int j=9;j<16;j++)
    {
       y[3][j]=y[2][j]-15;
    }
    for(int j=16;j<24;j++)
    {
       y[3][j]=y[2][j];
    }
    for(int j=24;j<32;j++)
    {
       y[3][j]=y[2][j]+15;
    }
    

    }
    
}