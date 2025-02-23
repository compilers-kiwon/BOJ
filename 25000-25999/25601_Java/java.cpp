#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string,unordered_set<string>> parents;

void input(string& c1, string&c2) {
    int N;

    cin>>N;

    for (int i = 1; i < N; i++) {
        string A, B;

        cin>>A>>B;
        parents[A].insert(B);
    }

    cin>>c1>>c2;
}

bool is_parent(const string& child, const string& parent) {
    unordered_set<string>& my_parents = parents[child];

    if (my_parents.find(parent) != my_parents.end()) {
        return true;
    }

    bool found = false;
    unordered_set<string>::iterator it;

    for (it = my_parents.begin(); it != my_parents.end(); it++) {
        if ((found=is_parent(*it, parent)) == true) {
            break;
        }
    }

    return found;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string class1, class2;

    input(class1, class2);

    if (is_parent(class1, class2)
            || is_parent(class2, class1)) {
        cout<<"1\n";
    } else {
        cout<<"0\n";
    }

    return 0;
}