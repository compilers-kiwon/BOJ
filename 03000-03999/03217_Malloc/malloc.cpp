#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

typedef struct{
    int size,state,prev,next;
} Memory;

#define FREE    0
#define USED    1

#define NONE        0
#define MAX_SIZE    (100000)

static Memory   mem[MAX_SIZE+1];

#define VAR_LENGTH          4
#define IDX_TO_DETERMINE    4

#define FREE_VAR_POS    5
#define PRINT_VAR_POS   6
#define MALLOC_VAR_POS  0
#define MALLOC_SIZE_POS 12

int init_mem(void)
{
    mem[1] = {MAX_SIZE,FREE,NONE,NONE};
    return  0;
}

int alloc(int size)
{
    int ret = NONE;

    for (int p=1;p<=MAX_SIZE;p+=mem[p].size) {
        if (mem[p].state==USED || mem[p].size<size) {
            continue;
        }

        if (mem[p].size == size) {
            mem[p].state = USED;
        } else {
            mem[p+size] = {mem[p].size-size,FREE,p,mem[p].next};
            if (mem[p].next != NONE) mem[mem[p].next].prev = p+size;
            mem[p] = {size,USED,mem[p].prev,p+size};
        }

        ret = p;
        break;
    }

    return  ret;
}

int free(int pos) {
    if (pos == NONE) return 0;
    mem[pos].state = FREE;

    if (mem[pos].next!=NONE &&
            mem[mem[pos].next].state==FREE) {
        mem[pos].size += mem[mem[pos].next].size;
        mem[pos].next = mem[mem[pos].next].next;
        if (mem[pos].next != NONE) mem[mem[pos].next].prev = pos;
    }

    if (mem[pos].prev!=NONE &&
            mem[mem[pos].prev].state==FREE) {
        mem[mem[pos].prev].size += mem[pos].size;
        mem[mem[pos].prev].next = mem[pos].next;
        if (mem[pos].next != NONE) mem[mem[pos].next].prev = mem[pos].prev;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    map<string,int> variable;

    cin>>N;
    init_mem();

    for (int i=1;i<=N;i++) {
        string  s,var;
        int     size = 0;

        cin>>s;

        switch (s[IDX_TO_DETERMINE]) {
            case '(' :  // free()
                var = s.substr(FREE_VAR_POS,VAR_LENGTH);
                free(variable[var]);
                variable.erase(var);
                break;
            case 't' : // print()
                var = s.substr(PRINT_VAR_POS,VAR_LENGTH);
                cout<<variable[var]<<'\n';
                break;
            default :  // malloc()
                var = s.substr(MALLOC_VAR_POS,VAR_LENGTH);
                variable.erase(var);
                for (int i=MALLOC_SIZE_POS;s[i]!=')';i++) {
                    size = size*10+((int)(s[i]-'0'));
                }
                size = alloc(size);
                if (size != NONE) variable[var]=size;
                break;
        }
    }

    return  0;
}