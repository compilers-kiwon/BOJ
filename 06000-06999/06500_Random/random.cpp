#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

#define LEN_OF_NUMBER   4

#define square(num)     (to_string(stoi((num))*stoi((num))))
#define get_mid(num)    ((num).substr(LEN_OF_NUMBER/2,LEN_OF_NUMBER))

#define align_number(num,head) \
    for(;(num).length()<2*LEN_OF_NUMBER;(num).insert((num).begin(),(head)))

int simulate(string num)
{
    set<string> random_numbers;

    for(random_numbers.insert(num);;)
    {
        string  tmp;

        tmp = square(num);
        align_number(tmp,'0');
        tmp = get_mid(tmp);

        if( random_numbers.find(tmp) != random_numbers.end() )
        {
            break;
        }

        random_numbers.insert(tmp);
        num = tmp;
    }

    return  random_numbers.size();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  num;

        cin>>num;

        if( num == "0" )
        {
            break;
        }

        cout<<simulate(num)<<'\n';
    }

    return  0;
}