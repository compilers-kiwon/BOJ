#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int W,H,w,h,n1,n2;

    cin>>W>>H>>w>>h;
    
    n1 = W/min(W,2*w)+((W%min(W,2*w))>=w?1:0);
    n2 = H/min(H,2*h)+((H%min(H,2*h))>=h?1:0);

    cout<<n1*n2<<'\n';

    return  0;
}