#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;

    return (x[1] > y[1]) - (x[1] < y[1]);
}

int maximumSaleItems(int** items, int itemsSize,
                     int* itemsColSize, int budget) {
    int n = itemsSize;

    int* freq = calloc(n + 1, sizeof(int));
    int* bonus = calloc(n + 1, sizeof(int));

    long long minPrice = INT_MAX;
    long long remaining = budget;
    long long ans = 0;

    // Count factor frequencies and find minimum price
    for (int i = 0; i < n; i++) {
        freq[items[i][0]]++;

        if (items[i][1] < minPrice)
            minPrice = items[i][1];
    }

    // Count eligible free item types
    for (int f = 1; f <= n; f++) {
        if (freq[f] == 0)
            continue;

        for (int m = f; m <= n; m += f) {
            bonus[f] += freq[m];
        }

        bonus[f]--;
    }

    // Sort items by increasing price
    qsort(items, n, sizeof(int*), compare);

    // Purchase beneficial bonus copies
    for (int i = 0; i < n; i++) {
        int f = items[i][0];
        long long price = items[i][1];

        if (price >= 2LL * minPrice)
            break;

        if (price > remaining)
            break;

        long long take = remaining / price;

        if (take > bonus[f])
            take = bonus[f];

        ans += 2LL * take;
        remaining -= take * price;
    }

    // Spend remaining budget on cheapest item
    ans += remaining / minPrice;

    free(freq);
    free(bonus);

    return (int)ans;
}