#include <stdio.h>
#include <string.h>

void Delete(char* N, int len, int M)
{
    char min = N[0];
    int i, min_pos = 0;
    if(M <= 0) return;
    for(i = 1; i <= M; i++)
        if(N[i] < min){
            min = N[i];
            min_pos = i;
        }
    if(min_pos){
        memcpy(N, N + min_pos, len - min_pos + 1);
        Delete(N, len - min_pos, M - min_pos);
    }else{
        Delete(N + 1, len - 1, M);
    }
}

int main()
{
    #ifdef FILEOUT
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    #endif
    char N[300];
    int M, len;
    scanf("%s%d", N, &M) ;
    len = strlen(N);
    Delete(N, len, M);
    int fr0=1;
    for(unsigned int i=0;i<strlen(N);i++)
    {
        if(fr0==1&&N[i]=='0') continue;
        putchar(N[i]);
        fr0=0;
    }
    return 0;
}
