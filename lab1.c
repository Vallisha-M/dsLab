#include <stdio.h>
#define MAX 100

void input(int* id, int* age, int* marks);
void validateDisplay(int id, int age, int marks);

struct student
{
    int id;
    int age;
    int marks;
};

void input(int* id, int* age, int* marks)
{
    printf("Enter student id : ");
    scanf("%d", id);
    printf("Enter student age : ");
    scanf("%d", age);
    printf("Enter student marks : ");
    scanf("%d", marks);
}

void validateDisplay(int id, int age, int marks)
{
    if(age<20||marks<0||marks>100)
        printf("Invalid Data");

    else if(marks>=65)
        printf("Qualified for admission");

    else
        printf("Not qualified for admission");
    printf("\n\n");

}

int main()
{
    struct student st[MAX];
    int n, i;

    printf("Enter number of students : ");
    scanf("%d", &n);

    if(n>MAX)
    {

        printf("\nMAX limit exceeded\n\n");
        return 1;
    }

    for(i=0;i<n;i++)
    {
        input(&(st[i].id), &(st[i].age), &(st[i].marks));
        validateDisplay(st[i].id, st[i].age, st[i].marks);
    }

    printf("-----DONE-----");

    return 0;
}
