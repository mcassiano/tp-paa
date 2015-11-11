#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_INT 32767
#define MAX_CITY 100

struct city
{
    int x;
    int y;
};

float calc_dist_city(struct city *c1, struct city *c2) {
    return sqrt(pow(c2->x - c1->x, 2) +  pow(c2->y - c1->y, 2));
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void permute(int *a, int l, int r, float *min_cost, int *sol, float dists[MAX_CITY][MAX_CITY])
{
    if (l == r) {
        /* check the cost for this path */
        
        /* but only if it starts with the first city
         "Inicie sempre esta sequência com a cidade 1." */
        
        if (a[0] != 0)
            return;
        
        float temp_cost = 0;
        
        for (int i = 1; i <= r; i++)
            temp_cost += dists[a[i-1]][a[i]];

        /* to close the circle, sum the distance from
            the last city to the first */
        
        temp_cost += dists[a[r]][a[0]];
        
        if (temp_cost < *min_cost) {
            *min_cost = temp_cost;
            
            for (int j = 0; j <= r; j++)
                sol[j] = a[j];
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r, min_cost, sol, dists);
            swap((a+l), (a+i)); //backtrack
        }
    }
}


void solve(float dists[MAX_CITY][MAX_CITY], int n) {
    
    int initial_state[MAX_CITY], sol[MAX_CITY];
    float min_cost = MAX_INT;
    
    for (int i = 0; i < n; i++)
        initial_state[i] = i;
    
    permute(initial_state, 0, n - 1, &min_cost, sol, dists);
    
    printf("%0.2f\n", min_cost);
    
    for (int i = 0; i < n; i++)
        printf("%d ", sol[i] + 1);
    
}


int main (int argc, char **argv) {
    
    int n;
    float dists[MAX_CITY][MAX_CITY];
    struct city cities[MAX_CITY];
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d %d", &(cities[i].x), &(cities[i].y));
    
    for (int i = 0; i < n; i++) {
        dists[i][i] = 0;
        for (int j = 0; j < n; j++) {
            if (i != j)
                dists[i][j] = calc_dist_city(&cities[i], &cities[j]);
        }
    }
    
    solve(dists, n);

    return 0;
}