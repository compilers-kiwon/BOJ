#include    <iostream>
#include    <string>

using namespace std;

#define OFFSET              ('a'-'A')
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    get_lower_str(string& str)
{
    for(int i=0;i<str.length();i++)
    {
        char& c = str[i];

        c += (IN_RANGE('A',c,'Z')?OFFSET:0); 
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cnt;

    cin>>N;
    cnt = 0;

    for(int i=1;i<=N;i++)
    {
        string  str;

        cin>>str;
        get_lower_str(str);

        if( str.find("pink")!=string::npos
            || str.find("rose")!=string::npos )
        {
            cnt++;
        }
    }

    if( cnt != 0 )
    {
        cout<<cnt<<'\n';
    }
    else
    {
        cout<<"I must watch Star Wars with my daughter\n";
    }

    return  0;
}