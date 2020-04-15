// https://leetcode.com/problems/number-of-islands/

type Grid struct {
    grid [][]bool
    length int
    width int
}

type Pair struct {
    x int
    y int
}

func initG(grid [][]byte) Grid {
    l := len(grid)
    w := len(grid[0])
    
    realGrid := make([][]bool, l)
    
    for y := 0; y < l; y++ {
        row := make([]bool, w)
        realGrid[y] = row
        
        for x := 0; x < w; x++ {
            realGrid[y][x] = grid[y][x] == byte(49)
        }
    }
    
    return Grid{realGrid, l, w}
}

func (g Grid) print() {
    fmt.Println("length:", g.length, "width:", g.width)
    
    for _, row := range g.grid {
        for _, cell := range row {
            fmt.Printf("%v ", cell)
        }
        fmt.Print("\n")
    }
    fmt.Println("\n")
}

func (g Grid) search() Pair {
    for y := 0; y < g.length; y++ {
        for x := 0; x < g.width; x++ {
            if g.grid[y][x] {
                return Pair{x: x, y: y}
            }
        }
    }
    
    return Pair{-1, -1}
}

func (g Grid) neighbors(x, y int) []bool {
    nbors := make([]bool, 4)
    
    nbors[0] = x - 1 >= 0 && g.grid[y][x - 1]
    nbors[1] = x + 1 < g.width && g.grid[y][x + 1]
    nbors[2] = y - 1 >= 0 && g.grid[y - 1][x]
    nbors[3] = y + 1 < g.length && g.grid[y + 1][x]
    
    return nbors
}

func numIslands(grid [][]byte) int {
    if len(grid) == 0 {
        return 0
    }
    
    g := initG(grid)
    count := 0
    
    //g.print()
    //fmt.Println(g.neighbors(0, 0))
    
    for {
        q := make([]Pair, 1)
        q[0] = g.search()
        
        //fmt.Println(q[0])
        
        if q[0].x == -1 {
            break
        }
        
        g.grid[q[0].y][q[0].x] = false
        count++
        
        for len(q) > 0 {
            cur := q[0]
            q = q[1:]

            nbors := g.neighbors(cur.x, cur.y)

            if nbors[0] {
                q = append(q, Pair{x: cur.x - 1, y: cur.y})
                g.grid[cur.y][cur.x - 1] = false
            } 
            if nbors[1] {
                q = append(q, Pair{x: cur.x + 1, y: cur.y})
                g.grid[cur.y][cur.x + 1] = false
            }
            if nbors[2] {
                q = append(q, Pair{x: cur.x, y: cur.y - 1})
                g.grid[cur.y - 1][cur.x] = false
            }
            if nbors[3] {
                q = append(q, Pair{x: cur.x, y: cur.y + 1})
                g.grid[cur.y + 1][cur.x] = false
            }
        }
    }
    
    return count
}