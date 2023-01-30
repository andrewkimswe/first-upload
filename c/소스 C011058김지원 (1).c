#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define WEEKS 15
#define STUDENTS 10

// 구조체
struct score {
	int score_mid; // 시험1 점수
	int score_final; // 시험2 점수
	int score_project; // 과제 점수
	int score_attend; // 출석 점수
	int score_result; // 총합
};

struct student {
	char name[100]; // 이름
	int attendance[WEEKS]; // 출결
	struct score s; // 점수
	int rank;
	char grade[5]; // GPA
};

// 구조체 변수 선언
struct student list[STUDENTS];

// 함수 원형
void get_name(void); // 학생 이름을 입력받는 함수(N=10)
void get_attendance(void); // 학생 출석 기록(1-15주차)을 입력받는 함수
void attendance_to_score(void); // 출석 기록을 출석 점수로 변환하는 함수
void get_score(void); // 학생 점수(시험1, 시험2, 과제, 출석)을 합치는 함수
void calculate_rank(void); // 점수를 (선택)정렬하고 순위를 매기는 함수
void rank_to_GPA(void); // 순위를 GPA로 변환하는 함수(순차 탐색 활용)
void ret_GPA(void); // 학생의 점수와 GPA를 출력하는 함수

int main(void) {

	get_name();

	get_attendance();

	attendance_to_score();

	get_score();

	calculate_rank();

	rank_to_GPA();

	ret_GPA();

	return 0;
}

void get_name(void) {

	for (int i = 0; i < STUDENTS; i++) {
		printf("학생 이름을 입력하시오 : ");
		scanf("%s", &list[i].name);
	}
}

void get_attendance(void) {

	for (int j = 0; j < WEEKS; j++) {
		printf("%d주차 출결을 입력하시오(출석 0, 결석 1)\n", j + 1);

		for (int i = 0; i < STUDENTS; i++) {
			printf("%s : ", list[i].name);
			scanf("%d", &list[i].attendance[j]);
		}
	}
}

void attendance_to_score(void) {

	for (int i = 0; i < STUDENTS; i++) {
		list[i].s.score_attend = 10;

		for (int j = 0; j < WEEKS; j++) {
			list[i].s.score_attend -= list[i].attendance[j];
		}
	}
}

void get_score(void) {

	for (int i = 0; i < STUDENTS; i++) {
		printf("%s의 시험1, 시험2, 과제 성적을 입력하시오\n", list[i].name);

		printf("시험1 :");
		scanf("%d", &list[i].s.score_mid);

		printf("시험2 :");
		scanf("%d", &list[i].s.score_final);

		printf("시험3 :");
		scanf("%d", &list[i].s.score_project);

		list[i].s.score_result = list[i].s.score_attend + list[i].s.score_mid + list[i].s.score_final + list[i].s.score_project;
	}
}

// Selection Sort & Sequential Search 사용
void calculate_rank(void) {

	int local_arr[STUDENTS];
	int i, j, temp, least;

	for (i = 0; i < STUDENTS; i++) {
		local_arr[i] = list[i].s.score_result;
	}

	for (i = 0; i < STUDENTS - 1; i++) {
		least = i;
		for (j = i + 1; j < STUDENTS; j++) {
			if (local_arr[j] < local_arr[least]) {
				least = j;
			}
		}
		temp = local_arr[i];
		local_arr[i] = local_arr[least];
		local_arr[least] = temp;
	}

	for (i = 0; i < STUDENTS; i++)
		for (j = 0; j < STUDENTS; j++)
			if (local_arr[j] == list[i].s.score_result)
				list[i].rank = j + 1;
}

void rank_to_GPA(void) {
	int i = 0;

	for (; i < STUDENTS; i++) {
		switch (list[i].rank) {
		case 10:
			list[i].grade[0] = 'A';
			list[i].grade[1] = '+';
			break;
		case 9:
		case 8:
			list[i].grade[0] = 'A';
			list[i].grade[1] = '0';
			break;
		case 7:
		case 6:
			list[i].grade[0] = 'B';
			list[i].grade[1] = '+';
			break;
		case 5:
		case 4:
			list[i].grade[0] = 'B';
			list[i].grade[1] = '0';
			break;
		case 3:
		case 2:
			list[i].grade[0] = 'C';
			list[i].grade[1] = '0';
			break;
		case 1:
			list[i].grade[0] = 'D';
			list[i].grade[1] = '0';
			break;
		}
	}
}

void ret_GPA(void) {

	printf("이름\t 점수\t 평점\n");

	for (int i = 0; i < STUDENTS; i++) {
		printf("%s \t", list[i].name);
		printf("%d \t", list[i].s.score_result);
		if (list[i].s.score_attend < 6)
			printf("F");
		else
			printf("%s \n", list[i].grade);
	}
}
