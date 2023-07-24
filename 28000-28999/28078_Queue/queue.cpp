#include    <iostream>
#include    <string>
#include    <deque>

using namespace std;

#define MAX_DIR         4
#define FRONT_BOTTOM    1

static deque<char>  q;
static int  state,num_of_borders;

#define is_border(n)        ((n)=='w')        
#define is_horizontal(s)    ((s)%2==0)
#define get_bottom(q,s)     ((s)==FRONT_BOTTOM?(q).front():(q).back())
#define fall(q,s)           ((s)==FRONT_BOTTOM?(q).pop_front():(q).pop_back())
#define get_next_state(s,d) (((s)+(MAX_DIR+((d)=='r'?1:-1)))%MAX_DIR)

int update(void)
{
    if (q.empty() || is_horizontal(state)) return 0;
    for(;!q.empty()&&!is_border(get_bottom(q,state));fall(q,state));
    
    return  0;
}

int push(char element)
{
    if (is_border(element)) num_of_borders++;
    q.push_back(element);
    update();

    return  0;
}

int pop(void)
{
    if (q.empty()) return 0;
    if (is_border(q.front())) num_of_borders--;

    q.pop_front();
    update();

    return  0;
}

int rotate(char direction)
{
    state = get_next_state(state,direction);
    update();

    return  0;
}

int count(char element)
{
    return  is_border(element)?
                num_of_borders:q.size()-num_of_borders;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Q;

    cin>>Q;

    for(int i=1;i<=Q;i++)
    {
        string  query;
        char    d;

        cin>>query;

        if (query == "pop") {
            pop();
            continue;
        }

        cin>>d;

        if (query == "push") push(d);
        else if (query == "rotate") rotate(d);
        else cout<<count(d)<<'\n';
    }

    return  0;
}