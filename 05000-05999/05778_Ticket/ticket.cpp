#include    <iostream>
#include    <set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int N,M;

        cin>>N>>M;
        if (N==0 && M==0) break;

        set<int>    tickets,fake;

        for (int i=1;i<=M;i++) {
            int T;

            cin>>T;

            if (tickets.find(T) == tickets.end()) {
                tickets.insert(T);
            } else {
                fake.insert(T);
            }
        }

        cout<<fake.size()<<'\n';
    }

    return  0;
}