CMAKE_MINIMUM_REQUIRED(VERSION 3.22 FATAL_ERROR)

target_sources(
    ${PROJECT_NAME} 
    PRIVATE 
    main.cpp 
    shop-server.cpp 
    product-category.cpp
    shop-server-utility.cpp
)