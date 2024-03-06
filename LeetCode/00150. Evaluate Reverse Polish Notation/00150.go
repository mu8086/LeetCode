// https://leetcode.com/problems/evaluate-reverse-polish-notation

const (
    ADD = "+"
    SUB = "-"
    MUL = "*"
    DIV = "/"
)

func evalRPN(tokens []string) int {
    var stack []int

    for i, stackSize := 0, 0; i < len(tokens); i++ {
        switch tokens[i] {
        case ADD:
            stack[stackSize-2] += stack[stackSize-1]
            stack = stack[:stackSize-1]
            stackSize--
        case SUB:
            stack[stackSize-2] -= stack[stackSize-1]
            stack = stack[:stackSize-1]
            stackSize--
        case MUL:
            stack[stackSize-2] *= stack[stackSize-1]
            stack = stack[:stackSize-1]
            stackSize--
        case DIV:
            stack[stackSize-2] /= stack[stackSize-1]
            stack = stack[:stackSize-1]
            stackSize--
        default:
            num, _ := strconv.Atoi(tokens[i])
            stack = append(stack, num)
            stackSize++
        }
    }

    return stack[0]
}
