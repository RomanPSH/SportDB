#include "Review.h"
#include "SportswearItem.h"

class SportswearDatabase {
private:
    std::vector<SportswearItem> database;
    std::vector<Review> reviews;
    std::string userType;

    void addItem();

    void deleteItem();

    void updateItemById();

    void displayItems() const;

    void sortItemsByName();

    void sortItemsByBrand();

    void sortItemsByPrice();

    void searchItemsByBrand() const;
    
    void searchItemsByID() const;

    void addReview();

    void deleteReview();

    void displayReviews() const;

    void saveDatabaseToFile() const;

    void saveReviewsToFile() const;

    void loadDatabaseFromFile();

    void loadReviewsFromFile();

public:
    SportswearDatabase();

    bool login();

    void displayMenu() const;

    void run();
};