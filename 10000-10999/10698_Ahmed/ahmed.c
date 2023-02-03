#include    <stdio.h>

int main(void)
{
    int T;

    scanf("%d",&T);

    for(int i=1;i<=T;i++)
    {
        int     X,Y,Z,R;
        char    O;

        scanf("%d %c %d = %d",&X,&O,&Y,&Z);

        switch(O)
        {
            case '+':R=X+Y;break;
            case '-':R=X-Y;break;
            default:break;
        }

        printf("Case %d: %s\n",i,(R==Z)?"YES":"NO");
    }

    return  0;
}