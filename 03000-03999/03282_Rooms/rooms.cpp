#include    <iostream>

using namespace std;

#define MAX_NUM_OF_ROOMS    (100+1)

int N,G,room[MAX_NUM_OF_ROOMS];

int     find_room_with_one(void)
{
    int ret;

    for(ret=1;ret<=N;ret++)
    {
        if( room[ret] == 1 )
        {
            break;
        }
    }

    return  ret;
}

void    accommodate_guest_in_room(int n,int& empty)
{
    for(;n>0;)
    {
        if( empty <= N )
        {
            room[empty++] = ((n>=2)?2:1);
            n = max(0,n-2);
        }
        else
        {
            room[find_room_with_one()] = 2;
            n--;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int empty_ptr = 1;

    cin>>N>>G;

    for(int i=1;i<=G;i++)
    {
        int num_of_guests;

        cin>>num_of_guests;
        accommodate_guest_in_room(num_of_guests,empty_ptr);
    }

    for(int i=1;i<=N;i++)
    {
        cout<<room[i]<<'\n';
    }

    return  0;
}