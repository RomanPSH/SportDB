#include "SportswearItem.h"

SportswearItem::SportswearItem(const int itemId, const std::string& itemName, const std::string& itemBrand, const std::string& itemType, const std::string& itemSezon, const std::string& itemGender, const std::string& itemSize, double itemPrice)
    : id(itemId), name(itemName), brand(itemBrand), type(itemType), sezon(itemSezon), gender(itemGender), size(itemSize), price(itemPrice) {}

void SportswearItem::updateItem(const std::string& itemName, const std::string& itemBrand, const std::string& itemType, const std::string& itemSezon, const std::string& itemGender, const std::string& itemSize, double itemPrice)
{
    name = itemName;
    brand = itemBrand;
    type = itemType;
    sezon = itemSezon;
    gender = itemGender;
    size = itemSize;
    price = itemPrice;
}

