#include    <iostream>
#include    <string>

using namespace std;

const string illegible = "069";

int change_number(string& number)
{
    for(int i=0;i<number.length();i++)
    {
        char&   c = number[i];

        if( illegible.find(c) != string::npos )
        {
            c = '9';
        }
    }

    return  0;
}

int get_average(int sum,int num)
{
    return  ((sum*10)/num+5)/10;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,sum;

    cin>>N;
    sum = 0;

    for(int i=1;i<=N;i++)
    {
        string  Q;

        cin>>Q;
        change_number(Q);

        sum += min(stoi(Q),100);
    }

    cout<<get_average(sum,N)<<'\n';

    return  0;
}