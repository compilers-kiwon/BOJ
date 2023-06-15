#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define get_dec_from_hex(h) (IN_RANGE('0',(h),'9')?(h)-'0':(h)-'A'+10)

#define HEX_BASE    16
#define OCT_BASE    8
#define DEC_BASE    10

#define LEN_OF_HEX_FOR_OCT  3
#define LEN_OF_OCT_FOR_HEX  4

int input(string& num)
{
    for(cin>>num;num.length()%LEN_OF_HEX_FOR_OCT!=0;
        num.insert(num.begin(),'0'));
    return  0;
}

int get_oct_from_hex(string h)
{
    int d,ret;
    
    d = ret = 0;

    for(int i=0;i<h.length();i++)
    {
        d = d*HEX_BASE+get_dec_from_hex(h[i]);
    }

    for(int pos=1;d>0;d/=OCT_BASE,pos*=DEC_BASE)
    {
        ret = ret+(d%OCT_BASE)*pos;
    }

    return  ret;
}

int convert(const string& h,vector<string>& o)
{
    for(int i=0;i<h.length();i+=LEN_OF_HEX_FOR_OCT)
    {
        int oct_num = get_oct_from_hex(h.substr(i,LEN_OF_HEX_FOR_OCT));

        for(o.push_back(to_string(oct_num));
            i!=0&&o.back().length()<LEN_OF_OCT_FOR_HEX;
            o.back().insert(o.back().begin(),'0'));
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string          hex;
    vector<string>  oct;

    input(hex);
    convert(hex,oct);

    for(int i=0;i<oct.size();i++)
    {
        cout<<oct[i];
    }

    cout<<'\n';
    return  0;
}