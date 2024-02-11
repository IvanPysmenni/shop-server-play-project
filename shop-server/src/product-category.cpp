#include <product-category.h>
#include <shop-server-utility.h>

std::string ProductCategoryToString(const ProductCategory& item)
{
    switch(item)
    {
        case ProductCategory::APPLE:        return "apple";
        case ProductCategory::ORANGE:       return "orange";
        case ProductCategory::SAUSAGE:      return "sausage";
        case ProductCategory::CHOCOLATE:    return "chocolate";
        case ProductCategory::BEER:         return "beer";
        case ProductCategory::INVALID:      return "";

        default: return "";
    }
}

ProductCategory StringToProductCategory(std::string str)
{
    shop_server_utility::trim(str);

    if(str == "apple")
    {
        return ProductCategory::APPLE;
    }
    else if(str == "orange")
    {
        return ProductCategory::ORANGE;
    }
    else if(str == "sausage")
    {
        return ProductCategory::SAUSAGE;
    }
    else if(str == "chocolate")
    {
        return ProductCategory::CHOCOLATE;
    }
    else if(str == "beer")
    {
        return ProductCategory::BEER;
    }
    else
    {
        return ProductCategory::INVALID;
    }
}