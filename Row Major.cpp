#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int rm[10][10],r,c,i,j;
    cout<<"Enter the row and column size respectively"<<endl;
    cin>>r>>c;
    cout<<"Enter the elements of matrix row wise"<<endl;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            cin>>rm[i][j];
    }
    cout<<"Displaying the row major matrix"<<endl;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            cout<<rm[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
