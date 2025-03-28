#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> Time;

#define GET_HOUR(t) ((t).first)
#define GET_MIN(t) ((t).second)

#define INC_HOUR(h) (((h)+1)%24)
#define INC_MIN(m) (((m)+1)%60)

#define NONE (-1)

static inline Time inc_hour(Time cur) {
    int hour = GET_HOUR(cur);
    return {INC_HOUR(hour), GET_MIN(cur)};
}

static inline Time inc_min(Time cur) {
    int hour = GET_HOUR(cur);
    int minute = GET_MIN(cur);

    if ((minute=INC_MIN(minute)) == 0) {
        hour = INC_HOUR(hour);
    }

    return {hour, minute};
}

int visited[24][60];

int main(void) {
    int shown_hh, shown_mm, correct_hh, correct_mm, cnt;
    queue<Time> q;

    scanf("%d:%d", &shown_hh, &shown_mm);
    scanf("%d:%d", &correct_hh, &correct_mm);

    fill(&visited[0][0], &visited[24][60], NONE);

    q.push({shown_hh, shown_mm});
    visited[shown_hh][shown_mm] = 0;

    for (; !q.empty(); q.pop()) {
        Time cur = q.front();
        int num_of_buttons = visited[GET_HOUR(cur)][GET_MIN(cur)];

        if (GET_HOUR(cur) == correct_hh
                && GET_MIN(cur) == correct_mm) {
            cnt = num_of_buttons;
            break;
        }

        Time button_a = inc_hour(cur);

        if (visited[GET_HOUR(button_a)][GET_MIN(button_a)] == NONE) {
            q.push(button_a);
            visited[GET_HOUR(button_a)][GET_MIN(button_a)] = num_of_buttons + 1;
        }

        Time button_b = inc_min(cur);

        if (visited[GET_HOUR(button_b)][GET_MIN(button_b)] == NONE) {
            q.push(button_b);
            visited[GET_HOUR(button_b)][GET_MIN(button_b)] = num_of_buttons + 1;
        }
    }

    cout<<cnt<<'\n';
    return 0;
}