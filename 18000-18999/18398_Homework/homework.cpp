#include    <iostream>

using namespace std;

int    main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int    T;
    
    cin>>T;
    
    for(int t=1;t<=T;t++)
    {
        int    N;
        
        cin>>N;
        
        for(int n=1;n<=N;n++)
        {
            int    A,B;
            
            cin>>A>>B;
            cout<<A+B<<' '<<A*B<<'\n';
        }
    }
    
    return    0;
}