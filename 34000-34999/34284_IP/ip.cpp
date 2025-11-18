#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MSB_POS (7)
#define LSB_POS (0)

vector<string> table;

string get_bit_stream(int num) {
    string ret;

    for (int pos = MSB_POS; pos >= LSB_POS; pos--) {
        ret.push_back((num&(1<<pos))==0?'0':'1');
    }

    return ret;
}

string convert_addr_to_bits(const string& addr) {
    string ret;
    size_t pos;

    for (pos = 0; pos < addr.length();) {
        size_t len = addr.find('.', pos) - pos;
        string num = addr.substr(pos, len);

        ret += get_bit_stream(stoi(num));
        pos += num.length() + 1;
    }

    return ret;
}

void build_table(int num_of_addr) {
    for (int i = 0; i < num_of_addr; i++) {
        size_t pos;
        string addr, bit_len;

        cin >> addr;
        pos = addr.find('/');

        bit_len = addr.substr(pos + 1);
        addr = addr.substr(0, pos);

        addr = convert_addr_to_bits(addr).substr(0, stoi(bit_len));
        table.push_back(addr);
    }
}

int compare_prefix(const string& ip, const string& entry) {
    return (ip.substr(0,entry.length())==entry?entry.length():0);
}

int match_prefix(const string& addr) {
    int ret = -1;
    int max_cnt = 0;
    string bits = convert_addr_to_bits(addr);

    for (int i = 0; i < table.size(); i++) {
        int cnt = compare_prefix(bits, table[i]);

        if (cnt > max_cnt) {
            max_cnt = cnt, ret = i;
        }
    }

    return ((ret==-1)?-1:ret+1);
}

void lookup_table(int num_of_addr) {
    for (int i = 1; i <= num_of_addr; i++) {
        string addr;
        cin >> addr;
        cout << match_prefix(addr) << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m;

    cin >> n >> m;
    
    build_table(n);
    lookup_table(m);

    return 0;
}