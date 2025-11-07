#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

void LU_Decomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int k=i; k<n; k++)
        {
            double sum=0;
            for(int j=0; j<i; j++)
                sum+=L[i][j]*U[j][k];
            U[i][k]=A[i][k]-sum;
        }

        for(int k=i; k<n; k++)
        {
            if(i==k) L[i][i]=1;
            else
            {
                double sum=0;
                for(int j=0; j<i; j++)
                    sum+=L[k][j]*U[j][i];
                L[k][i]=(A[k][i]-sum)/U[i][i];
            }
        }
    }
}

vector<double>forwardSubstitution(vector<vector<double>>&L, vector<double>&b, int n)
{
    vector<double>y(n);
    for(int i=0; i<n; i++)
    {
        double sum=0;
        for(int j=0; j<i; j++)
            sum+=L[i][j]*y[j];
        y[i]=b[i]-sum;
    }
    return y;
}

vector<double>backwardSubstitution(vector<vector<double>>&U, vector<double>&y, int n)
{
    vector<double>x(n);
    for(int i=n-1; i>=0; i--)
    {
        double sum=0;
        for(int j=i+1; j<n; j++)
            sum+=U[i][j]*x[j];
        x[i]=(y[i]-sum)/U[i][i];
    }
    return x;
}

int main()
{
    int n; cout<<"Enter number of equations: "; cin>>n;

    vector<vector<double>>A(n,vector<double>(n));
    vector<double>b(n);

    cout<<"Enter matrix A:\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin>>A[i][j];

    cout<<"Enter vector b:\n";
    for(int i=0; i<n; i++) cin>>b[i];

    vector<vector<double>>L(n,vector<double>(n,0)),U(n,vector<double>(n,0));

    LU_Decomposition(A,L,U,n);

    vector<double>y=forwardSubstitution(L,b,n);

    vector<double>x= backwardSubstitution(U,y,n);

    cout<<"\nLower Triangular Matrix L:\n";
    for(auto&row:L)
    {
        for(auto val:row)
            cout<<setw(10)<<val<<" ";
        cout<<endl;
    }
    for(int i=0; i<n; i++) cout<<b[i]<<" ";
    cout<<endl;

    cout<<"\nUpper Triangular Matrix U:\n";
    for(auto&row:U)
    {
        for(auto val:row)
            cout<<setw(10)<<val<<" ";
        cout<<endl;
    }

    cout<<"\nSolution Vector x:\n";
    for(int i=0; i<n; i++) cout<<"x"<<i+1<<" = "<<x[i]<<endl;

    return 0;
}
