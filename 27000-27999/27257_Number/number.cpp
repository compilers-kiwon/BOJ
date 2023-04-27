#include    <iostream>
#include    <string>

using namespace std;

#define remove_tail_zero(num) \
    {for(;!(num).empty()&&(num).back()=='0';(num).pop_back());}

int count_zero(const string& num)
{
    int ret = 0;

    for(int i=0;i<num.length();i++)
    {
        ret += (num[i]=='0')?1:0;
    }

    return  ret;
}

int main(void)
{
    string  num;

    cin>>num;

    remove_tail_zero(num);
    cout<<count_zero(num)<<'\n';

    return  0;
}