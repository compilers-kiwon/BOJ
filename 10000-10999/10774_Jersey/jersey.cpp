#include    <iostream>

using namespace std;

#define MAX_NUM (1000000+1)

enum {
    SMALL = 0,
    MEDIUM = 1,
    LARGE = 2,
    MAX_SIZE = 3
};

#define convert_size(c) (((c)=='S')?SMALL:((c)=='M')?MEDIUM:LARGE)

static int  J,A,jersey[MAX_NUM][MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int get_jersey_info(int num_of_jersey)
{
    for(int i=1;i<=num_of_jersey;i++)
    {
        char    size;

        cin>>size;
        jersey[i][convert_size(size)]++;
    }

    return  0;
}

int hand_out(int num_of_players)
{
    int ret = 0;
    
    for(int i=1;i<=num_of_players;i++)
    {
        int     num;
        char    size;

        cin>>size>>num;
        
        if( !IN_RANGE(1,num,J) )
        {
            continue;
        }

        for(int s=convert_size(size);s<MAX_SIZE;s++)
        {
            if( jersey[num][s] != 0 )
            {
                ret++;
                jersey[num][s]--;

                break;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>J>>A;

    get_jersey_info(J);
    cout<<hand_out(A)<<'\n';

    return  0;
}