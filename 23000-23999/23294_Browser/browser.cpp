#include    <iostream>
#include    <vector>
#include    <deque>

using namespace std;

#define MAX_NUM_OF_PAGES    (2000+1)

#define NONE    -1

static int  N,Q,C,page_size[MAX_NUM_OF_PAGES];
static int  used_cache_size,b_cache_size,f_cache_size;
static deque<int> backward_pages,forward_pages;

#define get_cache_size(p)   (page_size[(p)])

#define _push_front(dq,n,c_size) \
    {(dq).push_front((n));(c_size)+=get_cache_size((n));}

#define _push_back(dq,n,c_size) \
    {(dq).push_back((n));(c_size)+=get_cache_size((n));}

#define _pop_front(dq,n,c_size) \
    {(n)=(dq).front();(dq).pop_front();(c_size)-=get_cache_size((n));}

#define _pop_back(dq,n,c_size) \
    {(n)=(dq).back();(dq).pop_back();(c_size)-=get_cache_size((n));}

#define erase_cache(dq,c_size) \
    {(dq).clear();used_cache_size-=(c_size);(c_size)=0;}

#define visit_new_page(current,new) \
    {(current)=(new);used_cache_size+=get_cache_size((current));}

#define make_non_empty(dq)  ((dq).empty()?(dq).push_back(NONE):(void)0)

int do_backward(int& current)
{
    if( !backward_pages.empty() )
    {
        _push_front(forward_pages,current,f_cache_size);
        _pop_back(backward_pages,current,b_cache_size);
    }

    return  0;
}

int do_forward(int& current)
{
    if( !forward_pages.empty() )
    {
        _push_back(backward_pages,current,b_cache_size);
        _pop_front(forward_pages,current,f_cache_size);
    }

    return  0;
}

int access_web_page(int& current,int new_page)
{
    erase_cache(forward_pages,f_cache_size);

    if( current != NONE )
    {
        _push_back(backward_pages,current,b_cache_size);
    }

    visit_new_page(current,new_page);

    for(;!backward_pages.empty()&&used_cache_size>C;)
    {
        int oldest_page;

        _pop_front(backward_pages,oldest_page,b_cache_size);
        used_cache_size -= get_cache_size(oldest_page);
    }

    return  0;
}

int compress(void)
{
    vector<int> buffer;

    for(;!backward_pages.empty();backward_pages.pop_front())
    {
        int current = backward_pages.front();

        if( buffer.empty() || buffer.back()!=current )
        {
            buffer.push_back(current);
            continue;
        }

        used_cache_size -= get_cache_size(current);
        b_cache_size -= get_cache_size(current);
    }

    for(int i=0;i<buffer.size();i++)
    {
        backward_pages.push_back(buffer[i]);
    }

    return  0;
}

int input(void)
{
    cin>>N>>Q>>C;
    for(int i=1;i<=N;i++) cin>>page_size[i];

    return  0;
}

int do_query(void)
{
    int current_page = NONE;

    for(int i=1;i<=Q;i++)
    {
        char    op;
        int     p;

        cin>>op;

        switch(op)
        {
            case 'B':do_backward(current_page);break;
            case 'F':do_forward(current_page);break;
            case 'C':compress();break;
            case 'A':cin>>p;access_web_page(current_page,p);break;
            defaut:/*do nothing*/;break;
        }
    }

    return  current_page;
}

int print_back(deque<int>& dq)
{
    for(make_non_empty(dq);!dq.empty();dq.pop_back()) 
    {
        cout<<dq.back()<<((dq.size()==1)?'\n':' ');
    }

    return  0;
}

int print_front(deque<int>& dq)
{
    for(make_non_empty(dq);!dq.empty();dq.pop_front()) 
    {
        cout<<dq.front()<<((dq.size()==1)?'\n':' ');
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<do_query()<<'\n';
    
    print_back(backward_pages);
    print_front(forward_pages);

    return  0;
}