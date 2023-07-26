#include    <iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

using namespace std;

#define itoc(i) ((char)((i)+(int)'0'))

typedef long long int   int64;

int64   get_sum(const vector<string>& nums)
{
    int64   ret = 0;
    for (int i=0;i<nums.size();i++) ret+=stoll(nums[i]);
    return  ret;
}

string  do_conversion(int64 num,int64 d)
{
    string  ret;

    for (;num>0;num/=d) ret.push_back(itoc((int)(num%d)));
    reverse(ret.begin(),ret.end());

    return  ret;
}

vector<string>  divide_num(const string& number)
{
    string          n;
    vector<string>  ret;
    
    for (int i=0;i<number.length();i++)
    {
        if (number[i] == '0') {
            if (!n.empty()) ret.push_back(n);
            n.clear();
        } else {
            n.push_back(number[i]);
        }
    }

    if (!n.empty()) ret.push_back(n);
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64           n,k,sum;
    string          number,answer;
    vector<string>  divided;
    
    cin>>n>>k;
    number = do_conversion(n,k);
    
    divided = divide_num(number);
    sum = get_sum(divided);

    answer = do_conversion(sum,k);
    cout<<answer<<'\n';

    return  0;
}