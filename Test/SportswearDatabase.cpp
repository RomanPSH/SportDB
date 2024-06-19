#include "SportswearDatabase.h"    

    void SportswearDatabase::addItem()
    {
        int id;
        std::string name, brand, type, sezon, gender, size;
        double price;
    tryAgain:
        std::cout << "Enter the ID of the item: ";
        std::cin >> id;

        auto it = std::find_if(database.begin(), database.end(), [&](const SportswearItem& item) {
            return item.id == id;
            });
        if (it != database.end()) {
            std::cout << "Продукт з таким ідентифікатором вже існує" << std::endl;
            goto tryAgain;
        }

        std::cout << "Enter the name of the item: ";
        std::cin >> name;
        std::cout << "Enter the brand of the item: ";
        std::cin >> brand;
        std::cout << "Enter the type of the item: ";
        std::cin >> type;
        std::cout << "Enter the sezon of the item: ";
        std::cin >> sezon;
        std::cout << "Enter the gender of the item: ";
        std::cin >> gender;
        std::cout << "Enter the size of the item: ";
        std::cin >> size;
        std::cout << "Enter the price of the item: ";
        std::cin >> price;

        SportswearItem newItem(id, name, brand, type, sezon, gender, size, price);
        database.push_back(newItem);
        std::cout << "Item added successfully.\n";
        std::cout << std::setw(9) << "ID" << std::setw(23) << "Name" << std::setw(20) << "Brand" << std::setw(17) << "Type" << std::setw(15) << "Sezon" << std::setw(15) << "Gender" << std::setw(7) << "Size" << std::setw(10) << "Price" << "\n";
        std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        std::cout << std::setw(9) << id << std::setw(23) << name << std::setw(20) << brand << std::setw(17) << type << std::setw(15) << sezon << std::setw(15) << gender << std::setw(7) << size << std::setw(10) << price << "\n";
    }

    void SportswearDatabase::deleteItem()
    {
        int id;
        std::cout << "Enter the ID of the item to delete: ";
        std::cin >> id;

        auto it = std::find_if(database.begin(), database.end(), [&](const SportswearItem& item) {
            return item.id == id;
            });

        if (it != database.end()) {
            database.erase(it);
            std::cout << "Item deleted successfully.\n";
        }
        else {
            std::cout << "Item not found.\n";
        }
    }

    void SportswearDatabase::updateItemById()
    {
        int itemId;
        std::cout << "Enter the id of the item to update: ";
        std::cin >> itemId;

        auto it = std::find_if(database.begin(), database.end(), [&](const SportswearItem& item) {
            return item.id == itemId;
            });

        if (it != database.end()) {
            std::string name, brand, type, sezon, gender, size;
            double price;

            std::cout << "Enter the name of the item (or enter 1 to keep the existing value): ";
            std::cin >> name;
            if (name != "1") {
                it->name = name;
            }

            std::cout << "Enter the brand of the item (or enter 1 to keep the existing value): ";
            std::cin >> brand;
            if (brand != "1") {
                it->brand = brand;
            }

            std::cout << "Enter the type of the item (or enter 1 to keep the existing value): ";
            std::cin >> type;
            if (type != "1") {
                it->type = type;
            }

            std::cout << "Enter the season of the item (or enter 1 to keep the existing value): ";
            std::cin >> sezon;
            if (sezon != "1") {
                it->sezon = sezon;
            }

            std::cout << "Enter the gender of the item (or enter 1 to keep the existing value): ";
            std::cin >> gender;
            if (gender != "1") {
                it->gender = gender;
            }

            std::cout << "Enter the size of the item (or enter 1 to keep the existing value): ";
            std::cin >> size;
            if (size != "1") {
                it->size = size;
            }

            std::cout << "Enter the price of the item (or enter 1 to keep the existing value): ";
            std::cin >> price;
            if (price != 1) {
                it->price = price;
            }

            std::cout << "Item updated successfully.\n";
            std::cout << std::setw(9) << "ID" << std::setw(23) << "Name" << std::setw(20) << "Brand" << std::setw(17) << "Type" << std::setw(15) << "Sezon" << std::setw(15) << "Gender" << std::setw(7) << "Size" << std::setw(10) << "Price" << "\n";
            std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";

            std::cout << std::setw(9) << itemId << std::setw(23) << it->name << std::setw(20) << it->brand << std::setw(17) << it->type << std::setw(15) << it->sezon << std::setw(15) << it->gender << std::setw(7) << it->size << std::setw(10) << it->price << "\n";
        }
        else {
            std::cout << "Item not found.\n";
        }
    }

    void SportswearDatabase::displayItems() const
    {
        if (database.empty()) {
            std::cout << "No items found.\n";
            return;
        }

        std::cout << "Sportswear items in the database:\n";
        std::cout << std::setw(9) << "ID" << std::setw(23) << "Name" << std::setw(20) << "Brand" << std::setw(17) << "Type" << std::setw(15) << "Sezon" << std::setw(15) << "Gender" << std::setw(7) << "Size" << std::setw(10) << "Price" << "\n";
        std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        for (const auto& item : database) {
            std::cout << std::setw(9) << item.id << std::setw(23) << item.name << std::setw(20) << item.brand << std::setw(17) << item.type << std::setw(15) << item.sezon << std::setw(15) << item.gender << std::setw(7) << item.size << std::setw(10) << item.price << "\n";
        }
    }

    void SportswearDatabase::sortItemsByName()
    {
        std::sort(database.begin(), database.end(), [](const SportswearItem& item1, const SportswearItem& item2) {
            return item1.name < item2.name;
            });
        std::cout << "Items sorted by name.\n";
    }

    void SportswearDatabase::sortItemsByBrand()
    {
        std::sort(database.begin(), database.end(), [](const SportswearItem& item1, const SportswearItem& item2) {
            return item1.brand < item2.brand;
            });
        std::cout << "Items sorted by brand.\n";
    }

    void SportswearDatabase::sortItemsByPrice()
    {
        std::sort(database.begin(), database.end(), [](const SportswearItem& item1, const SportswearItem& item2) {
            return item1.price < item2.price;
            });
        std::cout << "Items sorted by price.\n";
    }

    void SportswearDatabase::searchItemsByBrand() const
    {
        std::string brand;
        std::cout << "Enter the brand to search for: ";
        std::cin >> brand;

        // Перетворюємо введений бренд у нижній регістр для порівняння
        std::transform(brand.begin(), brand.end(), brand.begin(), ::tolower);

        std::vector<SportswearItem> searchResults;

        std::copy_if(database.begin(), database.end(), std::back_inserter(searchResults), [&](const SportswearItem& item) {
            // Перетворюємо бренд елемента бази даних у нижній регістр для порівняння
            std::string itemBrand = item.brand;
        std::transform(itemBrand.begin(), itemBrand.end(), itemBrand.begin(), ::tolower);
        return itemBrand.find(brand) != std::string::npos;
            });

        if (searchResults.empty()) {
            std::cout << "No items found for the brand: " << brand << "\n";
        }
        else {
            std::cout << "Search results for the brand: " << brand << "\n";
            std::cout << std::setw(9) << "ID" << std::setw(23) << "Name" << std::setw(20) << "Brand" << std::setw(17) << "Type" << std::setw(15) << "Sezon" << std::setw(15) << "Gender" << std::setw(7) << "Size" << std::setw(10) << "Price" << "\n";
            std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
            for (const auto& item : searchResults) {
                std::cout << std::setw(9) << item.id << std::setw(23) << item.name << std::setw(20) << item.brand << std::setw(17) << item.type << std::setw(15) << item.sezon << std::setw(15) << item.gender << std::setw(7) << item.size << std::setw(10) << item.price << "\n";
            }
        }
    }

    void SportswearDatabase::searchItemsByID() const
    {
        int id;
        std::cout << "Enter the ID to search for: ";
        std::cin >> id;

        std::vector<SportswearItem> searchResults;

        std::copy_if(database.begin(), database.end(), std::back_inserter(searchResults), [&](const SportswearItem& item) {
            return item.id == id;
            });

        if (searchResults.empty()) {
            std::cout << "No items found for the ID: " << id << "\n";
        }
        else {
            std::cout << "Search result for the ID: " << id << "\n";
            std::cout << std::setw(9) << "ID" << std::setw(23) << "Name" << std::setw(20) << "Brand" << std::setw(17) << "Type" << std::setw(15) << "Sezon" << std::setw(15) << "Gender" << std::setw(7) << "Size" << std::setw(10) << "Price" << "\n";
            std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
            for (const auto& item : database) {
                std::cout << std::setw(9) << item.id << std::setw(23) << item.name << std::setw(20) << item.brand << std::setw(17) << item.type << std::setw(15) << item.sezon << std::setw(15) << item.gender << std::setw(7) << item.size << std::setw(10) << item.price << "\n";
            }
        }
    }

    void SportswearDatabase::addReview()
    {
        std::string itemName, customerName, comment;

        std::cout << "Enter the name of the item: ";
        std::cin >> itemName;
        std::cout << "Enter your name: ";
        std::cin >> customerName;
        std::cout << "Enter your comment: ";
        std::cin.ignore();
        std::getline(std::cin, comment);

        Review newReview(itemName, customerName, comment);
        reviews.push_back(newReview);
        std::cout << "Review added successfully.\n";
        std::cout << "Item: " << itemName << ", Customer: " << customerName << "\nComment: " << comment << "\n";
    }

    void SportswearDatabase::deleteReview()
    {
        std::string itemName, customerName, comment;

        std::cout << "Enter the name of the item: ";
        std::cin >> itemName;
        std::cout << "Enter the customer's name: ";
        std::cin >> customerName;

        auto it = std::find_if(reviews.begin(), reviews.end(), [&](const Review& review) {
            return review.itemName == itemName && review.customerName == customerName;
            });

        if (it != reviews.end()) {
            reviews.erase(it);
            std::cout << "Review deleted successfully.\n";
        }
        else {
            std::cout << "Review not found.\n";
        }
    }

    void SportswearDatabase::displayReviews() const
    {
        if (reviews.empty()) {
            std::cout << "No reviews found.\n";
            return;
        }

        std::cout << "Reviews:\n";
        for (const auto& review : reviews) {
            std::cout << "Item: " << review.itemName << ", Customer: " << review.customerName << "\nComment: " << review.comment << "\n";
        }
    }

    void SportswearDatabase::saveDatabaseToFile() const
    {
        std::ofstream outFile("database.txt");
        if (!outFile) {
            std::cout << "Error: Unable to save database to file.\n";
            return;
        }

        for (const auto& item : database) {
            outFile << item.id << " " << item.name << " " << item.brand << " " << item.type << " " << item.sezon << " " << item.gender << " " << item.size << " " << item.price << "\n";
        }

        outFile.close();
    }

    void SportswearDatabase::saveReviewsToFile() const
    {
        std::ofstream outFile("reviews.txt");
        if (!outFile) {
            std::cout << "Error: Unable to save reviews to file.\n";
            return;
        }

        for (const auto& review : reviews) {
            outFile << review.itemName << " " << review.customerName << " " << review.comment << "\n";
        }

        outFile.close();
    }

    void SportswearDatabase::loadDatabaseFromFile()
    {
        std::ifstream inFile("database.txt");
        if (!inFile) {
            std::cout << "Database file not found.\n";
            return;
        }

        int id;
        std::string name, brand, type, sezon, gender, size;
        double price;

        while (inFile >> id >> name >> brand >> type >> sezon >> gender >> size >> price) {
            SportswearItem newItem(id, name, brand, type, sezon, gender, size, price);
            database.push_back(newItem);
        }

        inFile.close();
    }

    void SportswearDatabase::loadReviewsFromFile()
    {
        std::ifstream inFile("reviews.txt");
        if (!inFile) {
            std::cout << "Reviews file not found.\n";
            return;
        }

        std::string itemName, customerName, comment;

        while (inFile >> itemName >> customerName) {
            inFile.ignore();
            std::getline(inFile, comment);

            Review newReview(itemName, customerName, comment);
            reviews.push_back(newReview);
        }

        inFile.close();
    }

    SportswearDatabase::SportswearDatabase()
    {
        userType = "guest";
        loadDatabaseFromFile();
        loadReviewsFromFile();
    }

    bool SportswearDatabase::login()
    {
        std::string username, password, storedUsername, storedPassword;
        std::ifstream authFile("auth.txt");

        if (!authFile) {
            std::cout << "Authentication file not found.\n";
            return false;
        }



        std::cout << "Enter your username: ";
        std::cin >> username;
        std::cout << "Enter your password: ";
        std::cin >> password;

        // Perform authentication here, e.g., check against a user database
        bool isAuthenticated = false; // Змінна для збереження результату аутентифікації

        while (authFile >> storedUsername >> storedPassword >> userType) {
            if (username == storedUsername && password == storedPassword) {
                isAuthenticated = true;
                break; // Зупинити цикл після успішної аутентифікації
            }
        }

        if (isAuthenticated) {
            return true;
        }
        else {
            return false;
        }

        authFile.close();
    }

    void SportswearDatabase::displayMenu() const
    {
        std::cout << "========== Menu ==========\n";
        if (userType == "admin") {
            std::cout << "1. Add item\n";
            std::cout << "2. Delete item\n";
            std::cout << "3. Display items\n";
            std::cout << "4. Sort items\n";
            std::cout << "5. Search items by brand\n";
            std::cout << "6. Add review\n";
            std::cout << "7. Delete review\n";
            std::cout << "8. Display reviews\n";
            std::cout << "9. Update item\n";
            std::cout << "10. Logout\n";
        }
        else if (userType == "customer") {
            std::cout << "1. Display items\n";
            std::cout << "2. Search items by brand\n";
            std::cout << "3. Add review\n";
            std::cout << "4. Delete review\n";
            std::cout << "5. Display reviews\n";
            std::cout << "6. Logout\n";
        }
        std::cout << "==========================\n";
    }

    void SportswearDatabase::run()
    {
        bool loggedIn = false;

        while (true) {
            while (!loggedIn) {
                std::cout << "========== Login ==========\n";
                loggedIn = login();
            }

            system("cls");
            displayMenu();

            int choice;
            std::cout << "Enter your choice: ";
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid menu choice.\n";
                continue;
            }
            system("cls");

            if (userType == "admin") {
                if (choice < 1 || choice > 10) {
                    std::cout << "Invalid choice. Please enter a valid menu option.\n";
                    continue;
                }

                switch (choice) {
                case 1:
                    system("cls");
                    addItem();
                    break;
                case 2:
                    displayItems();
                    deleteItem();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    displayItems();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    int sortChoice;
                    tr:
                    std::cout << "========== Sort by ==========\n";
                    std::cout << "1. Name\n";
                    std::cout << "2. Brand\n";
                    std::cout << "3. Price\n";
                    std::cout << "4. <<<\n";

                    std::cin >> sortChoice;

                    switch (sortChoice) {
                    case 1:
                        system("cls");
                        sortItemsByName();
                        displayItems();
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        sortItemsByBrand();
                        displayItems();
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        system("cls");
                        sortItemsByPrice();
                        displayItems();
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        system("cls");
                        break;
                    }
                    
                    system("cls");
                    break;
                case 5:
                    searchItemsByBrand();
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    addReview();
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    deleteReview();
                    system("pause");
                    system("cls");
                    break;
                case 8:
                    displayReviews();
                    system("pause");
                    system("cls");
                    break;
                case 9:
                    updateItemById();
                    system("pause");
                    system("cls");
                    break;
                case 10:
                    saveDatabaseToFile();
                    saveReviewsToFile();
                    loggedIn = false;
                    std::cout << "Logout successful.\n";
                    break;
                }
            }
            else if (userType == "customer") {
                if (choice < 1 || choice > 6) {
                    std::cout << "Invalid choice. Please enter a valid menu option.\n";
                    continue;
                }

                switch (choice) {
                case 1:
                    displayItems();
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    searchItemsByBrand();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    addReview();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    deleteReview();
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    displayReviews();
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    loggedIn = false;
                    std::cout << "Logout successful.\n";
                    break;
                }
            }
        }
    }
