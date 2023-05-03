#include    <iostream>

using namespace std;

#define MAX_SIZE    (10000+1)
#define PANG_SIZE   4

enum{
    RED = 1,
    BLUE = 2,
    YELLOW = 3
};

static int  N,ball[MAX_SIZE];

#define get_size(left,right) \
        ((left)+(N-(right)+1)-(((left)==(right))?1:0))

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>ball[i];
    }

    return  0;
}

int pang(int lptr,int rptr)
{
    if( lptr<1 || rptr>N || ball[lptr]!=ball[rptr] )
    {
        return  get_size(lptr,rptr);
    }

    int num_of_left_side,num_of_right_side,continuous_size,ret;

    num_of_left_side = num_of_right_side = 0;

    for(int i=lptr;i>=1&&ball[lptr]==ball[i];i--,num_of_left_side++);
    for(int i=rptr;i<=N&&ball[rptr]==ball[i];i++,num_of_right_side++);

    continuous_size = num_of_left_side+num_of_right_side-((lptr==rptr)?1:0);
    
    if( continuous_size >= PANG_SIZE )
    {
        ret = pang(lptr-num_of_left_side,rptr+num_of_right_side);
    }
    else
    {
        ret = get_size(lptr,rptr);
    }

    return  ret;
}

int simulate(void)
{
    int ret = MAX_SIZE;

    for(int i=1;i<=N;i++)
    {
        for(int c=RED;c<=YELLOW;c++)
        {
            if( ball[i] != c )
            {
                int tmp = ball[i];

                ball[i] = c;
                ret = min(ret,pang(i,i));
                ball[i] = tmp;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}