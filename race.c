#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include"list.h"

void main(void){
	int i,time1[32],time2[32],sum_time[i],race_head_count;
	FILE *fp;
	pack_type array[element];

	srand((unsigned)time(NULL));

	if((fp =  fopen("race.txt","r")) == NULL){
		puts("Can't open text FILE.");
		exit(1);
	}

	for(i=0;i<32;i++){
		time1[i] = 0;
		time2[i] = 0;
		sum_time[i] = 0;
	}

	fscanf(fp,"%d",&race_head_count);
	for(i=0;i<race_head_count;i++){
		fscanf(fp, "%s",array[i].head.uma_name);
		fscanf(fp, "%s",array[i].head.owner_name);
		fscanf(fp, "%d",&array[i].data.type);
		fscanf(fp, "%d",&array[i].data.sex);
		fscanf(fp, "%d",&array[i].data.leg);
		fscanf(fp, "%d",&array[i].data.power);
		fscanf(fp, "%d",&array[i].data.stamina);
		fscanf(fp, "%d",&array[i].data.fight);
		fscanf(fp, "%d",&array[i].data.energy);
		fscanf(fp, "%d",&array[i].data.life);
		fscanf(fp, "%d",&array[i].data.mat);
		fscanf(fp, "%d",&array[i].ID);
	}
	for(i=0;i<race_head_count;i++){
		if(array[i].data.leg == 0)time1[i] = 450 - 2 * array[i].data.power - (array[i].data.fight - 50) -(rand()%101 - 20);
		if(array[i].data.leg == 1)time1[i] = 450 -     array[i].data.power - (array[i].data.fight - 50) - (rand()%101 -20);
		if(array[i].data.leg == 0)time2[i] = 450 -     array[i].data.power - (array[i].data.stamina - 50) - (rand()%121 - 30);
		if(array[i].data.leg == 1)time2[i] = 450 - 2 * array[i].data.power - (array[i].data.stamina - 50) - (rand()%121 -30);
		sum_time[i] = time1[i] + time2[i];
	}

	fp = fopen("race_result.txt","w");
	for(i=0;i<race_head_count;i++){
		fprintf(fp, "馬名:%s\n",array[i].head.uma_name);
		fprintf(fp, "前半タイム:%d\n",time1[i]);
		fprintf(fp, "後半タイム:%d\n",time2[i]);
		fprintf(fp, "合計タイム:%d\n\n",sum_time[i]);
		fprintf(fp, "\n");
	}fclose(fp);

	puts("Succeed!!");


}