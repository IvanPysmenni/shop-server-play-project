#ifndef PRODUCT_CATEGORY_H 
#define PRODUCT_CATEGORY_H 

#include <string>

enum class ProductCategory
{
    APPLE,
    ORANGE,
    SAUSAGE,
    CHOCOLATE,
    BEER,

    INVALID
};
std::string ProductCategoryToString(const ProductCategory& item);
ProductCategory StringToProductCategory(std::string str);

#endif // PRODUCT_CATEGORY_H