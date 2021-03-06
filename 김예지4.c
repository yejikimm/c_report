#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InputGrade(int *class);	
void Descending(int class, int e, FILE *f);
void Ascending(int class, int e, FILE *f);
void ClassGrade(int class, FILE *f);
void AllGrade(int class, FILE *f);

int main(void) {

	char *fname = "score.txt";
	FILE *f;

	int class[4][20] = { 0 };

	int one = 0;
	int two = 1;
	int three = 2;
	int four = 3;

	InputGrade(class);
	
	if ((f = fopen(fname, "w")) == NULL) {
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	};

	fprintf(f, "<1��~4�ݱ����� ��������>\n\n");

	fprintf(f, "1���� �������� ���� : ");
	Descending(class, one, f);

	fprintf(f, "2���� �������� ���� : ");
	Ascending(class, two, f);

	fprintf(f, "3���� �������� ���� : ");
	Descending(class, three, f);

	fprintf(f, "4���� �������� ���� : ");
	Ascending(class, four, f);

	fprintf(f, "\n");

	ClassGrade(class, f);
	AllGrade(class, f);

	printf("score.txt ���Ͽ� �ۼ��� �Ϸ�Ǿ����ϴ�.\n");

}

void InputGrade(int class[4][20]) {		

	long seconds = (long)time(NULL);
	srand(seconds);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			class[i][j] = rand() % 100 + 1;
		}
	}
	
}

void Descending(int class[4][20], int e, FILE *f) {
	for (int i = 0; i < 19; i++) {
		int max = i;
		for (int j = i + 1; j < 20; j++) {
			if (class[e][j] > class[e][max])
				max = j;
		}
		int temp = class[e][i];
		class[e][i] = class[e][max];
		class[e][max] = temp;
	}
	
	for (int i = 0; i < 20; i++) {
		fprintf(f, "%d ", class[e][i]);
	}
	fprintf(f, "\n");
	
}

void Ascending(int class[4][20], int e, FILE *f) {
	for (int i = 0; i < 19; i++) {
		int least = i;
		for (int j = i + 1; j < 20; j++) {
			if (class[e][j] < class[e][least])
				least = j;
		}
		int temp = class[e][i];
		class[e][i] = class[e][least];
		class[e][least] = temp;
	}

	for (int i = 0; i < 20; i++) {
		fprintf(f, "%d ", class[e][i]);
	}
	fprintf(f, "\n");
}

void ClassGrade(int class[4][20], FILE *f) {
	fprintf(f, "�б޺� ��ռ���, �ְ���, ������\n");
	double avg = 0;
	int sum = 0;

	fprintf(f, "1��\n");
	for (int i = 0; i < 20; i++) {
		sum += class[0][i];
	}
	avg = (double)sum / 20;
	
	fprintf(f, "��ռ��� : %.2f\n", avg);
	fprintf(f, "�ְ��� : %d\n", class[0][0]);
	fprintf(f, "������ : %d\n", class[0][19]);
	

	fprintf(f, "2��\n");
	sum = 0;
	avg = 0;
	for (int i = 0; i < 20; i++) {
		sum += class[1][i];
	}
	avg = (double)sum / 20;
	
	fprintf(f, "��ռ��� : %.2f\n", avg);
	fprintf(f, "�ְ��� : %d\n", class[1][19]);
	fprintf(f, "������ : %d\n", class[1][0]);
	
	fprintf(f, "3��\n");
	sum = 0;
	avg = 0;
	for (int i = 0; i < 20; i++) {
		sum += class[2][i];
	}
	avg = (double)sum / 20;

	fprintf(f, "��ռ��� : %.2f\n", avg);
	fprintf(f, "�ְ��� : %d\n", class[2][0]);
	fprintf(f, "������ : %d\n", class[2][19]);

	fprintf(f, "4��\n");
	sum = 0;
	avg = 0;
	for (int i = 0; i < 20; i++) {
		sum += class[3][i];
	}
	avg = (double)sum / 20;
	
	fprintf(f, "��ռ��� : %.2f\n", avg);
	fprintf(f, "�ְ��� : %d\n", class[3][19]);
	fprintf(f, "������ : %d\n", class[3][0]);
	fprintf(f, "\n");
}

void AllGrade(int class[4][20], FILE *f) {
	fprintf(f, "��ü �л��� ��ռ���, �ְ���, ��������\n");
	int allsum = 0;
	double avg = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			allsum += class[i][j];
		}
	}
	avg = (double)allsum / 80;
	fprintf(f, "��ռ��� : %.2lf\n", avg);

	int max = class[0][0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			max = (max > class[i][j]) ? max : class[i][j];
		}
	}
	fprintf(f, "�ְ��� : %d\n", max);

	int min = class[0][0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			min = (min< class[i][j]) ? min : class[i][j];
		}
	}
	fprintf(f, "�������� : %d\n", min);
}
