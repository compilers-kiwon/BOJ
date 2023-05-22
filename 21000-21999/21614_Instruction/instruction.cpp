#include    <iostream>
#include    <string>

using namespace std;

#define LEFT    0
#define RIGHT   1

const static string dir[] = {"right","left"};

#define char2int(c)         ((int)((c)-'0'))
#define get_dir(cur,sum)    (((sum)==0)?(cur):dir[(sum)%2])

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(string d;;)
    {
        string  inst;

        cin>>inst;
        if(inst=="99999") break;

        d = get_dir(d,char2int(inst[0])+char2int(inst[1]));
        cout<<d<<' '<<inst.substr(2)<<'\n';
    }

    return  0;
}