#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define NO_CHILD    ' '

typedef pair<char,char> Children;

char    build_tree(string pre,string in,
                    map<char,Children>& tree)
{
    if( pre.empty() )
    {
        return  NO_CHILD;
    }

    char    ret = pre[0];
    string  next_in,next_pre;
    int     in_pos,pre_pos;
    
    for(in_pos=0,pre_pos=1;in[in_pos]!=ret;in_pos++,pre_pos++)
    {
        next_in.push_back(in[in_pos]);
        next_pre.push_back(pre[pre_pos]);
    }
    
    tree[ret].first = build_tree(next_pre,next_in,tree);
    
    next_pre.clear();next_in.clear();

    for(++in_pos;in_pos<in.length();in_pos++,pre_pos++)
    {
        next_in.push_back(in[in_pos]);
        next_pre.push_back(pre[pre_pos]);
    }
    
    tree[ret].second = build_tree(next_pre,next_in,tree);

    return  ret;
}

void    print_postorder(char c,map<char,Children>& tree)
{
    char    left = tree[c].first;
    char    right = tree[c].second;

    if( left != NO_CHILD )
    {
        print_postorder(left,tree);
    }

    if( right != NO_CHILD )
    {
        print_postorder(right,tree);
    }

    cout<<c;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        char    root;
        string  pre,in;
        map<char,Children>  tree;

        cin>>pre>>in;

        if( pre.empty() && in.empty() )
        {
            break;
        }

        root = build_tree(pre,in,tree);
        
        print_postorder(root,tree);
        cout<<'\n';
    }

    return  0;
}