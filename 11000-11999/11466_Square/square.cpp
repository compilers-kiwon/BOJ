#include    <iostream>

using namespace std;

#define PRECISE_LENGTH  3

#define set_precise(l)  \
    {cout<<fixed;cout.precision(l);}

double  get_square(double small,double big)
{
    return  max(min(small,big/3.0),
                    min(small/2.0,big/2.0));
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double  h,w;

    cin>>h>>w;

    set_precise(PRECISE_LENGTH);
    cout<<get_square(min(h,w),max(h,w))<<'\n';

    return  0;
}