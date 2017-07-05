//馬の交配プログラム
#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


pack_type father, mother, child;

int main(int argc, char const *argv[])
{
	int i,j;
	int cache;//一時格納変数
	int cookie_flag;//精力剤等のアイテムがあるかどうかを判定
	int p;//交配の大成功率判定
	FILE *fp;

	srand((unsigned)time(NULL));

	if( (fp=fopen("seisan_parent.txt","r")) == NULL){
	puts("Can't Read parents Data");
	exit(1);
	}

	//父ステータス取得
	fscanf(fp,"%d",&father.data.type);
	fscanf(fp,"%d",&father.data.sex);
	fscanf(fp,"%d",&father.data.leg);
	fscanf(fp,"%d",&father.data.power);
	fscanf(fp,"%d",&father.data.stamina);
	fscanf(fp,"%d",&father.data.fight);
	fscanf(fp,"%d",&father.data.energy);
	fscanf(fp,"%d",&father.data.life);
	fscanf(fp,"%d",&father.data.mat);

		//母ステータス取得
	fscanf(fp,"%d",&mother.data.type);
	fscanf(fp,"%d",&mother.data.sex);
	fscanf(fp,"%d",&mother.data.leg);
	fscanf(fp,"%d",&mother.data.power);
	fscanf(fp,"%d",&mother.data.stamina);
	fscanf(fp,"%d",&mother.data.fight);
	fscanf(fp,"%d",&mother.data.energy);
	fscanf(fp,"%d",&mother.data.life);
	//精力剤を使用するかどうかの判定
	fscanf(fp,"%d",&cookie_flag);
	fclose(fp);

	puts("Completed Reading parents data.");
	/*父がオスで母がメスなのかを確認*/
	if(father.data.sex != 0)exit(1);
	if(mother.data.sex != 1)exit(1);
	/*馬種*/
	child.data.type 	= 404;
	/*性別*/
	child.data.sex  	= rand()%2;

	/*脚質*/
	if(father.data.leg == mother.data.leg){
		child.data.leg 	= father.data.leg;
	}else{
		child.data.leg 	= rand()%2;
	}
		/*脚力*/
		child.data.power 	= (father.data.power + mother.data.power) / 4 + ( (rand()%66) - 15 );//後半は-15 ~ 50をランダムで与えたいので式変形した
		if(child.data.power > 100) child.data.power = 100;
		/*スタミナ、闘争心*/
		child.data.stamina 	= (father.data.stamina + mother.data.stamina) / 4 + ( (rand()%61) - 10 );
		if(child.data.stamina > 100) child.data.stamina = 100;
		child.data.fight		= (father.data.fight + mother.data.fight) / 4 + ( (rand()%61) - 10 );
		if(child.data.fight > 100) child.data.fight = 100;
		/*寿命・交配可能回数*/
		child.data.life		= 4;
		child.data.mat		= 2;//typeによって変更(手動)
		/*精力*/
		if(child.data.sex == father.data.sex){
		child.data.energy = father.data.energy + (rand()%21 - 10);
		}else{
		child.data.energy = mother.data.energy + (rand()%21 - 10);
		}
		if(child.data.energy > 50) child.data.energy = 50;

		child.ID = Generation_ID();
		/**/

		puts("Completed Setting Child Data");

		/*大成功の判定*/
		if(cookie_flag > 0){
		p = (father.data.energy + mother.data.energy) / 2;
		}else{
		p = (father.data.energy + mother.data.energy) / 4;
		}

		if( (rand()%100+1) < p){
		child.data.leg += 5;
		child.data.power	+= 5;
		child.data.stamina	+= 5;
		child.data.fight	+= 5;
		child.data.energy	+= 5;
		puts("Great Success!!");
		}else{
			puts("Normal Success...");
		}

		if((fp = fopen("seisan_child_for_Program.txt","w")) == NULL ){
		puts("Can't Write data.");
		exit(1);
		}
		/*子データ(プログラム用)を書出し*/
		fprintf(fp, "\n\n");
		fprintf(fp, "%d\n",child.data.type);
		fprintf(fp, "%d\n",child.data.sex);
		fprintf(fp, "%d\n",child.data.leg);
		fprintf(fp, "%d\n",child.data.power);
		fprintf(fp, "%d\n",child.data.stamina);
		fprintf(fp, "%d\n",child.data.fight);
		fprintf(fp, "%d\n",child.data.energy);
		fprintf(fp, "%d\n",child.data.life);
		fprintf(fp, "%d\n",child.data.mat);
		fprintf(fp, "%d\n",child.ID);
		fclose(fp);

		if((fp = fopen("seisan_child_for_Customer.txt","w")) == NULL ){
		puts("Can't Write data.");
		exit(1);
		}
		fprintf(fp, "馬名:未定\n");
		fprintf(fp, "オーナー名:未定\n");
		fprintf(fp, "タイプ:未定\n");
		if(child.data.sex == 0)fprintf(fp, "性別:オス\n");
		if(child.data.sex == 1)fprintf(fp, "性別:メス\n");
		if(child.data.leg == 0)fprintf(fp, "脚質:逃げ\n");
		if(child.data.leg == 1)fprintf(fp, "脚質:差し\n");
		fprintf(fp, "脚力:%d\n",child.data.power);
		fprintf(fp, "スタミナ:%d\n",child.data.stamina);
		fprintf(fp, "闘争心:%d\n",child.data.fight);
		fprintf(fp, "精力:%d\n",child.data.energy);
		fprintf(fp, "寿命:%d\n",child.data.life);
		fprintf(fp, "交配可能回数:%d\n",child.data.mat);
		fprintf(fp, "ID:%d\n",child.ID);
		fprintf(fp, "\n");

		puts("Completed Writing Child's Data");
		puts("");

		return 0;
		}


