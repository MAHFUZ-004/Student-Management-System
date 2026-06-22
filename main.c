#include<stdio.h>
#include "student.h"

int main()
{
    int choice;

    while(1)
    {
        printf("\n\t\t\t\t\t=================================================\n");
        printf("\t\t\t\t\t||          Student Management System          ||"    );
        printf("\n\t\t\t\t\t=================================================\n");
        printf("\n\t\t\t\t\t[1] Store Student Information");
        printf("\n\t\t\t\t\t[2] Display All Student Information");
        printf("\n\t\t\t\t\t[3] Search Student Information");
        printf("\n\t\t\t\t\t[4] Edit Student Information");
        printf("\n\t\t\t\t\t[5] Delete Student Information");
        printf("\n\t\t\t\t\t[6] About Us");
        printf("\n\t\t\t\t\t[0] Exit Program\n");
        printf("\n\t\t\t\t\t=================================================\n");
        printf("\t\t\t\t\tSelect an option: ");
        scanf("%d", &choice);
          switch(choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                editStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                aboutUs();
                break;
            case 0:
                return 0;

            default:
                printf("\t\t\t\t\tInvalid option. Select an valid Option\n");
        }
    }
}
