#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

static int N,M;
static map<int,string> table;

static inline void read_table(int size) {
    for (int i=1;i<=size;i++) {
        string name;
        int upper;

        cin>>name>>upper;
        if (table[upper].empty()) table[upper]=name;
    }
}

static inline void simulate(int size)
{
    for (int i=1;i<=size;i++) {
        int p;
        map<int,string>::iterator it;

        cin>>p;
        it = table.lower_bound(p);

        if (it == table.end()) it--;
        cout<<it->second<<'\n';
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M;

    cin>>N>>M;

    read_table(N);
    simulate(M);

    return  0;
}