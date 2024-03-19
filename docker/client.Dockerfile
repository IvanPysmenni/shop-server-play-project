FROM golang:1.18.1 as builder

WORKDIR /shop-sever-play-project

COPY . .

RUN make build-client

FROM golang:1.18.1-stretch as runner

WORKDIR /apps

COPY --from=builder /shop-sever-play-project/shop-client/build/shop-client .

ENTRYPOINT [ "./shop-client" ]