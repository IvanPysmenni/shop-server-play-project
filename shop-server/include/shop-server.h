#ifndef SHOP_SERVER_H
#define SHOP_SERVER_H

#include <mutex>

class ShopServer
{
public:
    void TakeOneApple();
    void TakeOneOrange();
    void TakeOneSausage();
    void TakeOneChocolate();
    void TakeOneBeer();

private:
    int m_apple = 100;
    int m_orange = 100;
    int m_sausage = 100;
    int m_chocolate = 100;
    int m_beer = 100;

    std::mutex m_mt;
};

#endif // SHOP_SERVER_H