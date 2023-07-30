#include    <iostream>
#include    <string>

using namespace std;

#define get_degree(c) \
    ((c)=='N'?0:(c)=='W'?90:(c)=='S'?180:270)

int get_change_of_degree(char d1,char d2)
{
    int t1 = get_degree(d1);
    int t2 = get_degree(d2);

    return  ((t1+90)%360==t2)?90:
                ((t1+270)%360==t2)?-90:0;
}

bool    is_clockwise(const string& steps)
{
    int sum_of_degrees = 0;

    for(int i=0;i<steps.length();i++)
    {
        sum_of_degrees += 
            get_change_of_degree(steps[i],steps[(i+1)%steps.length()]);
    }

    return  (sum_of_degrees==360)?false:true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  str;

        cin>>str;
        cout<<(is_clockwise(str)?"CW":"CCW")<<'\n';
    }

    return  0;
}