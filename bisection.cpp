#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
double f(double x)
{
    return x*x*x -x-1;
}

int main()
{
    double E,x0,root;
    vector<double> roots;
    cin>>E;
    for(double i=-10; i<=10;i++)
    {
        double x1=i;
        double x2=i+1;

        if(f(x1)*f(x2)<0)
        {
            while(fabs(x2-x1)>E)
            {
            x0=(x1+x2)/2.0; //mid

            if(fabs(f(x0))<E)
            {
                break;
            }

            else if(f(x0)*f(x1)<0) x2=x0;

            else if(f(x0)*f(x2)<0) x1=x0;
        }

        root=(x1+x2)/2.0;
        roots.push_back(root);

        }
    }

    for(int i=0; i<roots.size(); i++)
    {
        cout<<roots[i]<<endl;
    }


}
