#include    <iostream>
#include    <set>

using namespace std;

#define MAX_SIZE    4

void    input(int& num_of_empty,int& empty_pos,
                    set<int>& not_used,int num[])
{
    num_of_empty = 0;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        cin>>num[i];

        if( num[i] == 0 )
        {
            num_of_empty++;
            empty_pos = i;
        }
        else
        {
            not_used.erase(num[i]);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         num_of_empty,empty_pos,num[MAX_SIZE+1];
    set<int>    not_used;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        not_used.insert(i);
    }

    input(num_of_empty,empty_pos,not_used,num);

    switch(num_of_empty)
    {
        case    0:
            cout<<num[1]<<' '<<num[2]<<'\n';
            break;
        case    1:
            cout<<empty_pos<<' '<<*(not_used.begin())<<'\n';
            break;
        case    2:
            cout<<*(not_used.begin())<<' '<<*(not_used.rbegin())<<'\n';
            break;
        default:
            break;
    }

    return  0;
}