#include    <iostream>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,k;
    double  avg1,avg2,sum1,sum2;

    cin>>n>>k>>avg1>>avg2;

    sum1 = avg1*(double)n;
    sum2 = avg2*(double)k;
    
    if( IN_RANGE(0.0,(sum1-sum2)/(double)(n-k),100.0) )
    {
        cout.setf(ios::fixed);cout.precision(6);
        cout<<(sum1-sum2)/(double)(n-k)<<'\n';
    }
    else
    {
        cout<<"impossible\n";
    }

    return  0;
}