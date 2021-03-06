#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InputGrade(int *class);	//class 배열을 받아서 값을 수정했으므로 int로 return할 필요가 없다.
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

	printf("1반부터 4반까지 성적입력\n");
	InputGrade(class);	//class배열을 InputGrade로 받아 값을 수정함.
	//class[4][20] = InputGrade(class[4][20]); 이미 위에 InputGrade를 사용했으므로 중복해서 사용할 필요가 없다.
	printf("완료.\n");
	puts("");

	printf("1반과 3반 내림차순 정렬\n");
	printf("1반 >> ");
	Descending(class, one);
	printf("3반 >> ");
	Descending(class, three);
	puts("");

	printf("2반과 4반 오름차순 정렬\n");
	printf("2반 >> ");
	Ascending(class, two);
	printf("4반 >> ");
	Ascending(class, four);
	puts("");

	ClassGrade(class);
	puts("");
	AllGrade(class);
	
}

void InputGrade(int class[4][20]) {		//int로 리턴타입을 되돌릴 필요가 없다.

	long seconds = (long)time(NULL);
	srand(seconds);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			class[i][j] = rand() % 100 + 1;
		}
	}
	//return class;		class배열을 받아서 변경했으므로, return할 필요가 없다.
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
	printf("각 학급별 평균성적, 최고점, 최저점\n");
	double avg = 0;
	int sum = 0;

	printf("1반\n");
	for (int i = 0; i < 20; i++) {
		sum += class[0][i];
	}
	avg = (double)sum / 20;
	printf("평균성적 : %.2f\n", avg);
	printf("최고점 : %d\n", class[0][0]);
	printf("최저점 : %d\n", class[0][19]);

	printf("2반\n");
	sum = 0;
	avg = 0;
	for (int i = 0; i < 20; i++) {
		sum += class[1][i];
	}
	avg = (double)sum / 20;
	printf("평균성적 : %.2f\n", avg);
	printf("최고점 : %d\n", class[1][19]);
	printf("최저점 : %d\n", class[1][0]);

	printf("3반\n");
	sum = 0;
	avg = 0;
	for (int i = 0; i < 20; i++) {
		sum += class[2][i];
	}
	avg = (double)sum / 20;
	printf("평균성적 : %.2f\n", avg);
	printf("최고점 : %d\n", class[2][0]);
	printf("최저점 : %d\n", class[2][19]);

	printf("4반\n");
	sum = 0;
	avg = 0;
	for (int i = 0; i < 20; i++) {
		sum += class[3][i];
	}
	avg = (double)sum / 20;
	printf("평균성적 : %.2f\n", avg);
	printf("최고점 : %d\n", class[3][19]);
	printf("최저점 : %d\n", class[3][0]);
}

void AllGrade(int class[4][20]) {
	printf("전체 학생의 평균성적, 최고성적, 최저성적\n");
	int allsum = 0;
	double avg = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			allsum += class[i][j];
		}
	}
	avg = (double)allsum / 80;
	printf("평균성적 : %.2lf\n", avg);

	int max = class[0][0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			max = (max > class[i][j]) ? max : class[i][j];
		}
	}
	printf("최고성적 : %d\n", max);

	int min = class[0][0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			min = (min< class[i][j]) ? min : class[i][j];
		}
	}
	printf("최저성적 : %d\n", min);
}

