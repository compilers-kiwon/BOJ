#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM (10)

void print_reach_point(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout<<v[i]<<' ';
    }
    
    cout<<'\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B, C;
    vector<int> result[MAX_NUM + 1];

    cin>>A>>B>>C;

    for (int x = 1; x <= MAX_NUM; x++) {
        for (int y = 1; y <= MAX_NUM; y++) {
            if ((A*x + B*y) == C) {
                result[x].push_back(y);
            }
        }
    }

    for (int v = 1; v <= MAX_NUM; v++) {
        if (result[v].empty()) {
            cout<<"0\n";
        } else {
            print_reach_point(result[v]);
        }
    }

    return 0;
}