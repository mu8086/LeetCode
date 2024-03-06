// https://leetcode.com/problems/construct-quad-tree

func isSameVal(grid [][]int, x, y, length int) bool {
    prev := grid[x][y]

    for i := x+length-1; i >= x; i-- {
        for j := y+length-1; j >= y; j-- {
            if grid[i][j] != prev {
                return false
            }
        }
    }

    return true
}

func _construct(grid [][]int, x, y, length int) *Node {
    node := &Node{
        Val: grid[x][y] == 1,
        IsLeaf: true,
        TopLeft: nil,
        TopRight: nil,
        BottomLeft: nil,
        BottomRight: nil,
    }

    if !isSameVal(grid, x, y, length) {
        halfLength := length/2

        *node = Node{
            IsLeaf: false,
            TopLeft: _construct(grid, x, y, halfLength),
            TopRight: _construct(grid, x, y+halfLength, halfLength),
            BottomLeft: _construct(grid, x+halfLength, y, halfLength),
            BottomRight: _construct(grid, x+halfLength, y+halfLength, halfLength),
        }
    }

    return node
}

func construct(grid [][]int) *Node {
    return _construct(grid, 0, 0, len(grid))
}
