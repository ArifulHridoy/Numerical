#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

double f(double x, vector<double>&coeffs)
{
    double res=0.0;
    int n=coeffs.size();
    for (int i=0; i<n; ++i)
    {
        res+=coeffs[i]*pow(x,n-1-i);
    }
    return res;
}

int main()
{
    int degree;
    cout<<"Enter degree: ";
    cin>>degree;

    vector<double>coeffs(degree+1);
    cout<<"Enter coefficients:\n";
    for (int i=0; i<=degree; ++i)
        cin>>coeffs[i];

    double x0,x1,x2;
    cout<<"Enter x0 and x1: ";
    cin>>x0>>x1;

    double E=1e-5;
    int iter=0;


    while(1)
    {
        double f0=f(x0,coeffs);
        double f1=f(x1,coeffs);

        x2=x1-f1*(x1-x0)/(f1-f0);
        iter++;

        if(fabs((x2-x1)/x2)<E || fabs(f1-f0)<1e-12)
            break;

        x0=x1;
        x1=x2;
    }

    cout<<"\nThe eqn. is: ";
    for(int i=0; i<=degree; ++i)
    {
        cout<<coeffs[i];
        if(degree-i>0)
            cout<<"x^"<<(degree-i);
        if(i!=degree) cout<<" +";
    }
    cout<<"=0\n";

    cout<<"Root : "<<x2<<endl;
    cout<<"["<<x0<< ", "<<x1<< "]\n";
    cout<<"Iterations = "<<iter<<endl;

    return 0;
}
