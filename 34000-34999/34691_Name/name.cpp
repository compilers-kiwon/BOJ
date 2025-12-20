#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> scientific_name = {
    {"animal", "Panthera tigris"},
    {"flower", "Forsythia koreana"},
    {"tree", "Pinus densiflora"}, 
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string q;

        cin >> q;

        if (q == "end") {
            break;
        }

        cout << scientific_name[q] << '\n';
    }

    return 0;
}