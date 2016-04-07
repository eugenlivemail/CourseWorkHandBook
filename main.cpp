#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <locale.h>

//add data
struct Data
{
	char id[3];
	char name[40];
	char yearlife[40];
	char quore[500];
	char composition[30];
	
};

//about the autor
void autor()
{ 
  printf("\t\t\t\tСВЕДЕНИЯ ОБ АВТОРЕ\n");
  printf("\t\t\Омский Государственный Технический Университет\n");
  printf("\tКафедра: Математических методов и информационных технологий в экономике\n");
  printf("\t\t\t\tНаправление:09.03.03\n");
  printf("Курсовую работу выполнила: студентка группы ПИ-151 Сорокина Екатерина Валерьевна\n");
} 

//all data
void allData()
{
	FILE *fdata;
	fdata=fopen("book.txt","rt");
	if(fdata==NULL)
	{
		printf("ERROR: FILE NOT FOUND\n");
		getchar();
	}
	char buf[30000];
	fread(buf,sizeof(buf),1,fdata);
	printf("%s",buf);
	fclose(fdata);
}

//add to file
void addData()
{
	FILE* fdataAdd;
	int t;
	printf("Введите данные\n");
	while(true)
	{
		fdataAdd=fopen("book.txt","at");
		Data dataAdd;
		printf("Введите ID\n");
		fscanf(stdin,"%s",&dataAdd.id,&t);
		printf("Введите имя композитора\n");
		fscanf(stdin,"%s",&dataAdd.name,&t);
		printf("Введите годы жизни\n");
		fscanf(stdin,"%s",&dataAdd.yearlife,&t);
		printf("Введите цитату\n");
		fscanf(stdin,"%s",&dataAdd.quore,&t);
		printf("Введите произведение\n");
		fscanf(stdin,"%s",&dataAdd.composition,&t);
		fprintf(fdataAdd,"%s\n",dataAdd.id,t);
		fprintf(fdataAdd,"%s\n",dataAdd.name,t);
		fprintf(fdataAdd,"%s\n",dataAdd.yearlife,t);
		fprintf(fdataAdd,"%s\n",dataAdd.quore,t);
		fprintf(fdataAdd,"%s\n",dataAdd.composition,t);
		fclose(fdataAdd);
		printf("Нажмите Q/q для выхода из режима заполнения или Enter для продолжения\n");
		char c=' ';
		scanf("%s",&c);
		if(c=='q' || c=='Q')
			break; 
	}
	
}

int main() 
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//allData();
	//autor();
	addData();
	getchar();
}
