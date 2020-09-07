#include <iostream>
#include <algorithm>

using namespace std;

#define ENTRY_SIZE 10

int main(void)
{
    int W[ENTRY_SIZE],K[ENTRY_SIZE];
    
    for(int i=0;i<ENTRY_SIZE;i++)
    {
        cin>>W[i];
    }
    sort(&W[0],&W[ENTRY_SIZE]);
    
    for(int i=0;i<ENTRY_SIZE;i++)
    {
        cin>>K[i];
    }
    sort(&K[0],&K[ENTRY_SIZE]);
    
    int W_sum = W[ENTRY_SIZE-1]+W[ENTRY_SIZE-2]+W[ENTRY_SIZE-3];
    int K_sum = K[ENTRY_SIZE-1]+K[ENTRY_SIZE-2]+K[ENTRY_SIZE-3];
    
    cout<<W_sum<<' '<<K_sum<<endl;
    
    return 0;
}
