#include    <iostream>
#include    <cfloat>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    double  max_val,min_val,sum;

    cin>>N;

    max_val = DBL_MIN;
    min_val = DBL_MAX;
    sum = 0.0;

    for(int i=1;i<=N;i++)
    {
        double  a,b,val;

        cin>>a>>b;
        val = a/b;

        sum += val;
        max_val = max(max_val,val);
        min_val = min(min_val,val);
    }

    cout<<fixed;cout.precision(6);
    cout<<min_val<<' '<<max_val<<' '<<sum<<'\n';

    return  0;
}
