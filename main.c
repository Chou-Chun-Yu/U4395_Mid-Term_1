#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f_price(char);
int d_price(int);
const char* food(char);
const char* drink(int);

int main(){
	char capp;
	int drink_type, sum, total_price = 0, count = 0;
	printf("a.�@�����׶� $200/��, b.���N������ $300/��, c.�����N�N�� $250/�� \n");
	printf("1.���G�� $50//cup, 2.����(�N/��) $45/cup, 3.�����@�� $60/cup, 4.�G�� $45/cup \n");
	printf("5.������� $50/cup, 6.�T�� $30/cup, 7.�i�� $30/cup \n");
	while(1){
		printf("�п�ܥD�����: ");
		scanf(" %c", &capp);
		capp = tolower(capp);
		if(capp =='x')  break;
		printf("�п�ܶ��~����: ");
		scanf("%d", &drink_type);

		sum = f_price(capp) + d_price(drink_type);
		printf("%s + %s, �p�p %d ��\n", food(capp), drink(drink_type), sum);

		total_price += sum;
		count++;
	}

	if(count >= 6) total_price = total_price*0.9;
	printf("\n\t\t\t�`���G %d \n",total_price);

	system("pause");
	return 0;
}

int f_price(char type){
	switch(type){
		case 'a':
			return 200;
		break;
		case 'b':
			return 300;
		break;
		case 'c':
			return 250;
		break;
	}
}

int d_price(int type){
	switch(type){
		case 1:
			return 50;
		break;
		case 2:
			return 45;
		break;
		case 3:
			return 60;
		break;
		case 4:
			return 45;
		break;
		case 5:
			return 50;
		break;
		case 6:
			return 30;
		break;
		case 7:
			return 30;
		break;
	}
}

const char* food(char type){
	int types = 0;

	switch (type){
		case 'a':
			types = 0;
		break;
		case 'b':
			types = 1;
		break;
		case 'c':
			types = 2;
		break;
	}
	static char* foods[] = {"�@�����׶�", "���N������", "�����N�N��"};
	return foods[types];
}

const char* drink(int type){
	static char* drinks[] = {"���G��", "����(��)", "�����@��", "�G��", "�������", "�T��","�i��"};
	return drinks[type - 1];
}
