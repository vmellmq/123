#include "student.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    std::string filename = "students.txt";
    std::vector<Student> students = loadFromFile(filename);

    if (students.empty()) {
        std::cout << "Нет данных о студентах!" << std::endl;
        return 1;
    }

    std::cout << "Студенты и их оценки по дисциплине 'История Беларуси':\n";
    printStudents(filterBySubject(students, "История Беларуси"));

    std::cout << "\nСтуденты с оценками выше 7 баллов:\n";
    printStudents(filterByGrade(students, 7));

    std::cout << "\nСортировка по фамилии (вставками):\n";
    insertionSortBySurname(students);
    printStudents(students);

    std::cout << "\nСортировка по дисциплине и убыванию оценки (слияние):\n";
    mergeSort(students);
    printStudents(students);

    return 0;
}