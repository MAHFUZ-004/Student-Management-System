#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

struct Student
{
    char name[50];
    int id;
    char email[50];
    char phone[20];
    char department[50];
    char program[50];
    char semester[30];
    char batch[10];
};

void addStudent();
void displayStudent();
void searchStudent();
void editStudent();
void deleteStudent();
void aboutUs();
#endif // STUDENT_H_INCLUDED
