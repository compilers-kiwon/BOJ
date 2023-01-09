#include    <iostream>

using namespace std;

#define MAX_SIZE    4

void    input(int d[])
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        cin>>d[i];
    }
}

enum{
    RISING = 0,
    DIVING = 1,
    CONSTANT = 2,
    NO_FISH = 3,
    MAX_STATE = MAX_SIZE
};

#define is_increasing(data,iter)    \
    {for((iter)=0;(iter)<MAX_SIZE-1;(iter)++) \
        if((data)[(iter)]>=(data)[(iter)+1])break;}

#define is_decreasing(data,iter)    \
    {for((iter)=0;(iter)<MAX_SIZE-1;(iter)++) \
        if((data)[(iter)]<=(data)[(iter)+1])break;}

#define is_constant(data,iter)    \
    {for((iter)=0;(iter)<MAX_SIZE-1;(iter)++) \
        if((data)[(iter)]!=(data)[(iter)+1])break;}

#define RETURN(cond,ret)    {if((cond))return (ret);}

int     decide_state(int d[])
{
    int idx;

    is_increasing(d,idx);
    RETURN(idx==MAX_SIZE-1,RISING);

    is_decreasing(d,idx);
    RETURN(idx==MAX_SIZE-1,DIVING);

    is_constant(d,idx);
    RETURN(idx==MAX_SIZE-1,CONSTANT);

    return  NO_FISH;
};

const string    alarm[MAX_SIZE] =
    {"Fish Rising","Fish Diving",
        "Fish At Constant Depth","No Fish"};

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int depth[MAX_SIZE];

    input(depth);
    cout<<alarm[decide_state(depth)]<<'\n';

    return  0;
}