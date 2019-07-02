#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char x='x';
char o='o';
char player='x';
char arr[3][3]= {'1','2','3','4','5','6','7','8','9'};
void print()
{
    system("cls");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void play()
{

    char index;
    cout<< "player "<<player<<" choose index : ";
    cin>> index;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(index==arr[i][j])
                arr[i][j]= player;
        }

    }
    if(player=='x' )
    {
        player='o';
    }
    else
    {
        player='x';
    }
}
char winner()
{
    int xc=0,oc=0,counter=0;;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[i][j]!='x'&&arr[i][j]!='o')

                counter++;

            if(arr[i][j]=='x')
                xc++;
            else if(arr[i][j]=='o')
                oc++;
            if(xc==3)
                return 'x';
            if(oc==3)
                return 'o';
        }
        xc=0;
        oc=0;
    }
    if(counter==0)
    {
        return 'v';
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[j][i]=='x')
                xc++;
            else if(arr[j][i]=='o')
                oc++;
        }
        if(xc==3)
            return 'X';
        if(oc==3)
            return 'C';
        xc=0;
        oc=0;
    }
    if(arr[0][0]=='x'&&arr[1][1]=='x'&&arr[2][2]=='x')
        return 'X';
    else if(arr[0][2]=='x'&&arr[1][1]=='x'&&arr[2][0]=='x')
        return 'X';
    else if(arr[0][0]=='o'&&arr[1][1]=='o'&&arr[2][2]=='o')
        return 'O';
    else if(arr[0][2]=='o'&&arr[1][1]=='o'&&arr[2][0]=='o')
        return 'O';



    return  'z';
}


int main()
{


    while(winner()=='z')
    {
        print();
        play();
    }
    print();
    if(winner()=='v')
    {
        cout<< "no one winner";
    }
    else
    {
        cout<<"player "<< winner() <<"  is winner";
    }


    return 0;
}
