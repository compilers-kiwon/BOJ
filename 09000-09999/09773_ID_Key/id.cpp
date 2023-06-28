#include    <iostream>
#include    <string>

using namespace std;

#define NUM_LEN     13
#define TAIL_LEN    3
#define ID_LEN      4

#define ALLOW_LEADING_ZERO(w)   {cout.fill('0');cout.width((w));}

#define _4_digits           9999
#define _3_digits           999
#define scaler_of_4_digits  1000
#define get_4_digits(n)     ((n)%10000)

int get_sum_of_digits(const string& num)
{
    int ret = 0;

    for(int i=0;i<num.length();i++)
    {
        ret += (int)(num[i]-'0');
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string  str;
    int     N,tmp1,tmp2;

    cin>>N;

    for(int n=1;n<=N;n++)
    {
        cin>>str;

        tmp1 = get_sum_of_digits(str);
        tmp2 = stoi(str.substr(NUM_LEN-TAIL_LEN,TAIL_LEN))*10;
    
        ALLOW_LEADING_ZERO(ID_LEN);
        cout<<((tmp1+tmp2)>_4_digits?get_4_digits(tmp1+tmp2):
                    (tmp1+tmp2)+((tmp1+tmp2)<=_3_digits?scaler_of_4_digits:0))<<'\n';
    }

    return  0;
}