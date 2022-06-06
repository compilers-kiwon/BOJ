#include    <iostream>

using namespace std;

#define input(a,b,c)        (cin>>(a)>>(b)>>(c))
#define max_value(a,b,c)    (max((a),max((b),(c))))
#define get_sum(a,b,c)      ((a)+(b)+(c))
#define is_triangle(a,b,c)  (get_sum((a),(b),(c))>2*max_value((a),(b),(c)))
#define get_sign(n)         ((n)>0?1:(n)<0?-1:0)
#define evaluate(a,b,c)     ((a)*(a)+(b)*(b)+(c)*(c)-2*max_value((a),(b),(c))*max_value((a),(b),(c)))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_acute,num_of_obtuse,num_of_right;

    for(num_of_acute=num_of_obtuse=num_of_right=0;;)
    {
        int a,b,c;

        input(a,b,c);

        if( is_triangle(a,b,c) == false )
        {
            break;
        }

        switch(get_sign(evaluate(a,b,c)))
        {
            case    1:
                num_of_acute++;
                break;
            case    -1:
                num_of_obtuse++;
                break;
            case    0:
                num_of_right++;
                break;
            default:
                // do nothing
                break;
        }
    }

    cout<<get_sum(num_of_acute,num_of_obtuse,num_of_right)
        <<' '<<num_of_right<<' '<<num_of_acute<<' '<<num_of_obtuse<<'\n';

    return  0;
}