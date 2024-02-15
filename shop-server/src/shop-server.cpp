#include <shop-server.h>
#include <nlohmann/json.hpp>

ShopServer::ShopServer()
{
    m_productList[ProductCategory::APPLE]       = 100;
    m_productList[ProductCategory::BEER]        = 100;
    m_productList[ProductCategory::CHOCOLATE]   = 100;
    m_productList[ProductCategory::ORANGE]      = 100;
    m_productList[ProductCategory::SAUSAGE]     = 100;
}

bool ShopServer::RemoveOneItem(const ProductCategory& itemType)
{
    std::lock_guard<std::mutex> lk(m_mt);
    if(m_productList.find(itemType) == m_productList.end())
    {
        return false;
    }

    m_productList[itemType] = m_productList[itemType] - 1;

    if(m_productList[itemType] == 0)
    {
        m_productList.erase(itemType);
    }

    return true;
}

std::string ShopServer::GetProductList()
{
    std::lock_guard<std::mutex> lk(m_mt);

    nlohmann::json root = nlohmann::json::array();
    for(const auto& [key, _]: m_productList)
    {
        std::string productName = ProductCategoryToString(key);
        if(productName != "")
        {
            root.push_back(productName);
        }
    }

    return root.dump();
}

std::string ShopServer::GetAvailableProductList()
{
    std::lock_guard<std::mutex> lk(m_mt);

    nlohmann::json root = nlohmann::json::array();
    for(const auto& [key, value]: m_productList)
    {
        std::string productName = ProductCategoryToString(key);
        if(productName != "")
        {
            nlohmann::json productInfo = nlohmann::json::object();
            productInfo["name"] = productName;
            productInfo["amount"] = value;

            root.push_back(productInfo);
        }
    }

    return root.dump();
}