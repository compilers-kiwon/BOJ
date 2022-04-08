#include    <iostream>
#include    <set>

using namespace std;

typedef unsigned long long  uint64;
typedef pair<int,uint64>    Node;   // first:value,second:height

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N;
    uint64      sum;
    set<Node>   tree;

    cin>>N;
    sum = 0;

    for(int i=1;i<=N;i++)
    {
        Node                new_node;
        set<Node>::iterator left,right;

        cin>>new_node.first;
        
        if( tree.empty() )
        {
            new_node.second = 1;
            tree.insert(new_node);

            sum += new_node.second;
            continue;
        }

        right = tree.lower_bound(new_node);

        if( right == tree.begin() )
        {
            new_node.second = right->second+1;
            tree.insert(new_node);

            sum += new_node.second;
            continue;
        }

        if( right == tree.end() )
        {
            left=right;left--;
            new_node.second = left->second+1;

            tree.insert(new_node);
            sum += new_node.second;

            continue;
        }

        left=right;left--;
        new_node.second = max(left->second,right->second)+1;

        tree.insert(new_node);
        sum += new_node.second;
    }

    cout<<sum<<'\n';

    return  0;
}