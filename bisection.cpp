#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

double f(double x)
{
     return x*x*x*x -5*x*x + 4;
}

double limCalc(double an, double an1, double an2)
{
    return sqrt((an1/an)*(an1/an) -2*(an2/an));
}

void removeDup(vector<double> &roots, double E)
{
    sort(roots.begin(),roots.end());
    roots.erase(unique(roots.begin(),roots.end(),[&](double a,double b){return fabs(a-b)<E;}),roots.end());
}

int main()
{
    int cnt=0;
    double E,x0,root;
    vector<double>roots;
    cin>>E;
    double lim=limCalc(1,0,-5);
    cout<<"Lim = "<<lim<<endl;

    for(double i=-lim;i<=3; i=i+0.5)
    {
        double x1=i;
        double x2=i+0.5;

        if(fabs(f(x1))<E)
        {
            roots.push_back(x1);
            cout<<"Root found exactly at x = "<<x1<<endl;
            continue;
        }

        if(fabs(f(x2))<E)
        {
            roots.push_back(x2);
            cout<<"Root found exactly at xx = "<<x2<<endl;
            i+=0.5;
            continue;
        }

        else if(f(x1)*f(x2)<0)
        {
            while(fabs(x2-x1)>E)
            {
                cnt++;
                x0=(x1+x2)/2.0;

                if(fabs(f(x0))<E) break;

                else if(f(x0)*f(x1)<0) x2=x0;

                else x1 = x0;
            }
            root=(x1+x2)/2.0;
            roots.push_back(root);
            cout<<cnt<<" iteration needed"<<endl;
            cnt=0;
            cout<<"Root found in ["<<i<<","<<i+0.5<<"] = "<<root<<endl;
        }
    }
    removeDup(roots,E);
    
    cout<<"\nAll real roots:\n";
    for(double r : roots)
        cout<<r<<endl;

}
