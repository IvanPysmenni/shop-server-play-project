This is just a play project created just to test some frameworks. Idea is to simulate grocery shop with one manager how looking for shop state and several clients that buying some amount of products

## Build

```
make all
make install
```

## Docker build
```
make docker
```

## Run
### Shop
```
./apps/shop-server
```

### Manager
```
./apps/shop-manager -h 127.0.0.1 -p 18080
```

### Client
```
./apps/shop-client -h 127.0.0.1 -p 18080 -n Clara
```
