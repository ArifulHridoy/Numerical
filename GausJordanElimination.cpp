#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"No. of unknowns : ";
    int n;cin>>n;

    vector<vector<double>>a(n,vector<double>(n+1));
    cout<<"Coff. of augmented matrix : "<<endl;

    for(int i=0; i<n; i++)
        for(int j=0; j<n+1; j++)
            cin>>a[i][j];

    for(int i=0; i<n; i++)
    {
        double d=a[i][i];
        for(int j=0; j<n+1; j++) a[i][j]/=d;

        for(int k=0; k<n; k++)
        {
            if(k==i) continue;
            double f=a[k][i];
            for(int j=0; j<n+1; j++) a[k][j]-=f*a[i][j];
        }
    }
    for(int i=0; i<n; i++)
            cout<<"x"<<i+1<<" = "<<fixed<<setprecision(2)<<a[i][n]<<endl;
}
