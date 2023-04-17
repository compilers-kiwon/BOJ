#include    <iostream>
#include    <string>
#include    <vector>
#include    <algorithm>

using namespace std;

#define char2int(c)     ((int)((c)-'0'))
#define get_diff(c1,c2) (char2int((c1))-char2int((c2)))

#define get_year(d)     ((d).substr(0,4))
#define get_month(d)    ((d).substr(4,2))
#define get_day(d)      ((d).substr(6,2))

int get_sum_of_digits(string birth,string today)
{
    int ret = 0;

    for(int i=0;i<birth.length();i++)
    {
        ret += get_diff(birth[i],today[i])
                    *get_diff(birth[i],today[i]);
    }

    return  ret;
}

int input(string& birth,vector<string>& candidates)
{
    int N;

    cin>>birth>>N;

    for(int i=1;i<=N;i++)
    {
        string  d;

        cin>>d;
        candidates.push_back(d);
    }

    sort(candidates.begin(),candidates.end());

    return  0;
}

int simulate(const string& birth,
                const vector<string>& candidates)
{
    int ret,max_value;

    max_value = -1;

    for(int i=0;i<candidates.size();i++)
    {
        int Y = get_sum_of_digits(get_year(birth),get_year(candidates[i]));
        int M = get_sum_of_digits(get_month(birth),get_month(candidates[i]));
        int D = get_sum_of_digits(get_day(birth),get_day(candidates[i]));

        if( Y*M*D > max_value )
        {
            max_value = Y*M*D;
            ret = stoi(candidates[i]);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string          birth;
    vector<string>  dates;

    input(birth,dates);
    cout<<simulate(birth,dates)<<'\n';

    return  0;
}