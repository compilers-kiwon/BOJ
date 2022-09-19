#include    <iostream>
#include    <string>
#include    <stack>

using namespace std;

#define chr2int(c)          ((int)((c)-'0'))
#define PAREN               (-1)
#define mark_paren(st)      (st).push(PAREN)
#define is_tail(pos,s)      ((pos)==(s).length()-1)
#define get_element(n,st)   {(n)=(st).top();(st).pop();}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string      str;
    stack<int>  st;

    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        int tmp;

        switch(str[i])
        {
            case    '(':
                mark_paren(st);
                break;
            case    ')':
                for(int len=0;!st.empty();)
                {
                    get_element(tmp,st);

                    if( tmp == PAREN )
                    {
                        get_element(tmp,st);
                        st.push(len*tmp);
                        break;    
                    }

                    len += tmp;
                }
                break;
            default:
                if( !is_tail(i,str) && str[i+1]=='(' )
                {
                    st.push(chr2int(str[i]));
                }
                else
                {
                    st.push(1);
                }
                break;
        }
    }

    int sum = 0;

    for(;!st.empty();st.pop())
    {
        sum += st.top();
    }

    cout<<sum<<'\n';

    return  0;
}