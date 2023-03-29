#include    <iostream>
#include    <vector>
#include    <cmath>

using namespace std;

#define MAX_NUM 5000

#define UNKNWON     -1
#define DEFICIENT   0
#define ABUNDANT    1
#define PERFECT     2

static int  sum_of_divisors[MAX_NUM+1],attr[MAX_NUM+1];
static vector<int> divisors[MAX_NUM+1];

#define TRUE    1
#define FALSE   0

#define get_pow(n)  ((n)*(n))

int get_attr(int n)
{
    int&    ret = attr[n];

    if( ret != UNKNWON )
    {
        return  ret;
    }

    int s = sum_of_divisors[n]-n;

    return  (ret=((s==n)?PERFECT:(s>n)?ABUNDANT:DEFICIENT));
}

int exclude_abundant_divisor(int n)
{
    vector<int>&    d = divisors[n];

    for(int i=0;i<d.size();i++)
    {
        if( d[i]!=n && get_attr(d[i])==ABUNDANT )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int get_divisors(int n)
{
    int ret = 0;

    for(int i=1;i<=sqrt(n);i++)
    {
        if( n%i == 0 )
        {
            ret += i+(n/i);

            divisors[n].push_back(i);
            divisors[n].push_back(n/i);
        }
    }

    if( n == get_pow(divisors[n].back()) )
    {
        ret -= divisors[n].back();
        divisors[n].pop_back();
    }

    return  ret;
}

int init(void)
{
    for(int i=1;i<=MAX_NUM;i++)
    {
        sum_of_divisors[i] = get_divisors(i);
        attr[i] = UNKNWON;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;
    init();

    for(int i=1;i<=T;i++)
    {
        int n;

        cin>>n;

        if( get_attr(n)==ABUNDANT && 
                exclude_abundant_divisor(n) )
        {
            cout<<"Good Bye\n";
        }
        else
        {
            cout<<"BOJ 2022\n";
        }
    }

    return  0;
}