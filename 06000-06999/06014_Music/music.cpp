#include    <iostream>
#include    <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N,Q;
    vector<int> notes;

    cin>>N>>Q;

    for (int i=1;i<=N;i++) {
        int B;

        cin>>B;
        for (int j=1;j<=B;j++) notes.push_back(i);
    }

    for (int i=1;i<=Q;i++) {
        int T;

        cin>>T;
        cout<<notes[T]<<'\n';
    }

    return  0;
}