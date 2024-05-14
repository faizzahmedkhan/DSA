#include <iostream>
using namespace std;
#include <cstdlib>

struct Student
{
    int SID;
    Student * SNext;
};

struct Course
{
    int CID;
    Course * CNext;
    Student * StuNext;
};

void InsertCourse(Course ** CHead)
{
    Course * ptr = (Course *)malloc(sizeof(Course));

    cout << "Enter Course ID: ";
    cin >> ptr->CID;

    ptr->CNext = NULL;
    ptr->StuNext = NULL;

    if (*CHead == NULL)
    {
        *CHead = ptr;
    }
    else
    {
        Course * curr = *CHead;
        while (curr->CNext != NULL)
        {
            curr = curr->CNext;
        }
        
        curr->CNext = ptr;
    }
}

void DeleteCourse(Course ** CHead)
{
    if (*CHead == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Enter Course ID of the course you want to delete: ";
        int toDel;
        cin >> toDel;
        bool flag = false;

        if ((*CHead)->CID == toDel)
        {
            Course * temp = *CHead;
            *CHead = (*CHead)->CNext;
            free(temp);
            flag = true;
        }
        else
        {
            Course * curr = (*CHead)->CNext;
            Course * prev = *CHead;

            while (curr != NULL)
            {
                if (curr->CID == toDel)
                {
                    prev->CNext = curr->CNext;
                    free(curr);
                    flag = true;
                    break;
                }
                
                curr = curr->CNext;
                prev = prev->CNext;
            }
        }

        if (flag == false)
        {
            cout << "No Course was found" << endl;
        }
    }
}

void SearchCourse(Course * CHead)
{
    if (CHead == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Enter the Course ID you want to search: ";
        int toSearch;
        cin >> toSearch;

        Course * curr = CHead;
        bool flag = false;

        while (curr != NULL)
        {
            if (curr->CID == toSearch)
            {
                cout << "Found" << endl;
                flag = true;
                break;
            }
            curr = curr->CNext;
        }
        
        if (flag == false)
        {
            cout << "Course not found" << endl;
        }
    }
}

void PrintCourses(Course * CHead)
{
    if (CHead == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Course * curr = CHead;

        while (curr != NULL)
        {
            cout << "Course ID: " << curr->CID << endl;
            curr = curr->CNext;
        }
    }
}

void AddStudent(Course * CHead)
{
    Student * ptr = (Student *)malloc(sizeof(Student));
     
    cout << "Enter Student ID: ";
    cin >> ptr->SID;

    cout << "Enter Course ID of the student to be added to: ";
    int toAdd;
    cin >> toAdd;

    ptr->SNext == NULL;

    Course * curr = CHead;
    bool flag = false;

    while (curr != NULL)
    {
        if (curr->CID == toAdd)
        {
            if (curr->StuNext == NULL)
            {
                curr->StuNext = ptr;
            }
            else
            {
                Student * temp = curr->StuNext;
                while (temp->SNext != NULL)
                {
                    temp = temp->SNext;
                }
                
                temp->SNext = ptr;
            }
            
            flag = true;
            break;
        }
        
        curr = curr->CNext;
    }
    
    if (flag == false)
    {
        cout << "Course not found" << endl;
    }
    
}

void DeleteStudent(Course * CHead, int CtoDel)
{
    if (CHead == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Enter the ID of the student to be deleted: ";
        int toDel;
        cin >> toDel;

        // cout << "Enter the Course ID to delete from: ";
        // int CtoDel;
        // cin >> CtoDel;

        Course * curr = CHead;
        bool flag1 = false;

        while (curr != NULL)
        {
            if (curr->CID == CtoDel)
            {
                bool flag2 = false;
                if (curr->StuNext == NULL)
                {
                    cout << "There are no students in this course" << endl;
                }
                else if (curr->StuNext->SID == toDel)
                {
                    Student * temp = curr->StuNext;
                    curr->StuNext = curr->StuNext->SNext;
                    free(temp);
                    flag2 = true;
                    cout << "Deleted" << endl;
                }
                else
                {
                    Student * temp = curr->StuNext->SNext;
                    Student * prev = curr->StuNext;

                    while (temp != NULL)
                    {
                        if (temp->SID == toDel)
                        {
                            prev->SNext = temp->SNext;
                            free(temp);
                            flag2 = true;
                            cout << "Deleted" << endl;
                            break;
                        }
                        
                        temp = temp->SNext;
                        prev = prev->SNext;
                    }
                    
                }
                if (flag2 == false)
                {
                    cout << "Student was not found in this course" << endl;
                }
                
                flag1 = true;
                break;
            }
            curr = curr->CNext;
        }
        
        if (flag1 == false)
        {
            cout << "Course not found" << endl;
        }
    }
}

