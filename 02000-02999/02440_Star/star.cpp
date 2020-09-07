#include    <iostream>
#include    <string>

using namespace std;

typedef    unsigned int    uint32;

string    stars[11] = 
{
    "",
    "*",
    "**",
    "***",
    "****",
    "*****",
    "******",
    "*******",
    "********",
    "*********",
    "**********"
};

int    main(void)
{
    uint32    N,a,b,c,i,j;
    
    cin>>N;
    
    for(c=N;c>=1;c--)
    {
    	a = c/10;
    	b = c%10;
    	
    	for(i=1;i<=a;i++)
    	{
    		cout<<stars[10];
		}
		cout<<stars[b]<<endl;
	}
    return    0;
}
