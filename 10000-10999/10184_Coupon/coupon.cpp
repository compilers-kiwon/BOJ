#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void get_purchase_info(int num_of_purchases, unordered_map<string, double>& p) {
    for (int i = 1; i <= num_of_purchases; i++) {
        string code;
        double price;

        cin >> code >> price;
        p[code] = price;
    }
}

void discount(int num_of_coupons, vector<string>& invalid,
            unordered_map<string, double>& p) {
    for (int i = 1; i <= num_of_coupons; i++) {
        string code;
        double off;

        cin >> code >> off;

        auto it = p.find(code);

        if (it == p.end()) {
            invalid.push_back(code);
        } else {
            it->second *= 1.0 - off;
        }
    }
}

double get_total_of_purchases(unordered_map<string, double>& p) {
    double ret = 0.0;

    for (auto it = p.begin(); it != p.end(); it++) {
        ret += it->second;
    }

    return ret;
}

void print(unordered_map<string, double>& p, vector<string>& invalid) {
    cout << fixed;
    cout.precision(2);

    cout << get_total_of_purchases(p) << '\n';

    if (invalid.empty() != true) {
        cout << "INVALID COUPONS\n";

        for (int i = 0; i < invalid.size(); i++) {
            cout << invalid[i] << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; n--) {
        int X, Y;
        vector<string> invalid_coupons;
        unordered_map<string, double> table;

        cout.unsetf(ios::fixed);
        cin >> X >> Y;
        
        get_purchase_info(X, table);
        discount(Y, invalid_coupons, table);
        print(table, invalid_coupons);
    }

    return 0;
}