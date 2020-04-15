// https://leetcode.com/problems/map-sum-pairs/

type Node struct {
    key rune
    val int
    children []*Node
}

type MapSum struct {
    root *Node
}


func convert(key string) []int {
    runes := []rune(strings.ToUpper(key))
    out := make([]int, len(runes))
    
    for i, val := range runes {
        out[i] = int(val) - 65
    }
    
    return out
}

func recursiveSum(cur *Node) int {
    sum := 0
    
    if cur == nil {
        return sum
    }
    
    for _, node := range cur.children {
        if node == nil {
            continue
        }
        
        sum += node.val
        sum += recursiveSum(node)
    }
    
    return sum
}

func printTree(n *Node) {
    fmt.Println("printing tree")
    nonEmpty := make([]*Node, 0)
    
    for _, child := range n.children {
        if child == nil {
            continue
        }
        
        nonEmpty = append(nonEmpty, child)
        
        fmt.Printf("key: %v, val: %v ", child.key, child.val)
    }
    
    fmt.Println()
    
    for _, child := range nonEmpty {
        printTree(child)
    }
}

/** Initialize your data structure here. */
func Constructor() MapSum {
    children := make([]*Node, 26)
    root := Node{rune(0), 0, children}
    return MapSum{&root}
}


func (this *MapSum) Insert(key string, val int)  {
    convertedKey := convert(key)
    //fmt.Println(convertedKey, key)
    runes := []rune(key)
    cur := this.root
    
    for i := 0; i < len(runes); i++ {
        letters := cur.children

        if letters[convertedKey[i]] == nil {
            newChildren := make([]*Node, 26)
            n := Node{key: runes[i], val: 0, children: newChildren}
            letters[convertedKey[i]] = &n
            cur = &n
        } else {
            cur = letters[convertedKey[i]]
        }
        
        if i == len(runes) - 1 {
            letters[convertedKey[i]].val = val
        }
    }
}


func (this *MapSum) Sum(prefix string) int {
    //printTree(this.root)
    
    convertedKey := convert(prefix)
    cur := this.root
    
    for i := 0; i < len(convertedKey); i++ {
        if cur == nil {
            break
        }
        
        cur = cur.children[convertedKey[i]]
    }
    
    //printTree(cur)
    
    sum := recursiveSum(cur)
    if cur != nil {
        sum += cur.val
    }
    return sum
}


/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */