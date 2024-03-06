// https://leetcode.com/problems/design-parking-system

type ParkingSystem struct {
    slot map[int]int
}

func Constructor(big int, medium int, small int) ParkingSystem {
    return ParkingSystem{
        slot: map[int]int {
            1: big, 2: medium, 3: small,
        },
    }
}

func (this *ParkingSystem) AddCar(carType int) bool {
    if this.slot[carType] > 0 {
        this.slot[carType]--
        return true
    }
    return false
}
