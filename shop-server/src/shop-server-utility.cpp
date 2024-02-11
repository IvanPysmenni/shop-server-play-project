#include <algorithm> 
#include <cctype>
#include <locale>

#include <shop-server-utility.h>

namespace shop_server_utility
{

void rtrim(std::string& str)
{
    str.erase(
        std::find_if(
            str.rbegin(), 
            str.rend(), 
            [](unsigned char ch) 
            {
                return !std::isspace(ch);
            }
        ).base(), 
        str.end()
    );
}

void ltrim(std::string& str)
{
    str.erase(
        str.begin(),
        std::find_if(
            str.begin(), 
            str.end(), 
            [](unsigned char ch) 
            {
                return !std::isspace(ch);
            }
        )
    );
}

void trim(std::string& str)
{
    rtrim(str);
    ltrim(str);
}

};