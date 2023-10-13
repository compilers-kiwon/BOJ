#include    <iostream>
#include    <string>

using namespace std;

typedef unsigned int    uint32;

const static uint32 NUM_OF_LETTERS = 26;
const static string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static inline uint32    get_offset(uint32 a,uint32 b)
{
    if (b == 0) return 1;
    if (a == 0) return 0;

    uint32  ret = 1;
    
    for (uint32 i=1;i<=b;i++) {
        ret=(ret*(a%NUM_OF_LETTERS))%NUM_OF_LETTERS;
    }

    return  ret;
}

static inline char  decrypt(char en,uint32 offset)
{
    uint32  pos = (uint32)(en-'A');
    return  str[(pos+NUM_OF_LETTERS-offset)%NUM_OF_LETTERS];
}

int main(void)
{
    uint32  n,a,b,offset;
    string  enc;

    cin>>n>>a>>b;
    getchar();

    getline(cin,enc);
    offset = get_offset(a,b);

    for (int i=0;i<enc.length();i++) {
        char&   c = enc[i];
        cout<<(c==' '?' ':decrypt(c,offset));    
    }

    cout<<'\n';
    return  0;
}