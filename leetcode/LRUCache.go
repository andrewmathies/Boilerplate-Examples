// https://leetcode.com/problems/lru-cache/

type LRUCache struct {
    store map[int]int
    q *list.List
    capacity int
}


func Constructor(capacity int) LRUCache {
    store := make(map[int]int, capacity)
    q := list.New()
    
    return LRUCache{ store, q, capacity}
}


func (this *LRUCache) Get(key int) int {
    if val, inStore := this.store[key]; inStore {
        for cur := this.q.Front(); cur != nil; cur = cur.Next() {
            if cur.Value == key {
                this.q.MoveToFront(cur)
                break
            }
        }
        
        return val
    }
    
    return -1
}


func (this *LRUCache) Put(key int, value int)  {
    if _, inStore := this.store[key]; inStore {
        for cur := this.q.Front(); cur != nil; cur = cur.Next() {
            if cur.Value == key {
                this.q.MoveToFront(cur)
                break
            }
        }
        
        this.store[key] = value
        return
    }
    
    last := this.q.Back()
    
    if this.q.Len() == this.capacity {
        delete(this.store, last.Value.(int))
        this.q.Remove(last)
    }
    
    this.q.PushFront(key)
    this.store[key] = value
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */