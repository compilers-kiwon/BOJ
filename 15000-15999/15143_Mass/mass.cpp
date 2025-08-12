#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define is_lower(c) ('a'<=(c)&&(c)<='z')

void input(unordered_map<string, int>& table, string& compound) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string sym;
        int m1, m2;

        cin >> sym;
        scanf("%d.%d", &m1, &m2);
        table[sym] = (m1 * 100) + m2;
    }

    cin >> compound;
}

int simulate(unordered_map<string, int>& table, string& compound) {
    int ret = 0;

    for (int i = 0; i < compound.length();) {
        if (compound[i] == ' ') {
            break;
        }

        string sym, num;

        if (is_lower(compound[i+1]) == true) {
            sym = compound.substr(i, 2);
            i += 2;
        } else {
            sym.push_back(compound[i]);
            i += 1;
        }

        for (; isdigit(compound[i]); i++) {
            num.push_back(compound[i]);
        }

        ret += table[sym] * (num.empty()?1:stoi(num));
    }

    return ret;
}

int main(void) {
    int mass;
    string comp;
    unordered_map<string, int> table;

    input(table, comp);
    comp.push_back(' ');
    
    mass = simulate(table, comp);
    printf("%d.%02d\n", mass / 100, mass % 100);

    return 0;
}