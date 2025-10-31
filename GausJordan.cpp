#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"No. of unknowns : ";
    int n;cin>>n;

    vector<vector<double>>a(n,vector<double>(n+1));

    cout<<"Coff. of augmented matrix : "<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n+1; j++)
            cin>>a[i][j];

    for(int i=0; i<n-1; i++){
        int p=i;
        for(int j=i+1;j<n;j++)
            if(fabs(a[j][i])>fabs(a[p][i]))p=j;
        if(p!=i)swap(a[p],a[i]);
        /*if(fabs(a[i][i])<1e-9){
            cout<<"Mathematical Error: zero pivot found.\n";
            return 0;
        }*/
        for(int j=i+1;j<n;j++){
            double f=a[j][i]/a[i][i];
            for(int k=i;k<=n;k++)a[j][k]-=f*a[i][k];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<fixed<<setprecision(2)<<a[i][j]<<" ";
        cout<<endl;}

    vector<double>x(n);
    for(int i=n-1;i>=0;i--){
        x[i]=a[i][n];
        for(int j=i+1;j<n;j++)
            x[i]-=a[i][j]*x[j];
        x[i]/=a[i][i];
    }
    cout<<"Solutions : "<<endl;
    for(int i=0;i<n;i++)
        cout<<"x"<<i+1<<" = "<<fixed<<setprecision(3)<<x[i]<<endl;
}
