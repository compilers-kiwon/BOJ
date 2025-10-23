#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum {
    STUDENT_ID_ASC = 0,
    STUDENT_ID_DESC = 1,
    GRADE_ASC = 2,
    GRADE_DESC = 3,
    MAX_ORDER = 4,
};

typedef pair<int, int> Record;

#define id first
#define grade second

bool sort_student_id_asc(const Record& r1, const Record& r2) {
    return r1.id < r2.id;
}

bool sort_student_id_desc(const Record& r1, const Record& r2) {
    return r1.id > r2.id;
}

bool sort_grade_asc(const Record& r1, const Record& r2) {
    bool ret;

    if (r1.grade < r2.grade) {
        ret = true;
    } else if (r1.grade > r2.grade) {
        ret = false;
    } else {
        ret = (r1.id < r2.id);
    }

    return ret;
}

bool sort_grade_desc(const Record& r1, const Record& r2) {
    bool ret;

    if (r1.grade < r2.grade) {
        ret = false;
    } else if (r1.grade > r2.grade) {
        ret = true;
    } else {
        ret = (r1.id < r2.id);
    }

    return ret;
}

bool (*compare[MAX_ORDER])(const Record&, const Record&) {
    sort_student_id_asc,
    sort_student_id_desc,
    sort_grade_asc,
    sort_grade_desc,
};

int get_score(const string& answer_key, const string& student_answer) {
    int ret = 0;

    for (int i= 0 ; i < answer_key.length(); i++) {
        ret += (answer_key[i]==student_answer[i])?1:0;
    }

    return ret;
}

void read_answer(string& s, int num) {
    for (int i = 1; i <= num; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }
}

int get_grade(int num_of_quizzes, const string& answer_key) {
    string student_answer;
    read_answer(student_answer, num_of_quizzes);
    return get_score(answer_key, student_answer);
}

void read_student_info(int num_of_quizzes, int num_of_students,
                        const string& answer, vector<Record>& buf) {
    for (int i = 1; i <= num_of_students; i++) {
        Record r;
        
        cin >> r.id;
        r.grade = get_grade(num_of_quizzes, answer);
        buf.push_back(r);
    }
}

int get_sort_type(void) {
    int ret;
    string str;

    cin >> str;

    if (str == "STUDENT_ID_ASC") {
        ret = STUDENT_ID_ASC;
    } else if (str == "STUDENT_ID_DESC") {
        ret = STUDENT_ID_DESC;
    } else if (str == "GRADE_ASC") {
        ret = GRADE_ASC;
    } else {
        ret = GRADE_DESC;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    string answer;
    vector<Record> r;

    cin >> N;
    read_answer(answer, N);

    cin >> M;
    read_student_info(N, M, answer, r);

    sort(r.begin(), r.end(), compare[get_sort_type()]);

    for (int i = 0; i < M; i++) {
        cout << r[i].id << ' ' << r[i].grade << '\n';
    }

    return 0;
}