void DeleteStudentAll(Course * CHead)
{
    if (CHead == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Enter student ID: ";
        int toDel;
        cin >> toDel;

        Course * curr = CHead;

        while (curr != NULL)
        {
            DeleteStudent(CHead, curr->CID);
            curr = curr->CNext;
        }
        cout << "Deleted" << endl;
    }
}

void SearchStudent(Course * CHead)
{
    if (CHead == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Enter student ID: ";
        int toSearch;
        cin >> toSearch;

        Course * curr = CHead;
        bool flag = false;

        while (curr != NULL)
        {
            Student * temp = curr->StuNext;

            while (temp != NULL)
            {
                if (temp->SID == toSearch)
                {
                    cout << "Found in Course " << curr->CID << endl;
                    flag = true;
                    break;
                }
                temp = temp->SNext;
            }
            curr = curr->CNext;
        }
        if (flag == false)
        {
            cout << "Not found in any course" << endl;
        }
    }
}

void PrintStudents(Course * CHead)
{
    if (CHead == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Enter Course ID: ";
        int toPrint;
        cin >> toPrint;

        Course * curr = CHead;
        bool flag = false;

        while (curr != NULL)
        {
            if (curr->CID == toPrint)
            {
                if (curr->StuNext == NULL)
                {
                    cout << "This course has 0 students" << endl;
                }
                else
                {
                    Student * temp = curr->StuNext;
                    while (temp != NULL)
                    {
                        cout << "Student " << temp->SID << endl;
                        temp = temp->SNext;
                    }
                    flag = true;
                }        
            }
            
            curr = curr->CNext;
        }
        
        if (flag == false)
        {
            cout << "No such course found" << endl;
        }
    }
}

int main ()
{
    Course * CHead = NULL;
    bool flag = true;
    int option;

    while (flag == true)
    {
        cout << "Press" << endl;
        cout << "1. Add a Course" << endl;
        cout << "2. Delete a course" << endl;
        cout << "3. Search a course" << endl;
        cout << "4. Print courses" << endl;
        cout << "5. Add a student to a course" << endl;
        cout << "6. Delete a student from a course" << endl;
        cout << "7. Delete a student from all courses" << endl;
        cout << "8. Search a student" << endl;
        cout << "9. Print list of students in a course" << endl;
        cout << "0. Exit" << endl;

        cin >> option;

        if (option == 1)
        {
            InsertCourse(&CHead);
        }
        else if (option == 2)
        {
            DeleteCourse(&CHead);
        }
        else if (option == 3)
        {
            SearchCourse(CHead);
        }
        else if (option == 4)
        {
            PrintCourses(CHead);
        }
        else if (option == 5)
        {
            AddStudent(CHead);
        }
        else if (option == 6)
        {
            cout << "Enter the Course ID to delete from: ";
            int CtoDel;
            cin >> CtoDel;
            DeleteStudent(CHead, CtoDel);
        }
        else if (option == 7)
        {
            DeleteStudentAll(CHead);
        }
        else if (option == 8)
        {
            SearchStudent(CHead);
        }
        else if (option == 9)
        {
            PrintStudents(CHead);
        }
        else if (option == 0)
        {
            flag == false;
        }
        else
        {
            cout << "Enter valid option" << endl;
        }
    }
    
    return 0;
}