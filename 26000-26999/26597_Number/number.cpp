#include    <iostream>

using namespace std;

#define LOWER   (-1000000000000000000LL)
#define UPPER   (1000000000000000000LL)

typedef long long int   int64;

#define lower_candidate(x)  ((x)+1)
#define upper_candidate(x)  ((x)-1)

#define NONE        0
#define update(n,v) ((n)=((n)==NONE?(v):(n)))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     Q,find_favorite;
    int64   min_num,max_num;

    cin>>Q;
    find_favorite = 0;

    min_num = LOWER;
    max_num = UPPER;

    for(int i=1;i<=Q;i++)
    {
        int64   x;
        char    answer;

        cin>>x>>answer;

        if( answer == '^' )
        {
            if( lower_candidate(x) > max_num )
            {
                cout<<"Paradox!\n"<<i<<'\n';
                return  0;
            }

            min_num = max(min_num,lower_candidate(x));
        }
        else
        {
            if( upper_candidate(x) < min_num )
            {
                cout<<"Paradox!\n"<<i<<'\n';
                return  0;
            }

            max_num = min(max_num,upper_candidate(x));
        }

        if( min_num == max_num )
        {
            update(find_favorite,i);
        }
    }

    if( find_favorite != 0 )
    {
        cout<<"I got it!\n"<<find_favorite<<'\n';
    }
    else
    {
        cout<<"Hmm...\n";
    }

    return  0;
}