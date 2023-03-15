#include <iostream>
#include <fstream>

const int MAX_TITLE_SIZE = 64;
const int MAX_GAMES = 3;
const char PATH[30] = "test.txt";

void strCopy(char *str1, const char *str2) {
    int rotator = -1;
    while (str2[++rotator]) {
        str1[rotator] = str2[rotator];
    }
    str1[rotator] = '\0';
}

class Game {
    char title[MAX_TITLE_SIZE];
    float price;
    bool isAvailable;

    Game() {
        strCopy(this->title, "none");
        price = -1;
        isAvailable = false;
    }

    Game(const char *title, float price, bool isAvailable) {
        strCopy(this->title, title);
        this->price = price;
        this->isAvailable = isAvailable;
    }

public:
    const char *getTitle() const {
        return title;
    }

    float getPrice() const {
        return price;
    }

    bool getIsAvailable() const {
        return isAvailable;
    }

    void SetTitle(const char *title) {
        strCopy(this->title, title);
    }

    void SetPrice(float price) {
        this->price = price;
    }

    void SetIsAvailable(bool isAvailable) {
        this->isAvailable = isAvailable;
    }

    bool isFree() const {
        if (1 - price < 1)
            return false;
        return true;
    }

    void print() const {
        std::cout << "Title: " << title << std::endl
                  << "Price: " << price << std::endl
                  << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }
};

class GamePlatform {
    Game games[MAX_GAMES];
    int size;
public:
    void addGame(const char *title, float price, bool isAvailable) {
        if (size == MAX_GAMES)
            return;
        size++;
        games[size].SetTitle(title);
        if (price < 0)
            games[size].SetPrice(0);
        else
            games[size].SetPrice(price);
        games[size].SetIsAvailable(isAvailable);
    }

    void readByIndex(int index) const {
        if (index >= size || index < 0 || games[index].getPrice() == -1)
            return;
        games[index].print();
    }

    void readAll() const {
        for (int i = 0; i < size; ++i)
            games[i].print();
    }

    void readMinMaxPriceGame() const {
        int min_pos = 0, max_pos = 0, min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < size; ++i) {
            if (min > games[i].getPrice() && games[i].getPrice() != 0) {
                min = games[i].getPrice();
                min_pos = i;
            }
            if (max < games[i].getPrice() && games[i].getPrice() != 0) {
                max = games[i].getPrice();
                max_pos = i;
            }
        }
        std::cout << "Max: \n";
        games[max_pos].print();
        std::cout << "Min: \n";
        games[min_pos].print();
    }

    void readFree() const {
        for (int i = 0; i < size; ++i)
            if (games[i].isFree())
                games[i].print();
    }

    void deleteByIndex(int index) {
        if (index >= size || index < 0 || games[index].getPrice() == -1)
            return;
        games[index].SetTitle("none");
        games[index].SetPrice(-1);
        games->SetIsAvailable(false);
    }

    void writeToFile() const {
        std::fstream file(PATH, std::ios::out);

        //continue

        file.close();
    }
};

int main() {

}
