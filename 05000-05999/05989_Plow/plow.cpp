#include    <iostream>

using namespace std;

const static int MAX_SIZE = 240+1;

static bool squares[MAX_SIZE][MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X,Y,I,cnt;

    cin>>X>>Y>>I;
    cnt = 0;

    for (int i=1;i<=I;i++) {
        int Xll,Yll,Xur,Yur;

        cin>>Xll>>Yll>>Xur>>Yur;

        for (int y=Yll;y<=Yur;y++) {
            for (int x=Xll;x<=Xur;x++) {
                cnt += (!squares[y][x])?1:0;
                squares[y][x] = true;
            }
        }
    }

    cout<<cnt<<'\n';
    return  0;
}