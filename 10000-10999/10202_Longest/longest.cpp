#include    <iostream>

using namespace std;

int get_longest_length(int total_length)
{
    int ret,cur,i;

    for (ret=cur=0,i=1;i<=total_length;i++) {
        char    c;

        cin>>c;
        (c=='X')?cur++:cur=0;
        ret = max(ret,cur);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for (int i=1;i<=N;i++) {
        int s;

        cin>>s;
        cout<<"The longest contiguous subsequence of X\'s is of length "
            <<get_longest_length(s)<<'\n';
    }

    return  0;
}