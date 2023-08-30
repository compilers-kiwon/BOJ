#include    <iostream>
#include    <vector>

using namespace std;

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    int64   sum;
    vector<int64> e;

    cin>>n;
    sum = 0;

    for (int i=1;i<=n;i++) {
        int64 f;

        cin>>f;
        sum+=f;e.push_back(f);
    }

    bool found = false;

    for (int i=0;i<e.size();i++) {
        if (found==false && e[i]==(sum/2)) {
            found = true;
            continue;
        }
        cout<<e[i]<<' ';
    }

    cout<<sum/2<<'\n';
    return  0;
}