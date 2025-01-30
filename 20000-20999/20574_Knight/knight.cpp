#include <iostream>
#include <set>

using namespace std;

typedef pair<char,int> Pos;

const int MIN_ROW = 1;
const int MAX_ROW = 8;

const char MIN_COL = 'a';
const char MAX_COL = 'h';

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n) && (n)<=(MAX))

#define IS_REACHABLE_ROW(r) IN_RANGE(MIN_ROW,(r),MAX_ROW)
#define IS_REACHABLE_COL(c) IN_RANGE(MIN_COL,(c),MAX_COL)

#define IS_AVAILABLE(p) (IS_REACHABLE_COL((p).first) && IS_REACHABLE_ROW((p).second))

int move_in_row(int cur_row, int offset) {
    return (cur_row + offset);
}

int move_in_col(char cur_col, int offset) {
    return (char)((int)cur_col + offset);
}

void move_knight(int a, int b, Pos cur, set<Pos>& p) {
    for (int d1 = -1; d1 <= 1; d1 += 2) {
        for (int d2 = -1; d2 <= 1; d2 += 2) {
            Pos p1, p2;

            p1 = {move_in_col(cur.first, d1 * a),
                    move_in_row(cur.second, d2 * b)};
            p2 = {move_in_col(cur.first, d1 * b),
                    move_in_row(cur.second, d2 * a)};

            if (IS_AVAILABLE(p1)) {
                p.insert(p1);
            }

            if (IS_AVAILABLE(p2)) {
                p.insert(p2);
            }
        }
    }
}

void print(set<Pos>& p) {
    set<Pos>::iterator it;

    cout<<p.size()<<'\n';

    for (it = p.begin(); it != p.end(); it++) {
        cout<<it->first<<it->second<<' ';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a, b;
    Pos start;
    set<Pos> p;

    cin>>a>>b>>start.first>>start.second;
    move_knight(a, b, start, p);
    print(p);

    return 0;
}