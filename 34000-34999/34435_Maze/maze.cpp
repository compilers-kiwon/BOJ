#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3,
    MAX_DIR = 4,
};

const string dir_str[MAX_DIR] =
    {"North", "South", "East", "West"};

vector<int> cur_dir[MAX_DIR] =
    {{NORTH,}, {SOUTH,}, {EAST,}, {WEST,}};

vector<int> transformation;

void get_words(const string& s, vector<string>& w) {
    string cur;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            w.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(s[i]);
        }
    }
}

int get_dir(const string& s) {
    int ret;

    if (s == "North") {
        ret = NORTH;
    } else if (s == "South") {
        ret = SOUTH;
    } else if (s == "East") {
        ret = EAST;
    } else { // s == "West"
        ret = WEST;
    }

    return ret;
}

const int move_dir_pos = 1;
const int change_from_dir = 1;
const int change_to_dir = 3;
const int num_of_untransform_steps_pos = 4;

void move_robot(const string& s) {
    cout << dir_str[cur_dir[get_dir(s)].back()] << '\n';
}

void change(const string& from, const string& to) {
    int from_dir = get_dir(from);
    int to_dir = get_dir(to);

    cur_dir[from_dir].push_back(to_dir);
    transformation.push_back(from_dir);
}

void untrnasform(int steps) {
    for (int i = 0; i < steps; i++) {
        cur_dir[transformation.back()].pop_back();
        transformation.pop_back();
    }
}

void simulate(const string& action) {
    vector<string> words;

    get_words(action, words);

    if (words.front() == "Move") {
        move_robot(words[move_dir_pos]);
    } else if (words.front() == "Change") {
        change(words[change_from_dir], words[change_to_dir]);
    } else { // words.front() == "Get"
        untrnasform(stoi(words[num_of_untransform_steps_pos]));
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string s;

    getline(cin, s);
    N = stoi(s);

    for (int i = 1; i <= N; i++) {
        getline(cin, s);
        s.push_back(' ');
        simulate(s);
    }

    return 0;
}