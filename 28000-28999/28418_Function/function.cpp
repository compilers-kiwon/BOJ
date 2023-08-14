#include    <iostream>

using namespace std;

#define INF 0x7FFFFFFF

typedef struct {int a,b,c;} Function;

static Function f,g,p,q,r;

#define get_discriminant(e) ((e).b*(e).b-4*(e).a*(e).c)

int get_p(void)
{
    p.a = f.a*(g.b*g.b);
    p.b = 2*f.a*g.b*g.c+f.b*g.b;
    p.c = f.a*(g.c*g.c)+f.b*g.c+f.c;
    
    return  0;
}

int get_q(void)
{
    q.a = f.a*g.b;
    q.b = f.b*g.b;
    q.c = f.c*g.b+g.c;

    return  0;
}

int determine(void)
{
    r.a = p.a-q.a;
    r.b = p.b-q.b;
    r.c = p.c-q.c;

    if (r.a==0) {
        if(r.b==0 && r.c==0) return INF;
        if(r.b==0 && r.c!=0) return 0;
        return  1;
    }

    int d = get_discriminant(r);
    return  (d==0)?1:(d>0)?2:0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>f.a>>f.b>>f.c>>g.b>>g.c;
    get_p();get_q();

    switch (determine()) {
        case 0:cout<<"Head on\n";break;
        case 1:cout<<"Remember my character\n";break;
        case 2:cout<<"Go ahead\n";break;
        case INF:cout<<"Nice\n";break;
        default:/*do nothing*/;break;
    }

    return  0;
}