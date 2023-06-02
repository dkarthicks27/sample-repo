#include <stdio.h>

struct Employee
{
    char name[100];
    int age;
    int employee_id;
    int reporting_to_id;
};

void printEmployees(struct Employee employees[], int n, int reporting_to_id)
{
    for (int i = 0; i < n; i++)
    {
        if (employees[i].reporting_to_id == reporting_to_id)
        {
            printf("%s %d\n", employees[i].name, employees[i].employee_id);
            printEmployees(employees, n, employees[i].employee_id);
        }
    }
}

int main()
{
    struct Employee employees[] = {
        {"karthick", 24, 125, 112},
        {"dinesh", 26, 126, 112},
        {"sathish", 32, 112, 105},
        {"Nikhil", 42, 105, -1},
        {"Mani", 22, 709, 125},
        {"Jegan", 32, 120, 709},
        {"Sanjeev", 21, 805, 125},
        {"chetanya", 19, 710, 126}};

    int n = sizeof(employees) / sizeof(employees[0]);

    for (int i = 0; i < n; i++)
    {
        if (employees[i].reporting_to_id == -1)
        {
            printf("%s %d\n", employees[i].name, employees[i].employee_id);
            printEmployees(employees, n, employees[i].employee_id);
        }
    }

    return 0;
}
