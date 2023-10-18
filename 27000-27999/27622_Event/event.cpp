#include    <iostream>
#include    <set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,suspicious;
    set<int> users;

    cin>>N;
    suspicious = 0;

    for (int i=1;i<=N;i++) {
        int A;

        cin>>A;

        if (A > 0) {
            users.insert(A);
        } else {
            if (users.find(-A) == users.end()) {
                suspicious++;
            } else {
                users.erase(-A);
            }
        }
    }

    cout<<suspicious<<'\n';
    return  0;
}