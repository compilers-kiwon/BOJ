#include <iostream>

using namespace std;

#define NUM_OF_DWARF 9

int main(void)
{
	int sum,i,dwarf[NUM_OF_DWARF];
	bool    found;
    
	for(sum=i=0;i<NUM_OF_DWARF;i++)
	{
		cin>>dwarf[i];
		sum += dwarf[i];
	}
	
    found = false;
    
	for(int i=0;i<NUM_OF_DWARF-1;i++)
	{
		sum -= dwarf[i];
		dwarf[i] = -dwarf[i];
		
		for(int j=i+1;j<NUM_OF_DWARF;j++)
		{
			sum -= dwarf[j];
			dwarf[j] = -dwarf[j];
			
			if( sum == 100 )
			{
				for(int k=0;k<NUM_OF_DWARF;k++)
				{
					if( dwarf[k] > 0 )
					{
						cout<<dwarf[k]<<endl;
					}
				}
                found = true;
				break;
			}
			
			dwarf[j] = -dwarf[j];
			sum += dwarf[j];
		}
		
		if( found == true )
		{
			break;
		}
		
		dwarf[i] = -dwarf[i];
		sum += dwarf[i];
	}
	return 0;
}
