#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_LEN		(30+1)

#define	FULL		0
#define	PARTIAL		1
#define	MAX_PART	2

uint64	tile_table[MAX_LEN][MAX_PART];

int		main(void)
{
	uint64	N;
	
	tile_table[0][FULL] = 1;tile_table[1][PARTIAL] = 0;
	tile_table[1][FULL] = 0;tile_table[1][PARTIAL] = 1;
	
	cin>>N;
	
	for(uint64 i=2;i<=N;i++)
	{
		tile_table[i][FULL] = tile_table[i-2][FULL]+2*tile_table[i-1][PARTIAL];
		tile_table[i][PARTIAL] = tile_table[i-1][FULL]+tile_table[i-2][PARTIAL];
	}
	cout<<tile_table[N][FULL];
	
	return	0;
}
