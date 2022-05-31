#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define get_cube(n) ((n)*(n)*(n))
#define MAX_NUM     2000000000

void    init(vector<int>& cube)
{
    for(int i=1;;i++)
    {
        int c = get_cube(i);

        if( c > MAX_NUM )
        {
            break;
        }

        cube.push_back(c);
    }
}

int     find_cubes(vector<int>& cube_arr,int lower,int upper)
{
    vector<int>::iterator   l = lower_bound(cube_arr.begin(),cube_arr.end(),lower);
    vector<int>::iterator   u = upper_bound(cube_arr.begin(),cube_arr.end(),upper);

    return  u-l;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         T;
    vector<int> cube;

    cin>>T;
    init(cube);

    for(int t=1;t<=T;t++)
    {
        int A,B;

        cin>>A>>B;
        cout<<"Case #"<<t<<": "<<find_cubes(cube,A,B)<<'\n';
    }

    return  0;
}