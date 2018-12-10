#include <iostream>
#include<cmath>
#include <math.h>
using namespace std;
double f(double x)
{
//return (sqrt(3-exp(-x)*2/x)); 1.6....
//return (log((x*x*x-3*x)/2)); nan
return (pow( (3*x+2*exp(-x)),0.33333333333333333333333) ) ;
}

int main()
{
    double y,x0,x;
    double e=0.000000000001;
    int n=0;
    cout<<"enter x0:";
    cin>>x0;

     x=x0;
     do
      {
         x0=x;
         x=f(x0);
         n++;
         cout<<"x"<<n<<"="<<x<<endl;
     } while(fabs(x-x0)>e);

    cout<<endl<<"root: "<<x<<endl;


    y=(x*x*x-3*x-2*exp(-x));
    cout<<"test: "<<y;
}
