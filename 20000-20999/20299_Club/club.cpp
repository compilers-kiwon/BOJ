#include    <iostream>
#include    <vector>

using namespace std;

#define get_min_score(s1,s2,s3) min((s1),min((s2),(s3)))
#define get_sum(s1,s2,s3)       ((s1)+(s2)+(s3))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N,K,L,cnt;
    vector<int> member;

    cnt = 0;
    cin>>N>>K>>L;

    for(int i=1;i<=N;i++)
    {
        int x1,x2,x3;

        cin>>x1>>x2>>x3;

        if( get_min_score(x1,x2,x3)<L || get_sum(x1,x2,x3)<K )
        {
            continue;
        }

        cnt++;

        member.push_back(x1);
        member.push_back(x2);
        member.push_back(x3);
    }

    cout<<cnt<<'\n';

    for(int i=0;i<member.size();i++)
    {
        cout<<member[i]<<' ';
    }

    cout<<'\n';

    return  0;
}