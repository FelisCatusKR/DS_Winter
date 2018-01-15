#include <stdio.h>

#define NUM_HW 3
#define NUM_EXAMS 2
#define MAX_ENROLL 5

typedef struct {
    char name[31];
    int progs [NUM_HW];
    int exams [NUM_EXAMS];
    int progAvg;
    double examAvg;
    double numGrade;
    char Grade;
} studentT;

typedef struct {
    studentT* students[MAX_ENROLL];
    int numEnrolled;
} courseT;

studentT* GetStudentData(void);
void PrintStudentData(studentT*);

int main(void) {
    int i;
    courseT* cs2010A = (courseT*)malloc(sizeof(courseT));
    cs2010A->numEnrolled = 0;

    for (i=0; i<MAX_ENROLL; i++) {
        cs2010A->students[i] = GetStudentData();
        cs2010A->numEnrolled++;
    }

    for (i=0; i<cs2010A->numEnrolled; i++)
        PrintStudentData(cs2010A->students[i]);

    return 0;
}

studentT* GetStudentData(void) {
    int i;
    int total;
    studentT* tmp = (studentT*)malloc(sizeof(studentT));

    printf("Student name: ");
    scanf("%s", tmp->name);
    for (i=0; i<NUM_HW; i++) {
        printf("Homework No.%d score: ", i+1);
        scanf("%d", &(tmp->progs[i]));
    }
    for (i=0; i<NUM_EXAMS; i++) {
        printf("Exam No.%d score: ", i+1);
        scanf("%d", &(tmp->exams[i]));
    }

    total = 0;
    for (i=0; i<NUM_HW; i++) {
        total += tmp->progs[i];
    }
    tmp->progAvg = total / NUM_HW;

    total = 0;
    for (i=0; i<NUM_EXAMS; i++) {
        total += tmp->exams[i];
    }
    tmp->examAvg = total / (double)NUM_EXAMS;

    tmp->numGrade = (tmp->progAvg + tmp->examAvg) / 2;

    switch((int)(tmp->numGrade/10)) {
    case 10:
    case 9:
        tmp->Grade = 'A';
        break;
    case 8:
        tmp->Grade = 'B';
        break;
    case 7:
        tmp->Grade = 'C';
        break;
    case 6:
        tmp->Grade = 'D';
        break;
    default:
        tmp->Grade = 'F';
    }

    return tmp;
}

void PrintStudentData(studentT* t) {
    int i;
    printf("Student name: %s\n", t->name);
    printf("Homework score: ");
    for(i=0; i<NUM_HW; i++)
        printf("%d ", t->progs[i]);
    putchar('\n');
    printf("Exam score: ");
    for(i=0; i<NUM_EXAMS; i++)
        printf("%d ", t->exams[i]);
    putchar('\n');
    printf("Grade: %c\n\n", t->Grade);
}
