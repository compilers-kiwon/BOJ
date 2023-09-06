#include    <iostream>
#include    <vector>
#include    <stack>

using namespace std;

#define MAX_NUM_OF_INSTRUCTIONS     (1000)
#define TAKE_TOPMOST_INTEGER(st,v)  {(v)=(st).top();(st).pop();}

typedef pair<int,int>   Instruction;

enum {
    PUSH = 0,
    STORE = 1,
    LOAD = 2,
    PLUS = 3,
    TIMES = 4,
    IFZERO = 5,
    DONE = 6
};

#define OPCODE(op)  ((op)=="PUSH"?PUSH:(op)=="STORE"?STORE:\
                    (op)=="LOAD"?LOAD:(op)=="PLUS"?PLUS:\
                    (op)=="TIMES"?TIMES:(op)=="IFZERO"?IFZERO:DONE)

static int  n;
static Instruction  program[MAX_NUM_OF_INSTRUCTIONS];

int input(void)
{
    cin>>n;

    for (int i=0;i<n;i++) {
        int     operand = 0;
        string  opcode;

        cin>>opcode;
        if (opcode=="PUSH" || opcode=="IFZERO") cin>>operand;
        program[i] = {OPCODE(opcode),operand};
    }

    return  0;
}

int do_plus(stack<int>& st)
{
    int tmp1,tmp2;

    TAKE_TOPMOST_INTEGER(st,tmp1);
    TAKE_TOPMOST_INTEGER(st,tmp2);

    st.push(tmp1+tmp2);
    return  0;
}

int do_times(stack<int>& st)
{
    int tmp1,tmp2;

    TAKE_TOPMOST_INTEGER(st,tmp1);
    TAKE_TOPMOST_INTEGER(st,tmp2);

    st.push(tmp1*tmp2);
    return  0;
}

int simulate(void)
{
    int         pc,reg;
    stack<int>  st;

    for (pc=reg=0;program[pc].first!=DONE;pc++) {
        int opcode = program[pc].first;
        int operand = program[pc].second;
        int tmp;

        switch (opcode) {
            case PUSH:st.push(operand);break;
            case STORE:TAKE_TOPMOST_INTEGER(st,reg);break;
            case LOAD:st.push(reg);break;
            case PLUS:do_plus(st);break;
            case TIMES:do_times(st);break;
            case IFZERO:
                TAKE_TOPMOST_INTEGER(st,tmp);
                pc=(tmp==0)?operand-1:pc;
                break;
            default:/*do nothing*/;break;
        }
    }

    return  st.top();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}