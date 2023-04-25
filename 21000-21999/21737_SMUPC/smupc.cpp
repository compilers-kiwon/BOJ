#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define NONE    ' '

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int get_number(const string& str,int& ptr)
{
    string  num;

    for(;IN_RANGE('0',str[ptr],'9');ptr++)
    {
        num.push_back(str[ptr]);
    }

    return  stoi(num);
}

int calculate(int n1,int n2,int op)
{
    int ret;

    switch(op)
    {
        case 'S':ret=n1-n2;break;
        case 'M':ret=n1*n2;break;
        case 'U':ret=n1/n2;break;
        case 'P':ret=n1+n2;break;
        default:break;
    }
    
    return  ret;
}

int interprete(const string& str,vector<int>& out)
{
    int prev_num = 0;
    int op = NONE;

    for(int i=0;i<str.length();)
    {
        if( IN_RANGE('0',str[i],'9') )
        {
            int current_num = get_number(str,i);

            if( op != NONE )
            {
                prev_num = calculate(prev_num,current_num,op);
            }
            else
            {
                prev_num = current_num;
            }
        }
        else
        {
            switch(str[i])
            {
                case 'C':out.push_back(prev_num);break;
                default:op=str[i];break;
            }

            i++;
        }
    }

    return  0;
}

int print(const vector<int>& numbers)
{
    if( numbers.empty() )
    {
        cout<<"NO OUTPUT\n";
    }
    else
    {
        for(int i=0;i<numbers.size();i++)
        {
            cout<<numbers[i]<<
                ((i==numbers.size()-1)?'\n':' ');
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N;
    string      expr;
    vector<int> out_buf;

    cin>>N>>expr;
    
    interprete(expr,out_buf);
    print(out_buf);

    return  0;
}