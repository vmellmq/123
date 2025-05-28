#include "pch.h"
#include "CppUnitTest.h"
#include "../laba8vvrpo/student.h"  // ���������� ��� ������������ ����
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
            // ���������� �������� ������
            std::vector<Student> testStudents = {
                {"������", "����", "��������", "2000-01-01", 8, "������� ��������"},
                {"������", "����", "��������", "2001-02-02", 7, "����������"},
                {"��������", "����", "���������", "2002-03-03", 9, "������� ��������"}
            };

            // ����� ����������� �������
            auto result = filterBySubject(testStudents, "������� ��������");

            // �������� �����������
            Assert::AreEqual(size_t(2), result.size(), L"������ ���� 2 ��������");
            Assert::AreEqual(std::string("������"), result[0].surname, L"������ ������� - ������");
            Assert::AreEqual(std::string("��������"), result[1].surname, L"������ ������� - ��������");
        }

        TEST_METHOD(TestFilterByGrade)
        {
            std::vector<Student> testStudents = {
                {"������", "����", "��������", "2000-01-01", 5, "������"},
                {"������", "����", "��������", "2001-02-02", 8, "�����"},
                {"�������", "�������", "����������", "2002-03-03", 7, "��������"}
            };

            auto result = filterByGrade(testStudents, 6);

            Assert::AreEqual(size_t(2), result.size());
            Assert::AreEqual(std::string("������"), result[0].surname);
            Assert::AreEqual(std::string("�������"), result[1].surname);
        }
    };

    TEST_CLASS(StudentSortTests)
    {
    public:
        TEST_METHOD(TestInsertionSortBySurname)
        {
            std::vector<Student> testStudents = {
                {"������", "����", "��������", "2001-02-02", 8, "�����"},
                {"�������", "�������", "����������", "2002-03-03", 7, "��������"},
                {"������", "����", "��������", "2000-01-01", 5, "������"}
            };

            insertionSortBySurname(testStudents);

            Assert::AreEqual(std::string("������"), testStudents[0].surname);
            Assert::AreEqual(std::string("������"), testStudents[1].surname);
            Assert::AreEqual(std::string("�������"), testStudents[2].surname);
        }
    };
}