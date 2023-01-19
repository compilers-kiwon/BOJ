#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_FLOOR   3
#define INF         0x7FFFFFFF

void    input(int* arr)
{
    for(int i=1;i<=MAX_FLOOR;i++)
    {
        cin>>arr[i];
    }
}

int     get_ideal_time(int* floor_info)
{
    int ret = INF;
    
    for(int machine_floor=1;machine_floor<=MAX_FLOOR;machine_floor++)
    {
        int time = 0;

        for(int worker_floor=1;worker_floor<=MAX_FLOOR;worker_floor++)
        {
            time += floor_info[worker_floor]*
                        abs(machine_floor-worker_floor)*2;
        }

        ret = min(ret,time);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_workers[MAX_FLOOR+1];

    input(num_of_workers);
    cout<<get_ideal_time(num_of_workers)<<'\n';

    return  0;
}