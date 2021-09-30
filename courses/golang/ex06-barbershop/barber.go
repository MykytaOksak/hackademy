package main

import (
	"fmt"
	"time"
)

const (
	customersCount       = 20
	seats                = 3
	customersDelay       = 15
	customersReturnDelay = 20
	barberDelay          = 15
)

func serveCustomer(customerId int, delay int, customersServed chan int) {
	time.Sleep(time.Duration(delay) * time.Millisecond)
	customersServed <- customerId
	fmt.Printf("Customer %d served.\n", customerId)
}

func barber(delay int, seats chan int, customersServed chan int, goingHome chan int, customersToServe int) {
	fmt.Println("Barber opening shop.")
	var customerId int = -1
	var numOfCustomerServed int = 0
	for {
		select {
		case customerId = <-seats: // if there is somebody, serve him
		default: // if there is nb, sleep untill sb come
			fmt.Println("Barber sleeping.")
			customerId = <-seats
			fmt.Printf("Barber woken up by customer %d.\n", customerId)
		}
		serveCustomer(customerId, delay, customersServed)
		numOfCustomerServed++
		if numOfCustomerServed == customersToServe {
			fmt.Println("All customers served.")
			break
		}
	}
	fmt.Printf("Barber closing shop.\n")
	customersServed <- 1
	goingHome <- 1
}

func customers(id int, return_delay int, seats chan int, customersServed chan int) {
	var serviced bool = false
	for !serviced {
		select {
		case seats <- id: // if there are seats
			fmt.Printf("Customer %d entering barber shop.\n", id)
			finished_customers := -1
			for finished_customers != id {
				finished_customers = <-customersServed
			}
			serviced = true
		default: // if shop is full
			fmt.Printf("Customer %d leaving barber shop unserviced.\n", id)
			time.Sleep(time.Duration(return_delay) * time.Millisecond)
		}
	}
}

func main() {
	seats := make(chan int, seats)
	customersServed := make(chan int)
	barbershopCloses := make(chan int)

	go barber(barberDelay, seats, customersServed, barbershopCloses, customersCount)
	for id := 0; id < customersCount; id++ {
		go customers(id, customersReturnDelay, seats, customersServed)
		time.Sleep(time.Duration(customersDelay) * time.Millisecond)
	}

	<-customersServed
	<-barbershopCloses
}
