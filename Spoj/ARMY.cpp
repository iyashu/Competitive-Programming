#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int g, m, i, j;
        scanf("%d %d", &g, &m);
        int mg[g], mm[m];
        for (i = 0; i < g; i++)
            scanf("%d", &mg[i]);
        for (i = 0; i < m; i++)
            scanf("%d", &mm[i]);
        sort(mg, mg + g);
        sort(mm, mm + m);
        i = 0, j = 0;
        while (1) {
            if (mg[i] == mm[j])
                j++;
            else {
                if (mg[i] < mm[j])
                    i++;
                else
                    j++;
            }
            if (i == g)
                break;
            if (j == m)
                break;
        }
        
        if (j == m)
            printf("Godzilla\n");
        else
            printf("MechaGodzilla\n");
    }
}
