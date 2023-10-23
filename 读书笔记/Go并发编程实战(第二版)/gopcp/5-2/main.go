package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	//go mutex()
	go rwmutex()
	time.Sleep(time.Second * 5)
}

func mutex() {
	defer func() {
		fmt.Println("Try to recover the panic in mutex : ")
		if p := recover(); p != nil {
			fmt.Printf("Recover the panic : (%#v).\n", p)
		}
	}()

	var mutex sync.Mutex
	fmt.Println("Lock the lock.")
	mutex.Lock()
	fmt.Println("The lock is locked.")
	//fmt.Println("Lock the lock again.")
	//mutex.Lock()
	//fmt.Println("The lock is locked again.")
	fmt.Println("Unlock the lock.")
	mutex.Unlock()
	fmt.Println("The lock is unlocked.")
	fmt.Println("Unlock the lock again.")
	mutex.Unlock()
}

func rwmutex() {
	defer func() {
		fmt.Println("Try to recover the panic in rwmutex : ")
		if p := recover(); p != nil {
			fmt.Printf("Recover the panic : (%#v).\n", p)
		}
	}()

	var rwm sync.RWMutex
	rwm.RLock()
	fmt.Println("The Rlock is locked.")
	rwm.Lock()
	fmt.Println("The lock is locked.")
	rwm.Unlock()
	fmt.Println("The lock is unlocked.")
	rwm.RUnlock()
	fmt.Println("The Rlock is unlocked.")
}
