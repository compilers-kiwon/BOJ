#include    <iostream>
#include    <vector>
#include    <map>
#include    <algorithm>

using namespace std;

int find_sequence(vector<int>& num,int idx,int offset)
{
    int ret,n;

    for(ret=1,n=num[idx];;ret++)
    {
        int                     target_num = n+offset;
        vector<int>::iterator   it = lower_bound(num.begin()+idx+1,num.end(),target_num);

        if( it==num.end() || (*it)!=target_num )
        {
            break;
        }

        n = target_num;
        idx = it-num.begin();
    }

    return  ret;
}

int input(vector<int>& num)
{
    int             N,ret;
    map<int,int>    cnt;

    cin>>N;
    ret = 0;

    for(int i=1;i<=N;i++)
    {
        int n;

        cin>>n;
        
        if( cnt.find(n) == cnt.end() )
        {
            num.push_back(n);
        }

        cnt[n]++;
        ret = max(ret,cnt[n]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         max_len;
    vector<int> num;

    max_len = input(num);
    sort(num.begin(),num.end());

    for(int i=0;i<num.size()-1;i++)
    {
        for(int j=i+1;j<num.size();j++)
        {
            if( (num.size()-j+1) < max_len )
            {
                break;
            }

            max_len = max(max_len,find_sequence(num,i,num[j]-num[i]));
        }
    }

    cout<<max_len<<'\n';

    return  0;
}