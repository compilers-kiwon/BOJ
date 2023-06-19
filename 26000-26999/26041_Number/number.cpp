#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define get_prefix(str,len) ((str).substr(0,(len)))

int input(vector<string>& numbers)
{
    for(;;)
    {
        string  num;

        cin>>num;
        if(num.empty()) break;
        numbers.push_back(num);
    }

    return  0;
}

int compare(const vector<string>& numbers)
{
    int ret = 0;
    int len_of_prefix = numbers.back().length();

    for(int i=0;i<numbers.size()-1;i++)
    {
        if(numbers[i].length()<=len_of_prefix) continue;
        ret += (get_prefix(numbers[i],len_of_prefix)==numbers.back())?1:0;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string>  numbers;

    input(numbers);
    cout<<compare(numbers)<<'\n';

    return  0;
}