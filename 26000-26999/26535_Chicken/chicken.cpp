#include    <iostream>
#include    <string>

using namespace std;

#define PEN     'x'
#define EMPTY   '.'
#define LOWER   3

#define get_num_of_empty_in_square(len) ((len)*(len)-4*((len)-1))

int draw_sqaure_pen(int size)
{
    for (int row=1;row<=size;row++) {
        if(row==1 || row==size) {
            cout<<string(size,PEN)<<'\n';
        } else {
            cout<<PEN<<string(size-2,EMPTY)<<PEN<<'\n';
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_chickens;

    cin>>num_of_chickens;

    for (int i=LOWER;;i++) {
        if (get_num_of_empty_in_square(i) >= num_of_chickens) {
            draw_sqaure_pen(i);
            break;
        }
    }

    return  0;
}