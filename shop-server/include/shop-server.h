#ifndef SHOP_SERVER_H 
#define SHOP_SERVER_H 

#include <mutex>
#include <map>
#include <string>

#include <product-category.h>

class ShopServer
{
public:
    ShopServer();

    bool RemoveOneItem(const ProductCategory& itemType);
    std::string GetProductList();
    std::string GetAvailableProductList();

private:
    std::map<ProductCategory, int> m_productList;

    std::mutex m_mt;
};

#endif // SHOP_SERVER_H