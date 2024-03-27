
#include <iostream>

using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    int mat[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    int k=0,l=0,row[n]={0},col[n]={0};
    for(k=0;k<n;k++)//0
    {    row[k]+= mat[k][l];//
        for(l=0;l<n;l++)
        {
            col[l]+=mat[k][l];//col[0]=2,col[1]=3,col[2]=1
            if(row[k]==1 && col[l]==n)
            {
                cout<< "Person"<<" "<< l<< " "<<"is the celebrity"<<endl;
                return 0;

            }
        }
        l=0;
    }
    cout << "There is no celebrity";
    return 0;
}
