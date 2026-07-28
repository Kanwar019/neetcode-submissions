class TimeMap {
    unordered_map<string, vector<pair<string,int>>> store; 
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)==store.end()){
            return "";
        }
        vector<pair<string,int>>& values =store[key];

        int left=0;
        int right=values.size()-1;
        int mid;
        string res="";
        while(left<=right){
            mid=(left+right)/2;
            if(values[mid].second<=timestamp){
                res=values[mid].first;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return res;
    }
};
