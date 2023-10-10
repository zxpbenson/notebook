package main

import (
	"fmt"
	"time"
)

func main() {
	intChan := make(chan int, 1)
	go func() {
		time.Sleep(time.Second)
		intChan <- 1
	}()
	select {
	case e := <-intChan:
		fmt.Printf("Receive : %v\n", e)
	case <-time.NewTimer(time.Millisecond * 1500).C:
		fmt.Println("Timeout !")
	}
}
