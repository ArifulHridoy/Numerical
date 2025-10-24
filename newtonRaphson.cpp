#include<iostream>
#include<cmath>
#include<set>
using namespace std;

double f(double x)
{
    return x*x*x-8*x*x+11*x-6;
}

double df(double x)
{
    return 3*x*x-16*x+11;
}

pair<double,int> raphson(double x0, double E)
{
    double x1;
    int iter=1;

    while(iter<1000)
    {
        double d=df(x0);
        if(fabs(d)<1e-9)  return {x0,iter};
        x1=x0-f(x0)/d;
        if(fabs(x1-x0)<E) return {x1,iter};
        x0=x1;
        iter++;
    }
    return {x0,iter};
}

int main()
{
    double E;
    set<double>roots;

    cout<<"Enter tolerance (E): ";
    cin>>E;

    for(double i=-10; i<=10; i=i+0.5)
    {
        auto[r,iter]=raphson(i,E);
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
