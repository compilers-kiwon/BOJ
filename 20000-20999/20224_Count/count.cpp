#include    <iostream>
#include    <string>

using namespace std;

#define TARGET_NUM  "2020"
#define NUM_LEN     4

int input(string& str)
{
    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        char    c;

        cin>>c;
        str.push_back(c);
    }

    return  0;
}

int find_number(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length()-NUM_LEN+1;i++)
    {
        ret += (str.substr(i,NUM_LEN)==TARGET_NUM)?1:0;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  str;

        input(str);
        if(str.empty()) break;
        cout<<find_number(str)<<'\n';
    }

    return  0;
}