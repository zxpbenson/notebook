package main

import (
	"fmt"
	"time"
)

func main() {
	intChan := make(chan int, 1)
	go func() {
		for i := 0; i < 5; i++ {
			time.Sleep(time.Second)
			intChan <- i
		}
		close(intChan)
	}()
	timeout := time.Millisecond * 500
	var timer *time.Timer
ForSelect://自己加的
	for {
		if timer == nil {
			timer = time.NewTimer(timeout)
		} else {
			timer.Reset(timeout)
		}
		select {
		case e, ok := <-intChan:
			if !ok {
				fmt.Println("End .")
				timer.Stop()//自己加的
				break ForSelect//自己加的
			}
			fmt.Printf("Received : %v\n", e)
		case <-timer.C:
			fmt.Println("Timeout !")
		}
	}
}
