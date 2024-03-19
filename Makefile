.PHONY: build-shop build-client build-manager clean-shop clean-client clean-manager install clean all docker

copy-asio:
	mkdir -p shop-server/build/asio
	cp -R vendor/asio/asio/include shop-server/build/asio/include

copy-nlohmann:
	mkdir -p shop-server/build/nlohmann
	cp -R vendor/nlohmann/single_include/nlohmann shop-server/build/nlohmann/

build-vendor: copy-asio copy-nlohmann
	cd vendor/Crow && \
	mkdir -p build && \
	cd build && \
	cmake .. 	-DCROW_BUILD_EXAMPLES=OFF \
				-DCROW_BUILD_TESTS=OFF \
				-DASIO_INCLUDE_DIR=../../../shop-server/build/asio/include \
				-DCMAKE_INSTALL_PREFIX=../../../shop-server/build/Crow \
	&& \
	make install

build-shop: build-vendor
	mkdir -p shop-server/build && \
	cd shop-server && \
	cd build && \
	cmake .. -DASIO_INCLUDE_DIR=asio/include && \
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

clean-vendor:
	rm -rf vendor/Crow/build

install:
	mkdir -p apps
	[ -f "shop-manager/build/shop-manager" ] && cp -u shop-manager/build/shop-manager apps/shop-manager
	[ -f "shop-client/build/shop-client" ] && cp -u shop-client/build/shop-client apps/shop-client
	[ -f "shop-server/build/bin/shop-server" ] && cp -u shop-server/build/bin/shop-server apps/shop-server

clean: clean-shop clean-client clean-manager
	rm -rf apps

all: build-shop build-client build-manager install

docker: 
	docker build --rm -t shop-server-play-project/server:latest -f docker/server.Dockerfile .
	docker build --rm -t shop-server-play-project/manager:latest -f docker/manager.Dockerfile .
	docker build --rm -t shop-server-play-project/client:latest -f docker/client.Dockerfile .