#include    <iostream>

using namespace std;

#define MAX_SIZE    3
#define INF         0x7FFFFFFF

const struct{int low,high,fine;}
    table[MAX_SIZE] = {{1,20,100},{21,30,270},{31,INF,500}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int get_fine(int over)
{
    int ret;

    for(int i=0;i<MAX_SIZE;i++)
    {
        if( IN_RANGE(table[i].low,over,table[i].high) )
        {
            ret = table[i].fine;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int limit,speed;

    cin>>limit>>speed;

    if( speed <= limit )
    {
        cout<<"Congratulations, you are " 
                        "within the speed limit!\n";
    }
    else
    {
        cout<<"You are speeding and your fine is $"
                        <<get_fine(speed-limit)<<".\n";
    }

    return  0;
}