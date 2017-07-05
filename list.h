#ifndef LIST_H
#define LIST_H
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#endif



/*PACKAGE構造体の定義*/
typedef struct HEAD
{
	char uma_name[32];		//馬名
	char owner_name[64];	//オーナー名

}head_type;

typedef struct DATA
{
	int type; 		//馬種：０なら競走馬、1なら交配馬、それ以外はエラー
	int sex;		//性別：０ならオス、１ならメス
	int leg;		//脚質：０なら逃げ、1なら差し
	int power;		//脚力：上限100
	int stamina;	//スタミナ：上限100
	int fight;		//闘争心：上限100
	int energy;		//精力：上限50
	int life;		//寿命：上限4
	int mat;		//交配可能回数：初期値２、種馬なら６
}data_type;


typedef struct PACKAGE
{
	head_type head;
	data_type data;
	int ID;
}pack_type;

/*マクロ定義************/
#define normal		0
#define stallion	1
#define	male		0
#define female		1
#define nige		0
#define sashi		1
#define def_life	4
#define def_mat_nor	2
#define def_mat_sta 6
const int element = 256;
/*******************/

/**/
/*add(pack配列, 追加したいpack)*/
int add_list(pack_type *ptr, pack_type pack)
{
	int i = 0;
	while(ptr[i].ID != 0){
		i++;
	}

	if(ptr[i].ID == 0){
		ptr[i] = pack;
		return 1;	//成功
	}else{
		return 0;	//失敗
	}
}
/*指定したidを持つ馬を削除する*/
int delete_list(pack_type *ptr, int id)
{
	int i = 0;
	while(1){
		if(ptr[i].ID == id){
			break;
		}
		if(ptr[i].ID == 0){
			return -1;
		}
		i++;
	}
	if(ptr[i].ID == id){
		for(i=0;i<element-1;i++){
			strcpy(ptr[i].head.uma_name, ptr[i+1].head.uma_name);
			strcpy(ptr[i].head.owner_name, ptr[i+1].head.owner_name);
			ptr[i].data.type 	= ptr[i+1].data.type;
			ptr[i].data.sex	 	= ptr[i+1].data.sex;
			ptr[i].data.leg	 	= ptr[i+1].data.leg;
			ptr[i].data.power 	= ptr[i+1].data.power;
			ptr[i].data.stamina = ptr[i+1].data.stamina;
			ptr[i].data.fight	= ptr[i+1].data.fight;
			ptr[i].data.energy  = ptr[i+1].data.energy;
			ptr[i].data.life 	= ptr[i+1].data.life;
			ptr[i].data.mat 	= ptr[i+1].data.mat;
			ptr[i].ID 			= ptr[i+1].ID;
		}return 1;
	}else{
		return 0;
	}
}

int search_list(pack_type *ptr, int id)
{
	int i = 0;
	while(ptr[i].ID != id){
		i++;
	}

	if(ptr[i].ID == id){
		return i;
	}else{
		return -1;
	}
}

void Init_list(pack_type *ptr)
{
	int i;
	char str_32[32] = "";
	char str_64[64] = "";


	for(i=0;i<element;i++){
		strcpy(ptr[i].head.uma_name, str_32);
		strcpy(ptr[i].head.owner_name, str_64);
		ptr[i].data.type 	= 0;
		ptr[i].data.sex	 	= 0;
		ptr[i].data.leg	 	= 0;
		ptr[i].data.power 	= 0;
		ptr[i].data.stamina = 0;
		ptr[i].data.fight	= 0;
		ptr[i].data.energy  = 0;
		ptr[i].data.life 	= 0;
		ptr[i].data.mat 	= 0;
		ptr[i].ID 			= 0;
	}

}

int Read_list(FILE *fp, pack_type *ptr)
{
	int i,head_count;

	fscanf(fp,"%d",&head_count);
	for(i=0;i<head_count;i++){
		fscanf(fp,"%s",ptr[i].head.uma_name);
		fscanf(fp,"%s",ptr[i].head.owner_name);
		fscanf(fp,"%d",&ptr[i].data.type);
		fscanf(fp,"%d",&ptr[i].data.sex);
		fscanf(fp,"%d",&ptr[i].data.leg);
		fscanf(fp,"%d",&ptr[i].data.power);
		fscanf(fp,"%d",&ptr[i].data.stamina);
		fscanf(fp,"%d",&ptr[i].data.fight);
		fscanf(fp,"%d",&ptr[i].data.energy);
		fscanf(fp,"%d",&ptr[i].data.life);
		fscanf(fp,"%d",&ptr[i].data.mat);
		fscanf(fp,"%d",&ptr[i].ID);
	}fclose(fp);

	return head_count;
}

int Generation_ID(void)
{
	int i,num;
	srand((unsigned)time(NULL));

	num = rand()%90000 + 10000;

	return num;
}



