package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"math/rand"
	"net/http"
	"time"
)

func GetListOfProducts(serverUrl string) (list []string, err error) {
	var ret []string

	resp, err := http.Get(serverUrl + "/list")
	if err != nil {
		return nil, err
	}

	defer resp.Body.Close()

	body, err := io.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}

	err = json.Unmarshal(body, &ret)
	if err != nil {
		return nil, err
	}

	return ret, nil
}

func BuyOneProduct(serverUrl string, productName string) (err error) {
	client := &http.Client{}
	req, err := http.NewRequest("POST", serverUrl+"/buy", nil)
	if err != nil {
		return err
	}

	q := req.URL.Query()
	q.Add("item_name", productName)
	req.URL.RawQuery = q.Encode()

	resp, err := client.Do(req)
	if err != nil {
		return err
	}

	defer resp.Body.Close()

	body, err := io.ReadAll(resp.Body)
	if err != nil {
		return err
	}

	fmt.Printf("I bought %s\n", string(body))
	return nil
}

func BuyProducts(serverUrl string) {
	for {
		productList, err := GetListOfProducts(serverUrl)
		if err == nil {
			if len(productList) > 0 {
				product := productList[rand.Intn(len(productList))]
				BuyOneProduct(serverUrl, product)
			} else {
				fmt.Print("No products left\n")
				break
			}
		} else {
			fmt.Printf("Fail to get information about available products: %s\n", err.Error())
		}

		time.Sleep(5 * time.Second)
	}
}

func main() {
	shopAddress := flag.String("h", "127.0.0.1", "Shop ip address")
	shopPort := flag.Int("p", 8080, "Shop port")
	appName := flag.String("n", "undefined-client", "Client name")

	flag.Parse()

	fmt.Printf("My name is %s. I will go to shop by this address %s:%d\n", *appName, *shopAddress, *shopPort)

	serverUrl := fmt.Sprintf("http://%s:%d", *shopAddress, *shopPort)
	BuyProducts(serverUrl)
}
