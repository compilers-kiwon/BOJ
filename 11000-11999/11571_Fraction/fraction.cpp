#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_NUM 1024

typedef pair<int,int>   State;  // first:numerator,second:fraction

int get_fraction(int numerator,int denominator,string& result)
{
    bool    visited[MAX_NUM] = {false,};
    vector<State>   num;

    for(;visited[numerator]!=true;)
    {
        State   s;

        visited[numerator] = true;

        s.first = numerator;
        s.second = (numerator*10)/denominator;
        
        num.push_back(s);
        numerator = (numerator*10)%denominator;
    }

    for(int i=0;i<num.size();i++)
    {
        if( num[i].first == numerator )
        {
            result.push_back('(');
        }

        result += to_string(num[i].second);
    }

    result.push_back(')');

    return  0;
}

int simulate(int numerator,int denominator)
{
    string  f;
    int     i = numerator/denominator;

    get_fraction(numerator%denominator,denominator,f);
    cout<<to_string(i)<<'.'<<f<<'\n';
    
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int n,d;

        cin>>n>>d;
        simulate(n,d);
    }

    return  0;
}