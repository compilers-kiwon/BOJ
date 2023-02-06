#include    <iostream>
#include    <string>

using namespace std;

#define WRONG_BIT           '9'
#define read_wrong_bit(b)   ((b).find(WRONG_BIT)!=string::npos)

int main(void)
{
    string  bits;

    getline(cin,bits);
    cout<<(read_wrong_bit(bits)?'F':'S')<<'\n';

    return  0;
}