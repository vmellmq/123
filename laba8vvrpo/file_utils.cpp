#include "student.h"
#include <fstream>
#include <sstream>

// Загрузка данных из файла
std::vector<Student> loadFromFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);
    std::string line;


    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Student student;
        iss >> student.surname >> student.name >> student.patronymic >> student.date >> student.grade;
        std::getline(iss >> std::ws, student.subject); // Чтение subject с удалением лишних пробелов
        students.push_back(student);
    }

    file.close();
    return students;
}