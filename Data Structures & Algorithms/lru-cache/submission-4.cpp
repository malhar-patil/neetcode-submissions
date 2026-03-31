class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> m;
    list<pair<int,int>> l;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key){
        pair<int,int> temp{-1,-1};
        if(m.find(key) != m.end()){
            auto it = m[key];
            temp = *it;
            l.erase(it);
            pair<int,int> lTemp{temp.first,temp.second};
            l.push_front(lTemp);
            m[key] = l.begin();
        }
        return temp.second;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            auto it = m[key];
            pair<int,int> temp = *it;
            temp.second = value;
            l.erase(it);
            l.push_front(temp);
            m[key] = l.begin();
            return;
        }

        if(m.size() == capacity){
            pair<int,int> temp;
            temp = (l.back());
            l.pop_back();
            m.erase(temp.first);
        }
        pair<int,int> lTemp{key,value};
        l.push_front(lTemp);
        m[key] = l.begin();
        return;
    }
};
