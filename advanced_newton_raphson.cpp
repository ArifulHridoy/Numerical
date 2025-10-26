#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

double f(double x, vector<double>&coeffs) {
    double res=0.0;
    int n=coeffs.size();
    for(int i=0;i<n;++i)
        res+=coeffs[i]*pow(x,n-1-i);
    return res;
}

double df(double x, vector<double>&coeffs) {
    double res=0.0;
    int n=coeffs.size();
    for(int i=0;i<n-1;++i)
        res+=coeffs[i]*(n-1-i)*pow(x,n-2-i);
    return res;
}

int main() {
    int degree;
    cout<<"Enter degree: ";
    cin>>degree;

    vector<double>coeffs(degree+1);
    cout<<"Enter coefficients:\n";
    for(int i=0;i<=degree;++i)
        cin>>coeffs[i];

    double x0;
    cout<<"Enter initial guess x0: ";
    cin>>x0;

    double E=1e-5;
    int iter=0;
    double x1;

    while(true) {
        double f0=f(x0,coeffs);
        double df0=df(x0,coeffs);
        if(fabs(df0)<1e-12) {
            cout<<"Derivative too small. Stopping iteration.\n";
            break;
        }
        x1=x0-f0/df0;
        iter++;
        if(fabs(x1-x0)<E) break;
        x0=x1;
    }

    cout<<"\nThe equation is: ";
    for(int i=0;i<=degree;++i) {
        cout<<coeffs[i];
        if(degree-i>0) cout<<"x^"<<(degree-i);
        if(i!=degree) cout<<" + ";
    }
    cout<<" = 0\n";

    cout<<"Root: "<<x1<<endl;
    cout<<"Interval: ["<<x0-E<<", "<<x0+E<<"]\n";
    cout<<"Iterations = "<<iter<<endl;

    return 0;
}
