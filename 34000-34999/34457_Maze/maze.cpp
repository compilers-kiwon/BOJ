#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define EMPTY (0)
#define BLOCKED (1)
#define FIRE (2)

#define UP (0)
#define LEFT (1)
#define DOWN (2)
#define RIGHT (3)
#define MAX_DIR (4)

#define MAX_SIZE (100+1)

typedef enum {
    DOWN_EVENT = 0,
    STAY_EVENT = 1,
    UP_EVENT = 2,
    MAX_EVENT = 3,
} Event;

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

const string event_order = "WASD";

Event get_event(const string& input_str, int idx, char event_key) {
    Event ret;
    char cur = input_str[idx];
    char prev = input_str[idx-1];

    if ((prev != event_key) && (cur == event_key)) {
        ret = DOWN_EVENT;
    } else if ((prev == event_key) && (cur == event_key)) {
        ret = STAY_EVENT;
    } else if ((prev == event_key) && (cur != event_key)) {
        ret = UP_EVENT;
    } else {
        ret = MAX_EVENT;
    }

    return ret;
}

int N, M, grid[MAX_SIZE][MAX_SIZE];
unordered_map<char, pair<Event, int>> event_map;

Event convert_event(const string& s) {
    Event ret;

    if (s == "Down") {
        ret = DOWN_EVENT;
    } else if (s == "Stay") {
        ret = STAY_EVENT;
    } else if (s == "Up") {
        ret = UP_EVENT;
    } else {
        ret = MAX_EVENT;
    }

    return ret;
}

void init_event_map(void) {
    for (int d = 0; d < MAX_DIR; d++) {
        string s;
        cin >> s;
        event_map[event_order[d]] = {convert_event(s), d};
    }
}

typedef pair<int, int> Pos;

Pos input(string& frame) {
    Pos ret;

    cin >> N >> M;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            cin >> grid[row][col];

            if (grid[row][col] == FIRE) {
                grid[row][col] = EMPTY;
                ret = {row, col};
            }
        }
    }

    init_event_map();

    cin >> frame;
    frame.insert(frame.begin(), ' ');

    return ret;
}

bool in_range(int row, int col) {
    return (((1 <= row) && (row <= N))
                && ((1 <= col) && (col <= N)));
}

Pos simulate(const string& frame, Pos cur_pos) {
    for (int i = 1; i < frame.length(); i++) {
        for (int d = 0; d < MAX_DIR; d++) {
            char event_ch = event_order[d];
            Event e = get_event(frame, i, event_ch);

            if (e != event_map[event_ch].first) {
                continue;
            }

            int evt_dir = event_map[event_ch].second;
            int adj_row = cur_pos.first + adj[evt_dir].d_row;
            int adj_col = cur_pos.second + adj[evt_dir].d_col;

            if (!in_range(adj_row, adj_col) || grid[adj_row][adj_col] == BLOCKED) {
                continue;
            }

            cur_pos = {adj_row, adj_col};
        }
    }

    return cur_pos;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos fire_pos;
    string frame;

    fire_pos = input(frame);
    fire_pos = simulate(frame, fire_pos);

    cout << fire_pos.first << ' ' << fire_pos.second << '\n';
    return 0;
}