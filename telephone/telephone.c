#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



#define MAX_NUM 100

int person=0;


typedef struct
{
	char name[30];
	char phone1[20];
	char phone2[20];
	char memo[40];

} User;

User user[MAX_NUM];

void intro();	//���� ����
int search(User* ptr, int* num);	//�˻�
void add(User* ptr, int* num);	//�߰�
int delete(User* ptr, int* num);	//����
void sort(User* ptr, int* num);	//�˹ٺ� ������ ��ȭ��ȣ�� ����Ʈ �����ֱ�
int included(char s1[40], char s2[40]);	//���ԵǾ����� �˻�




int main(void) {

	FILE* fr = NULL;
	fr=fopen("C:\\Users\\gildo\\Develop\\CPL2\\telephone\\data.txt", "r");
	if (fr == NULL) {
		fprintf(stderr, "������ ���� �� �����ϴ�.");
		return -1;                //������ �� �� ���� ��(-1�� ��ȯ�� �������� ���� �ǹ�)
	}

	//���Ͽ� �ִ� ���� �� ����. �� ����� ��� �� ����
	char c=NULL;
	person = 0;
	while ((c = fgetc(fr)) != EOF)
		if (c == '\n') person++;

	//������ ���� ���� : ���δ� �� �ȵǳ�...

	fseek(fr, 0, SEEK_SET);	//���������� ó������
	for (int i = 0; i < person; i++) {
		fscanf(fr,"%s %s %s %s\n", &user[i].name, &user[i].phone1, &user[i].phone2, &user[i].memo);
		printf("%s %s %s %s\n", user[i].name, user[i].phone1, user[i].phone2, user[i].memo);
		
		//printf("%s\n", user[i].phone2);
	}

	
	
	
	
	





	fclose(fr);
	//intro();
	printf("%d\n", person);
	add(user, &person);
	
	
	//delete(user, &person);
	//search(user, &person);
	//sort(user, &person);
	//for (int i = 0; i < person; i++) {
	//	printf("%s %s %s %s\n", user[i].name, user[i].phone1, user[i].phone2, user[i].memo);
	//}
	printf("%d", person);
	return 0;
}


void intro() {
	printf("<Phone book>\n");
	printf("You can access Search, Add, Delete, List Mode. \n");
	printf("If you want <Search Mode>, input number or name and press Enter key.\n");
	printf("If you want <Add Mode>, input name, phone1, phone2 and memo with option -a\n");
	printf("If you want <Delete Mode>, input name you want to delete with option -d\n");
	printf("If you want <List Mode>, input option -l\n");
}


void add(User* ptr, int* num) {
	
    if (*num < MAX_NUM) {
		FILE* fp=NULL;
		fopen(&fp, "c:\\users\\gildo\\develop\\cpl2\\telephone\\data.txt", "r+");   //�Է� ��Ʈ�� ����
		if (fp == NULL) {
			fprintf(stderr, "can not read file.\n");
			return -1;                //������ �� �� ���� ��(-1�� ��ȯ�� �������� ���� �ǹ�)
		}
		scanf("\n%s %s %s %s", ptr[*num].name,ptr[*num].phone1, ptr[*num].phone2, ptr[*num].memo);


		fseek(fp, 0, SEEK_END);
		fputs(ptr[*num].name, fp);
		fputs(" ", fp);
		fputs(ptr[*num].phone1, fp);
		fputs(" ", fp);
		fputs(ptr[*num].phone2, fp);
		fputs(" ", fp);
		fputs(ptr[*num].memo, fp);
		fputs("\n", fp);
		
		
		
		(*num)++;
		
		
		fclose(fp);
        printf("added successfully.\n\n");
		return 0;

    }
    //���� ������ �� ����
    else
        printf("no storage.\n\n");
}


