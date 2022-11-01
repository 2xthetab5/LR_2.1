#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <conio.h>
struct melee {
	char* type_of_melee;
	int durability_of_melee;
	char* color_of_melee;
};
struct weapon {
	char* type_of_weapon;
	int durability_of_weapon;
	char* color_of_weapon;
	int ammo_of_weapon;
};
struct kind {
	char* color_of_transformer;
	char* genus;
	int age_of_transformer;
};
struct form {
	char* model_of_car;
	int speed;
	int horsepower;
};
struct transformer {
	melee your_melee;
	weapon your_weapon;
	kind your_kind;
	form your_form;
};
void init(struct transformer* your_transformer);
void output(struct transformer* your_transformer);
void input(struct transformer* your_transformer);
void color(struct transformer* your_transformer);
void speed_type(struct transformer* your_transformer);

int main() {
	setlocale(LC_ALL, "Rus");
	struct transformer your_transformer;
	int x;
	x = 0;
	init(&your_transformer);
	input(&your_transformer);
	do {
		printf("\nВведите:\n1 - для вывода характеристики вашего трансформера \n2 - для анализа цветовой гаммы вышего трансформера \n3 - для анализа скорости вашего трансформера \nНажмите E если хотите выйти\n");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			output(&your_transformer);
			break;
		case 2:
			color(&your_transformer);
			break;
		case 3:
			speed_type(&your_transformer);
			break;
		}
	} while (getchar() != 'e');
}
void init(struct transformer* your_transformer) {
	your_transformer->your_melee.type_of_melee = (char*)calloc(20, (sizeof(char)));
	your_transformer->your_melee.durability_of_melee = 0;
	your_transformer->your_melee.color_of_melee = (char*)calloc(20, (sizeof(char)));
	your_transformer->your_weapon.type_of_weapon = (char*)calloc(20, (sizeof(char)));
	your_transformer->your_weapon.durability_of_weapon = 0;
	your_transformer->your_weapon.color_of_weapon = (char*)calloc(20, (sizeof(char)));
	your_transformer->your_weapon.ammo_of_weapon = 0;
	your_transformer->your_kind.color_of_transformer = (char*)calloc(20, (sizeof(char)));
	your_transformer->your_kind.genus = (char*)calloc(20, (sizeof(char)));
	your_transformer->your_kind.age_of_transformer = 0;
	your_transformer->your_form.model_of_car = (char*)calloc(20, (sizeof(char)));
	your_transformer->your_form.speed = 0;
	your_transformer->your_form.horsepower = 0;
}
void input(struct transformer* your_transformer) {
	do
	{
		printf("\nВведите род вашего трансформера(autobot или deseptikon): ");
		scanf("%s", your_transformer->your_kind.genus);
	} while ((strcmp(your_transformer->your_kind.genus,"autobot") != 0) && (strcmp(your_transformer->your_kind.genus, "deseptikon") != 0));
	do
	{
		printf("\nВведите возраст вашего трансформера: ");
		scanf("%d", &your_transformer->your_kind.age_of_transformer);
	} while (your_transformer->your_kind.age_of_transformer < 1);
	do
	{
		printf("\nВведите общий цвет вашего трансформера(eng): ");
		scanf("%s", your_transformer->your_kind.color_of_transformer);
	} while ((strcmp(your_transformer->your_kind.color_of_transformer,"red") != 0) && (strcmp(your_transformer->your_kind.color_of_transformer, "yellow") != 0) && (strcmp(your_transformer->your_kind.color_of_transformer, "green") != 0) && (strcmp(your_transformer->your_kind.color_of_transformer, "blue") != 0) && (strcmp(your_transformer->your_kind.color_of_transformer, "purple") != 0) && (strcmp(your_transformer->your_kind.color_of_transformer, "black") != 0) && (strcmp(your_transformer->your_kind.color_of_transformer, "white") != 0));
	do
	{
		printf("\nВведите каким оружием ближнего боя владеет ваш трансформер(saw, sword, axe, spear, mace): ");
		scanf("%s", your_transformer->your_melee.type_of_melee);
	} while ((strcmp(your_transformer->your_melee.type_of_melee, "saw") != 0) && (strcmp(your_transformer->your_melee.type_of_melee, "sword") != 0) && (strcmp(your_transformer->your_melee.type_of_melee, "axe") != 0) && (strcmp(your_transformer->your_melee.type_of_melee, "spear") != 0) && (strcmp(your_transformer->your_melee.type_of_melee, "mace") != 0));
	do
	{
		printf("\nВведите прочность оружия ближнего боя(от 1 до 100): ");
		scanf("%d", &your_transformer->your_melee.durability_of_melee);
	} while ((your_transformer->your_melee.durability_of_melee < 1) || (your_transformer->your_melee.durability_of_melee > 100));
	do
	{
		printf("\nВведите цвет оружия ближнего боя(eng): ");
		scanf("%s", your_transformer->your_melee.color_of_melee);
	} while ((strcmp(your_transformer->your_melee.color_of_melee, "red") != 0) && (strcmp(your_transformer->your_melee.color_of_melee, "yellow") != 0) && (strcmp(your_transformer->your_melee.color_of_melee, "green") != 0) && (strcmp(your_transformer->your_melee.color_of_melee, "blue") != 0) && (strcmp(your_transformer->your_melee.color_of_melee, "purple") != 0) && (strcmp(your_transformer->your_melee.color_of_melee, "black") != 0) && (strcmp(your_transformer->your_melee.color_of_melee, "white") != 0));
	do
	{
		printf("\nВведите каким оружием дальнего боя владеет ваш трансформер(machinegun, rocketlauncher, laser): ");
		scanf("%s", your_transformer->your_weapon.type_of_weapon);
	} while ((strcmp(your_transformer->your_weapon.type_of_weapon, "machinegun") != 0) && (strcmp(your_transformer->your_weapon.type_of_weapon, "rocketlauncher") != 0) && (strcmp(your_transformer->your_weapon.type_of_weapon, "laser") != 0));
	do
	{
		printf("\nВведите прочность оружия дальнего боя(от 1 до 100): ");
		scanf("%d", &your_transformer->your_weapon.durability_of_weapon);
	} while ((your_transformer->your_weapon.durability_of_weapon < 1) || (your_transformer->your_weapon.durability_of_weapon > 100));
	do
	{
		printf("\nВведите цвет оружия дальнего боя(eng): ");
		scanf("%s", your_transformer->your_weapon.color_of_weapon);
	} while ((strcmp(your_transformer->your_weapon.color_of_weapon, "red") != 0) && (strcmp(your_transformer->your_weapon.color_of_weapon, "yellow") != 0) && (strcmp(your_transformer->your_weapon.color_of_weapon, "green") != 0) && (strcmp(your_transformer->your_weapon.color_of_weapon, "blue") != 0) && (strcmp(your_transformer->your_weapon.color_of_weapon, "purple") != 0) && (strcmp(your_transformer->your_weapon.color_of_weapon, "black") != 0) && (strcmp(your_transformer->your_weapon.color_of_weapon, "white") != 0));
	do
	{
		printf("\nВведите количество патронов в оружии дальнего боя(от 0 до 200): ");
		scanf("%d", &your_transformer->your_weapon.ammo_of_weapon);
	} while ((your_transformer->your_weapon.durability_of_weapon < 0) || (your_transformer->your_weapon.durability_of_weapon > 200));
	do
	{
		printf("\nВведите в какой транспорт превращается ваш трансформер(sportcar, truck, tank, jeep): ");
		scanf("%s", your_transformer->your_form.model_of_car);
	} while ((strcmp(your_transformer->your_form.model_of_car, "sportcar") != 0) && (strcmp(your_transformer->your_form.model_of_car, "truck") != 0) && (strcmp(your_transformer->your_form.model_of_car, "tank") != 0) && (strcmp(your_transformer->your_form.model_of_car, "jeep") != 0));
	do
	{
		printf("\nВведите количество лошадиных сил у транспорта, в который превращается ваш трансформер(от 100 до 1000): ");
		scanf("%d", &your_transformer->your_form.horsepower);
	} while ((your_transformer->your_form.horsepower < 100) || (your_transformer->your_form.horsepower > 1000));
	do
	{
		printf("\nВведите максимальную скорость транспорта(в км/ч), в который превращается ваш трансформер(от 120 до 400): ");
		scanf("%d", &your_transformer->your_form.speed);
	} while ((your_transformer->your_form.speed < 120) || (your_transformer->your_form.speed > 400));
	while (getchar() != '\n');
}
void output(struct transformer* your_transformer) {
	printf("\nХарактеристики вашего трансформера: ");
	printf("\nРод: %s \nВозраст: %d \nЦвет: %s", your_transformer->your_kind.genus, your_transformer->your_kind.age_of_transformer, your_transformer->your_kind.color_of_transformer);
	printf("\nОружие ближнего боя вашего трансформера: %s \nПрочность оружия ближнего боя: %d \nЦвет оружия ближнего боя: %s", your_transformer->your_melee.type_of_melee, your_transformer->your_melee.durability_of_melee, your_transformer->your_melee.color_of_melee);
	printf("\nОружие дальнего боя вашего трансформера: %s \nПрочность оружия дальнего боя: %d \nЦвет оружия дальнего боя: %s \nКоличество патронов в оружии дальнего боя: %d", your_transformer->your_weapon.type_of_weapon, your_transformer->your_weapon.durability_of_weapon, your_transformer->your_weapon.color_of_weapon, your_transformer->your_weapon.ammo_of_weapon);
	printf("\nТранспорт, в который превращается ваш трансформер: %s \nКоличество лошадиных сил транспорта, в который превращается ваш трансформер: %d \nМаксимальная скорость транспорта, в который превращается ваш трансформер: %d", your_transformer->your_form.model_of_car, your_transformer->your_form.horsepower, your_transformer->your_form.speed);
}
void color(struct transformer* your_transformer) {
	if ((strcmp(your_transformer->your_kind.color_of_transformer, your_transformer->your_weapon.color_of_weapon) == 0) && (strcmp(your_transformer->your_kind.color_of_transformer, your_transformer->your_melee.color_of_melee) == 0))
		printf("\nВаш трансформер одноцветный\n");
	else
		printf("\nВаш трансформер разноцветный\n");
}
void speed_type(struct transformer* your_transformer) {
	if ((your_transformer->your_form.speed >= 120) && (your_transformer->your_form.speed < 200))
		printf("\nУ вашего трансформера маленькая скорость\n");
	if ((your_transformer->your_form.speed >= 200) && (your_transformer->your_form.speed < 300))
		printf("\nУ вашего трансформера средняя скорость\n");
	if ((your_transformer->your_form.speed >= 300) && (your_transformer->your_form.speed <= 400))
		printf("\nУ вашего трансформера большая скорость\n");
}
