#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"
void addStudent()
{
    FILE *fp;

    struct Student s;
    fp=fopen("students.dat","ab");
    if(fp==NULL)
    {
        printf("File opening failed\n");
        return;
    }
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t||          Store Student Information          ||"    );
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\n\t\t\t\t\tStudent's Name: ");
    scanf(" %[^\n]", s.name);
    printf("\n\t\t\t\t\tStudent ID: ");
    scanf("%d", &s.id);
    printf("\n\t\t\t\t\tEmail ID: ");
    scanf("%s",s.email);
    printf("\n\t\t\t\t\tPhone Number: ");
    scanf("%s",s.phone);
    printf("\n\t\t\t\t\tDepartment: ");
    scanf(" %[^\n]",s.department);
    printf("\n\t\t\t\t\tProgram: ");
    scanf(" %[^\n]",s.program);
    printf("\n\t\t\t\t\tEnrollment Semester: ");
    scanf(" %[^\n]",s.semester);
    printf("\n\t\t\t\t\tBatch: ");
    scanf(" %[^\n]",s.batch);
    printf("\n\t\t\t\t\t=================================================\n");

    fwrite(&s,sizeof(struct Student),1,fp);

    fclose(fp);

    printf("\t\t\t\t\tStudent Added Successfully!\n");

}
void displayStudent()
{
    FILE*fp;

    struct Student s;

    fp=fopen("students.dat", "rb");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tStudent record not found\n");
        return;
    }
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t||       Display All Student Information       ||"    );
    printf("\n\t\t\t\t\t=================================================\n");
    while(fread(&s,sizeof(struct Student),1,fp))
    {
    printf("\n\t\t\t\t\tStudent's Name: %s",s.name);
    printf("\n\t\t\t\t\tStudent ID: %d",s.id);
    printf("\n\t\t\t\t\tEmail ID: %s",s.email);
    printf("\n\t\t\t\t\tPhone Number: %s",s.phone);
    printf("\n\t\t\t\t\tDepartment: %s",s.department);
    printf("\n\t\t\t\t\tProgram: %s",s.program);
    printf("\n\t\t\t\t\tEnrollment Semester: %s",s.semester);
    printf("\n\t\t\t\t\tBatch: %s\n",s.batch);
    printf("\n\t\t\t\t\t=================================================\n");
    }

    fclose(fp);

}

void searchStudent()
{
    FILE*fp;

    int id;
    int found=0;

    struct Student s;

    fp=fopen("students.dat", "rb");

    if(fp==NULL)
    {
        printf("\t\t\t\t\tStudent record not found\n");
        return;
    }
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t||          Search Student Information         ||"    );
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\tEnter student ID to search: " );
    scanf("%d", &id);

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(id==s.id)
        {
            found=1;
            printf("\t\t\t\t\tStudent ID found\n");
            printf("\n\t\t\t\t\t=================================================\n");
            printf("\n\t\t\t\t\tStudent's Name: %s",s.name);
            printf("\n\t\t\t\t\tStudent ID: %d",s.id);
            printf("\n\t\t\t\t\tEmail ID: %s",s.email);
            printf("\n\t\t\t\t\tPhone Number: %s",s.phone);
            printf("\n\t\t\t\t\tDepartment: %s",s.department);
            printf("\n\t\t\t\t\tProgram: %s",s.program);
            printf("\n\t\t\t\t\tEnrollment Semester: %s",s.semester);
            printf("\n\t\t\t\t\tBatch: %s\n",s.batch);
            printf("\n\t\t\t\t\t=================================================\n");
            break;
        }
    }
    if(!found)
    {
        printf("\t\t\t\t\tStudent ID not found\n" );
    }
    fclose(fp);
}

