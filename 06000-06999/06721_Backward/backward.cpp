#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

#define remove_tailing_zeroes(num) \
    {for(;(num).length()>1&&(num).back()=='0';(num).pop_back());}

#define tail_pos(n) ((n).length()-1)

#define char2int(c) ((int)((c)-'0'))
#define int2char(i) ((char)i+'0')

int get_backward_number(string& number)
{
    remove_tailing_zeroes(number);
    reverse(number.begin(),number.end());

    return  0;
}

int add(const string& n1,const string& n2,string& ret)
{
    int carry = 0;

    for(int n1_pos=tail_pos(n1),n2_pos=tail_pos(n2);
                    n1_pos>=0||n2_pos>=0;n1_pos--,n2_pos--)
    {
        int d1 = (n1_pos>=0)?char2int(n1[n1_pos]):0;
        int d2 = (n2_pos>=0)?char2int(n2[n2_pos]):0;

        ret.push_back(int2char((d1+d2+carry)%10));
        carry = (d1+d2+carry)/10;
    }

    ret.push_back(int2char(carry));

    remove_tailing_zeroes(ret);
    reverse(ret.begin(),ret.end());

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  n1,n2,ret;

        cin>>n1>>n2;

        get_backward_number(n1);
        get_backward_number(n2);

        add(n1,n2,ret);
        get_backward_number(ret);

        cout<<ret<<'\n';
    }

    return  0;
}