#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    cout<<"No. of unknowns : "<<endl;
    int n; cin>>n;

    vector<vector<double>>a(n, vector<double>(n));
    vector<double>b(n);
    vector<double>x(n,0.0);
    vector<double>x_new(n,0.0);

    cout<<"Co-eff matrix : "<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        cin>>a[i][j];

    cout<<"Constant matrix : "<<endl;
    for(int i=0; i<n; i++)
        cin>>b[i];

    cout<<"Tolerence & max iterations : "<<endl;
    double tol; cin>>tol;
    int maxIt; cin>>maxIt;

    for(int it=1; it<=maxIt; it++)
    {

        for(int i=0; i<n; i++)
            {
                double sum=0.0;

                for(int j=0; j<n; j++)
                {
                    if(j!=i)
                        sum+=a[i][j]*x[j];
                }
                x_new[i]=(b[i]-sum)/a[i][i];
            }

    double error=0.0;
    for(int i=0; i<n; i++)
        error+=fabs(x_new[i]-x[i]);

        cout<<"Iteration : "<<it<<" ";

        for(int i=0; i<n; i++)
            cout<<"x"<<i+1<<"="<<x_new[i]<<" ";
            cout<<" | Error : "<<error<<endl;

    if(error<tol) break;

    x=x_new;
    }

    for(int i=0; i<n; i++)
        cout<<"x"<<i+1<<" = "<<x_new[i]<<endl;
}
