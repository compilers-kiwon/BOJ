#include    <iostream>
#include    <vector>
#include    <map>

using namespace std;

static int  N,Q;
static map<int,int> icecream;

typedef pair<int,int>   State;  // first: marble, second: num

const static int    FAIL = -1;

int remove_marbles()
{
    int             A;
    map<int,int>    removed;

    cin>>A;

    for (int i=1;i<=A;i++) {
        int a;

        cin>>a;
        removed[a]++;
    }

    vector<State>   result;
    map<int,int>::iterator  it;

    for (it=removed.begin();it!=removed.end();it++) {
        int     marble = it->first;
        int     num = it->second;
        map<int,int>::iterator  m = icecream.find(marble);

        if (m==icecream.end() || num>m->second) {
            return  FAIL;
        }

        result.push_back({marble,m->second-num});
    }

    for (int i=0;i<result.size();i++) {
        int     marble = result[i].first;
        int     num = result[i].second;

        if (num == 0) icecream.erase(marble);
        else icecream[marble]=num;
    }

    return  A;
}

int add_marbles(bool available)
{
    int             B;
    map<int,int>    added;

    cin>>B;

    for (int i=1;i<=B;i++) {
        int b;

        cin>>b;
        added[b]++;
    }

    if (!available) return 0;

    map<int,int>::iterator  it;

    for (it=added.begin();it!=added.end();it++) {
        icecream[it->first] += it->second;
    }

    return  B;
}

int print(void)
{
    cout<<N<<'\n';
    if (N == 0) return 0;

    map<int,int>::iterator  it;

    for (it=icecream.begin();it!=icecream.end();it++) {
        int marble = it->first;
        int num = it->second;

        for (int i=1;i<=num;i++) cout<<marble<<' ';
    }

    cout<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for (int i=1;i<=N;i++) {
        int m;

        cin>>m;
        icecream[m]++;
    }

    cin>>Q;

    for (int i=1;i<=Q;i++) {
        int num_of_removed_marbles = remove_marbles();

        if (num_of_removed_marbles == FAIL) {
            N += add_marbles(false);
        } else {
            N += add_marbles(true)-num_of_removed_marbles;
        }
    }

    print();
    return  0;
}