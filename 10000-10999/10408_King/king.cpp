#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define chr2int(c)  ((int)((c)-'0'))

int parse(const string& str,vector<int>& grades)
{
    for (int i=0;i<str.length();i++) {
        int n = chr2int(str[i]);

        if (n == 0) {
            grades.back() *= 10;
        } else {
            grades.push_back(n);
        }
    }

    return  0;
}

int get_average(const vector<int>& grades)
{
    int sum = 0;
    int avg;

    for (int i=0;i<grades.size();i++) {
        sum += grades[i];
    }

    avg = (sum*1000/grades.size()+5)/10;
    printf("%d.%02d\n",avg/100,avg%100);
    
    return  0;
}

int main(void)
{
    string      S;
    vector<int> grades;

    cin>>S;
    parse(S,grades);

    get_average(grades);
    return  0;
}