#include    <iostream>
#include    <vector>

using namespace std;

typedef long long int   int64;

int     get_digits(int64 n,vector<int>& d)
{
    int ret = 0;

    for(;n>0;n/=10)
    {
        d.push_back(n%10);
    }

    if( d.size() > 1 )
    {
        ret = d[1]-d[0];
    }

    return  ret;
}

bool    is_cute(const vector<int>& seq,int offset)
{
    bool    ret = true;

    for(int i=0;i<seq.size()-1;i++)
    {
        if( seq[i]+offset != seq[i+1] )
        {
            ret = false;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64       k;
    int         offset;
    vector<int> s;

    cin>>k;
    offset = get_digits(k,s);
    cout<<(is_cute(s,offset)?
        "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n":"흥칫뿡!! <(￣ ﹌ ￣)>\n");

    return  0;
}