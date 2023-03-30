#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    3
#define MAX_STATE   4

const static string state[MAX_STATE] = {
    "zilch","double","double-double","triple-double"
};

int get_num_of_doubles(int stats[])
{
    int ret = 0;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        ret += (stats[i]>=10)?1:0;
        cout<<stats[i]<<((i==MAX_SIZE)?'\n':' ');
    }

    return  ret;
}

int input(int data_buf[])
{
    for(int i=1;i<=MAX_SIZE;i++)
    {
        cin>>data_buf[i];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int data[MAX_SIZE+1];

        input(data);
        cout<<state[get_num_of_doubles(data)]<<"\n\n";
    }

    return  0;
}