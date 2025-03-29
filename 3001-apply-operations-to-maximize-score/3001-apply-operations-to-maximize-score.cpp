class Solution {
public:


    #define ll long long
    const int mod = 1000000007;
    ll power(ll base, ll exp)
    {
        ll res = 1;

        while(exp > 0)
        {
            if(exp % 2 == 1)
                res = ((res * base) % mod);
            
            base = (base * base) % mod;

            exp /= 2;
        }

        return res;
    }

    int primeScore(int n)
    {
        int cnt = 0;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i == 0)
                cnt++;

            while(n%i==0)
                n = n/i;
        }
        if(n >= 2) cnt++;
        return cnt;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> score(n);

        for(int i=0;i<n;i++)
            score[i] = primeScore(nums[i]);
        
        vector<int> nD(n,n);
        vector<int> pD(n,-1);

        stack<int> sta;

        for(int i = 0;i<n; i++)
        {
            while(!sta.empty() && score[sta.top()] < score[i])
            {
                int tI = sta.top();
                sta.pop();

                nD[tI] = i;
            }

            if(!sta.empty())
                pD[i] = sta.top();

            sta.push(i);
        }


        vector<ll> numofsubarray(n);

        for(int i=0;i<n;i++)
            numofsubarray[i] = (ll)(nD[i] - i)*(i - pD[i]);

        priority_queue<pair<int,int>> pQ;


        for(int i=0;i<n;i++)
            pQ.push({nums[i], i});
        

        ll scor = 1;

        while(k>0)
        {
            auto [num, index] = pQ.top();
            pQ.pop();

            ll ope = min((ll)k, numofsubarray[index]);

            scor = (scor* power(num, ope)) % mod;

            k -= ope;
        }
        
        return scor;

    }
};