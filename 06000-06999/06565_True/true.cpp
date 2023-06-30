#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

#define MAX_LEN         (7+1)
#define reverse_str(s)  (reverse((s).begin(),(s).end()))

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

string  calculate(string& a,string &b,string& c)
{
    reverse_str(a);reverse_str(b);reverse_str(c);
    return  (stoi(c)==stoi(a)+stoi(b))?"True":"False";
}

string  get_num(const string& e,int& pos)
{
    string  ret;

    for(pos++;pos<e.length()&&IN_RANGE('0',e[pos],'9');pos++)
    {
        ret.push_back(e[pos]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    for(;;)
    {
        string  a,b,c,exp;
        int     pos = -1;

        cin>>exp;

        a = get_num(exp,pos);
        b = get_num(exp,pos);
        c = get_num(exp,pos);
        
        cout<<calculate(a,b,c)<<'\n';
        if( a=="0" && b=="0" && c=="0") break;
    }

    return  0;
}