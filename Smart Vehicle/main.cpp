#include<bits/stdc++.h>
#include<conio.h>

#include<dos.h>
#include <chrono>
#include <windows.h>
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
bool shesh = 0;

//------Variables---------
struct Point
{
    int x,y;
};
struct queueNode
{
    Point pt;
    int dist;
};
int ROW,COL;
char MAT[1000+5][1000+5];
Point src,dest;
Point parents[1000+5][1000+5];
//------------------------


//Graphics add kore welcome Kortesi----------------------


//------------------------------------------------------


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
void biday()
{
    clrscr();
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"--------------------------\n";
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"AI Project\n";
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"Smart Car\n";
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"Marjana Nur Mim\n";
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"ID : 161-115-122\n";
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"Farhaan Mahbub\n";
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"ID : 171-115-215\n";
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"--------------------------\n";
    shesh = 1;

    //return 0;
}
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



void getSrcDest()
{
    cout<<endl;
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"# Where is your location right now ?";
    cout<<endl;
    for(int j=0; j<50; j++) cout<<" ";
    cout<<": ";
    cin>>src.x>>src.y;
    cout<<endl;
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"# Where do you want to go ?";
    cout<<endl;
    for(int j=0; j<50; j++) cout<<" ";
    cout<<": ";
    cin>>dest.x>>dest.y;
}

void getDest()
{

    src.x = dest.x;
    src.y = dest.y;
    for(int j=0; j<50; j++) cout<<" ";
    cout<<"# Do u want to continue? (y/n)";
    cout<<endl;
    char cccc;
    for(int j=0; j<50; j++) cout<<" ";
    cin>>cccc;

    if(cccc=='y' or cccc=='Y')
    {
        for(int j=0; j<50; j++) cout<<" ";
        cout<<"# Where do you want to go ?";
        cout<<endl;
        for(int j=0; j<50; j++) cout<<" ";
        cout<<": ";
        cin>>dest.x>>dest.y;
    }
    else
    {
        biday();
    }

}






//Graph part----------------()
int ds,dd;

bool isvalid(int r,int c)
{
    return r>=0 and r<=ROW and c>=0 and c<=COL;
}
int rowArr[] = {-1,0,0,1};
int colArr[] = {0,-1,1,0};

int getPath()
{
    if(!MAT[src.x][src.y] or !MAT[dest.x][dest.y])
    {
        return -1;
    }

    bool visited[ROW+5][COL+5];
    memset(visited,false,sizeof(visited));
    memset(parents,-1,sizeof(parents));




    visited[src.x][src.y] = true;

    queue<queueNode>q;



    queueNode Start = {src,0};
    q.push(Start);

    while(!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;

        if(pt.x==dest.x and pt.y==dest.y)
        {
            return curr.dist;
        }
        q.pop();
        //ds = pt.x;
        //dd = pt.y;
        for(int i=0; i<4; i++)
        {

            int row = pt.x+rowArr[i];
            int col = pt.y+colArr[i];
            ds = row;dd = col;
            if(isvalid(row,col) and MAT[row][col]=='.' and !visited[row][col])
            {
                visited[row][col] = true;
                parents[row][col].x = pt.x;
                parents[row][col].y = pt.y;
                queueNode jachchi = {{row,col},curr.dist+1};
                q.push(jachchi);
            }

        }
    }

    return -1;

}


int getPath1(int x,int y)
{
    src.x = x;
    src.y = y;
    if(!MAT[src.x][src.y] or !MAT[dest.x][dest.y])
    {
        return -1;
    }

    bool visited[ROW+5][COL+5];
    memset(visited,false,sizeof(visited));
    memset(parents,-1,sizeof(parents));




    visited[src.x][src.y] = true;

    queue<queueNode>q;



    queueNode Start = {src,0};
    q.push(Start);

    while(!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;

        if(pt.x==dest.x and pt.y==dest.y)
        {
            return curr.dist;
        }
        q.pop();
        ds = pt.x;
        dd = pt.y;
        for(int i=0; i<4; i++)
        {
            int row = pt.x+rowArr[i];
            int col = pt.y+colArr[i];

            if(isvalid(row,col) and !visited[row][col])
            {
                visited[row][col] = true;
                parents[row][col].x = pt.x;
                parents[row][col].y = pt.y;
                queueNode jachchi = {{row,col},curr.dist+1};
                q.push(jachchi);
            }

        }
    }

    return -1;

}


