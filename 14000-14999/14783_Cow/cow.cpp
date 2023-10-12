#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

void    input(queue<int>& cow,
                vector<int>& elimination)
{
    int N,L,e;

    cin>>N>>L;
    for (int i=1;i<=N;i++) cow.push(i);

    for (int i=1;i<=L;i++) {
        cin>>e;
        elimination.push_back(e);
    }
}

void    simulate(queue<int>& cow,
                vector<int>& elimination)
{
    for (int i=0;cow.size()!=1;
            i=(i+1)%elimination.size(),cow.pop()) {
        for (int j=1;j<elimination[i];j++) {
            cow.push(cow.front());
            cow.pop();
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<int>  cow;
    vector<int> elimination;

    input(cow,elimination);
    simulate(cow,elimination);

    cout<<cow.front()<<'\n';
    return  0;
}