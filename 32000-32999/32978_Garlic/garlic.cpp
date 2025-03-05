#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void input(vector<string>& required,
            unordered_set<string>& used) {
    int N;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        string in;
        cin>>in;
        required.push_back(in);
    }

    for (int i = 1; i <= N - 1; i++) {
        string in;
        cin>>in;
        used.insert(in);
    }
}

int find_missed_one(vector<string>& required,
                    unordered_set<string>& used) {
    int ret;

    for (int i = 0; i < required.size(); i++) {
        if (used.find(required[i]) == used.end()) {
            ret = i;
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> required;
    unordered_set<string> used;

    input(required, used);
    cout<<required[find_missed_one(required,used)]<<'\n';

    return 0;
}