#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string find_head(unordered_set<string>& all,
                unordered_map<string, string>& ticket) {
    for (auto it = ticket.begin(); it != ticket.end(); it++) {
        all.erase(it->second);
    }

    return (*all.begin());
}

void print_ticket(const string& head,
                    unordered_map<string, string>& ticket) {
    for (string cur = head;; cur = ticket[cur]) {
        if (ticket[cur].empty()) {
            break;
        }
        
        cout << ' ' << cur << '-' << ticket[cur];
    }

    cout << '\n';
}

void input(unordered_set<string>& all,
            unordered_map<string, string>& ticket) {
    int N;

    for (cin >> N; N > 0; N--) {
        string src, dst;
        
        cin >> src >> dst;
        
        all.insert(src), all.insert(dst);
        ticket[src] = dst;
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        unordered_set<string> all;
        unordered_map<string, string> ticket;

        string h;

        input(all, ticket);
        h = find_head(all, ticket);

        cout << "Case #" << t << ':';
        print_ticket(h, ticket);
    }

    return 0;
}