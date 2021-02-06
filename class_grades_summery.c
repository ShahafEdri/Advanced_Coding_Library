#include <stdio.h>
#include <stdlib.h>

typedef struct student_init_data {
	int studentID = 0;
	int* ptrGrades = NULL;
	int TotalCoursesTaken = 0;
} Student_init_data;

typedef struct student_processed_data {
	int studentID;
	int gradesAverage = 0;
}Student_processed_data;

typedef struct statistics {
	Student_processed_data* ptrStudentsListAboveAverage = NULL;
	Student_processed_data* ptrStudentsListBelowAverage = NULL;
	int sizeOfPtrA = 0;
	int sizeOfPtrB = 0;
	int classRoomAverage = 0;
}Statistics;

int* Input_Data(const int examsCount) {
	int* examsGradesArray;
	examsGradesArray = (int*)malloc(examsCount * sizeof(int));
	for (int i = 0;i < examsCount;i++) {
		printf("please enter the grade for exam #%d", i);
		scanf_s("%d", (examsGradesArray + i));
	}
	return examsGradesArray;
}

int Student_Average(int* const ptrToStudentGradesArray, const int examsCount) {
	int studentAverage = 0;
	for (int i = 0;i < examsCount;i++) {
		studentAverage += ptrToStudentGradesArray[i];
	}
	return (studentAverage / examsCount);
}

float Total_Average(int* const ptrToStudentsAveragesArray, const int numberOfStudents) {
	float classAverage = 0;
	for (int i = 0;i < numberOfStudents;i++) {
		classAverage += ptrToStudentsAveragesArray[i];
	}
	return (classAverage / numberOfStudents);
}

void Classification(Statistics* const classStatistics, Student_init_data* const students_data, int numberOfStudents = 0) {
	int* arrStudentAverageByOrder = NULL;
	int i;
	int classAverage = 0;
	Student_processed_data* a = NULL;
	int a_size = 0;
	Student_processed_data* b = NULL;
	int b_size = 0;
	arrStudentAverageByOrder = (int*)malloc(numberOfStudents * sizeof(int)); // (*students_data).ptrGrades == students_data->ptrGrades
	for (i = 0; i < numberOfStudents; i++) {
		arrStudentAverageByOrder[i] = Student_Average(students_data[i].ptrGrades, students_data[i].TotalCoursesTaken); //students_data[i] == *(students_data+i) 
	}
	classAverage = Total_Average(arrStudentAverageByOrder, numberOfStudents);
	for (i = 0; i < numberOfStudents; i++) {
		if (arrStudentAverageByOrder[i] >= classAverage) {
			a = (Student_processed_data*)realloc(a, (a_size + 1) * sizeof(Student_processed_data)); // (*students_data).ptrGrades == students_data->ptrGrades
			a[a_size].studentID = students_data[i].studentID; // puts in the last array location the student id
			a[a_size].gradesAverage = arrStudentAverageByOrder[i]; // puts in the last array location the student id
			a_size++;
		}
		else {
			b = (Student_processed_data*)realloc(b, (b_size + 1) * sizeof(Student_processed_data)); // (*students_data).ptrGrades == students_data->ptrGrades
			b[b_size].studentID = students_data[i].studentID; // puts in the last array location the student id
			b[b_size].gradesAverage = arrStudentAverageByOrder[i]; // puts in the last array location the student id
			b_size++;
		}
	}
	(*classStatistics).ptrStudentsListAboveAverage = a;
	(*classStatistics).ptrStudentsListBelowAverage = b;
	(*classStatistics).sizeOfPtrA = a_size;
	(*classStatistics).sizeOfPtrB = b_size;
	(*classStatistics).classRoomAverage = classAverage;
}

void Print_Tab(Statistics* const classStatistics) {
	printf("the class average is %d\n", classStatistics->classRoomAverage);

	printf("the students ABOVE the class average are (by ID):\n");
	for (int i = 0; i < classStatistics->sizeOfPtrA; i++) {
		printf("%d->", classStatistics->ptrStudentsListAboveAverage[i].studentID);
		printf("%d\t", classStatistics->ptrStudentsListAboveAverage[i].gradesAverage);
	}

	printf("\nthe students BELOW the class average are (by ID):\n");
	for (int i = 0; i < classStatistics->sizeOfPtrB; i++) {
		printf("%d->", classStatistics->ptrStudentsListBelowAverage[i].studentID);
		printf("%d\t", classStatistics->ptrStudentsListAboveAverage[i].gradesAverage);
	}
}

void Free_Memory() {

}

int main() {
	Statistics classStatistics;
	Student_init_data* ptrToStudentInitData;
	char flag = 'y';
	int numberOfStudent = 0;
	printf("how many students are in the class? -> "); scanf_s("%d", &numberOfStudent);
	ptrToStudentInitData = (Student_init_data*)malloc(numberOfStudent * sizeof(Student_init_data));
	for (int i = 0; i < numberOfStudent; i++) {
		printf("\tenter student #%d I.D.? -> ", (i + 1)); scanf_s("%d", &ptrToStudentInitData[i].studentID);
		printf("\thow many courses the student  #%d take? -> ", (i + 1)); scanf_s("%d", &ptrToStudentInitData[i].TotalCoursesTaken);
		ptrToStudentInitData[i].ptrGrades = (int*)malloc((ptrToStudentInitData[i].TotalCoursesTaken) * sizeof(int));
		for (int j = 0; j < ptrToStudentInitData[i].TotalCoursesTaken; j++) {
			printf("\t\t\tenter grade for exam #%d -> ", (j + 1)); scanf_s("%d", &ptrToStudentInitData[i].ptrGrades[j]);
		}
	}
	Classification(&classStatistics, ptrToStudentInitData, numberOfStudent);
	Print_Tab(&classStatistics);
	Free_Memory();
}
