#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

#define remove_leading_zeroes(num) \
    {for(;(num).length()>1&&(num).front()=='0';(num).erase(0,1));}

int decrease_by_one(string& num)
{
    int n = stoi(num);

    n--;num.clear();
    num = to_string(n);
    
    return  0;
}

int simulate(string& num)
{
    int ret;

    for(ret=0;!num.empty()&&num!="0";ret++)
    {
        size_t  offset;

        if( (offset=num.find('1')) != string::npos)
        {
            num.erase(offset,1);
        }
        else
        {
            decrease_by_one(num);
        }

        remove_leading_zeroes(num);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  N;

    cin>>N;
    cout<<simulate(N)<<'\n';

    return  0;
}