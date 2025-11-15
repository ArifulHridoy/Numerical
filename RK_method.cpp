#include<bits/stdc++.h>
using namespace std;

double f(double x,double y)
{
    return x*y+y*y;
}

double rungeKutta(double x0,double y0,double h, double x_end)
{
    double n=(x_end-x0)/h;
    double x=x0, y=y0;

    for(int i=0; i<n; i++)
    {
        double k1=h*f(x, y);
        double k2=h*f(x+h/2.0, y+k1/2.0);
        double k3=h*f(x+h/2.0, y+k2/2.0);
        double k4=h*f(x+h, y+k3);

        y=y+(k1+2*k2+2*k3+k4)/6.0;
        x=x+h;
    }
    return y;
}

int main()
{
    double x0,y0; cout<<"Enter initial x0 and y0 : "; cin>>x0>>y0;
    double h; cout<<"Enter step size : "; cin>>h;
    double x_end; cout<<"Enter the value for which y need :"; cin>>x_end;
    double result=rungeKutta(x0,y0,h,x_end);
    cout<<"At x = "<<x_end<<" y= " <<result<<endl;
    return 0;
}

