#include    <iostream>

using namespace std;

#define INF         0x7FFFFFFF
#define TABLE_SIZE  5

#define NUM_OF_STORES   2

const struct{int lower,upper,fixed,flexible;} cost[NUM_OF_STORES][TABLE_SIZE] =
{
    {{-1,5,400,0},{5,10,700,0},{10,20,1200,0},{20,30,1700,0},{30,INF,0,57}},
    {{-1,2,90,90},{2,5,100,85},{5,20,125,80},{20,40,325,70},{40,INF,925,55}}
};

int get_cost(int store,int dist)
{
    int ret;

    for(int i=0;i<TABLE_SIZE;i++)
    {
        if( cost[store][i].lower<dist 
                && dist<=cost[store][i].upper )
        {
            ret = cost[store][i].fixed+cost[store][i].flexible*dist;
            break;
        }
    }
    
    return  ret;
}

int get_min_cost(int dist)
{
    int ret = INF;

    for(int i=0;i<NUM_OF_STORES;i++)
    {
        ret = min(ret,get_cost(i,dist));
    }

    return  ret;
}

int main(void)
{
    int d1,d2,min_cost;

    scanf("%d %d",&d1,&d2);
    
    d1 /= 1000;
    d2 /= 1000;

    min_cost = get_min_cost(d1)+get_min_cost(d2);
    printf("%d.%02d\n",min_cost/100,min_cost%100);
        
    return  0;
}