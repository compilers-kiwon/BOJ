#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define chr2int(c)  ((int)((c)-'0'))

#define update_number(num,digit_sum,new_digit) \
    ((num)=(num)*10+(new_digit),(digit_sum)+=(new_digit))

int divide_number(const string& number,int& x,int& y)
{
    int x_cnt,y_cnt;

    x = y = x_cnt = y_cnt = 0;

    for (int i=0;i<number.length();i++) {
        int d,big,small;
        
        d = chr2int(number[i]);
        small = d/2;
        big = d/2+(d%2==0?0:1);

        if (x_cnt >= y_cnt) {
            update_number(x,x_cnt,small);
            update_number(y,y_cnt,big);
        } else {
            update_number(x,x_cnt,big);
            update_number(y,y_cnt,small);
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for (int i=1;i<=t;i++) {
        string  n;
        int     x,y;

        cin>>n;
        divide_number(n,x,y);
        cout<<x<<' '<<y<<'\n';
    }

    return  0;
}