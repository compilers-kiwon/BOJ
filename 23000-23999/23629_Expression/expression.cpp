#include    <iostream>
#include    <string>
#include    <vector>
#include    <map>
#include    <cmath>

using namespace std;

#define TRUE    1
#define FALSE   0

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef long long int   int64;

static map<string,int64> str2num = {
    {"ZERO",0},{"ONE",1},{"TWO",2},{"THREE",3},{"FOUR",4},
    {"FIVE",5},{"SIX",6},{"SEVEN",7},{"EIGHT",8},{"NINE",9}
};

const static string digit[10] = {
    "ZERO","ONE","TWO","THREE","FOUR",
    "FIVE","SIX","SEVEN","EIGHT","NINE"
};

#define ADD     (-1)
#define SUB     (-2)
#define MUL     (-3)
#define DIV     (-4)
#define EQUAL   (-5)

#define wrong_expression_and_exit()  {cout<<"Madness!\n";return 0;}

int64   get_operator(char c)
{
    int64   ret = FALSE;

    switch(c)
    {
        case '+':ret=ADD;break;
        case '-':ret=SUB;break;
        case 'x':ret=MUL;break;
        case '/':ret=DIV;break;
        case '=':ret=EQUAL;break;
        default:/*do nothing*/;break;
    }

    return  ret;
}

int64   get_number(const string& str,int64& val)
{
    string  num;

    for(int i=0;i<str.length();i++)
    {
        num.push_back(str[i]);

        if( str2num.find(num) != str2num.end() )
        {
            val = val*10+str2num[num];
            num.clear();
        }   
    }

    return  (!num.empty()||val==0)?FALSE:TRUE;
}

int is_expr(const string& str,vector<int64>& expr)
{
    string  num;

    for(int i=0;i<str.length();i++)
    {
        char    c = str[i];
        int64   op;

        if( (op=get_operator(c)) != FALSE )
        {
            int64   n = 0;

            if( num.empty() || get_number(num,n)==FALSE )
            {
                return  FALSE;
            }

            expr.push_back(n);
            expr.push_back(op);

            if( op == EQUAL )
            {
                break;
            }

            num.clear();
        }
        else
        {
            num.push_back(c);
        }
    }

    return  TRUE;
}

int64   calculate(const vector<int64>& expr)
{
    int64   ret = expr.front();

    for(int i=1;i<expr.size();i+=2)
    {
        if( expr[i] == EQUAL )
        {
            break;
        }

        switch(expr[i])
        {
            case ADD:ret+=expr[i+1];break;
            case SUB:ret-=expr[i+1];break;
            case MUL:ret*=expr[i+1];break;
            case DIV:ret/=expr[i+1];break;
            default:/*do nothing*/;break;
        }
    }

    return  ret;
}

char    get_op_ch(int64 op)
{
    return  (op==ADD)?'+':(op==SUB)?'-':
                (op==MUL)?'x':(op==DIV)?'/':'=';
}

string  num2str(int64 num)
{
    string  ret;
    string  sign = (num<0)?"-":"";

    if( num == 0 )
    {
        return  "ZERO";
    }

    for(num=abs(num);num>0;num/=10)
    {
        ret = digit[num%10]+ret;
    }

    return  sign+ret;
}

int print(const vector<int64>& expr)
{
    for(int i=0;i<expr.size();i++)
    {
        int64   n = expr[i];

        if( n > 0 )
        {
            cout<<n;
        }
        else
        {
            cout<<get_op_ch(n);
        }
    }

    cout<<'\n'<<num2str(calculate(expr))<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string          S;
    vector<int64>   expr;

    cin>>S;

    if( !IN_RANGE('A',S.front(),'Z')
            || S.find('=')!=S.length()-1 )
    {
        wrong_expression_and_exit();
    }

    if( is_expr(S,expr) == FALSE )
    {
        wrong_expression_and_exit();
    }

    print(expr);

    return  0;
}