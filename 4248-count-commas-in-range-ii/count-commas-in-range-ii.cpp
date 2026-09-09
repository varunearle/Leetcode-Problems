class Solution {
public:
    static constexpr int64_t pow1000[] = { 1000, 1000000, 1000000000, 1000000000000, 1000000000000000, 1000000000000000000 };
    
    int64_t countCommas(auto& n) {
        int64_t k = 0;        
        for (auto& p : pow1000) k += n >= p;
        
        return k * (n + 1) - (pow1000[k] - 1000) / 999;
    }
};