#include <iostream>
#include <string>

#include <crow.h>
#include <shop-server.h>
#include <product-category.h>

int main()
{
    ShopServer server;

    crow::SimpleApp app;

    CROW_ROUTE (app, "/list")
    (
        [&server]() 
        {
            return server.GetProductList();
        }
    );

    CROW_ROUTE (app, "/list/details")
    (
        [&server]() 
        {
            return server.GetAvailableProductList();
        }
    );

    CROW_ROUTE (app, "/buy").methods(crow::HTTPMethod::POST)
    (
        [&server](const crow::request& req) 
        {
            std::cout << "Key size" << req.url_params.keys().size() << std::endl;
            for(auto key : req.url_params.keys())
            {
                std::cout << key << std::endl;
            }
            ProductCategory cat = StringToProductCategory(req.url_params.get("item_name"));

            std::string responseStr;
            if(cat == ProductCategory::INVALID)
            {
                responseStr = "There is no item with name ";
                responseStr = req.url_params.get("item_name");
                return responseStr;
            }

            if(server.RemoveOneItem(cat))
            {
                responseStr = "Here is one ";
                responseStr = req.url_params.get("item_name");
                return responseStr;
            }
            else
            {
                responseStr = "Item ";
                responseStr = req.url_params.get("item_name");
                responseStr = " is out of stock";

                return responseStr;
            }
        }
    );

    app.port(18080).multithreaded().run();


    return 0;
}