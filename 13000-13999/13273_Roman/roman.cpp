#include    <iostream>
#include    <string>
#include    <queue>
#include    <vector>

using namespace std;

typedef pair<int,string>    Roman;  

#define MAX_NUM_OF_ROMANS   13

static int   r2i[0x100];
static Roman i2r[MAX_NUM_OF_ROMANS] = {
    {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
    {100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
    {10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define is_roman(num)       (!IN_RANGE('0',(num).front(),'9'))

int init(void)
{
    r2i['I'] = 1;
    r2i['V'] = 5;
    r2i['X'] = 10;
    r2i['L'] = 50;
    r2i['C'] = 100;
    r2i['D'] = 500;
    r2i['M'] = 1000;

    return  0;
}

int get_sum(const vector<int>& n)
{
    int ret = 0;

    for(int i=0;i<n.size();i++)
    {
        ret += n[i];
    }

    return  ret;
}

int roman2int(const string& r)
{
    vector<int> num;

    for(int i=0;i<r.length();i++)
    {
        int n = r2i[r[i]];

        if( !num.empty() && n>num.back() )
        {
            num.back() = n-num.back();
        }
        else
        {
            num.push_back(n);
        }
    }

    return  get_sum(num);
}

string  int2roman(int n)
{
    string  ret;

    for(int ptr=0;ptr<MAX_NUM_OF_ROMANS;ptr++)
    {
        for(;n>=i2r[ptr].first;n-=i2r[ptr].first)
        {
            ret += i2r[ptr].second;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;
    init();

    for(int t=1;t<=T;t++)
    {
        string  num;

        cin>>num;

        if( is_roman(num) )
        {
            cout<<roman2int(num)<<'\n';
        }
        else
        {
            cout<<int2roman(stoi(num))<<'\n';
        }
    }

    return  0;
}