int cleardist()
{
    if(!MAT[src.x][src.y] or !MAT[dest.x][dest.y])
    {
        return -1;
    }

    bool visited[ROW+5][COL+5];
    memset(visited,false,sizeof(visited));
    memset(parents,-1,sizeof(parents));




    visited[src.x][src.y] = true;

    queue<queueNode>q;



    queueNode Start = {src,0};
    q.push(Start);

    while(!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
        curr.dist = 0;
        if(pt.x==dest.x and pt.y==dest.y)
        {
            return curr.dist;
        }
        q.pop();
        ds = pt.x;
        dd = pt.y;
        for(int i=0; i<4; i++)
        {
            int row = pt.x+rowArr[i];
            int col = pt.y+colArr[i];

            if(isvalid(row,col) and MAT[row][col]=='.' and !visited[row][col])
            {
                visited[row][col] = true;
                queueNode jachchi = {{row,col},0};
                q.push(jachchi);
            }

        }
    }

    return -1;

}

void printGrid()
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
vector<Point>path;
int countPath=0;
void printPath(int cost,int startx,int starty)
{
    path.clear();
    int stx = startx,sty = starty;


    while(parents[stx][sty].x!=-1 and parents[stx][sty].y!=-1)
    {
        path.push_back({stx,sty});
        path.push_back({parents[stx][sty].x,parents[stx][sty].y});
        //cout<<stx<<" "<<sty<<" --->> "<<parents[stx][sty].x<<" "<<parents[stx][sty].y<<endl;
        stx = parents[stx][sty].x;
        sty = parents[stx][sty].y;

    }



    for(int i=path.size()-1; i>=0; i--)
    {

        MAT[path[i].x][path[i].y] = 'C';
        printGrid();
        Sleep(200);
    }

    for(int i=1; i<=ROW; i++)
    {
        for(int j=1; j<=COL; j++)
        {
            if(MAT[i][j]=='C') countPath++;
        }
    }

    countPath--;





}



int main()
{
    //Welcome();
    createHeader();

    string skip1 = "SKIP INTRODUCTION ? (Y/N) : ";
    for(int j=0; j<50; j++) cout<<" ";
    for(int j=0; j<skip1.size(); j++)
    {
        cout<<skip1[j];
        Sleep(20);
    }
    char skip;
    cin>>skip;
    clrscr();
    createHeader();
    if(skip=='n' or skip=='N') intro();


    takeGraphSize();

    defaultGrid();

    getUserGrid();

    userGivenGrid();

    int cost;

    bool ekbar = 0;
    countPath = 0;
    while(true)
    {
        if(shesh==1){
            break;
        }
        if(ekbar==0)
        {
            getSrcDest();
            ekbar = true;
        }
        else
        {
            clrscr();
            createHeader();


            userGivenGrid();

            string s = "Your current location is in : ";
            cleardist();
            int costt = 0;
            //countPath = 0;
            for(int i=1; i<=ROW; i++)
            {
                for(int j=1; j<=COL; j++)
                {
                    //cout<<MAT[i][j]<<" ";
                    if(MAT[i][j]=='C')
                    {
                        costt++;
                        //countPath++;
                        MAT[i][j]='.';

                    }
                    //cout<<endl;
                }
            }
            //int cost2 = getPath1(dest.x,dest.y);
            //costt--;

            for(int j=0; j<50; j++) cout<<" ";
            cout<<"You can go with us at most to "<<dest.x<<" "<<dest.y<<" :D\n\n";

            countPath = costt;


            //cout<<"cost : "<<costt<<" path : "<<countPath<<endl;
            for(int j=0; j<50; j++) cout<<" ";
            for(int j=0; j<s.size(); j++)
            {
                cout<<s[j];
                Sleep(20);
            }

            cout<<dest.x<<" "<<dest.y<<endl<<endl;

            for(int j=0; j<50; j++) cout<<" ";
            cout<<"Path Completed in total : "<<((countPath*100)/costt)<<"%\n\n";



            for(int j=0; j<50; j++) cout<<" ";
            cout<<"** Cost from "<<src.x<<" "<<src.y<<" to "<<dest.x<<" "<<dest.y<<" is : "<<costt<<" taka"<<endl;



            getDest();
        }

        cost = getPath();
        //cout<<cost<<endl;
        if(cost == -1)
        {
            //cout<<"PATH ASEEEEE\n";
            clrscr();
            createHeader();
            //userGivenGrid();
            cout<<ds<<" "<<dd<<endl;
            printPath(cost,ds,dd);
            dest.x = ds;
            dest.y = dd;
            for(int j=0; j<50; j++) cout<<" ";
            cout<<"** There is no path available to your destination.\n";
            for(int j=0; j<50; j++) cout<<" ";
            cout<<"** Try Helicopter instead :| :|\n";

        }
        else
        {
            //cout<<"got itttttt\n\n";
            printPath(cost,dest.x,dest.y);


            //break;
        }






    }
    return 0;
}
/*
.____
..___
_..__
__.._
___..
*/
