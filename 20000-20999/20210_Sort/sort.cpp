#include    <iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define is_number(c)    IN_RANGE('0',(c),'9')
#define is_upper(c)     IN_RANGE('A',(c),'Z')
#define is_lower(c)     IN_RANGE('a',(c),'z')

string  get_number(const string& str,int& pos)
{
    string  ret;

    for(;pos<str.length()&&is_number(str[pos]);pos++)
    {
        ret.push_back(str[pos]);
    }

    return  ret;
}

int get_idx(char c)
{
    int idx = (int)(c-(is_upper(c)?'A':'a'))*2;

    return  idx+(is_lower(c)?1:0);
}

int remove_leading_zeroes(string& num)
{
    int num_of_leading_zeroes = 0;

    for(int i=0;i<num.length()-1&&num[i]=='0';i++)
    {
        num_of_leading_zeroes++;
    }

    num.erase(0,num_of_leading_zeroes);

    return  num_of_leading_zeroes;
}

bool    is_less(const string& str1,const string& str2)
{
    for(int p1=0,p2=0;p1<str1.length()&&p2<str2.length();p1++,p2++)
    {
        char    c1 = str1[p1];
        char    c2 = str2[p2];

        if( is_number(c1) != is_number(c2) )
        {
            return  is_number(c1);
        }

        if( is_number(c1)==true && is_number(c2)==true )
        {
            string  num1,num2;
                        
            num1 = get_number(str1,p1);
            num2 = get_number(str2,p2);

            int num_of_leading_zeroes_of_num1 = remove_leading_zeroes(num1);
            int num_of_leading_zeroes_of_num2 = remove_leading_zeroes(num2);

            if( num1.length() != num2.length() )
            {
                return  (num1.length()<num2.length());
            }

            if( num1 != num2 )
            {
                return  (num1<num2);
            }

            if( num_of_leading_zeroes_of_num1 != num_of_leading_zeroes_of_num2 )
            {
                return  (num_of_leading_zeroes_of_num1<num_of_leading_zeroes_of_num2);
            }

            p1--;p2--;
        }
        else
        {
            int idx_of_c1 = get_idx(c1);
            int idx_of_c2 = get_idx(c2);

            if( idx_of_c1 != idx_of_c2 )
            {
                return  (idx_of_c1<idx_of_c2);
            }
        }
    }

    return  (str1.length()<str2.length());
}

int input(vector<string>& s)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  str;

        cin>>str;
        s.push_back(str);
    }

    return  0;
}

int print(const vector<string>& s)
{
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string>  s;

    input(s);
    sort(s.begin(),s.end(),is_less);
    print(s);

    return  0;
}