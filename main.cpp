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
  printf("\t\t\t\t�������� �� ������\n");
  printf("\t\t\������ ��������������� ����������� �����������\n");
  printf("\t�������: �������������� ������� � �������������� ���������� � ���������\n");
  printf("\t\t\t\t�����������:09.03.03\n");
  printf("�������� ������ ���������: ��������� ������ ��-151 �������� ��������� ����������\n");
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
	printf("������� ������\n");
	while(true)
	{
		fdataAdd=fopen("book.txt","at");
		Data dataAdd;
		printf("������� ID\n");
		fscanf(stdin,"%s",&dataAdd.id,&t);
		printf("������� ��� �����������\n");
		fscanf(stdin,"%s",&dataAdd.name,&t);
		printf("������� ���� �����\n");
		fscanf(stdin,"%s",&dataAdd.yearlife,&t);
		printf("������� ������\n");
		fscanf(stdin,"%s",&dataAdd.quore,&t);
		printf("������� ������������\n");
		fscanf(stdin,"%s",&dataAdd.composition,&t);
		fprintf(fdataAdd,"%s\n",dataAdd.id,t);
		fprintf(fdataAdd,"%s\n",dataAdd.name,t);
		fprintf(fdataAdd,"%s\n",dataAdd.yearlife,t);
		fprintf(fdataAdd,"%s\n",dataAdd.quore,t);
		fprintf(fdataAdd,"%s\n",dataAdd.composition,t);
		fclose(fdataAdd);
		printf("������� Q/q ��� ������ �� ������ ���������� ��� Enter ��� �����������\n");
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
