class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num2_bits = 0;

        while (num2 > 0) {
            if (num2 & 1)
                num2_bits++;
            num2 = num2 >> 1;
        }

        int num1_bits = 0;
        int num11 = num1;
        while (num11 > 0) {
            if (num11 & 1)
                num1_bits++;
            num11 = num11 >> 1;
        }


        if (num1_bits == num2_bits)
            return num1;
        if (num1_bits < num2_bits) {
            int n1 = num1;
            int i = num2_bits - num1_bits;
            int j = 0;
            while (i > 0) {
                while ((n1 >> j) & 1)
                    ++j;
                n1 |= (1 << j);
                i--;
            }

            return n1;
        }

        int num = num1;
        int i = 0;
        int cnt = num1_bits - num2_bits;
        while (cnt > 0) {
            num &= (num - 1);
            cnt--;
        }

        return num;
    }
};