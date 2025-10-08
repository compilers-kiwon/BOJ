#include <iostream>

using namespace std;

#define GET_COST(q,u,p) (((q)/(u))*(p))

int main(void) {
    cin.tie(NULL);
    cout.sync_with_stdio(false);

    int X, Y, Z, U, V, W;

    cin >> X >> Y >> Z >> U >> V >>W;
    
    cout << GET_COST(U, 100, X)
            + GET_COST(V, 50, Y)
            + GET_COST(W, 20, Z) << '\n';
    
    return 0;
}