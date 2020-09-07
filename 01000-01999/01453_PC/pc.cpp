#include    <iostream>

using namespace std;

#define    NUM_OF_PC    100

int    main(void)
{
    bool    used[NUM_OF_PC+1];
    
    for(int i=1;i<=NUM_OF_PC;i++)
    {
        used[i] = false;
    }
    
    int    N,cnt;
    
    cin>>N;
    cnt = 0;
    
    for(int i=1;i<=N;i++)
    {
        int    s;
        
        cin>>s;
        
        if( used[s] == false )
        {
            used[s] = true;
        }
        else
        {
            ++cnt;
        }
    }
    cout<<cnt<<endl;
    
    return    0;
}