void editStudent()
{
    FILE*fp;

    int id;
    int found=0;
    int choice;

    struct Student s;

    fp=fopen("students.dat", "rb+");

    if(fp==NULL)
    {
        printf("\t\t\t\t\tStudent record not found\n");
        return;
    }
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t||          Update Student Information         ||"    );
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\tEnter student ID to update information: " );
    scanf("%d", &id);

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(id==s.id)
        {
            found=1;
            printf("\t\t\t\t\tStudent ID found\n");
            printf("\n\t\t\t\t\t=================================================\n");
            printf("\t\t\t\t\t[1]Student's Name\n");
            printf("\t\t\t\t\t[2]Student ID\n");
            printf("\t\t\t\t\t[3]Email ID\n");
            printf("\t\t\t\t\t[4]Phone Number\n");
            printf("\t\t\t\t\t[5]Department\n");
            printf("\t\t\t\t\t[6]Program\n");
            printf("\t\t\t\t\t[7]Enrollment Semester\n");
            printf("\t\t\t\t\t[8]Batch\n");
            printf("\n\t\t\t\t\t=================================================\n");
            printf("\t\t\t\t\tSelect an option to update information: ");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    printf("\t\t\t\t\tUpdate Name: ");
                    scanf(" %[^\n]", s.name);
                    break;
                case 2:
                    printf("\t\t\t\t\tUpdate Student ID: ");
                    scanf("%d", &s.id);
                    break;
                case 3:
                    printf("\t\t\t\t\tUpdate Email ID: ");
                    scanf("%s", s.email);
                    break;
                case 4:
                    printf("\t\t\t\t\tUpdate Phone Number: ");
                    scanf("%s", s.phone);
                    break;
                case 5:
                    printf("\t\t\t\t\tUpdate Department: ");
                    scanf(" %[^\n]", s.department);
                    break;
                case 6:
                    printf("\t\t\t\t\tUpdate Program: ");
                    scanf(" %[^\n]", s.program);
                    break;
                case 7:
                    printf("\t\t\t\t\tUpdate Enrollment Semester: ");
                    scanf(" %[^\n]", s.semester);
                    break;
                case 8:
                    printf("\t\t\t\t\tUpdate Batch: ");
                    scanf(" %[^\n]", s.batch);
                    break;
                default:
                    printf("\t\t\t\t\tInvalid option. Select an valid Option\n");
                    fclose(fp);
                    return;
            }

            fseek(fp, -sizeof(struct Student), SEEK_CUR);

            if(fwrite(&s, sizeof(struct Student), 1, fp))
            {

                printf("\n\t\t\t\t\tStudent Information Updated Successfully\n");
            }
            else
            {
                printf("\n\t\t\t\t\tStudent Information Updated Failed!\n");
            }
            break;

        }
    }

    if(!found)
    {
        printf("\t\t\t\t\tStudent ID not found\n" );
    }
    fclose(fp);
}

void deleteStudent()
{
    FILE*fp;
    FILE*temp;
    int id;
    int found=0;

    struct Student s;

    fp=fopen("students.dat", "rb");
    temp=fopen("temp.dat", "wb");

    if(fp==NULL)
    {
        printf("\t\t\t\t\tStudent record not found\n");
        return;
    }
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t||          Delete Student Information         ||"    );
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\tEnter student ID to delete information: ");
    scanf("%d", &id);

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(id==s.id){
            found=1;
        }
        else{
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    if(found){
    remove("students.dat");
    rename("temp.dat", "students.dat");
    printf("\t\t\t\t\tStudent ID found\n");
    printf("\t\t\t\t\tStudent information delete successfully\n");
    }

    if(!found)
    {
        remove("temp.dat");
        printf("\n\t\t\t\t\tStudent ID Not found\n");
        printf("\n\t\t\t\t\tStudent Information not deleted\n");
    }
}

void aboutUs(){

    printf("\n\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t||                   About Us                  ||"    );
    printf("\n\t\t\t\t\t=================================================\n");

    printf("\n\t\t\t\t\t======================================================\n");
    printf("\n\t\t\t\t\tName: Muhammad Mahfuzul Hasan");
    printf("\n\t\t\t\t\tID: 1002520005101029");
    printf("\n\t\t\t\t\tDepartment: Computer Science and Engineering");
    printf("\n\t\t\t\t\tProgram: B.Sc in CSE");
    printf("\n\t\t\t\t\tSemester: Spring 2026");
    printf("\n\t\t\t\t\tUniversity: Khulna Khan Bahadur Ahsanullah University\n");
    printf("\n\t\t\t\t\t======================================================\n");
    printf("\n\t\t\t\t\t======================================================\n");
    printf("\n\t\t\t\t\tName: Reyadul Islam Reyad");
    printf("\n\t\t\t\t\tID: 1002520005101030");
    printf("\n\t\t\t\t\tDepartment: Computer Science and Engineering");
    printf("\n\t\t\t\t\tProgram: B.Sc in CSE");
    printf("\n\t\t\t\t\tSemester: Spring 2026");
    printf("\n\t\t\t\t\tUniversity: Khulna Khan Bahadur Ahsanullah University\n");
    printf("\n\t\t\t\t\t======================================================\n");
    printf("\n\t\t\t\t\t======================================================\n");
    printf("\n\t\t\t\t\tName: Sudip Sarker");
    printf("\n\t\t\t\t\tID: 1002520005101031");
    printf("\n\t\t\t\t\tDepartment: Computer Science and Engineering");
    printf("\n\t\t\t\t\tProgram: B.Sc in CSE");
    printf("\n\t\t\t\t\tSemester: Spring 2026");
    printf("\n\t\t\t\t\tUniversity: Khulna Khan Bahadur Ahsanullah University\n");
    printf("\n\t\t\t\t\t======================================================\n");
}
