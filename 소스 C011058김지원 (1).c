#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define WEEKS 15
#define STUDENTS 10

// ����ü
struct score {
	int score_mid; // ����1 ����
	int score_final; // ����2 ����
	int score_project; // ���� ����
	int score_attend; // �⼮ ����
	int score_result; // ����
};

struct student {
	char name[100]; // �̸�
	int attendance[WEEKS]; // ���
	struct score s; // ����
	int rank;
	char grade[5]; // GPA
};

// ����ü ���� ����
struct student list[STUDENTS];

// �Լ� ����
void get_name(void); // �л� �̸��� �Է¹޴� �Լ�(N=10)
void get_attendance(void); // �л� �⼮ ���(1-15����)�� �Է¹޴� �Լ�
void attendance_to_score(void); // �⼮ ����� �⼮ ������ ��ȯ�ϴ� �Լ�
void get_score(void); // �л� ����(����1, ����2, ����, �⼮)�� ��ġ�� �Լ�
void calculate_rank(void); // ������ (����)�����ϰ� ������ �ű�� �Լ�
void rank_to_GPA(void); // ������ GPA�� ��ȯ�ϴ� �Լ�(���� Ž�� Ȱ��)
void ret_GPA(void); // �л��� ������ GPA�� ����ϴ� �Լ�

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
		printf("�л� �̸��� �Է��Ͻÿ� : ");
		scanf("%s", &list[i].name);
	}
}

void get_attendance(void) {

	for (int j = 0; j < WEEKS; j++) {
		printf("%d���� ����� �Է��Ͻÿ�(�⼮ 0, �Ἦ 1)\n", j + 1);

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
		printf("%s�� ����1, ����2, ���� ������ �Է��Ͻÿ�\n", list[i].name);

		printf("����1 :");
		scanf("%d", &list[i].s.score_mid);

		printf("����2 :");
		scanf("%d", &list[i].s.score_final);

		printf("����3 :");
		scanf("%d", &list[i].s.score_project);

		list[i].s.score_result = list[i].s.score_attend + list[i].s.score_mid + list[i].s.score_final + list[i].s.score_project;
	}
}

// Selection Sort & Sequential Search ���
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

	printf("�̸�\t ����\t ����\n");

	for (int i = 0; i < STUDENTS; i++) {
		printf("%s \t", list[i].name);
		printf("%d \t", list[i].s.score_result);
		if (list[i].s.score_attend < 6)
			printf("F");
		else
			printf("%s \n", list[i].grade);
	}
}