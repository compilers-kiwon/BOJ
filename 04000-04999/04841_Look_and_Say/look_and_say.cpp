#include    <iostream>

using namespace std;

int count_digit(const string& num)
{
    char    cur_d = num.front();
    int     cur_cnt = 1;

    for(int i=1;i<num.length();i++)
    {
        if( cur_d != num[i] )
        {
            cout<<cur_cnt<<cur_d;
            cur_d = num[i];
            cur_cnt = 1;
        }
        else
        {
            cur_cnt++;
        }
    }

    cout<<cur_cnt<<cur_d<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        string  n;

        cin>>n;
        count_digit(n);
    }

    return  0;
}