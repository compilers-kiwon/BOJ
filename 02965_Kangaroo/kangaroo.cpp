#include <iostream>

using namespace std;

int main(void)
{
    int A,B,C;
    
    cin>>A>>B>>C;
    
    int max_diff;
    max_diff = max(B-A,C-B);
    
    cout<<max_diff-1<<endl;
    
    return 0;
}
