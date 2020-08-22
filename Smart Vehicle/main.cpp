#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include <chrono>
using namespace std;


#define WINDOWS 1
void clrscr()
{
#ifdef WINDOWS
    system("cls");
#endif
#ifdef LINUX
    system("clear");
#endif
}

int ROW,COL;
char MAT[1000+5][1000+5];


//Header---------------------

void createHeader()
{
    //space 25 ta
    for(int i=0; i<=50; i++) cout<<" ";
    cout<<"---------------------------------------------------------\n";
    for(int i=0; i<50; i++) cout<<" ";
    cout<<"|                       Smart Vehicle                     |\n";
    for(int i=0; i<50; i++) cout<<" ";
    cout<<"|                        AI-Project                       |\n";
    for(int i=0; i<=50; i++) cout<<" ";
    cout<<"---------------------------------------------------------\n\n\n";

}
//---------------------------


//Extra shajanor jonno-----
void sp()
{
    cout<<"          ";
}
//-------------------------


//Introduction to user---------
int intro()
{
    string s1 = "     1. You can draw the map as you want and give paths between nodes.";
    string s2 = "     2. (.) means the cell in the grid can be visited by the car.";
    string s3 = "     3. (_) means theres a obstacle on the road... can be damaged road,water,a long traffic that is not negotiable.";
    string s4 = "     4. Moving from one cell to another cell costs 1 minute and 1 taka (Default).";
    string s5 = "     Continue (Y/N) : ";


    for(int i=0; i<20; i++) cout<<" ";
    sp();
    for(int i=0; i<s1.size(); i++)
    {
        cout<<s1[i];
        Sleep(25);
    }
    cout<<"\n\n";
    //Sleep(10000);

    for(int i=0; i<20; i++) cout<<" ";
    sp();
    for(int i=0; i<s2.size(); i++)
    {
        cout<<s2[i];
        Sleep(25);
    }
    cout<<"\n\n";
    for(int i=0; i<20; i++) cout<<" ";
    sp();
    for(int i=0; i<s3.size(); i++)
    {
        cout<<s3[i];
        Sleep(25);
    }
    cout<<"\n\n";
    for(int i=0; i<20; i++) cout<<" ";
    sp();
    for(int i=0; i<s4.size(); i++)
    {
        cout<<s4[i];
        Sleep(25);
    }
    cout<<"\n\n\n";

    char ok=0;

    for(int i=0; i<20; i++) cout<<" ";
    sp();
    for(int i=0; i<s5.size(); i++)
    {
        cout<<s5[i];
        Sleep(25);
    }
    cout<<"";
    cin>>ok;
    if(ok=='Y' or ok=='y')
    {
        clrscr();
        createHeader();
    }
    else
    {
        return 0;
    }
}
//-------------------

void takeGraphSize()
{
    string s1 = "# How many rows in your map ?";
    string s2 = "# How many column in your map ?";
    for(int i=0; i<50; i++) cout<<" ";
    for(int i=0; i<s1.size(); i++)
    {
        cout<<s1[i];
        Sleep(25);
    }
    cout<<"\n\n";
    for(int i=0; i<50; i++) cout<<" ";
    cin>>ROW;
    cout<<endl;
    for(int i=0; i<50; i++) cout<<" ";
    for(int i=0; i<s2.size(); i++)
    {
        cout<<s2[i];
        Sleep(25);
    }
    cout<<"\n\n";
    for(int i=0; i<50; i++) cout<<" ";
    cin>>COL;
    cout<<endl<<endl;



}

void defaultGrid()
{
    clrscr();
    createHeader();
    cout<<endl;

    for(int j=0; j<50; j++) cout<<" ";

    int spaceHobe = (COL*5)/2;
    if((COL*5)%2==0) spaceHobe-=3;
    else spaceHobe-=4;
    //The Map Lehkha majkane ashar jonno
    for(int i=1; i<=spaceHobe; i++) cout<<" ";
    cout<<"The Map\n\n";


    for(int i=1; i<=ROW+1; i++)
    {
        for(int j=0; j<50; j++) cout<<" ";
        for(int j=1; j<=COL; j++)
        {
            cout<<"-----";
        }
        Sleep(20);
        cout<<endl;
        if(i<=ROW)
        {
            for(int j=0; j<50; j++) cout<<" ";
            for(int j=1; j<=5*COL; j++)
            {
                if((j%5)==0 or j==1)
                {
                    cout<<"|";
                    Sleep(20);
                }
                else cout<<" ";
            }
            cout<<endl;

            for(int j=0; j<50; j++) cout<<" ";
            for(int j=1; j<=5*COL; j++)
            {
                if((j%5)==0 or j==1)
                {
                    cout<<"|";
                    Sleep(20);
                }
                else cout<<" ";
            }
            cout<<endl;

            for(int j=0; j<50; j++) cout<<" ";
            for(int j=1; j<=5*COL; j++)
            {
                if((j%5)==0 or j==1)
                {
                    cout<<"|";
                    Sleep(20);
                }
                else cout<<" ";
            }
            cout<<endl;
        }
        //cout<<endl<<endl<<endl;
    }

}


void getUserGrid()
{
    string s1 = "Draw the map (. for path, _ for obstacles, No space) according to ROW and COLUMN.";

    cout<<endl;
    for(int i=0; i<50; i++) cout<<" ";
    for(int i=0; i<s1.size(); i++)
    {
        cout<<s1[i];
        Sleep(25);
    }
    cout<<"\n\n";

    //char MAT[ROW+5][COL+5];
    //cout<<"ok\n";
    for(int i=1; i<=ROW; i++)
    {
        for(int j=0; j<50; j++) cout<<" ";

        for(int j=1; j<=COL; j++)
        {
            cin>>MAT[i][j];
        }
    }

}


void userGivenGrid()
{
    clrscr();
    createHeader();
    cout<<endl;

    for(int j=0; j<50; j++) cout<<" ";

    int spaceHobe = (COL*5)/2;
    if((COL*5)%2==0) spaceHobe-=3;
    else spaceHobe-=4;
    //The Map Lehkha majkane ashar jonno
    for(int i=1; i<=spaceHobe; i++) cout<<" ";
    cout<<"Given Map\n\n";


    int xx=1;

    for(int i=1; i<=ROW+1; i++)
    {
        for(int j=0; j<50; j++) cout<<" ";
        for(int j=1; j<=COL; j++)
        {
            cout<<"-----";
        }
        cout<<endl;
        if(i<=ROW)
        {
            for(int j=0; j<50; j++) cout<<" ";
            for(int j=1; j<=5*COL; j++)
            {
                if((j%5)==0 or j==1) cout<<"|";
                else cout<<" ";
            }
            cout<<endl;

            int yy=1;
            int pos=3;
            for(int j=0; j<50; j++) cout<<" ";
            for(int j=1; j<=5*COL; j++)
            {
                if((j%5)==0 or j==1) cout<<"|";
                else if(j==pos)
                {
                    cout<<MAT[xx][yy];
                    yy++;
                    pos+=5;
                }
                else cout<<" ";
            }
            cout<<endl;

            for(int j=0; j<50; j++) cout<<" ";
            for(int j=1; j<=5*COL; j++)
            {
                if((j%5)==0 or j==1) cout<<"|";
                else cout<<" ";
            }
            cout<<endl;
            xx++;
        }
        //cout<<endl<<endl<<endl;
    }

}

int main()
{

    createHeader();
    intro();
    takeGraphSize();
    defaultGrid();
    getUserGrid();
    userGivenGrid();

    return 0;
}

