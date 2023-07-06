#include    <iostream>

using namespace std;

#define get_num_of_required_edges_for_tree(num_of_nodes)    ((num_of_nodes)-1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int N,M;

        cin>>N>>M;
        cout<<"Case "<<t<<": "<<
            M-get_num_of_required_edges_for_tree(N)<<'\n';
    }

    return  0;
}