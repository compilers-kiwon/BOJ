#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define is_american_format(d)           ((d).find('/')!=string::npos)
#define print_european_format(y,m,d)    (cout<<(d)<<'.'<<(m)<<'.'<<(y))
#define print_american_format(y,m,d)    (cout<<(m)<<'/'<<(d)<<'/'<<(y))

int parse_date(string& str,vector<string>& s)
{
    char    separator;
    string  cur;

    separator = is_american_format(str)?'/':'.';
    str.push_back(separator);

    for (int i=0;i<str.length();i++) {
        if(str[i] == separator) {
            s.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(str[i]);
        }
    }

    return  0;
}

int fill_zero(string& s,int len) {
    for(;s.length()<len;s.insert(s.begin(),'0'));
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for (int i=1;i<=n;i++) {
        string          date;
        vector<string>  numbers;

        cin>>date;
        parse_date(date,numbers);

        fill_zero(numbers[0],2);
        fill_zero(numbers[1],2);
        fill_zero(numbers[2],4);

        string  year,month,day;

        if (is_american_format(date)) {
            month = numbers[0];
            day = numbers[1];    
        } else {
            month = numbers[1];
            day = numbers[0];
        }

        year = numbers[2];

        print_european_format(year,month,day);
        cout<<' ';
        print_american_format(year,month,day);
        cout<<'\n';
    }

    return  0;
}