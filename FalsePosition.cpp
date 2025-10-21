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

int main()
{
    double E,x0,root;
    vector<double>roots;
    cin>>E;
    int cnt=0;
    double lim=limCalc(1,0,-5);

    for(double i=-lim;i<=lim; i=i+0.5)
    {
        double x1=i;
        double x2=i+0.5;

        if(fabs(f(x1))<E)
        {
            roots.push_back(x1);
            continue;
        }

        if(fabs(f(x2))<E)
           {
               roots.push_back(x2);
               i+=0.5;
               continue;
           }

        else if(f(x1)*f(x2)<0)
        {
            double f1=f(x1);
            double f2=f(x2);

            while(fabs(x2-x1)>E)
            {
                cnt++;
                x0=(x1*f2-x2*f1)/(f2-f1);
                double f0=f(x0);

                if(fabs(f(x0))<E) break;
                else if(f(x0)*f(x1)<0)
                {
                    x2=x0;
                    f2=f0;
                }
                else
                {
                    x1=x0;
                    f1=f0;
                }
            }
            root=x0;
            roots.push_back(root);
            cout<<cnt<<" iteration needed."<<endl;
            cnt=0;
            cout<<"Root found in ["<<i<<","<<i+0.5<<"] = "<<root<<endl;
        }
    }

    sort(roots.begin(),roots.end());
    roots.erase(unique(roots.begin(),roots.end(),[&](double a,double b){return fabs(a-b)<E;}),roots.end());

    cout<<"\nAll real roots:\n";
    for(double r : roots)
        cout<<r<<endl;
}

