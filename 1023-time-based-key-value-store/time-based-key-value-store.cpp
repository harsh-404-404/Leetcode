class TimeMap {
private:
    std::unordered_map<std::string,std::map<int,std::string,std::greater<int>>> hash {};
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto point = hash[key].lower_bound(timestamp);
        if(point == hash[key].end()) return "";
        return point->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */