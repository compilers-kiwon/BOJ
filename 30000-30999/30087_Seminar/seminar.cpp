#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> table = {
    {"Algorithm", "204"}, {"DataAnalysis", "207"},
    {"ArtificialIntelligence", "302"},
    {"CyberSecurity", "B101"}, {"Network", "303"},
    {"Startup",	"501"}, {"TestStrategy", "105"},
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        string topic;
        cin >> topic;
        cout << table[topic] << '\n';
    }

    return 0;
}