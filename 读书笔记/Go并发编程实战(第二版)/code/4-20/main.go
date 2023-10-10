package main

import (
	"fmt"
	"time"
)

func main() {

	intChan := make(chan int, 1)
	ticker := time.NewTicker(time.Second)
	go func() {
		for {
			for _ = range ticker.C {//如果收方调用ticker.Stop()，会阻塞在这一步
				select {//就算接收方停止接收时调用ticker.Stop()也不能跳出这个for+select循环
				case intChan <- 1:
				case intChan <- 2:
				case intChan <- 3:
				}
			}
		}
		fmt.Println("[Sender] End.")
	}()

	var sum int
	for e := range intChan {
		fmt.Printf("[Reciver] Receive : %v\n", e)
		sum += e
		if sum > 10 {
			fmt.Printf("[Reciver] Sum accumulate : %v\n", sum)
			break
		}
	}
	fmt.Println("[Receiver] Stop ticker.")
	//fmt.Printf("[Receiver] Ticker.C == nil, cap, len %v %v %v.\n", ticker.C == nil, cap(ticker.C), len(ticker.C))
	//ticker.Stop()
	fmt.Println("[Receiver] End.")
}
