#include <iostream>
#include <vector>

using namespace std;

int main() {

    int days;
    cin >> days;
    long long money = 100;
    long long total = 100000;

    int price;
    vector<int> prices;
    // Indicates for which day she should decided to buy and sell.
    int buy = 0, sell = 0;
    for (int i = 0; i < days; i++) {
        cin >> price;
        prices.push_back(price);
    }

    int start, end;
    for (int i = 0; i < days; i++) {
        // Continue to search for better buy date.
        while(i + 1 < days && prices[i] > prices[i+1]) i++;
        // Price to buy at.
        start = prices[i];

        // Greedily buy all she can, she never wants to only sell a portion of her stocks.
        long long purchases = money / start;

        if (purchases > total) purchases = total;
        total -= purchases;

        // How much money she might have left over if she cant afford an exact stock #.
        money = money - (purchases * start);

        while(i+1 < days && prices[i] < prices[i+1]) i++;
        end = prices[i];

        money += (purchases * end);
        // Enter these stocks back into the market.
        total += purchases;
    }

    cout << money << endl;

    return 0;
}
