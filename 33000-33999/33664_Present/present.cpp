#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    int64 B;
    unordered_map<string, int64> item_list;

    cin>>B>>N>>M;

    for (int n = 1; n <= N; n++) {
        string i;
        int64 p;

        cin>>i>>p;
        item_list[i] = p;
    }

    int64 sum = 0;

    for (int m = 1; m <= M; m++) {
        string j;

        cin>>j;
        sum += item_list[j];
    }

    cout<<((sum<=B)?"acceptable":"unacceptable")<<'\n';

    return 0;
}