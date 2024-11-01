#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int MAT[][10], int n)
{
    int i, j;
    cout << "\n\n" << setw(4) << " ";
    for (i=0 ; i<n ; i++)
        cout << setw(3) << "(" << i+1 << ")";
    cout << "\n\n";
    for (i=0 ; i<n ; i++)
    {
        cout << setw(3) << "(" << i+1 << ")";
        for (j=0 ; j<n ; j++)
        {
            cout << setw(4) << MAT[i][j];
        }
        cout << "\n\n";
    }
}
int main()
{
    int i, j, v;
    cout << "Enter the number of vertexes: ";
    cin >> v;
    int MAT[10][10];
    cout << "\n";
    for (i=0 ; i<v ; i++)
    {
        for(j=1 ; j<v ; j++)
        {
            if(i!=j)
            {
                cout << "Enter 1 if vertex " << i+1 << " is adjacent to " << j+1 << " , otherwise 0: ";
                cin >> MAT[i][j];
                MAT[j][i] = MAT[i][j];
            }
            else
                MAT[i][j] = 0;
        }
    }
    PrintMatrix(MAT, v);
    return 0;
}
