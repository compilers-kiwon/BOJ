#include    <stdio.h>
#include    <malloc.h>

#define MAX_SIZE    10000

int main(void)
{
    int     N,cnt;
    char*   S;

    scanf("%d",&N);
    S = (char*)malloc(sizeof(char)*(N+1));
    
    scanf("%s",S);
    cnt = 0;

    for (int i=0;i<N-1;i++) {
        char cur = S[i];
        char adj = S[i+1];

        if (cur != adj ) {
            cnt++;i++;
        }
    }

    printf("%d\n",cnt);

    free(S);
    return  0;
}