#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_SIZE    10
#define Mack_Number 18
#define Zack_Number 17

const static string state[4] = {"none","zack","mack","both"};

int find_twins(const vector<int>& numbers)
{
    int ret = 0;

    for(int i=0;i<MAX_SIZE;i++)
    {
        cout<<numbers[i]<<((i==MAX_SIZE-1)?'\n':' ');

        switch(numbers[i])
        {
            case Mack_Number:ret|=(1<<1);break;
            case Zack_Number:ret|=(1<<0);break;
            default:/*do nothing*/;break;
        }
    }

    return  ret;
}

int input(vector<int>& numbers)
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        int n;

        cin>>n;
        numbers.push_back(n);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        vector<int> numbers;

        input(numbers);
        cout<<state[find_twins(numbers)]<<"\n\n";
    }

    return  0;
}