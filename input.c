#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(void)
{
	int i,limit;
	FILE *fp;
	char c;
	pack_type input[element];

	Init_list(input);

	if ((fp = fopen("add_list.txt","w")) == NULL)
	{
		puts("Can't Open add.txt");
		exit(1);
	}

	printf("何匹追加しますか？\n->");
	scanf("%d%c",&limit,&c);

	printf("\n%d匹分のデータを逐次入力します\n",limit);
	for(i=0;i<limit;i++){
		printf("\n%d匹目\n",i+1);
		printf("馬名:");
		gets(input[i].head.uma_name);
		printf("オーナー名:");
		gets(input[i].head.owner_name);
		printf("タイプ(競走馬=0/種馬=1):");
		scanf("%d",&input[i].data.type,&c);
		printf("性別(オス=0/メス=1):");
		scanf("%d",&input[i].data.sex,&c);
		printf("脚質(逃げ=0/差し=1):");
		scanf("%d",&input[i].data.leg,&c);
		printf("脚力:");
		scanf("%d",&input[i].data.power,&c);
		printf("スタミナ:");
		scanf("%d",&input[i].data.stamina,&c);
		printf("闘争心:");
		scanf("%d",&input[i].data.fight,&c);
		printf("精力:");
		scanf("%d",&input[i].data.energy,&c);
		printf("寿命	(変更不可):4\n");
		input[i].data.life = 4;
		printf("交配可能回数(競争馬=2/種馬=6):");
		scanf("%d",&input[i].data.mat,&c);
		printf("ID:");
		scanf("%d%c",&input[i].ID,&c);
		puts("OK");
		puts("");
	}printf("\nCompleted\n");

	//fprintf(fp,"%d\n",limit);
	for(i=0;i<limit;i++){
		fprintf(fp, "%s\n",input[i].head.uma_name);
		fprintf(fp, "%s\n",input[i].head.owner_name);
		fprintf(fp, "%d\n",input[i].data.type);
		fprintf(fp, "%d\n",input[i].data.sex);
		fprintf(fp, "%d\n",input[i].data.leg);
		fprintf(fp, "%d\n",input[i].data.power);
		fprintf(fp, "%d\n",input[i].data.stamina);
		fprintf(fp, "%d\n",input[i].data.fight);
		fprintf(fp, "%d\n",input[i].data.energy);
		fprintf(fp, "%d\n",input[i].data.life);
		fprintf(fp, "%d\n",input[i].data.mat);
		fprintf(fp, "%d\n",input[i].ID);
	}
	puts("");
	puts("Task All Completed.");
	fclose(fp);
}