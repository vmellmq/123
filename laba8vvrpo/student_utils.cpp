#include "student.h"
#include <iostream>
#include <algorithm>
#include <sstream>

// Вывод списка студентов
void printStudents(const std::vector<Student>& students) {
    for (const auto& student : students) {
        std::cout << student.surname << " " << student.name << " " << student.patronymic
            << " | Дата: " << student.date << " | Оценка: " << student.grade
            << " | Дисциплина: " << student.subject << std::endl;
    }
}

// Фильтрация по предмету
std::vector<Student> filterBySubject(const std::vector<Student>& students, const std::string& subject) {
    std::vector<Student> result;
    for (const auto& student : students) {
        if (student.subject == subject) {
            result.push_back(student);
        }
    }
    return result;
}

// Фильтрация по оценке
std::vector<Student> filterByGrade(const std::vector<Student>& students, int minGrade) {
    std::vector<Student> result;
    for (const auto& student : students) {
        if (student.grade > minGrade) {
            result.push_back(student);
        }
    }
    return result;
}

// Сортировка вставками по фамилии
void insertionSortBySurname(std::vector<Student>& students) {
    for (size_t i = 1; i < students.size(); i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].surname > key.surname) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

// Компаратор для сортировки слиянием
bool compareBySubjectAndGrade(const Student& a, const Student& b) {
    if (a.subject != b.subject) {
        return a.subject < b.subject;
    }
    return a.grade > b.grade;
}

// Сортировка слиянием
void mergeSort(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), compareBySubjectAndGrade);
}