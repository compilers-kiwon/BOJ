#include    <iostream>

using namespace std;

typedef enum{
    LENGTH_MEASUREMENT,
    WIDTH_MEASUREMENT,
    DEPTH_MEASUREMENT,
    WEIGHT_MEASUREMENT,
    MAX_NUM_OF_MEASUREMENTS
} Measurement;

const double    maximum[MAX_NUM_OF_MEASUREMENTS] = {56.0,45.0,25.0,7.0};

#define MAX_SUM_OF_LENGTH   125.0

void    input(double data[])
{
    for(int i=LENGTH_MEASUREMENT;i<=WEIGHT_MEASUREMENT;i++)
    {
        cin>>data[i];
    }
}

bool    is_allowed(double data[])
{
    double  sum = 0.0;
    bool    ret = true;

    if( data[WEIGHT_MEASUREMENT] > maximum[WEIGHT_MEASUREMENT] )
    {
        return  false;
    }

    for(int i=LENGTH_MEASUREMENT;i<=DEPTH_MEASUREMENT;i++)
    {
        sum += data[i];

        if( data[i] > maximum[i] )
        {
            ret = false;
        }
    }

    return  (ret||(sum<=MAX_SUM_OF_LENGTH));
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t,cnt;

    cin>>t;
    cnt = 0;

    for(int i=1;i<=t;i++)
    {
        double  measurement[MAX_NUM_OF_MEASUREMENTS];

        input(measurement);

        if( is_allowed(measurement) == true )
        {
            cout<<"1\n";
            cnt++;
        }
        else
        {
            cout<<"0\n";
        }
    }

    cout<<cnt<<'\n';

    return  0;
}