#include    <iostream>

using namespace std;

int    main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int    N,A,last_num;
    
    cin>>N;
    last_num = 0;
    
    for(int i=1;i<=N;i++)
    {
        cin>>A;
        last_num = max(last_num,A);
    }
    
    cout<<last_num<<'\n';
    
    return    0;
}