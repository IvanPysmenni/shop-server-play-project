package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"net/http"
	"time"
)

type ProductInfo struct {
	Name   string `json:"name"`
	Amount int    `json:"amount"`
}

func GetProductList(serverUrl string) (productList []ProductInfo, err error) {
	resp, err := http.Get(serverUrl + "/list/details")
	if err != nil {
		return nil, fmt.Errorf("fail to get list of products: %s\n", err.Error())
	}

	defer resp.Body.Close()

	body, err := io.ReadAll(resp.Body)
	if err != nil {
		return nil, fmt.Errorf("fail to read list of products: %s\n", err.Error())
	}

	err = json.Unmarshal(body, &productList)
	if err != nil {
		return nil, fmt.Errorf("fail to parse list of products: %s\n", err.Error())
	}

	return productList, nil
}

func WatchShopState(serverUrl string) {
	for {
		productList, err := GetProductList(serverUrl)
		if err == nil {
			for _, product := range productList {
				fmt.Printf("There is %d of %s\n", product.Amount, product.Name)
			}
		} else {
			fmt.Print(err.Error())
		}

		time.Sleep(5 * time.Second)
	}
}

func main() {
	shopAddress := flag.String("h", "127.0.0.1", "Shop ip address")
	shopPort := flag.Int("p", 8080, "Shop port")

	flag.Parse()

	fmt.Printf("I'm manager. I'm watching for shop state by this address %s:%d\n", *shopAddress, *shopPort)

	serverUrl := fmt.Sprintf("http://%s:%d", *shopAddress, *shopPort)
	WatchShopState(serverUrl)
}
