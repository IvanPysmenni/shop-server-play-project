package main

import (
	"flag"
	"fmt"
)

func main() {
	shopAddress := flag.String("h", "127.0.0.1", "Shop ip address")
	shopPort := flag.Int("p", 8080, "Shop port")
	appName := flag.String("-n", "undefined-client", "Client name")

	fmt.Printf("My name is %s. I will go to shop by this address %s:%d", *appName, *shopAddress, shopPort)

}

// 1. Read parameters with information about server(shop)
// 2. Output information about this client
// 3. Make a request to server for get information about available products
// 4. Buy one random product
// 5. Sleep for several seconds(random from 1 to 5)
// 6. Repeat steps 3,4,5 till no products are available
