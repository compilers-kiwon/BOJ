#include    <iostream>

using namespace std;

#define BYTE_SIZE   8

int is_error(string data)
{
    int cnt = 0;

    for(int i=0;i<data.length();i++)
    {
        cnt += (data[i]=='1')?1:0;
    }

    return  (cnt%2!=0);
}

int get_num_of_errors(const string& data)
{
    int ret = 0;

    for(int i=0;i<data.length();i+=BYTE_SIZE)
    {
        ret += is_error(data.substr(i,BYTE_SIZE));
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        string  data;

        cin>>data;
        cout<<get_num_of_errors(data)<<'\n';
    }

    return  0;
}