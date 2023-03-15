#include <iostream>
#include <fstream>

const int MAX_NAME_LENGTH = 40;
const int MAX_TEXT_SIZE = 360;
const int AMOUNT_EXERCISES = 2;

void strCopy(char *str1, const char *str2) {
    int rotator = -1;
    while (str2[++rotator]) {
        str1[rotator] = str2[rotator];
    }
    str1[rotator] = '\0';
}

class Exercise {
    char name[MAX_NAME_LENGTH], text[MAX_TEXT_SIZE];
    int point;
public:
    int getPoint() const {
        return point;
    }

    const char *getName() const {
        return name;
    }

    const char *getText() const {
        return text;
    }

    void SetText(const char *text) {
        strCopy(this->text, text);
    }

    void SetName(const char *name) {
        strCopy(this->name, name);
    }

    void SetPoints(const int point) {
        this->point = point;
    }
};

struct Exam {
    Exercise test[AMOUNT_EXERCISES];
    int minPoints;

    void writeToFile() const {
        std::fstream file("data.dat", std::ios::out | std::ios::binary);
        file.write((const char *) &this->test, sizeof(test));
        file.write((const char *) &this->minPoints, 4);
        file.close();
    }

    void readFromFile() {
        std::fstream file("data.dat", std::ios::in | std::ios::binary);
        file.read((char *) &this->test, sizeof(test));
        file.read((char *) &this->minPoints, 4);
        file.close();
    }

    void changeMin(const int min) {
        this->minPoints = min;
    }

    int getMax() const {
        int res = 0;
        for (int i = 0; i < AMOUNT_EXERCISES; ++i) {
            res += this->test->getPoint();
        }
        return res;
    }
};

int main() {
    Exam exam;
    for (int i = 0; i < AMOUNT_EXERCISES; ++i) {
        exam.test[i].SetName("Tessfsddfs");
        exam.test[i].SetText("Tes Text");
        exam.test[i].SetPoints(0);
    }
    for (int i = 0; i < AMOUNT_EXERCISES; ++i) {
        std::cout << exam.test[i].getName() << " "
                  << exam.test[i].getText() << " "
                  << exam.test[i].getPoint() << std::endl;
    }
    exam.readFromFile();
    for (int i = 0; i < AMOUNT_EXERCISES; ++i) {
        std::cout << exam.test[i].getName() << " "
                  << exam.test[i].getText() << " "
                  << exam.test[i].getPoint() << std::endl;
    }
}