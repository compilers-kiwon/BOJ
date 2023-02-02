#include    <iostream>

using namespace std;

#define INF     0x7FFFFFFF
#define PENGUIN -1
#define NONE    0

#define get_min_value(data,size,iter,min_value,end) \
    for((data)=NONE;(data)!=(end)&&(iter)<=(size);(iter)++) \
    { \
        cin>>(data); \
        if((data)!=(end)) (min_value)=min((min_value),(data)); \
    }

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,left_min,right_min,i,ice;

    cin>>N;

    i = 1;
    left_min = right_min = INF;

    get_min_value(ice,N,i,left_min,PENGUIN);
    get_min_value(ice,N,i,right_min,PENGUIN);

    cout<<left_min+right_min<<'\n';

    return  0;
}