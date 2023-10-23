#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

static inline int   get_value(int R,int S,int D) {
    return  (2*R)+(3*S)+D;
}

const static int NUM_OF_PREFERRED_COMPUTERS = 2;
const static int NONE = 0;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;
    if (n == NONE) return 0;

    set<pair<int,string>> computers;

    for (int i=1;i<=n;i++) {
        string  name;
        int     RAM,CPU,DISK;

        cin>>name>>RAM>>CPU>>DISK;
        computers.insert({-get_value(RAM,CPU,DISK),name});
    }

    set<pair<int,string>>::iterator it = computers.begin();

    for (int i=1;it!=computers.end()&&
            i<=NUM_OF_PREFERRED_COMPUTERS;i++,it++) {
        cout<<it->second<<'\n';
    }

    return  0;
}