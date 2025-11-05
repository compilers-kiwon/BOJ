#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, pair<int, int>> meal_plan = {
    {"Marble", {19, 20000}}, {"Marble+", {19, 35000}},
    {"Quartz", {14, 20000}}, {"Quartz+", {14, 35000}},
};

#define swipe first
#define money second

void print(const string& student_name,
            const string& plan_name,
            int num_of_swipes, int munch_money) {
    pair<int, int> info = meal_plan[plan_name];

    cout << student_name << ' ';

    int swipe_diff = info.swipe - num_of_swipes;
    cout << swipe_diff << ' ';
    
    int money_diff = info.money - munch_money;
    cout << money_diff / 100 << '.' <<
            ((money_diff%100<10)?"0":"") << money_diff%100 << ' ';

    if (swipe_diff > 0 && money_diff > 0) {
        cout << "Use meal swipe or munch money\n";
    } else if (swipe_diff == 0 && money_diff > 0) {
        cout << "Use munch money\n";
    } else if (swipe_diff > 0 && money_diff == 0) {
        cout << "Use meal swipe\n";
    } else { // swipe_diff == 0 && money_diff == 0
        cout << "Go to Downtown Golden!\n";
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        string student_name, plan_name;
        int num_of_swipes, m1, m2;
        char p;

        cin >> student_name >> plan_name >>
                num_of_swipes >> m1 >> p >> m2;
        print(student_name, plan_name, num_of_swipes, (m1 * 100) + m2);
    }

    return 0;
}