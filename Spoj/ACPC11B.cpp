#include <stdio.h>
#include <stdlib.h>

int a[1000], b[1000];

int main () {
    
    int T, N1, N2, min, i, j, sub;
    
    scanf ("%d", &T);
    while (T--) {
        min = 1000000;
        scanf ("%d", &N1);
        for (i = 0; i < N1; i++)
            scanf ("%d", &a[i]);
        scanf ("%d", &N2);
        for (i = 0; i < N2; i++)
            scanf ("%d", &b[i]);
        
        
        
        for (i = 0; i < N1; i++) {
            for (j = 0; j < N2; j++) {
                sub = a[i]-b[j];
                sub = sub>0?sub:-sub;
                min = min>sub?sub:min;
                if (min == 0)
                    break;
            }
            if (min == 0)
                break;
        }
        
        printf ("%d\n", min);
    }

    return 0;
}
