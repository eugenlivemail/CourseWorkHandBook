#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <locale.h>

//add data
struct Data
{
	char id[3];
	char name[20];
	char yearlife[22];
	char quore[100];
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
	printf("������� ������\n");
	FILE *fdataAdd;
	while(true)
	{
		fdataAdd=fopen("book.txt","at");
		Data dataAdd;
		printf("������� ID\n");
		scanf("%s",&dataAdd.id);
		printf("������� ��� �����������\n");
		scanf("%s",&dataAdd.name);
		printf("������� ���� �����\n");
		scanf("%s",&dataAdd.yearlife);
		printf("������� ������\n");
		scanf("%s",&dataAdd.quore);
		printf("������� ������������\n");
		scanf("%s",&dataAdd.composition);
		fwrite(&dataAdd.id,sizeof(dataAdd.id),1,fdataAdd);
		fwrite(&dataAdd.name,sizeof(dataAdd.name),1,fdataAdd);
		fwrite(&dataAdd.yearlife,sizeof(dataAdd.yearlife),1,fdataAdd);
		fwrite(&dataAdd.quore,sizeof(dataAdd.quore),1,fdataAdd);
		fwrite(&dataAdd.composition,sizeof(dataAdd.composition),1,fdataAdd);
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
	setlocale(LC_ALL,"Russian");
	//allData();
	//autor();
//	addData();
	getchar();
}
