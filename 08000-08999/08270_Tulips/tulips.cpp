#include    <iostream>
#include    <set>

using namespace std;

#define MAX_NUM 15000

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    set<int> t;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int num;

        cin>>num;
        t.insert(num);
    }

    cout<<MAX_NUM-t.size()<<'\n';
    return  0;
}