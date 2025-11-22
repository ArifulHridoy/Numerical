#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter N : ";
    int n;
    cin>>n;
    cout<<"Enter X : ";
    float X;
    cin>>X;

    float x[n],y[n],d[n][n];

    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    for(int i=0; i<n; i++) d[i][0]=y[i];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            d[j][i]=(d[j+1][i-1]-d[j][i-1])/(x[i+j]-x[j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<setw(6)<<x[i]<<"\t";
        for(int j=0; j<n-i; j++)
        {
            cout<<setw(10)<<d[i][j]<<"\t";
        }
        cout<<endl;
    }

        float sum=d[0][0];
        float t=1;

        for(int i=1; i<n; i++)
        {
            t*=(X-x[i-1]);
            sum+=t*d[0][i];
        }
        cout<<"Value at "<<X<<" : "<<sum<<endl;
}
