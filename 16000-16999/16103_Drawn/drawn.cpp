#include    <iostream>
#include    <string>

using namespace std;

#define NUM_OF_BLOCKS   4
#define NUM_OF_PATTERNS 3

typedef long long int   int64;

const static int block_order[NUM_OF_PATTERNS][NUM_OF_BLOCKS] = {
    {0,1,2,3},{0,3,1,2},{0,2,3,1}
};

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,size_of_each_block;
    int64   K;
    string  S,block_str[NUM_OF_BLOCKS];

    cin>>N>>K>>S;
    size_of_each_block = S.length()/NUM_OF_BLOCKS;

    for (int i=0,p=0;i<NUM_OF_BLOCKS;
                p+=size_of_each_block,i++) {
        block_str[i] = S.substr(p,size_of_each_block);
    }

    for (int i=0;i<NUM_OF_BLOCKS;i++) {
        int block_ptr = block_order[K%NUM_OF_PATTERNS][i];
        cout<<block_str[block_ptr];
    }

    cout<<'\n';
    return  0;
}