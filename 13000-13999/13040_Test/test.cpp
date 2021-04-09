#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

int n,t,time_to_copy,m,time_to_solve[MAX_SIZE];

int take_test(void)
{
    bool    copied = false;
    int     ret,max_time_to_solve,required_time;

    ret = max_time_to_solve = required_time = 0;

    for(int i=1;i<=m;i++)
    {
        required_time += time_to_solve[i];
        max_time_to_solve = max(max_time_to_solve,time_to_solve[i]);

        if( required_time>t && copied==false )
        {
            copied = true;
            required_time -= max_time_to_solve-time_to_copy;
        }

        if( required_time > t )
        {
            break;
        }

        ret = i;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n>>t>>time_to_copy;

    for(int i=1;i<=n;i++)
    {
        cin>>m;

        for(int j=1;j<=m;j++)
        {
            cin>>time_to_solve[j];
        }

        cout<<take_test()<<'\n';
    }

    return  0;
}