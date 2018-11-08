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
	printf("a.咖哩雞肉飯 $200/份, b.紅燒牛肉燴飯 $300/份, c.鰻魚燒烤飯 $250/份 \n");
	printf("1.水果茶 $50//cup, 2.紅茶(冷/熱) $45/cup, 3.美式咖啡 $60/cup, 4.果汁 $45/cup \n");
	printf("5.紅葡萄汁 $50/cup, 6.汽水 $30/cup, 7.可樂 $30/cup \n");
	while(1){
		printf("請選擇主菜種類: ");
		scanf(" %c", &capp);
		capp = tolower(capp);
		if(capp =='x')  break;
		printf("請選擇飲品種類: ");
		scanf("%d", &drink_type);

		sum = f_price(capp) + d_price(drink_type);
		printf("%s + %s, 小計 %d 元\n", food(capp), drink(drink_type), sum);

		total_price += sum;
		count++;
	}

	if(count >= 6) total_price = total_price*0.9;
	printf("\n\t\t\t總價： %d \n",total_price);

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
	static char* foods[] = {"咖哩雞肉飯", "紅燒牛肉燴飯", "鰻魚燒烤飯"};
	return foods[types];
}

const char* drink(int type){
	static char* drinks[] = {"水果茶", "紅茶(熱)", "美式咖啡", "果汁", "紅葡萄汁", "汽水","可樂"};
	return drinks[type - 1];
}
