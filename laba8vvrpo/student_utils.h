#ifndef STUDENT_UTILS_H
#define STUDENT_UTILS_H

#include <vector>
#include "student.h"

vector<Student> filterBySubject(const vector<Student>& students, const string& subject);
vector<Student> filterByGrade(const vector<Student>& students, int minGrade);
void insertionSortBySurname(vector<Student>& students);
void mergeSort(vector<Student>& students);
void printStudents(const vector<Student>& students);

#endif // STUDENT_UTILS_H
