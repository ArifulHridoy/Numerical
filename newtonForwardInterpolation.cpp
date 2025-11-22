#include<bits/stdc++.h>
using namespace std;

float uCal(float u, int n)
{
    float t=u;
    for(int i=1; i<n; i++) t*=(u-i);
    return t;
}

int fact(int n)
{
    int f=1;
    for(int i=2; i<=n; i++) f*=i;
    return f;
}

int main()
{
    cout<<"Enter N : ";
    int n;
    cin>>n;
    cout<<"Enter X : ";
    float u,h,X;
    cin>>X;

    float x[n],y[n][n];

    for(int i=0; i<n; i++) cin>>x[i]>>y[i][0];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }

//Print table

    for(int i=0; i<n; i++)
    {
        cout<<setw(4)<<x[i]<<"\t";
        for(int j=0; j<n-i; j++)
        {
            cout<<setw(4)<<y[i][j]<<"\t";
        }
        cout<<endl;
    }

        h=x[1]-x[0];
        u=(X-x[0])/h;
        float sum=y[0][0];
        for(int i=1; i<n; i++) sum+=uCal(u,i)*y[0][i]/fact(i);

        cout<<"Value at "<<X<<" : "<<sum<<endl;
}
