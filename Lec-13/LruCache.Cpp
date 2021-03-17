//problem link: https://leetcode.com/problems/lru-cache/

class LRUCache {
    list<int> l;  //doubly linked list
    map<int,pair<list<int>::iterator,int>> m ;  //node ka address and value 
    int m_s;  //m_s is max size of cache
public:
    LRUCache(int capacity) {
        m_s=capacity;
    }
    
    int get(int key) {
        //check if present or not
        if(m.find(key)==m.end())
            return -1;
        
        //remove pervious instance and insert at front
         //get it address
             auto it1=m[key].first;  //get it's address and value
            
           int value = m[key].second;
            l.erase(it1);  ///remove prevoius node
            m.erase(key);  ///remove it from map too
            
            //insert new node at front
            l.push_front(key);
            auto it2=l.begin();  //address of newly inserted node
            m[key]={it2,value};
        return value;
    }
    
    void put(int key, int value) {
        //already present or not
        if(m.find(key)!=m.end()){
            //no worry about size
            //get it address
            
            auto it1=m[key].first; //address of this node
            l.erase(it1);  ///remove prevoius node
            m.erase(key);  ///remove it from map too
            
            //insert new node at front
            l.push_front(key);
            auto it2=l.begin();  //address of newly inserted node
            m[key]={it2,value};
            
        }
        else{
            //not present already
            //already filled to max capacity
            if(l.size()==m_s){
                auto it=l.rbegin();  //get tail address
                m.erase(*it);
               l.pop_back();
                
            }
            
            //insert new element
             //insert new node at front
            l.push_front(key);
            auto it2=l.begin();  //address of newly inserted node
            m[key]={it2,value};
}
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */