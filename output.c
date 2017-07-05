#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"list.h"

int main(void)
{
	int i;
	int head_count;
	FILE *fp;
	pack_type array[element];

	if((fp = fopen("uma_list.txt","r")) == NULL){
		puts("Can't open text FILE");
		exit(1);
	}

	Init_list(array);
	head_count = Read_list(fp,array);

	printf("head count:%d\n",head_count);
	fclose(fp);

	if((fp = fopen("output.txt","w")) == NULL){
		puts("Can't open text FILE");
		exit(1);
	}

	for(i=0;i<head_count;i++){
		fprintf(fp, "馬名:%s\n",array[i].head.uma_name);
		fprintf(fp, "オーナー名:%s\n",array[i].head.owner_name);
		if(array[i].data.type == 0)fprintf(fp, "タイプ:競走馬\n");
		if(array[i].data.type == 1)fprintf(fp, "タイプ:種馬\n");
		if(array[i].data.sex == 0)fprintf(fp, "性別:オス\n");
		if(array[i].data.sex == 1)fprintf(fp, "性別:メス\n");
		if(array[i].data.leg == 0)fprintf(fp, "脚質:逃げ\n");
		if(array[i].data.leg == 1)fprintf(fp, "脚質:差し\n");
		fprintf(fp, "脚力:%d\n",array[i].data.power);
		fprintf(fp, "スタミナ:%d\n",array[i].data.stamina);
		fprintf(fp, "闘争心:%d\n",array[i].data.fight);
		fprintf(fp, "精力:%d\n",array[i].data.energy);
		fprintf(fp, "寿命:%d\n",array[i].data.life);
		fprintf(fp, "交配可能回数:%d\n",array[i].data.mat);
		fprintf(fp, "ID:%d\n",array[i].ID);
		fprintf(fp, "\n");
	}fclose(fp);

	puts("Outpput Completed");
}


