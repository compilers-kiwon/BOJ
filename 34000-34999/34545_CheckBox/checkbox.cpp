#include <iostream>
#include <string>

using namespace std;

int input(string& src, string& dst) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        char c;
        cin >> c;
        src.push_back(c);
    }

    for (int i = 1; i <= N; ++i) {
        char c;
        cin >> c;
        dst.push_back(c);
    }

    return N;
}

int get_num_of_diffs(const string& src, const string& dst, int size) {
    int ret = 0;

    for (int i = 0; i < size; ++i) {
        ret += (src[i]!=dst[i])?1:0;
    }

    return ret;
}

int get_num_of_checked(const string& s) {
    int ret = 0;

    for (int i = 0; i < s.length(); ++i) {
        ret += (s[i]=='1')?1:0;
    }

    return ret;
}

int simulate(const string& src, const string& dst, int size) {
    int ret = get_num_of_diffs(src, dst, size);
    
    int src_num_of_checked = get_num_of_checked(src);
    int dst_num_of_checked = get_num_of_checked(dst);
    
    int src_num_of_unchecked = size - src_num_of_checked;
    int dst_num_of_unchecked = size - dst_num_of_checked;

    int checked_all, unchecked_all;

    if (src_num_of_checked == size) {
        checked_all = 0;
        unchecked_all = 1;
    } else if (src_num_of_checked == 0) {
        checked_all = 1;
        unchecked_all = 0;
    } else if (src_num_of_checked == 1) {
        checked_all = 1;
        unchecked_all = 1;
    } else {
        checked_all = 1;
        unchecked_all = 2;
    }

    ret = min(ret, min(unchecked_all + dst_num_of_checked,
                        checked_all + dst_num_of_unchecked));
    
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string src, dst;
    
    N = input(src, dst);
    cout << simulate(src, dst, N) << '\n';

    return 0;
}