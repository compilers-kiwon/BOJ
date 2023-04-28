#include    <iostream>
#include    <cmath>

using namespace std;

#define NONE    -1

#define get_altitude(t,h) \
    (-6*pow((t),4)+(h)*pow((t),3)+2*pow((t),2)+(t))

#define touch_ground(altitude)  ((altitude)<=0)

int simulate(int humidity,int max_hour)
{
    int ret = NONE;

    for(int t=1;t!=max_hour;t++)
    {
        int A = get_altitude(t,humidity);

        if( touch_ground(A) == true )
        {
            ret = t;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int h,M,t;

    cin>>h>>M;
    
    if( (t=simulate(h,M)) != NONE )
    {
        cout<<"The balloon first touches ground at hour: "<<t<<'\n';
    }
    else
    {
        cout<<"The balloon does not touch ground in the given time.\n";
    }

    return  0;
}