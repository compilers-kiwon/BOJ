#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> result;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        int a;

        cin>>a;

        if (result.empty() || result.back() <= a) {
            result.push_back(a);
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
        cout<<result[i]<<(i==result.size()-1?'\n':' ');
    }

    return 0;
}