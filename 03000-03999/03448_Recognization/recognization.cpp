#include    <iostream>
#include    <string>

using namespace std;

int input(string& str)
{
    for(string s;;str+=s)
    {
        getline(cin,s);
        if(s.empty()) break;
    }

    return  0;
}

int calculate(int recognized,int total)
{
    return  ((recognized*10000)/total+5)/10;
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
        ratio = calculate(count_recognized(str),str.length());

        cout<<"Efficiency ratio is "<<ratio/10;
        if(ratio%10!=0) cout<<'.'<<ratio%10;
        cout<<"%.\n";
    }

    return  0;
}