//������� ������ �����ϴ� �Լ�
int delete(User* ptr, int* num) {
	char name[30];
	int i, j;

	
		FILE* fp = NULL;
		fopen(&fp, "c:\\users\\gildo\\develop\\cpl2\\telephone\\data.txt", "w");   //�Է� ��Ʈ�� ����
		if (fp == NULL) {
			fprintf(stderr, "can not read file.\n");
			return -1;                //������ �� �� ���� ��(-1�� ��ȯ�� �������� ���� �ǹ�)
		}
	




	//�����Ͱ� ���� ���� ���� �� ����.
	if (*num > 0) {
		printf("Input Name you want to delete. : ");
		scanf("%s", name);

		int searchIndex[40] = { 0 };
		int j = 0;
		//   i : start from 0 to MAX_NUM
		for (i = 0; i < MAX_NUM; i++) {
			// compare whether name and ptr array's current value is same
			if (included(name, ptr[i].name)) {
				(*num)--;
				//  if same printf the value and
				printf("%d. %s\n", j+1, ptr[i].name);
				// regist currnet index:i to searchIndex array
				searchIndex[j] = i;
				j++;
			}
		}


		printf("what do you wanna delete?\n");

		//   user will select number wanna delete
		int selected = -1;
		scanf("%d", &selected);
		if (selected == -1) {
			// throw error
		}

		//   after selecting, copy and overwrite value after user selected index
		for (j = searchIndex[selected-1]; j < MAX_NUM; j++) {
			strcpy(ptr[j].name, ptr[j + 1].name);
			strcpy(ptr[j].phone1, ptr[j + 1].phone1);
			strcpy(ptr[j].phone2, ptr[j + 1].phone2);
			strcpy(ptr[j].memo, ptr[j + 1].memo);
		}
		// cuz one of value was Deleted and overwrited so the last value should to go away far far far from herrreee
		*ptr[MAX_NUM ].name = NULL;
		*ptr[MAX_NUM ].phone2 = NULL;
		*ptr[MAX_NUM ].phone2 = NULL;
		*ptr[MAX_NUM ].memo = NULL;
		

		//���� ����
		for (i = 0; i < *num; i++) {
			fprintf(fp, "%s %s %s %s\n", ptr[i].name, ptr[i].phone1,ptr[i].phone2,ptr[i].memo);
		}

		fclose(fp);
		
		return 0;
		printf("Can Not Found \n\n");
		

	}


	//����� ���� ������ ���ٸ�

	else {
		printf("No Data \n\n");
		return 0;

	}

}



int included(char s1[40], char s2[40]) {
	int j = 0;
	for (int i = 0; s2[i]; i++) {
		if (s1[j] == s2[i]) {
			if (s1[i + 1] == NULL) {
				return 1;
			}
			j++;
		}
		else {
			j = 0;
		}
	}
	return 0;
}




int search(User* ptr, int* num) {
	char name[30];
	int i;

	//����� �����Ͱ� �ִٸ�
	if (*num > 0) {
		printf("Input Name: ");
		scanf("%s", name);

		int j = 0;

		for (i = 0; i < MAX_NUM; i++) {
			//strcmp�� ���ڿ��� ��ġ�Ҷ� 0�� ��ȯ
			//0�� C���� ������ �ǹ�
			//�׷��Ƿ� ! �� �ٿ� ������ �����Ͽ� ����
			if (included(name,ptr[i].name)|| included(name, ptr[i].phone1)||included( name, ptr[i].phone2)||included( name, ptr[i].memo)){
				
				printf("%d. %s %s %s %s\n", j+1,ptr[i].name,ptr[i].phone1,ptr[i].phone2,ptr[i].memo);

				
				j++;
				
			}
			
		}
		printf("Match Found \n\n");
		return 0;
		printf("Not Found \n\n");
		return 0;
	}
	else {
		printf("  No Data \n\n");
		return 0;
	}
}





// sort string array by alphbet sequence

void sort(User* ptr, int* num) {
	int i, j;
	User temp;

	for (i = 0; i < *num - 1; i++) {
		for (j = 0; j < *num - i - 1; j++) {
			if (strcmp(ptr[j].name, ptr[j + 1].name) > 0) {
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < *num; i++) {
		printf("%d. %s %s %s %s\n", i + 1, ptr[i].name, ptr[i].phone1, ptr[i].phone2, ptr[i].memo);
		
	}
}
















