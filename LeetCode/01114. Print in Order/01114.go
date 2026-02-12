// https://leetcode.com/problems/print-in-order

type Foo struct {
    firstDone chan struct{}
    secondDone chan struct{}
}

func NewFoo() *Foo {
    return &Foo{
        firstDone: make(chan struct{}),
        secondDone: make(chan struct{}),
    }
}

func (f *Foo) First(printFirst func()) {
    // Do not change this line
    printFirst()

    close(f.firstDone)
}

func (f *Foo) Second(printSecond func()) {
    <-f.firstDone

    /// Do not change this line
    printSecond()

    close(f.secondDone)
}

func (f *Foo) Third(printThird func()) {
    <-f.secondDone

    // Do not change this line
    printThird()
}
