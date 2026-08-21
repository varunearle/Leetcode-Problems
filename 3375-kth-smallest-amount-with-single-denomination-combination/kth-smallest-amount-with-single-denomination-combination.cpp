class Solution {
public:
    using ll = long long;

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        // Remove redundant coins
        vector<int> c;
        for (int x : coins) {
            bool useful = true;

            for (int y : c) {
                if (x % y == 0) {
                    useful = false;
                    break;
                }
            }

            if (useful)
                c.push_back(x);
        }

        int n = c.size();

        auto count = [&](ll x) -> ll {
            ll total = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                ll lcm = 1;
                int bits = 0;
                bool tooLarge = false;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        ll g = __gcd(lcm, (ll)c[i]);

                        // Avoid overflow
                        if (lcm > x / (c[i] / g)) {
                            tooLarge = true;
                            break;
                        }

                        lcm = (lcm / g) * c[i];
                    }
                }

                if (tooLarge || lcm > x)
                    continue;

                if (bits % 2 == 1)
                    total += x / lcm;
                else
                    total -= x / lcm;
            }

            return total;
        };

        ll low = 1;
        ll high = 1LL * c[0] * k;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};