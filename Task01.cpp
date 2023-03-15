#include <iostream>

const int MAX_NAME_LENGTH = 20;

void strCopy(char *str1, const char *str2) {
    int rotator = -1;
    while (str2[++rotator]) {
        str1[rotator] = str2[rotator];
    }
    if (rotator == 0) {
        str1[0] = '\0';
    }
}

class Teacher {
private:
    char name[MAX_NAME_LENGTH];
    int age, exp;

public:
    const char *getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    int getExp() const {
        return exp;
    }
    void setName(const char *name) {
        strCopy(this->name, name);
    }
    void setAge(const int age) {
        this->age = age;
    }
    void setExp(const int exp) {
        this->exp = exp;
    }
};

int main() {
    Teacher teacher;
    teacher.setAge(70);
    teacher.setExp(100);
    teacher.setName("Babev");
    std::cout << teacher.getName() << " " << teacher.getAge() << " " << teacher.getExp() << std::endl;
}