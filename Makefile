.PHONY: build-shop build-client build-manager clean-shop clean-client clean-manager install clean all

build-shop:
	cd shop-server && \
	mkdir -p build && \
	cd build && \
	cmake .. && \
	make 

build-client:
	cd shop-client && \
	mkdir -p build && \
	go build -o build

build-manager:
	cd shop-manager && \
	mkdir -p build && \
	go build -o build

clean-shop:
	rm -rf shop-server/build

clean-client:
	rm -rf shop-client/build

clean-manager:
	rm -rf shop-manager/build

install:
	mkdir -p apps
	[ -f "shop-manager/build/shop-manager" ] && cp -u shop-manager/build/shop-manager apps/shop-manager
	[ -f "shop-client/build/shop-client" ] && cp -u shop-client/build/shop-client apps/shop-client
	[ -f "shop-server/build/bin/shop-server" ] && cp -u shop-server/build/bin/shop-server apps/shop-server

clean: clean-shop clean-client clean-manager
	rm -rf apps

all: build-shop build-client build-manager install