#include    <iostream>
#include    <deque>
#include    <stack>

using namespace std;

#define NONE    -1

static int  N,Q,cur_page;
static stack<int>   f;
static deque<int>   b;

#define return_if_empty(n)  {if((n).empty())return 0;}
#define clear_stack(st)     {for(;!(st).empty();(st).pop());}

int go_backward(void)
{
    return_if_empty(b);
    f.push(cur_page);

    cur_page = b.back();
    b.pop_back();

    return  0;
}

int go_forward(void)
{
    return_if_empty(f);
    b.push_back(cur_page);

    cur_page = f.top();
    f.pop();

    return  0;
}

int access_page(void)
{
    int new_page;

    cin>>new_page;
    clear_stack(f);

    if (cur_page != NONE) b.push_back(cur_page);
    cur_page = new_page;

    return  0;
}

int compress(void)
{
    for (int i=1,size=b.size();i<=size;i++)
    {
        int p = b.front();

        b.pop_front();
        if (i!=1 && p==b.back()) continue;  // The first page should not be
                                            // merged into the last page.
        b.push_back(p);
    }

    return  0;
}

int print(void)
{
    cout<<cur_page<<'\n';

    if (b.empty()) {
        cout<<"-1\n";
    } else {
        for (;!b.empty();b.pop_back()) cout<<b.back()<<' ';
        cout<<'\n';
    }

    if (f.empty()) {
        cout<<"-1\n";
    } else {
        for(;!f.empty();f.pop()) cout<<f.top()<<' ';
        cout<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>Q;
    cur_page = NONE;

    for (int i=1;i<=Q;i++)
    {
        char    c;

        cin>>c;

        switch(c) {
            case 'B':go_backward();break;
            case 'F':go_forward();break;
            case 'A':access_page();break;
            case 'C':compress();break;
            default:/*do nothing*/;break;
        }
    }

    print();
    return  0;
}