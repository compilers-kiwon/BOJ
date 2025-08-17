#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

const unordered_set<string> digital_humanities = {
    "social", "history", "language", "literacy"
};

const unordered_set<string> public_bigdata = {
    "bigdata", "public", "society"
};

bool is_included(const unordered_set<string>& topics,
                    const unordered_set<string>& keywords) {
    for (auto it2 = topics.begin(); it2 != topics.end(); it2++) {
        for (auto it1 = keywords.begin(); it1 != keywords.end(); it1++) {
            if (it2->find(*it1) != string::npos) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    unordered_set<string> my_topics;
    for (string t; cin >> t; my_topics.insert(t));

    if (is_included(my_topics, digital_humanities)) {
        cout << "digital humanities\n";
    } else {
        cout << "public bigdata\n";
    }

    return 0;
}