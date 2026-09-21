class LRUCache {
public:
    // key to node
    unordered_map<int, list<int>::iterator> m1;

    // key to value
    unordered_map<int, int> m2;
    list<int> lt;
    int size;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(m1.contains(key)){
            lt.erase(m1[key]);
            lt.push_front(key);
            auto it = lt.begin();
            m1[key] = it;
            return m2[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lt.size() == size && !m2.contains(key)){
            m2.erase(lt.back());
            m1.erase(lt.back());
            lt.pop_back();
        }

        if(m1.contains(key)){
            lt.erase(m1[key]);
            lt.push_front(key);
            auto it = lt.begin();
            m1[key] = it;
            m2[key] = value;
        }
        else{
            lt.push_front(key);
            auto it = lt.begin();
            m1[key] = it;
            m2[key] = value;
        }
    }
};
