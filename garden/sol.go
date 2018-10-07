package main

import (
    "fmt"
)

struct Point {
    int x
    int y
}

func main() {
    x1, y1 := 100, 100
    x2, y2 := -100, -100
    area := 314

    fmt.Println(x1, y1, x2, y2, area)
}

