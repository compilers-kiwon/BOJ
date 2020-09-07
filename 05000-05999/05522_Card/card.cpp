#include    <iostream>

using namespace std;

#define    NUM_OF_CARDS    5

int    main(void)
{
    int    sum,i,c;
    
    for(i=1,sum=0;i<=NUM_OF_CARDS;i++)
    {
        cin>>c;
        sum += c;
    }
    cout<<sum<<endl;
    
    return    0;
}
