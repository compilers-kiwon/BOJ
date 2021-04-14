#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_TEMP    50
#define MIN_TEMP    -50

#define char2int(c) ((int)((c)-'0'))

int     str2int(const string& n)
{
    int i,ret,s;

    if( n[0] == '-' )
    {
        s = -1;
        i = 1;
    }
    else
    {
        s = 1;
        i = 0;
    }

    for(ret=0;i<n.length();i++)
    {
        ret = ret*10+char2int(n[i]);
    }

    return  s*ret;
}

void    parse(const string& data,vector<int>& measurement)
{
    int     i;
    string  t;

    for(i=0;data[i]!=' ';i++);

    for(i++;i<data.length();i++)
    {
        if( data[i] == ' ' )
        {
            int n;

            n = str2int(t);
            t.clear();

            measurement.push_back(n);
        }
        else
        {
            t.push_back(data[i]);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         min_temp,max_temp;
    vector<int> temperature;
    
    for(;;)
    {
        string  data;

        getline(cin,data);

        if( data.empty() )
        {
            break;
        }

        data.push_back(' ');
        parse(data,temperature);
    }

    min_temp = MAX_TEMP;
    max_temp = MIN_TEMP;

    for(int i=0;i<temperature.size();i++)
    {
        int&    t = temperature[i];

        min_temp = min(min_temp,t);
        max_temp = max(max_temp,t);
    }

    cout<<min_temp<<' '<<max_temp<<'\n';

    return  0;
}