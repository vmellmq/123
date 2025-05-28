#include "student.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    std::string filename = "students.txt";
    std::vector<Student> students = loadFromFile(filename);

    if (students.empty()) {
        std::cout << "��� ������ � ���������!" << std::endl;
        return 1;
    }

    std::cout << "�������� � �� ������ �� ���������� '������� ��������':\n";
    printStudents(filterBySubject(students, "������� ��������"));

    std::cout << "\n�������� � �������� ���� 7 ������:\n";
    printStudents(filterByGrade(students, 7));

    std::cout << "\n���������� �� ������� (���������):\n";
    insertionSortBySurname(students);
    printStudents(students);

    std::cout << "\n���������� �� ���������� � �������� ������ (�������):\n";
    mergeSort(students);
    printStudents(students);

    return 0;
}