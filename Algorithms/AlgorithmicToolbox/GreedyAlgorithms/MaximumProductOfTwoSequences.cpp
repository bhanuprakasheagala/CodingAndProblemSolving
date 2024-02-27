/*
Input: Two sequences of n positive integers: price1,...,pricen and clicks1,...,clicksn.
Output: The maximum value of price1 ·c1 +···+pricen ·cn, where c1,...,cn is a permutation of
clicks1,...,clicksn.

Examples:

Sample 1.
Input:
1
23
39
Output:
897
897=23·39. 

Sample 2.
Input:
3
2 3 9
7 4 2
Output:
79
79=7·9+2·2+3·4.
*/

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> prices;
    std::vector<int> clicks;

    for(int i=0; i<n; ++i) {
        int price;
        std::cin >> price;
        prices.push_back(price);
    }
    for(int i=0; i<n; ++i) {
        int click;
        std::cin >> click;
        clicks.push_back(click);
    }
        std::sort(prices.begin(), prices.end());
        std::sort(clicks.begin(), clicks.end());

        int res = 0;
        for(int i=0; i<n; ++i) {
            res += prices[i]*clicks[i];
        }
        std::cout << res;

    return 0;
}