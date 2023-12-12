// https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant

func displayTable(orders [][]string) (ans [][]string) {
    var (
        tableNum int
        food string
        foodList []string
        tableOrdersList []int
        stringSlice = []string{"Table"}
        existOrders map[string]int
        foodMap = make(map[string]bool)
        tableOrdersMap = make(map[int]map[string]int)
    )

    // fill map
    for _, order := range orders {
        tableNum, _ = strconv.Atoi(order[1])
        food = order[2]

        if existOrders = tableOrdersMap[tableNum]; existOrders == nil {
            existOrders = make(map[string]int)
        }
        existOrders[food]++
        tableOrdersMap[tableNum] = existOrders

        foodMap[food] = true
    }

    for food := range foodMap {
        foodList = append(foodList, food)
    }
    sort.Strings(foodList)

    for table := range tableOrdersMap {
        tableOrdersList = append(tableOrdersList, table)
    }
    sort.Ints(tableOrdersList)

    // fill ans
    stringSlice = append(stringSlice, foodList...)
    ans = append(ans, stringSlice)
    for _, tableNum := range tableOrdersList {
        stringSlice = nil

        stringSlice = append(stringSlice, fmt.Sprintf("%v", tableNum))

        tableOrders := tableOrdersMap[tableNum]
        for _, food := range foodList {
            stringSlice = append(stringSlice, fmt.Sprintf("%v", tableOrders[food]))
        }

        ans = append(ans, stringSlice)
    }

    return ans
}
