#include    <iostream>
#include    <string>

using namespace std;

#define get_ratio(R,A)  ((((R)*10000)/(A)+5)/10)

int input(string& str)
{
    for(string s;;str+=s)
    {
        getline(cin,s);
        if(s.empty()) break;
    }

    return  0;
}

int count_recognized(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret += (str[i]!='#')?1:0;
    }

    return  ret;
}

int main(void)
{
    int N;

    cin>>N;getchar();

    for(int i=1;i<=N;i++)
    {
        string  str;
        int     ratio;

        input(str);
        ratio = get_ratio(count_recognized(str),str.length());

        cout<<"Efficiency ratio is "<<ratio/10;
        if(ratio%10!=0) cout<<'.'<<ratio%10;
        cout<<"%.\n";
    }

    return  0;
}