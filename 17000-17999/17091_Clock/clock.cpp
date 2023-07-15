#include    <iostream>
#include    <string>

using namespace std;

#define MAX_HOUR    12
#define MAX_MINUTE  60

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const string    hour[1+MAX_HOUR+1] = {
    "NONE","one","two","three","four","five","six",
    "seven","eight","nine","ten","eleven","twelve","one"
};

const string    minute[(MAX_MINUTE/2)+1] = {
    "NONE","one minute","two minutes","three minutes",
    "four minutes","five minutes","six minutes",
    "seven minutes","eight minutes","nine minutes",
    "ten minutes","eleven minutes","twelve minutes",
    "thirteen minutes","fourteen minutes","quarter",
    "sixteen minutes","seventeen minutes","eighteen minutes",
    "nineteen minutes","twenty minutes","twenty one minutes",
    "twenty two minutes","twenty three minutes","twenty four minutes",
    "twenty five minutes","twenty six minutes","twenty seven minutes",
    "twenty eight minutes","twenty nine minutes","half"
};

string  convert_time_to_idx(int h,int m)
{
    string  ret;

    if( m == 0)
    {
        ret = hour[h]+" o' clock";
    }
    else if( IN_RANGE(1,m,30) )
    {
        ret = minute[m]+" past "+hour[h];
    }
    else
    {
        ret = minute[MAX_MINUTE-m]+" to "+hour[h+1];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int h,m;

    cin>>h>>m;
    cout<<convert_time_to_idx(h,m)<<'\n';

    return  0;
}