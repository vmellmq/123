#include "pch.h"
#include "CppUnitTest.h"
#include "../laba8vvrpo/student.h"  // Подключите ваш заголовочный файл
#include<vector>
#include "../laba8vvrpo/student_utils.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentTests
{
    TEST_CLASS(StudentFilterTests)
    {
    public:

        TEST_METHOD(TestFilterBySubject)
        {
            // Подготовка тестовых данных
            std::vector<Student> testStudents = {
                {"Иванов", "Иван", "Иванович", "2000-01-01", 8, "История Беларуси"},
                {"Петров", "Петр", "Петрович", "2001-02-02", 7, "Математика"},
                {"Сидорова", "Анна", "Сергеевна", "2002-03-03", 9, "История Беларуси"}
            };

            // Вызов тестируемой функции
            auto result = filterBySubject(testStudents, "История Беларуси");

            // Проверка результатов
            Assert::AreEqual(size_t(2), result.size(), L"Должно быть 2 студента");
            Assert::AreEqual(std::string("Иванов"), result[0].surname, L"Первый студент - Иванов");
            Assert::AreEqual(std::string("Сидорова"), result[1].surname, L"Второй студент - Сидорова");
        }

        TEST_METHOD(TestFilterByGrade)
        {
            std::vector<Student> testStudents = {
                {"Иванов", "Иван", "Иванович", "2000-01-01", 5, "Физика"},
                {"Петров", "Петр", "Петрович", "2001-02-02", 8, "Химия"},
                {"Сидоров", "Алексей", "Алексеевич", "2002-03-03", 7, "Биология"}
            };

            auto result = filterByGrade(testStudents, 6);

            Assert::AreEqual(size_t(2), result.size());
            Assert::AreEqual(std::string("Петров"), result[0].surname);
            Assert::AreEqual(std::string("Сидоров"), result[1].surname);
        }
    };

    TEST_CLASS(StudentSortTests)
    {
    public:
        TEST_METHOD(TestInsertionSortBySurname)
        {
            std::vector<Student> testStudents = {
                {"Петров", "Петр", "Петрович", "2001-02-02", 8, "Химия"},
                {"Сидоров", "Алексей", "Алексеевич", "2002-03-03", 7, "Биология"},
                {"Иванов", "Иван", "Иванович", "2000-01-01", 5, "Физика"}
            };

            insertionSortBySurname(testStudents);

            Assert::AreEqual(std::string("Иванов"), testStudents[0].surname);
            Assert::AreEqual(std::string("Петров"), testStudents[1].surname);
            Assert::AreEqual(std::string("Сидоров"), testStudents[2].surname);
        }
    };
}