class NumberContainers {
public:
    map<int,set<int>> mp;
    map<int,int> ind;
    NumberContainers() {
        
    }
    void change(int index, int number) {
        if(ind[index]!=0){
            int num=ind[index];
            mp[num].erase(index);
            ind[index]=0;
        }
        mp[number].insert(index);
        ind[index]=number;
        
    }
    
    int find(int number) {
        if(!mp[number].empty()){
            return (*mp[number].begin());
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */