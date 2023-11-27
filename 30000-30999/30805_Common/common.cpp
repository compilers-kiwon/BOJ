#include    <iostream>
#include    <queue>

using namespace std;

const static int A = 1;
const static int B = 2;
const static int NUM_OF_SETS = 2;
const static int MAX_NUM = 100;

static queue<int> pos_q[NUM_OF_SETS+1][MAX_NUM+1];

void input(void)
{
    for (int q=1;q<=NUM_OF_SETS;q++) {
        int size;
        cin>>size;
        
        for (int i=1;i<=size;i++) {
            int n;
            cin>>n;
            pos_q[q][n].push(i);
        }
    }
}

void remove_prev_elements(queue<int>& pos,int cur_pos)
{
    for (;!pos.empty();pos.pop()) {
        if (pos.front() > cur_pos) break; 
    }
}

void simulate(queue<int>& common)
{
    int cur_pos[NUM_OF_SETS+1] = {0,};

    for (;;) {
        int n = -1;

        for (int i=MAX_NUM;i>=1;i--) {
            remove_prev_elements(pos_q[A][i],cur_pos[A]);
            remove_prev_elements(pos_q[B][i],cur_pos[B]);
            if (pos_q[A][i].empty() || pos_q[B][i].empty()) continue;
            
            n = i;
            cur_pos[A] = pos_q[A][i].front();pos_q[A][i].pop();
            cur_pos[B] = pos_q[B][i].front();pos_q[B][i].pop();
            
            break;
        }

        if (n == -1) break;
        common.push(n);
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<int>  K;

    input();
    simulate(K);

    cout<<K.size()<<'\n';
    for (;!K.empty();K.pop()) {
        cout<<K.front()<<' ';
    }

    cout<<'\n';
    return  0;
}