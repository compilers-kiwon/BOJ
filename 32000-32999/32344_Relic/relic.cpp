#include <iostream>
#include <cstdint>

using namespace std;

#define MAX_SIZE (100000)
#define MAX_NUM_OF_RELICS (100000+1)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef struct {
    int64_t up, down, left, right;
} Relic;

int N;
int64_t R, C;
Relic r[MAX_NUM_OF_RELICS];

bool is_available(int relic) {
    const Relic& cur = r[relic];
    return (IN_RANGE(1,cur.right,C) && IN_RANGE(1,cur.down,R));
}

int64_t get_area(int relic) {
    const Relic& cur = r[relic];
    return ((cur.right - cur.left + 1) * (cur.down - cur.up + 1));
}

void init(void) {
    cin>>R>>C>>N;

    for (int i = 1; i <= N; i++) {
        r[i].down = r[i].right = 0;
        r[i].up = r[i].left = MAX_SIZE;
    }
}

int get_pos(void) {
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        int a;
        int64_t v, h;

        cin>>a>>v>>h;
        ret = max(ret, a);

        r[a].left = min(r[a].left, h);
        r[a].right = max(r[a].right, h);

        r[a].up = min(r[a].up, v);
        r[a].down = max(r[a].down, v);
    }

    return ret;
}

int get_max_area(int num_of_relics) {
    int ret;
    int64_t max_area = 0;

    for (int i = 1; i <= num_of_relics; i++) {
        if (is_available(i) == false){
            continue;
        }

        int64_t cur_area = get_area(i);
        
        if (max_area < cur_area) {
            ret = i;
            max_area = cur_area;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_relics, biggest_relic;

    init();
    
    num_of_relics = get_pos();
    biggest_relic = get_max_area(num_of_relics);

    cout<<biggest_relic<<' '<<get_area(biggest_relic)<<'\n';
    return 0;
}