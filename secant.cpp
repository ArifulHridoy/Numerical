
#include<iostream>
#include<cmath>
#include<set>
using namespace std;

double f(double x)
{
    return x*x*x*x-3*x*x*x+2*x*x+6*x;
}

pair<double,int> secant(double x0,double x1, double E)
{
    double x2;
    int iter=1;

    while(iter<1000)
    {
        double f0=f(x0);
        double f1=f(x1);

        if(fabs(f1-f0)<1e-9) break;

        x2=x1-f1*(x1-x0)/(f1-f0);

        if(fabs(x2-x1)<E) return {x2,iter}; //stopping criteria

        x0=x1;
        x1=x2;
        iter++;
    }
    return {x1,iter};
}

int main()
{
    double E;
    set<double>roots;

    cout<<"Enter tolerance (E): ";
    cin>>E;

    for(double i=-3; i<=3; i=i+0.5)
    {
        double x0=i;
        double x1=i+0.5;
        auto[r,iter]=secant(x0,x1,E);
        if(fabs(f(r))<1e-4)
        {
            double rd=round(r*1000.0)/1000.0;
            if(roots.find(rd)==roots.end())
                cout<<"x0 = "<<i<<" | Root = "<<rd<<" | Iteration : "<<iter<<endl;
            roots.insert(rd);
        }
    }
    return 0;
}
