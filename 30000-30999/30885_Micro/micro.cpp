#include    <iostream>

using namespace std;

typedef long long int int64;

typedef struct {
    int64 size;
    int idx,prev,next;
} Micro;

const static int MAX_SIZE = 500000+1;

static int N;
static Micro m[MAX_SIZE];

void input(void)
{
    cin>>N;

    for (int i=1;i<=N;i++) {
        cin>>m[i].size;
        m[i].idx = i;
        m[i].prev = i-1;
        m[i].next = i+1;
    }

    m[1].prev = m[N].next = 0;
}

int simulate(void)
{
    int ptr = 1;

    for (;N!=1;) {
        for (int cur=ptr;cur!=0;cur=m[cur].next) {
            int64 new_size = m[cur].size;

            // take prev
            if (m[cur].prev!=0 &&
                    m[m[cur].prev].size<=m[cur].size) {
                new_size += m[m[cur].prev].size;
                if (ptr == m[cur].prev) ptr = cur;
                m[m[cur].prev].size = 0;
                if (m[m[cur].prev].prev != 0) {
                    m[m[m[cur].prev].prev].next = cur;
                }
                m[cur].prev = m[m[cur].prev].prev;
                N--;
            }

            // take next
            if (m[cur].next!=0 &&
                    m[m[cur].next].size<=m[cur].size) {
                new_size += m[m[cur].next].size;
                m[m[cur].next].size = 0;
                if (m[m[cur].next].next != 0) {
                    m[m[m[cur].next].next].prev = cur;
                }
                m[cur].next = m[m[cur].next].next;
                N--;
            }

            if (m[cur].size != new_size) m[cur].size=new_size;
        }
    }

    return  ptr;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int last;

    input();
    last = simulate();

    cout<<m[last].size<<'\n'<<m[last].idx<<'\n';
    return  0;
}