class Solution {
public:

    bool check(int power, int n)
    {
        if(n == 0) return 1;

        if(pow(3, power) > n ) return false;

        bool addPower = check(power + 1, n - pow(3, power));
        bool skipPower = check(power + 1, n);

        return addPower || skipPower; 
    }
    bool checkPowersOfThree(int n) {
        return check(0, n);
    }
};