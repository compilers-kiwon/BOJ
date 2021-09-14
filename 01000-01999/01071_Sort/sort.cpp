#include    <iostream>
#include    <vector>
#include    <map>

using namespace std;

#define MAX_SIZE    (50+1)

int             N;
map<int,int>    num;
vector<int>     output;


void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int n;

        cin>>n;
        num[n]++;
    }
}

void    write_output(int n,int size)
{
    for(int i=1;i<=size;i++)
    {
        output.push_back(n);
    }
}

void    sort(void)
{
    for(;output.size()!=N;)
    {
        map<int,int>::iterator  it = num.begin();

        int current = it->first;

        if( it->second == 0 )
        {
            num.erase(current);
            continue;
        }
        
        if( num[current+1] == 0 )
        {
            write_output(current,num[current]);
            num.erase(current);
        }
        else
        {
            map<int,int>::iterator  next_of_next;

            next_of_next = num.upper_bound(current+1);

            if( next_of_next == num.end() )
            {
                write_output(current+1,num[current+1]);
                num.erase(current+1);
            }
            else
            {
                write_output(current,num[current]);
                write_output(next_of_next->first,1);

                num.erase(current);
                
                if( --(next_of_next->second) == 0 )
                {
                    num.erase(next_of_next->first);
                }
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    sort();

    for(int i=0;i<N;i++)
    {
        cout<<output[i]<<' ';
    }

    return  0;
}