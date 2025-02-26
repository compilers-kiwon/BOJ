#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> Chapter;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, max_num_of_pages;
    vector<Chapter> c;

    cin>>N>>M;
    max_num_of_pages = 0;

    for (int i = 1; i <= M ; i++) {
        Chapter ch;
        cin>>ch.first>>ch.second;
        c.push_back(ch);
    }

    for (int i = 1; i < (1<<M); i++) {
        int cur_num_of_days = 0;
        int cur_num_of_pages = 0;

        for (int bit_pos = 0; bit_pos < M; bit_pos++) {
            if ((i & (1<<bit_pos)) != 0) {
                cur_num_of_days += c[bit_pos].first;
                cur_num_of_pages += c[bit_pos].second;
            }
        }

        if (cur_num_of_days <= N) {
            max_num_of_pages = max(max_num_of_pages, cur_num_of_pages);
        }
    }

    cout<<max_num_of_pages<<'\n';
    return 0;
}