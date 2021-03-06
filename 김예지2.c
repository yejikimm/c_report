#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InputGrade(int *class);	//class �迭�� �޾Ƽ� ���� ���������Ƿ� int�� return�� �ʿ䰡 ����.
void Descending(int class, int e);
void Ascending(int class, int e);
void ClassGrade(int class);
void AllGrade(int class);

int main(void) {

	int class[4][20] = { 0 };

	int one = 0;
	int two = 1;
	int three = 2;
	int four = 3;

	printf("1�ݺ��� 4�ݱ��� �����Է�\n");
	InputGrade(class);	//class�迭�� InputGrade�� �޾� ���� ������.
	//class[4][20] = InputGrade(class[4][20]); �̹� ���� InputGrade�� ��������Ƿ� �ߺ��ؼ� ����� �ʿ䰡 ����.
	printf("�Ϸ�.\n");
	puts("");

	printf("1�ݰ� 3�� �������� ����\n");
	printf("1�� >> ");
	Descending(class, one);
	printf("3�� >> ");
	Descending(class, three);
	puts("");

	printf("2�ݰ� 4�� �������� ����\n");
	printf("2�� >> ");
	Ascending(class, two);
	printf("4�� >> ");
	Ascending(class, four);
	puts("");

	ClassGrade(class);
	puts("");
	AllGrade(class);
	
}

void InputGrade(int class[4][20]) {		//int�� ����Ÿ���� �ǵ��� �ʿ䰡 ����.

	long seconds = (long)time(NULL);
	srand(seconds);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			class[i][j] = rand() % 100 + 1;
		}
	}
	//return class;		class�迭�� �޾Ƽ� ���������Ƿ�, return�� �ʿ䰡 ����.
}

void Descending(int class[4][20], int e) {
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
		printf("%d ", class[e][i]);
	}
	puts("");
}

void Ascending(int class[4][20], int e){
	for (int i = 0; i < 19; i++) {
		int least = i;
		for (int j = i + 1; j < 20; j++) {
			if (class[1][j] < class[1][least])
				least = j;
		}
		int temp = class[e][i];
		class[e][i] = class[e][least];
		class[e][least] = temp;
	}

	for (int i = 0; i < 20; i++) {
		printf("%d ", class[e][i]);
	}
	puts("");
}

void ClassGrade(int class[4][20]) {
	printf("�� �б޺� ��ռ���, �ְ���, ������\n");
	double avg = 0;
	int sum = 0;

	printf("1��\n");
	for (int i = 0; i < 20; i++) {
		sum += class[0][i];
	}
	avg = (double)sum / 20;
	printf("��ռ��� : %.2f\n", avg);
	printf("�ְ��� : %d\n", class[0][0]);
	printf("������ : %d\n", class[0][19]);

	printf("2��\n");
	sum = 0;
	avg = 0;
	for (int i = 0; i < 20; i++) {
		sum += class[1][i];
	}
	avg = (double)sum / 20;
	printf("��ռ��� : %.2f\n", avg);
	printf("�ְ��� : %d\n", class[1][19]);
	printf("������ : %d\n", class[1][0]);

	printf("3��\n");
	sum = 0;
	avg = 0;
	for (int i = 0; i < 20; i++) {
		sum += class[2][i];
	}
	avg = (double)sum / 20;
	printf("��ռ��� : %.2f\n", avg);
	printf("�ְ��� : %d\n", class[2][0]);
	printf("������ : %d\n", class[2][19]);

	printf("4��\n");
	sum = 0;
	avg = 0;
	for (int i = 0; i < 20; i++) {
		sum += class[3][i];
	}
	avg = (double)sum / 20;
	printf("��ռ��� : %.2f\n", avg);
	printf("�ְ��� : %d\n", class[3][19]);
	printf("������ : %d\n", class[3][0]);
}

void AllGrade(int class[4][20]) {
	printf("��ü �л��� ��ռ���, �ְ���, ��������\n");
	int allsum = 0;
	double avg = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			allsum += class[i][j];
		}
	}
	avg = (double)allsum / 80;
	printf("��ռ��� : %.2lf\n", avg);

	int max = class[0][0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			max = (max > class[i][j]) ? max : class[i][j];
		}
	}
	printf("�ְ��� : %d\n", max);

	int min = class[0][0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			min = (min< class[i][j]) ? min : class[i][j];
		}
	}
	printf("�������� : %d\n", min);
}

