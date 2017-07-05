#include"list.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int i, num, select=0;
	int head_count;//頭数
	int delete_id, search_id;
	int edit_flag, edit_id;
	int race_head_count, race_id[32],race_i[32];
	int father_id, mother_id, father_i, mother_i,cookie;
	FILE *fp;


	pack_type array[element];
	if( (fp = fopen("uma_list.txt","r")) == NULL ){
		exit(1);
	}

	Init_list(array);
	head_count = Read_list(fp,array);

	printf("%d\n",head_count);
	puts("What do you want to do ?");
	puts("1.add_uma(you must ready add_list.txt");
	puts("2.delete_uma");
	puts("3.Edit_uma");
	puts("4.make a race list(you must ready race_list.txt)");
	puts("5.make a parents list");
	puts("6.make a hush list(uma_name & ID only list)");
	printf("->");
	scanf("%d",&select);
	switch(select){
		case 1:
			if(( fp = fopen("add_list.txt","r")) ==NULL){
				puts("Can't Open add_list.txt");
				exit(1);
			}puts("flag1");
			scanf("%d",&num);
			for(i=0;i<num;i++){
				if(head_count <= element){
					fscanf(fp,"%s",array[head_count + i].head.uma_name);
					fscanf(fp,"%s",array[head_count + i].head.owner_name);
					fscanf(fp,"%d",&array[head_count + i].data.type);
					fscanf(fp,"%d",&array[head_count + i].data.sex);
					fscanf(fp,"%d",&array[head_count + i].data.leg);
					fscanf(fp,"%d",&array[head_count + i].data.power);
					fscanf(fp,"%d",&array[head_count + i].data.stamina);
					fscanf(fp,"%d",&array[head_count + i].data.fight);
					fscanf(fp,"%d",&array[head_count + i].data.energy);
					fscanf(fp,"%d",&array[head_count + i].data.life);
					fscanf(fp,"%d",&array[head_count + i].data.mat);
					fscanf(fp,"%d",&array[head_count + i].ID);
				}puts("Succeed!!");
			}fclose(fp);
			head_count += num;
			if(( fp = fopen("uma_list.txt","w")) == NULL){
				puts("Can't Open add_list.txt");
				exit(1);
			}

			fprintf(fp,"%d\n",head_count);
			for(i=0;i<head_count;i++){
				fprintf(fp, "%s\n",array[i].head.uma_name);
				fprintf(fp, "%s\n",array[i].head.owner_name);
				fprintf(fp, "%d\n",array[i].data.type);
				fprintf(fp, "%d\n",array[i].data.sex);
				fprintf(fp, "%d\n",array[i].data.leg);
				fprintf(fp, "%d\n",array[i].data.power);
				fprintf(fp, "%d\n",array[i].data.stamina);
				fprintf(fp, "%d\n",array[i].data.fight);
				fprintf(fp, "%d\n",array[i].data.energy);
				fprintf(fp, "%d\n",array[i].data.life);
				fprintf(fp, "%d\n",array[i].data.mat);
				fprintf(fp, "%d\n",array[i].ID);
			}fclose(fp);
			puts("add completed");
			break;
		case 2:
			puts("plz input ID to delete");
			printf("->");
			scanf("%d",&delete_id);
			delete_list(array,delete_id);
			fp = fopen("uma_list.txt","w");

			fprintf(fp, "%d\n",(head_count-1));
			for(i=0;i<head_count;i++){
				fprintf(fp, "%s\n",array[i].head.uma_name);
				fprintf(fp, "%s\n",array[i].head.owner_name);
				fprintf(fp, "%d\n",array[i].data.type);
				fprintf(fp, "%d\n",array[i].data.sex);
				fprintf(fp, "%d\n",array[i].data.leg);
				fprintf(fp, "%d\n",array[i].data.power);
				fprintf(fp, "%d\n",array[i].data.stamina);
				fprintf(fp, "%d\n",array[i].data.fight);
				fprintf(fp, "%d\n",array[i].data.energy);
				fprintf(fp, "%d\n",array[i].data.life);
				fprintf(fp, "%d\n",array[i].data.mat);
				fprintf(fp, "%d\n",array[i].ID);
			}fclose(fp);
			break;
		case 3:
			edit_flag = 0;
			while(edit_flag == 0){
				puts("input ID that want to edit");
				printf("->");
				scanf("%d",&edit_id);
				i = search_list(array,edit_id);
				printf("Edit uma_name (Before:%s):",array[i].head.uma_name);
				scanf("%s",&array[i].head.uma_name);
				printf("Edit owner_name (Before:%s):",array[i].head.owner_name);
				scanf("%s",&array[i].head.owner_name);
				printf("Edit ID (Before:%d):",array[i].ID);
				scanf("%d",&array[i].ID);
				printf("Continue \"Edit\"?\n->(y=0/n=1):");
				scanf("%d",&edit_flag);
			}
			fp = fopen("uma_list.txt","w");
			fprintf(fp, "%d\n",head_count);
			for(i=0;i<head_count;i++){
				fprintf(fp, "%s\n",array[i].head.uma_name);
				fprintf(fp, "%s\n",array[i].head.owner_name);
				fprintf(fp, "%d\n",array[i].data.type);
				fprintf(fp, "%d\n",array[i].data.sex);
				fprintf(fp, "%d\n",array[i].data.leg);
				fprintf(fp, "%d\n",array[i].data.power);
				fprintf(fp, "%d\n",array[i].data.stamina);
				fprintf(fp, "%d\n",array[i].data.fight);
				fprintf(fp, "%d\n",array[i].data.energy);
				fprintf(fp, "%d\n",array[i].data.life);
				fprintf(fp, "%d\n",array[i].data.mat);
				fprintf(fp, "%d\n",array[i].ID);
			}fclose(fp);
			puts("Edit Completed");
			break;
		case 4:
			if((fp=fopen("race_list.txt","r")) == NULL){
				puts("Can't Open race_list.txt");
				exit(1);
			}
			fscanf(fp,"%d",&race_head_count);
			for(i=0;i<race_head_count;i++){
				fscanf(fp,"%d",&race_id[i]);
				race_i[i] = search_list(array,race_id[i]);
				array[ race_i[i] ].data.life -= 1;
				if(array[ race_i[i] ].data.life  <= 1){
					delete_list(array,race_id[i]);
					head_count -= 1;
				}
			}fclose(fp);

			fp = fopen("race.txt","w");
			fprintf(fp,"%d\n",race_head_count);
			for(i=0;i<race_head_count;i++){
				fprintf(fp, "%s\n",array[race_i[i]].head.uma_name);
				fprintf(fp, "%s\n",array[race_i[i]].head.owner_name);
				fprintf(fp, "%d\n",array[race_i[i]].data.type);
				fprintf(fp, "%d\n",array[race_i[i]].data.sex);
				fprintf(fp, "%d\n",array[race_i[i]].data.leg);
				fprintf(fp, "%d\n",array[race_i[i]].data.power);
				fprintf(fp, "%d\n",array[race_i[i]].data.stamina);
				fprintf(fp, "%d\n",array[race_i[i]].data.fight);
				fprintf(fp, "%d\n",array[race_i[i]].data.energy);
				fprintf(fp, "%d\n",array[race_i[i]].data.life);
				fprintf(fp, "%d\n",array[race_i[i]].data.mat);
				fprintf(fp, "%d\n",array[race_i[i]].ID);
			}fclose(fp);
			puts("Succeed!!");
			break;
		case 5:


			printf("Father's ID\n->");
			scanf("%d",&father_id);
			printf("Mother's ID\n->");
			scanf("%d",&mother_id);
			printf("Use Unicum Cokiie ?(y=1/n=0)\n->");
			scanf("%d",&cookie);
			if(cookie > 1)cookie = 1;

			father_i = search_list(array,father_id);
			mother_i = search_list(array,mother_id);
			array[father_i].data.mat -= 1;
			array[mother_i].data.mat -= 1;
			if(array[father_i].data.mat == 0){
				delete_list(array,father_id);
			}
			if(array[mother_i].data.mat == 0){
				delete_list(array,mother_id);
			}

			if((fp=fopen("seisan_parent.txt","w"))==NULL){
				puts("Can't Open seisan_parent.txt");
				exit(1);
			}
			/*fatherの出力*/
			fprintf(fp, "%d\n",array[father_i].data.type);
			fprintf(fp, "%d\n",array[father_i].data.sex);
			fprintf(fp, "%d\n",array[father_i].data.leg);
			fprintf(fp, "%d\n",array[father_i].data.power);
			fprintf(fp, "%d\n",array[father_i].data.stamina);
			fprintf(fp, "%d\n",array[father_i].data.fight);
			fprintf(fp, "%d\n",array[father_i].data.energy);
			fprintf(fp, "%d\n",array[father_i].data.life);
			fprintf(fp, "%d\n",array[father_i].data.mat);
			/*motherの出力*/
			fprintf(fp, "%d\n",array[mother_i].data.type);
			fprintf(fp, "%d\n",array[mother_i].data.sex);
			fprintf(fp, "%d\n",array[mother_i].data.leg);
			fprintf(fp, "%d\n",array[mother_i].data.power);
			fprintf(fp, "%d\n",array[mother_i].data.stamina);
			fprintf(fp, "%d\n",array[mother_i].data.fight);
			fprintf(fp, "%d\n",array[mother_i].data.energy);
			fprintf(fp, "%d\n",array[mother_i].data.life);
			fprintf(fp, "%d\n",array[mother_i].data.mat);

			fprintf(fp, "%d\n",cookie);
			fclose(fp);

			fp = fopen("uma_list.txt","w");
			fprintf(fp,"%d\n",head_count);
			for(i=0;i<head_count;i++){
				fprintf(fp, "%s\n",array[i].head.uma_name);
				fprintf(fp, "%s\n",array[i].head.owner_name);
				fprintf(fp, "%d\n",array[i].data.type);
				fprintf(fp, "%d\n",array[i].data.sex);
				fprintf(fp, "%d\n",array[i].data.leg);
				fprintf(fp, "%d\n",array[i].data.power);
				fprintf(fp, "%d\n",array[i].data.stamina);
				fprintf(fp, "%d\n",array[i].data.fight);
				fprintf(fp, "%d\n",array[i].data.energy);
				fprintf(fp, "%d\n",array[i].data.life);
				fprintf(fp, "%d\n",array[i].data.mat);
				fprintf(fp, "%d\n",array[i].ID);
			}fclose(fp);
			puts("Succeed!!");
			break;
		case 6:
			if((fp = fopen("hush_list.txt","w"))==NULL){
				puts("Can't Open hush_list.txt");
				exit(1);
			}
			for(i=0;i<head_count;i++){
				fprintf(fp, "%s\n",array[i].head.uma_name);
				fprintf(fp, "%s\n",array[i].head.owner_name);
				fprintf(fp, "%d\n",array[i].ID);
			}

			fclose(fp);
			break;
		default:
			puts("You don't select any choice.");
			break;
	}
	return 0;
}
