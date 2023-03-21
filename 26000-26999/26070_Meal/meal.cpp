#include    <iostream>

using namespace std;

#define MAX_NUM_OF_MEALS    3

typedef long long int   int64;

static int64 demand[MAX_NUM_OF_MEALS],coupon[MAX_NUM_OF_MEALS];

#define get_meal_idx(n) ((n)%MAX_NUM_OF_MEALS);
#define EXCHANGE_RATIO  (3LL)

int     input(void)
{
    for(int i=0;i<MAX_NUM_OF_MEALS;i++)
    {
        cin>>demand[i];
    }

    for(int i=0;i<MAX_NUM_OF_MEALS;i++)
    {
        cin>>coupon[i];
    }

    return  0;
}

int64   simulate(int fixed_meal)
{
    int64   ret = 0;
    int64   exchanged = 0;
    
    for(int i=0;i<MAX_NUM_OF_MEALS;i++)
    {
        int     current_meal = get_meal_idx(fixed_meal+i);
        int64   current_demand = demand[current_meal];
        int64   current_coupon = coupon[current_meal]+exchanged;

        ret += min(current_demand,current_coupon);
        exchanged = max(0LL,current_coupon-current_demand)/EXCHANGE_RATIO;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   max_num = 0;

    input();

    for(int i=0;i<MAX_NUM_OF_MEALS;i++)
    {
        max_num = max(max_num,simulate(i));
    }

    cout<<max_num<<'\n';

    return  0;
}