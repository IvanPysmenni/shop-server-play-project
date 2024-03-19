FROM ubuntu:22.04 as builder

WORKDIR /shop-sever-play-project

COPY . .

RUN apt update && apt install -y cmake gcc g++

RUN make clean-vendor && make build-shop

FROM ubuntu:22.04 as runner

WORKDIR /apps

COPY --from=builder /shop-sever-play-project/shop-server/build/bin/shop-server .

ENTRYPOINT [ "./shop-server" ]

