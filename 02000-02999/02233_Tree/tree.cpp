#include    <iostream>
#include    <string>
#include    <stack>

using namespace std;

#define MAX_SIZE    (2000+1)

typedef pair<int,int>   Pos;    // first:idx of '0',second:idx of '1'

int     N,X,Y,parent[MAX_SIZE],depth[MAX_SIZE],matched[MAX_SIZE*2];
Pos     p[MAX_SIZE];
string  binary;

void    input(void)
{
    cin>>N>>binary;
    binary.insert(binary.begin(),' ');
    cin>>X>>Y;
}

void    build_tree(void)
{
    int         d,ptr,node_idx;
    stack<int>  st;

    d = ptr = node_idx = 0;

    for(int i=1;i<binary.length();i++)
    {
        switch(binary[i])
        {
            case    '0':
                st.push(ptr);
                ptr=++node_idx;d++;
                depth[ptr] = d;
                p[ptr].first = i;
                matched[i] = ptr;
                parent[ptr] = st.top();
                break;
            case    '1':
                p[ptr].second = i;
                matched[i] = ptr;
                ptr=st.top();d--;
                st.pop();
            default:
                // do nothing
                break;
        }
    }
}

int     remove_tree(void)
{
    int t1 = matched[X];
    int t2 = matched[Y];
    
    for(;depth[t1]!=depth[t2];)
    {
        if( depth[t1] < depth[t2] )
        {
            t2 = parent[t2];
        }
        else
        {
            t1 = parent[t1];
        }
    }

    for(;t1!=t2;t1=parent[t1],t2=parent[t2]);

    return  t1;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    input();
    build_tree();

    t = remove_tree();
    cout<<p[t].first<<' '<<t[p].second<<'\n';

    return  0;
}