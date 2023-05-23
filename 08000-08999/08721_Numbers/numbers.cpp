#include    <iostream>

using namespace std;

#define is_in_sequence(small,big)   ((small)+1==(big))

int get_sequence(int size)
{
    int ret = 0;

    for(int prev_num=0,i=1;i<=size;i++)
    {
        int current_num;

        cin>>current_num;

        if( is_in_sequence(prev_num,current_num) )
        {
            ret++;
            prev_num++;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,seq;

    cin>>n;
    seq = get_sequence(n);

    cout<<n-seq<<'\n';
    return  0;
}