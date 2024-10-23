#include <math.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int min_price = INT_MAX;
    int max_profit = 0; 
    
    for (int i = 0; i < pricesSize; i++) {
        min_price = min(prices[i], min_price);
        max_profit = max(max_profit, prices[i] - min_price);
    }

    return max_profit;
}