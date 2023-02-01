#include    <iostream>

using namespace std;

typedef long long int       int64;
typedef pair<int64,int64>   Cookie;

#define MAX_SIZE        3
#define NUM_OF_COOKIES  10

#define price   first
#define weight  second

const char  name[MAX_SIZE] = {'S','N','U'};

int input(Cookie* arr)
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        cin>>arr[i].price>>arr[i].weight;
    }

    return  0;
}

int get_required_money(int64* arr,
                const Cookie* cookie_info)
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        arr[i] = cookie_info[i].price*NUM_OF_COOKIES
                -((cookie_info[i].price*NUM_OF_COOKIES>=5000)?500:0);
    }

    return  0;
}

int64 get_excluded_money(int64* money,int me)
{
    int64   ret = 1;

    for(int i=0;i<MAX_SIZE;i++)
    {
        ret *= (i==me)?1:money[i];
    }

    return  ret;
}

int64 get_value(const Cookie& c,int64 n)
{
    return  c.weight*NUM_OF_COOKIES*n;
}

int get_best_cookie(const Cookie* cookie_info,
                            int64* required_money)
{
    int     ret;
    int64   max_value = 0;

    for(int i=0;i<MAX_SIZE;i++)
    {
        int64   n = get_excluded_money(required_money,i);
        int64   current_value = get_value(cookie_info[i],n);

        if( current_value > max_value )
        {
            ret = i;
            max_value = current_value;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Cookie  c[MAX_SIZE];
    int64   required_money[MAX_SIZE];

    input(c);
    get_required_money(required_money,c);

    cout<<name[get_best_cookie(c,required_money)]<<'\n';

    return  0;
}