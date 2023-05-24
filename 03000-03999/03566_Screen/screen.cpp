#include    <iostream>

using namespace std;

#define INF 0x7FFFFFFF

#define get_num_of_required(num,lower1,n1,lower2,n2) \
    {for((num)=0;(n1)*(num)<(lower1)||(n2)*(num)<(lower2);(num)++);}

typedef struct{int rh,rv,sh,sv;} Product;

int input(Product& info,int& num)
{
    cin>>info.rh>>info.rv>>info.sh>>info.sv>>num;
    return  0;
}

int rotate(const Product& src,Product& dst)
{
    dst = {src.rv,src.rh,src.sv,src.sh};
    return  0;
}

int get_cost(const Product& f,const Product& p,int price)
{
    int w,h;

    get_num_of_required(w,f.rh,p.rh,f.sh,p.sh);
    get_num_of_required(h,f.rv,p.rv,f.sv,p.sv);

    return  w*h*price;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Product finished;
    int     n,min_cost;

    min_cost = INF;
    input(finished,n);

    for(int i=1;i<=n;i++)
    {
        int     p;
        Product part1,part2;

        input(part1,p);
        rotate(part1,part2);

        min_cost = min(min_cost,
            min(get_cost(finished,part1,p),get_cost(finished,part2,p))
        );
    }

    cout<<min_cost<<'\n';

    return  0;
}