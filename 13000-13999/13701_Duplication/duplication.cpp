#include	<iostream>

using namespace	std;

#define	MAX_TABLE_LEN	0x400000
#define	BIT_LEN_OF_BYTE	8

#define	GET_BYTE_INDEX(n)	((n)/BIT_LEN_OF_BYTE)
#define	GET_BIT_INDEX(n)	((n)%BIT_LEN_OF_BYTE)

typedef	unsigned char	uint8;

uint8	table[MAX_TABLE_LEN];

const uint8	bit_mask[BIT_LEN_OF_BYTE] = {1,2,4,8,16,32,64,128};

int	main(void)
{
	int	A;
	
	while( scanf("%d",&A) == 1 )
	{
		int	byte_index,bit_index;
		
		byte_index = GET_BYTE_INDEX(A);
		bit_index = GET_BIT_INDEX(A);
		
		if( !(table[byte_index]&bit_mask[bit_index]) )
		{
			printf("%d ",A);
			table[byte_index] |= bit_mask[bit_index];
		}
	}
	
	return	0;
}
