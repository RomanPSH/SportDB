#include "Libs.h"

class SportswearItem {
public:
    int id;
    std::string name;
    std::string brand;
    std::string type;
    std::string sezon;
    std::string gender;
    std::string size;
    double price;

    SportswearItem(const int itemId, const std::string& itemName, const std::string& itemBrand, const std::string& itemType, const std::string& itemSezon, const std::string& itemGender, const std::string& itemSize, double itemPrice);

    void updateItem(const std::string& itemName, const std::string& itemBrand, const std::string& itemType, const std::string& itemSezon, const std::string& itemGender, const std::string& itemSize, double itemPrice);
};