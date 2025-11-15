#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<string, string> location;
unordered_map<string, set<string>> item;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        string op_str, i, l;

        cin >> op_str;

        if (op_str == "PUT") {
            cin >> i >> l;
            location[l] = i;
            item[i].insert(l);
        } else if (op_str == "TAKE") {
            cin >> l;
            
            item[location[l]].erase(l);

            if (item[location[l]].empty()) {
                item.erase(location[l]);
            }
            
            location.erase(l);
        } else { // op_str == "FIND"
            cin >> i;

            if (item.find(i) == item.end()) {
                cout << "NOT FOUND\n";
            } else {
                for (auto it = item[i].begin(); it != item[i].end(); it++) {
                    cout << *it << ' ';
                }

                cout << '\n';
            }
        }
    }

    return 0;
}