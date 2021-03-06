#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <string.h>

void Print(struct happiness data[]);
void Descending(struct happiness data[]);

struct happiness {
	char condition[20];
	int sum;
};
typedef struct happiness happiness;

int main(void) {

	happiness data[] = { { "Hard Work", 98 }, { "Konwledge", 96 }, { "Love", 54 },
	{ "Luck", 47 }, { "Money", 72 }, { "Leadership", 97 }, { "Attitude", 100 },
	{ "Friends", 75 }, { "Memory", 89 }, { "Passion", 92 } };

	printf("입력단어\t점수\n");
	Print(data);

	Descending(data);

	printf("정렬후 단어\t점수\n");
	Print(data);
}

void Print(struct happiness data[]) {
	printf("=======================\n");
	for (int i = 0; i < 10; i++) {
		printf("%10s%10d\n", data[i].condition, data[i].sum);
	}
	puts("");
}

void Descending(struct happiness data[]) {
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (data[j].sum < data[j + 1].sum) {
				int temp = data[j].sum;
				data[j].sum = data[j + 1].sum;
				data[j + 1].sum = temp;

				char temp2[20];
				strcpy_s(temp2, 20, data[j].condition);
				strcpy_s(data[j].condition, 20, data[j + 1].condition);
				strcpy_s(data[j + 1].condition, 20, temp2);
			}
		}
	}
}