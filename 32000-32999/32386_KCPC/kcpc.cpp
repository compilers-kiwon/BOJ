#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void input(unordered_map<string, int>& algorithm_table) {
    int N;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        int s, t;

        cin>>s>>t;

        for (int j = 1; j <= t; j++) {
            string a;

            cin>>a;
            algorithm_table[a]++;
        }
    }
}

string count_algorithm(unordered_map<string, int>& algorithm_table) {
    string ret;
    int max_val, num_of_max_val;
    unordered_map<string, int>::iterator it;

    max_val = num_of_max_val = 0;

    for (it=algorithm_table.begin();it!=algorithm_table.end();it++) {
        if (it->second == max_val) {
            num_of_max_val++;
        } else {
            if (it->second > max_val) {
                max_val = it->second;
                num_of_max_val = 1;
                ret = it->first;
            }
        }
    }

    return (num_of_max_val==1)?ret:"-1";
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    unordered_map<string, int> table;

    input(table);
    cout<<count_algorithm(table)<<'\n';

    return 0;
}