class LRUCache {
/*
LRU是Least Recently Used的简写，就是最近最少使用的意思。那么这个缓存器主要有两个成员函数，get和put，其中get函数是通过输入key来获得value，如果成功获
得后，这对(key, value)升至缓存器中最常用的位置（顶部），如果key不存在，则返回-1。而put函数是插入一对新的(key, value)，如果原缓存器中有该key，则需要
先删除掉原有的，将新的插入到缓存器的顶部。如果不存在，则直接插入到顶部。若加入新的值后缓存器超过了容量，则需要删掉一个最不常用的值，也就是底部的值。具
体实现时我们需要三个私有变量，cap, l和m，其中cap是缓存器的容量大小，l是保存缓存器内容的列表，m是HashMap，保存关键值key和缓存器各项的迭代器之间映射，
方便我们以O(1)的时间内找到目标项。
然后我们再来看get和put如何实现，get相对简单些，我们在m中查找给定的key，若不存在直接返回-1。如果存在则将此项移到顶部，这里我们使用C++ STL中的函数
splice，专门移动链表中的一个或若干个结点到某个特定的位置，这里我们就只移动key对应的迭代器到列表的开头，然后返回value。这里再解释一下为啥HashMap不用更
新，因为HashMap的建立的是关键值key和缓存列表中的迭代器之间的映射，get函数是查询函数，如果关键值key不在HashMap，那么不需要更新。如果在，我们需要更新
的是该key-value对在缓存列表中的位置，而HashMap中还是这个key跟键值对儿的迭代器之间的映射，并不需要更新什么。
对于put，我们也是现在m中查找给定的key，如果存在就删掉原有项，并在顶部插入新来项，然后判断是否溢出，若溢出则删掉底部项(最不常用项)。
*/
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto iter=m.find(key);//这里的iter是整个map的迭代器，指向map的<key,value>的位置（value在这里是）
        if(iter==m.end())return -1;
        l.splice(l.begin(),l,iter->second);//将找到的key对应的key-value对移动至列表的首端
        return iter->second->second;//iter->second对应的是list，iter->second->second对应的则是list中的key对应的value
    }
    
    void put(int key, int value) {
        auto iter=m.find(key);
        if(iter!=m.end()){
            l.erase(iter->second);
        }
        l.push_front(make_pair(key,value));
        m[key]=l.begin();
        if(m.size()>cap){
            int k=l.rbegin()->first;//l.rbegin()对应的是列表的逆序第一个元素即最后一个元素
            l.pop_back();
            m.erase(k);
        }
    }
private:
    int cap;
    list<pair<int,int>> l;
    //HashMap的建立的是关键值key和缓存列表中的迭代器之间的映射
    unordered_map<int,list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
