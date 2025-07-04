#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    set<string> items = {"keys", "phone", "wallet"};

    cin>>N;

    for (int i = 1; i <= N; i++) {
        string s;

        cin>>s;
        items.erase(s);
    }

    if (items.empty()) {
        cout<<"ready\n";
    } else {
        for (set<string>::iterator it=items.begin(); it != items.end(); it++) {
            cout<<*it<<'\n';
        }
    }

    return 0;
}