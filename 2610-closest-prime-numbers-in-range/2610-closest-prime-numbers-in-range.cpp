class Solution {
public:

void SieveOfEratosthenes(int n,vector<bool> &prime)
{

  for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
vector<int> closestPrimes(int left, int right) {
    vector<bool> prime(right+1,true);
    SieveOfEratosthenes(right,prime);
    prime[1]=false;
    vector<int> temp;
    for(int i=left;i<=right;i++){
        if(prime[i] == true){
            temp.push_back(i);
        }
    }
    vector<int> ans;
    ans.push_back(-1);
    ans.push_back(-1);
    int mn= INT_MAX;
    for(int i=1;i<temp.size();i++){
        if(temp[i]-temp[i-1]<mn){
            mn=temp[i]-temp[i-1];
            ans.clear();
            ans.push_back(temp[i-1]);
            ans.push_back(temp[i]);
        }
    }
    return ans;
}
};