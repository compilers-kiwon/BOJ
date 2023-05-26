#include    <iostream>
#include    <map>

using namespace std;

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,D;
    int64   num_of_shoots;

    map<int,int64>  cnt;
    map<int,int64>::reverse_iterator highest;
    
    cin>>N>>D;

    for(int i=1;i<=N;i++)
    {
        int h;

        cin>>h;
        cnt[h]++;
    }

    num_of_shoots = 0;

    for(int i=1;i<=D&&!cnt.empty();
            i++,cnt.erase(highest->first))
    {
        if((highest=cnt.rbegin())->first==0) break;

        num_of_shoots += highest->second;
        cnt[highest->first-1] += highest->second;
    }

    cout<<num_of_shoots<<'\n';
    return  0;
}