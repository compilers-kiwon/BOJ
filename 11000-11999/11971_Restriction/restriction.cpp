#include    <iostream>
#include    <vector>

using namespace std;

#define store_data(vec,size,data) \
    {for(int n=0;n<(size);n++) (vec).push_back((data));}

void    read_data(int num_of_repeats,vector<int>& buf)
{
    for(int i=1;i<=num_of_repeats;i++)
    {
        int l,s;

        cin>>l>>s;
        store_data(buf,l,s);
    }    
}

void    input(vector<int>& speed,vector<int>& restriction)
{
    int N,M;

    cin>>N>>M;

    read_data(N,restriction);
    read_data(M,speed);
}

int     get_max_over_speed(const vector<int>& speed,
                            const vector<int>& restriction)
{
    int ret = 0;

    for(int i=0;i<speed.size();i++)
    {
        ret = max(ret,speed[i]-restriction[i]);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> speed,restriction;

    input(speed,restriction);
    cout<<get_max_over_speed(speed,restriction)<<'\n';

    return  0;
}