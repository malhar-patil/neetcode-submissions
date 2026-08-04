class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int cnt = 32;
        while(cnt > 0){
            uint32_t last = n&1;
            res = res << 1;
            res = res | last;
            n = n >> 1;
            cnt--;
        }
        return res;
    }
};
