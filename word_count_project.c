#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
    int c, nl, nw, nc, nt, state;
    state = OUT;
    nl = nw = nc = nt = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n') 
            ++nl;
        if (c == '\t') 
            ++nt;
        if (c == '\n' || c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
         if (c == '\n')
            printf("\\n\n");
        else if (c == '\t')
            printf("\\t");
        else if (c == ' ') 
            printf("\\b");
        else 
            putchar(c);    
    }
    printf("%d line, %d word, %d tab, %d character\n", nl, nw, nt, nc);
    return 0;
}


 