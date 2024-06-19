#include "Libs.h"

class Review {
public:
    std::string itemName;
    std::string customerName;
    std::string comment;

    Review(const std::string& item, const std::string& customer, const std::string& text);
};