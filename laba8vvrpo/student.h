#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string date;
    int grade;
    std::string subject;
};

// Функции для работы со студентами
void printStudents(const std::vector<Student>& students);
std::vector<Student> filterBySubject(const std::vector<Student>& students, const std::string& subject);
std::vector<Student> filterByGrade(const std::vector<Student>& students, int minGrade);
void insertionSortBySurname(std::vector<Student>& students);
void mergeSort(std::vector<Student>& students);

// Функции для работы с файлами
std::vector<Student> loadFromFile(const std::string& filename);

#endif // STUDENT_H