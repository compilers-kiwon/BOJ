#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

typedef long long int   int64;

#define chr2int64(c)        (int64)((c)-'0')
#define scale_num(arr,idx) \
    ((arr)[(idx)-1]*(arr)[(idx)]*(arr)[(idx)+1])

int get_numbers(const string& str,
                    vector<int64>& numbers)
{
    int     ret = 0;
    int64   cur = 0;

    for (int i=0;i<str.length();i++) {
        if (str[i] == ' ') {
            numbers.push_back(cur);
            cur = 0;
            ret++;
        } else {
            cur = cur*10+chr2int64(str[i]);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;) {
        string  str;
        
        getline(cin,str);

        if (str.empty()) break;

        int             num_of_numbers;
        vector<int64>   numbers;

        str.push_back(' ');
        numbers.push_back(1);

        num_of_numbers = get_numbers(str,numbers);
        numbers.push_back(1);

        for (int i=1;i<=num_of_numbers;i++) {
            cout<<scale_num(numbers,i)<<' ';
        }

        cout<<'\n';
    }

    return  0;
}