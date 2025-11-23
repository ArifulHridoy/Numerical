#include<iostream>
#include<vector>
using namespace std;

vector<vector<double>>getMinor(const vector<vector<double>>& A, int r, int c)
{
    int n=A.size();
    vector<vector<double>>minor;

    for(int i=0; i<n; i++)
    {
        if(i==r) continue;
        vector<double>row;
        for(int j=0; j<n; j++)
        {
            if(j==c) continue;
            row.push_back(A[i][j]);
        }
        minor.push_back(row);
    }
    return minor;
}

double determinant(const vector<vector<double>>&A)
{
    int n=A.size();

    if(n==1)
        return A[0][0];
    if(n==2)
        return A[0][0]*A[1][1] - A[0][1]*A[1][0];

    double det=0;
    for(int col=0; col<n; col++)
    {
        vector<vector<double>>m=getMinor(A,0,col);
        det+=((col%2 ==0?1:-1)*A[0][col] * determinant(m));
    }
    return det;
}

vector<vector<double>>cofactorMatrix(const vector<vector<double>> &A)
{
    int n=A.size();
    vector<vector<double>>C(n, vector<double>(n));

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            vector<vector<double>>m=getMinor(A,i,j);
            C[i][j]=(((i+j)%2==0 ? 1:-1)*determinant(m));
        }
    }
    return C;
}

vector<vector<double>>transpose(const vector<vector<double>>& A)
{
    int n=A.size();
    vector<vector<double>>T(n,vector<double>(n));

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            T[j][i]=A[i][j];

    return T;
}

vector<vector<double>>inverse(const vector<vector<double>>&A)
{
    int n=A.size();
    double detA=determinant(A);

    if (detA==0)
    {
        throw runtime_error("Inverse does not exist (determinant = 0)");
    }

    vector<vector<double>>C=cofactorMatrix(A);
    vector<vector<double>>adj=transpose(C);

    vector<vector<double>>inv(n,vector<double>(n));
    for (int i=0; i <n; i++)
        for (int j=0; j<n; j++)
            inv[i][j]=adj[i][j]/detA;

    return inv;
}

vector<double>multiply(const vector<vector<double>> &A, const vector<double> &B)
{
    int n=A.size();
    vector<double> X(n,0);

    for (int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            X[i]+=A[i][j]*B[j];

    return X;
}

int main()
{
    int n;
    cout<<"Enter number of equations: ";
    cin>>n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);

    cout<<"Enter coefficient matrix A:\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>A[i][j];

    cout << "Enter constants vector B:\n";
    for(int i=0; i<n; i++)
        cin>>B[i];

    try
    {
        vector<vector<double>> invA=inverse(A);
        vector<double> X=multiply(invA, B);

        cout<<"\nSolution (X):\n";
        for(int i=0; i<n; i++)
            cout<<"x"<<i+1<<" = "<<X[i]<<endl;

    }
    catch (exception &e)
    {
        cout<<e.what()<<endl;
    }

    return 0;
}

