//Ardavan Khalij : 9621160013 & Mohammad Jamal Asadi : 
#include<stdio.h>
#include<stdlib.h>
typedef struct goods{
	char name[1000],brand[1000],code[1000],kind[1000],off[1000];
	int number;
	double price,offpercent;
}good;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int n=0;
void brl (void){
	FILE*fp;
	fp=fopen("n.bin","rb");
	fread(&n,sizeof(int),1,fp);
	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
good *p;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sell(void);
void add2(void);
void see2(void);
void goodedit(void);
void buy(void);
void removegood(void);
void edit(void);
void see1(void);
void add(void);
void search(void);
void add_or_see_or_edit_or_search_(char add_or_see_or_edit_or_search);
void buy_or_see_or_edit_or_search_(char buy_or_see_or_edit_or_search);
void help1(void);
void help2(void);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	char buy_or_sell;
	p=(good *)malloc(sizeof(good)*10000);
	printf("Salam be barname kharid va frush lavazeme computer khosh amadid.\n");
	printf("Jahat forush varede baname shodid ya kharid [s/b] ?\n");
	scanf(" %c",&buy_or_sell);
	if(buy_or_sell=='s'){
		sell();
	}
	if(buy_or_sell=='b'){
		printf("Deghat konid ke har kalayi ra ke bishtar az 10 adad az on bekharid shamel takhfif mishavad.\n");
		buy();
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_or_see_or_edit_or_search_(char add_or_see_or_edit_or_search){
	if(add_or_see_or_edit_or_search=='a'){
		add();
	}
	if(add_or_see_or_edit_or_search=='s'){
		see1();
	}
	if(add_or_see_or_edit_or_search=='e'){
		edit();
	}
	if(add_or_see_or_edit_or_search=='h'){
		search();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void help1(void){
	printf("Agar mikhahid kalai baraye frush begozarid 'a' ra vared konid.\n");
	printf("Agar mikhahid list kala haye khod ra bebinid 's' ra vared konid.\n");
	printf("Agar mikhahid kalayi az kalahaye khod ra virayesh konid 'e'ra vared konid.\n");
	printf("Agar mikhahid kalayi ra search konid 'h' ra vared konid.\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void help2(void){
	printf("Agar mikhahid kharid ra aghaz konid 'y' ra feshar dahid.\n");
	printf("Agar mikhahid list kala ha ra bebinid 's' ra vared konid.\n");
	printf("Agar mikhahid kalayi ra hazf ya tedade on ra taghir dahid 'e' ra vared konid.\n");
	printf("Agar mikhahid kalayi ra search konid 'h' ra vared konid.\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add(void){
	FILE *seller;
	int k,i=0;
	printf("Tedade kala hayi ke mikhahid ezafe konid ra vared konid.\n");
	seller=fopen("sell_info.bin","ab");
	scanf("%d",&k);
	i=i+n;
	n=n+k;
	for(;i<n;i++){
		printf("Mark ya brand kala %dom khod ra vared konid : ",i+1);
		scanf("%s",p[i].brand);
		fwrite(p[i].brand,sizeof(char)*1000,1,seller);
		printf("Name kalaye %dom khod ra vared konid : ",i+1);
		scanf("%s",p[i].name);
		fwrite(p[i].name,sizeof(char)*1000,1,seller);
		printf("Code kalaye %dom khod ra vared konid : ",i+1);
		scanf("%s",p[i].code);
		fwrite(p[i].code,sizeof(char)*1000,1,seller);
		printf("Daste kalaye %dom khod ra vared konid : ",i+1);
		scanf("%s",p[i].kind);
		fwrite(p[i].kind,sizeof(char)*1000,1,seller);
		printf("Gheimat kala %dom ra vared konid : \n",i+1);
		scanf("%lf",&p[i].price);
		fwrite(&p[i].price,sizeof(double),1,seller);
		printf("Tedade kala %dom ra vared konid : \n",i+1);
		scanf("%d",&p[i].number);
		fwrite(&p[i].number,sizeof(int),1,seller);
		printf("Code takhfife kalaye %dom ra vared konid  deghat konid ke in code takhfif baraye on ast ke agar moshtari in cod ra vared konad be on be andaze moshakhas takhfif dahad : ",i+1);
		scanf("%s",p[i].off);
		fwrite(p[i].off,sizeof(char)*1000,1,seller);
		printf("darsad takhfife kalae %dom ra vared konid : \n",i+1);
		scanf("%lf",&p[i].offpercent);
		fwrite(&p[i].offpercent,sizeof(double),1,seller);
	}
	fclose(seller);
	FILE *fp;
	fp=fopen("n.bin","wb");
	fwrite(&n,sizeof(int),1,fp);
	fclose(fp);	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void search(void){//kar nemikonad
	brl();
	printf("Bar asase kodam moshakhase az kala mikhahid jostoju konid ? name/code/kind/brand/price [n/c/k/b/p] \n");
	char name_code_kind,nn[1000],y_n='y';
	int i=0,g,w;
	double min,max;
	FILE *seller;
	seller=fopen("sell_info.bin","rb");
	scanf(" %c",&name_code_kind);
	if(name_code_kind=='p'){
		while(y_n=='y'){
			printf("Minimum meghdar budge khod ra vared konid : ");
			scanf("%lf",&min);
			printf("Maximum meghdar budge khod ra vared konid : ");
			scanf("%lf",&max);
			for(g=0;g<n;g++){
				fread(&p[g].price,sizeof(double),1,seller);
				printf("%lf",p[g].price);
				if(p[g].price<=max&&p[g].price>=min){
					fread(p[g].brand,sizeof(char)*1000,1,seller);
					fread(p[g].code,sizeof(char)*1000,1,seller);
					fread(p[g].kind,sizeof(char)*1000,1,seller);
					fread(p[g].name,sizeof(char)*1000,1,seller);
					fread(&p[g].number,sizeof(int),1,seller);
					fread(p[g].off,sizeof(char)*10000,1,seller);
					fread(&p[g].offpercent,sizeof(double),1,seller);
					printf("kind: %s     brand: %s     name: %s     code: %s     off percent: %lf     price: %lf     number left: %d.\n",p[g].kind,p[g].brand,p[g].name,p[g].code,p[g].offpercent,p[g].price,p[g].number);     
				}
			}
			printf("Aya mikhahid edame dahid (baz ham bar asas gheimat jostoju konid) ?");
			scanf(" %c",&y_n);
		}
	}
	if(name_code_kind=='b'){
		while(y_n=='y'){
			printf("Brande kala ye khod ra vared konid : \n");
			scanf("%s",nn);
			int ww,xx;
			for(ww=0;ww<n;ww++){
			}
	        for(i=0;p[i].brand;i++){
				fread(p[i].brand,sizeof(char)*1000,1,seller);
				for(w=0;(p[i].brand)[w];w++){
					if((p[i].brand)[w]==nn[w]){
						xx++;
					}
				}
				if(xx==ww){
					fread(&p[g].price,sizeof(double),1,seller);
					fread(p[g].brand,sizeof(char)*1000,1,seller);
					fread(p[g].code,sizeof(char)*1000,1,seller);
					fread(p[g].kind,sizeof(char)*1000,1,seller);
					fread(p[g].name,sizeof(char)*1000,1,seller);
					fread(&p[g].number,sizeof(int),1,seller);
					fread(p[g].off,sizeof(char)*10000,1,seller);
					fread(&p[g].offpercent,sizeof(double),1,seller);
					printf("kind: %s     brand: %s     name: %s     code: %s     off percent: %lf     price: %lf     number left: %d.\n",p[g].kind,p[g].brand,p[g].name,p[g].code,p[g].offpercent,p[g].price,p[g].number); 
				}
				xx=0;
			}
			printf("Aya mikhahid edame dadhid [y/n] ?\n");
	    	scanf(" %c",&y_n);
		}
	}
	if(name_code_kind=='n'){
		while(y_n=='y'){
			printf("Name kala ye khod ra vared konid : \n");
			scanf("%s",nn);
			int ww,xx;
			for(ww=0;ww<n;ww++){
			}
	        for(i=0;p[i].name;i++){
				fread(p[i].name,sizeof(char)*1000,1,seller);
				for(w=0;(p[i].name)[w];w++){
					if((p[i].name)[w]==nn[w]){
						xx++;
					}
				}
				if(xx==ww){
					fread(&p[g].price,sizeof(double),1,seller);
					fread(p[g].brand,sizeof(char)*1000,1,seller);
					fread(p[g].code,sizeof(char)*1000,1,seller);
					fread(p[g].kind,sizeof(char)*1000,1,seller);
					fread(p[g].name,sizeof(char)*1000,1,seller);
					fread(&p[g].number,sizeof(int),1,seller);
					fread(p[g].off,sizeof(char)*10000,1,seller);
					fread(&p[g].offpercent,sizeof(double),1,seller);
					printf("kind: %s     brand: %s     name: %s     code: %s     off percent: %lf     price: %lf     number left: %d.\n",p[g].kind,p[g].brand,p[g].name,p[g].code,p[g].offpercent,p[g].price,p[g].number); 
				}
				xx=0;
			}
			printf("Aya mikhahid edame dadhid [y/n] ?\n");
	    	scanf(" %c",&y_n);
		}
	}
	if(name_code_kind=='c'){
			while(y_n=='y'){
			printf("Code kala ye khod ra vared konid : \n");
			scanf("%s",nn);
			int ww,xx;
			for(ww=0;ww<n;ww++){
			}
	        for(i=0;p[i].code;i++){
				fread(p[i].code,sizeof(char)*1000,1,seller);
				for(w=0;(p[i].code)[w];w++){
					if((p[i].code)[w]==nn[w]){
						xx++;
					}
				}
				if(xx==ww){
					fread(&p[g].price,sizeof(double),1,seller);
					fread(p[g].brand,sizeof(char)*1000,1,seller);
					fread(p[g].code,sizeof(char)*1000,1,seller);
					fread(p[g].kind,sizeof(char)*1000,1,seller);
					fread(p[g].name,sizeof(char)*1000,1,seller);
					fread(&p[g].number,sizeof(int),1,seller);
					fread(p[g].off,sizeof(char)*10000,1,seller);
					fread(&p[g].offpercent,sizeof(double),1,seller);
					printf("kind: %s     brand: %s     name: %s     code: %s     off percent: %lf     price: %lf     number left: %d.\n",p[g].kind,p[g].brand,p[g].name,p[g].code,p[g].offpercent,p[g].price,p[g].number); 
				}
				xx=0;
			}
			printf("Aya mikhahid edame dadhid [y/n] ?\n");
	    	scanf(" %c",&y_n);
		}
	}
	if(name_code_kind=='k'){
			while(y_n=='y'){
			printf("Noe kala ye khod ra vared konid : \n");
			scanf("%s",nn);
			int ww,xx;
			for(ww=0;ww<n;ww++){
			}
	        for(i=0;p[i].kind;i++){
				fread(p[i].kind,sizeof(char)*1000,1,seller);
				for(w=0;(p[i].kind)[w];w++){
					if((p[i].kind)[w]==nn[w]){
						xx++;
					}
				}
				if(xx==ww){
					fread(&p[g].price,sizeof(double),1,seller);
					fread(p[g].brand,sizeof(char)*1000,1,seller);
					fread(p[g].code,sizeof(char)*1000,1,seller);
					fread(p[g].kind,sizeof(char)*1000,1,seller);
					fread(p[g].name,sizeof(char)*1000,1,seller);
					fread(&p[g].number,sizeof(int),1,seller);
					fread(p[g].off,sizeof(char)*10000,1,seller);
					fread(&p[g].offpercent,sizeof(double),1,seller);
					printf("kind: %s     brand: %s     name: %s     code: %s     off percent: %lf     price: %lf     number left: %d.\n",p[g].kind,p[g].brand,p[g].name,p[g].code,p[g].offpercent,p[g].price,p[g].number); 
				}
				xx=0;
			}
			printf("Aya mikhahid edame dadhid [y/n] ?\n");
	    	scanf(" %c",&y_n);
		}
	}
	
	fclose(seller);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void edit(void){
	brl();
	printf("Aya mikhahid be list kalaha chizi ezafe konid ya kam va ya virayesh [a/r/e] ?");
	char a_r;
	scanf(" %c",&a_r);
	if(a_r=='a'){
		add();
	}
	if(a_r=='r'){
		removegood();
	}
	if(a_r=='e'){
		goodedit();
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void goodedit(void){//avaz nemikonad
	brl();
	char k[1000],f,y='y';
	printf("Code kalaye khod ra jahate virayesh vared konid : ");
	scanf("%s",k);
	int j,i,a=0;
	FILE *fp;
	fp=fopen("sell_info.bin","rb+ab");
	while(y=='y'){
		for(i=0;i<n;i++){
			fread(p[i].code,1000*sizeof(char),1,fp);
			for(j=0;(p[i].code)[j];j++){
				if((p[i].code)[j]==k[j]){
					a++;
				}
			}
			if(a==j){
				printf("Kodam moshakhase kala ra mikhahid avaz konid ? [brand/price/name/code/kind/offpercent/off/number][b/p/n/c/k/o/f/u] ?\n");
				scanf(" %c",&f);
				if(f=='b'){
					printf("brand jadid ra vared konid :");
					scanf("%s",p[i].brand);
					fwrite(p[i].brand,sizeof(char)*1000,1,fp);
				}
				if(f=='p'){
					printf("price jadid ra vared konid :");
					scanf("%lf",&p[i].price);
					fwrite(&p[i].price,sizeof(double),1,fp);
				}
				if(f=='n'){
					printf("name jadid ra vared konid :");
					scanf("%s",p[i].name);
					fwrite(p[i].name,sizeof(char)*1000,1,fp);
				}
				if(f=='c'){
					printf("code jadid ra vared konid :");
					scanf("%s",p[i].code);
					fwrite(p[i].code,sizeof(char)*1000,1,fp);
				}
				if(f=='k'){
					printf("noe jadid ra vared konid :");
					scanf("%s",p[i].kind);
					fwrite(p[i].kind,sizeof(char)*1000,1,fp);
				}
				if(f=='o'){
					printf("darsad takhfif jadid ra vared konid :");
					scanf("%lf",&p[i].offpercent);
					fwrite(&p[i].offpercent,sizeof(double),1,fp);
				}
				if(f=='f'){
					printf("code takhfife jadid ra vared konid :");
					scanf("%s",p[i].off);
					fwrite(p[i].off,sizeof(char)*1000,1,fp);
				}
				if(f=='u'){
					printf("tedade jadid ra vared konid :");
					scanf("%d",&p[i].number);
					fwrite(&p[i].number,sizeof(int),1,fp);
				}
				printf("Aya baz ham mikhahid virayesh konid [y/n] ?");
				scanf(" %c",&y);
				break;
			}
			a=0;
		}
	}
	fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void removegood(void){//chera hazf nemikone
	brl();
	FILE *fp;
	int i,qq,j;
	char n__c,q='y',yes_no,k[1000];
	fp=fopen("sell_info.bin","rb+wb");
	printf("Aya mikhahid jostoju konid [y/n] ? \n");
	scanf(" %c",&yes_no);
	if(yes_no=='y'){
		search();
	}
	printf("Aya mikhahid list kala ha ra bebinid [y/n] ?\n");
	scanf(" %c",&yes_no);
	if(yes_no=='y'){
		see1();
	}
	while(q=='y'){
		printf("Hal beguid ke kodam kala ra mikhahid hzf konid agar mikhahid name kala ra vared konnid 'n' ra vared konid agar mikhahid code kala ra vared konid 'c' ra vared konid va agar mikhahid ke yek daste khas az kala ha ra hazf konid 'k' ra vared konid.\n");
		scanf(" %c",&n__c);
		if(n__c=='c'){
			printf("Code kalae morede nazare khod ra be deghat vared konid : ");
			scanf("%s",k);
			for(j=0;k[j];j++){
			}
			for(i=0;i<n;i++){
				fread(p[i].code,sizeof(char)*1000,1,fp);
				for(int h=0;(p[i].code)[h];h++){
					if((p[i].code)[h]==k[h]){
						qq++;
					}
				}
				if(qq==j){
					p[i].number=0;
					fwrite(&p[i].number,sizeof(int),1,fp);
				}
				qq=0;
			}
		} 
		if(n__c=='n'){
			printf("name kalae morede nazare khod ra be deghat vared konid : ");
			scanf("%s",k);
			for(j=0;k[j];j++){
			}
			for(i=0;i<n;i++){
				fread(p[i].name,sizeof(char)*1000,1,fp);
				for(int h=0;(p[i].name)[h];h++){
					if((p[i].name)[h]==k[h]){
						qq++;
					}
				}
				if(qq==j){
					p[i].number=0;
					fwrite(&p[i].number,sizeof(int),1,fp);
				}
				qq=0;
			}
		}
		if(n__c=='k'){
			printf("Daste kala ra ba deghat vared konid : ");
			scanf("%s",k);
			for(j=0;k[j];j++){
			}
			for(i=0;i<n;i++){
				fread(p[i].kind,sizeof(char)*1000,1,fp);
				for(int h=0;(p[i].kind)[h];h++){
					if((p[i].kind)[h]==k[h]){
						qq++;
					}
				}
				if(qq==j){
					p[i].number=0;
					fwrite(&p[i].number,sizeof(int),1,fp);
				}
				qq=0;
			}
		}
		printf("Aya mikhahid baz ham kala hazf konid [y/n] ?");
		scanf(" %c",&q);
	}
	fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void see1(void){//chera offpercent ro neshoon nemide
	brl();
	FILE *fp;
	fp=fopen("sell_info.bin","rb");
	printf("Dar paiin list kala ha be hamrahe code kala noe kala va code takhfife on ra mibinid : \n");
	int j;
	for(j=0;j<n;j++){
		fread(p[j].name,sizeof(char)*1000,1,fp);
		fread(p[j].code,sizeof(char)*1000,1,fp);
		fread(p[j].off,sizeof(char)*1000,1,fp);
		fread(p[j].brand,sizeof(char)*1000,1,fp);
		fread(&p[j].price,sizeof(double),1,fp);
		fread(&p[j].number,sizeof(int),1,fp);
		fread(&p[j].offpercent,sizeof(double),1,fp);
		fread(p[j].kind,sizeof(char)*1000,1,fp);
		if(p[j].number!=0){
			printf("brand : %s  name : %s  code : %s  kind : %s  price : %lf  number : %d  off : %s  off percent : %lf.\n",p[j].brand,p[j].name,p[j].code,p[j].kind,p[j].price,p[j].number,p[j].off,p[j].offpercent);
		}
	}
	fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sell(void){brl();
	char add_or_see_or_edit_or_search,help,more;
	printf("Aya niaz be komak dar kar ba barname darid [y/n] ?\n");
	scanf(" %c",&help);
	if(help=='y'){
		help1();
	}
	scanf(" %c",&add_or_see_or_edit_or_search);
	add_or_see_or_edit_or_search_(add_or_see_or_edit_or_search);
	printf("Aya darkhaste digari ham darid ?[y/n]\n");
	scanf(" %c",&more);
    while(more=='y'){
	   	printf("Aya baz ham niyaz be komak dar kar ba barname darid ? [y/n]");
 		scanf(" %c",&help);
		if(help=='y'){
			help1();
		}
		scanf(" %c",&add_or_see_or_edit_or_search);
		add_or_see_or_edit_or_search_(add_or_see_or_edit_or_search);
		printf("Aya darkhaste digari ham darid ?[y/n]\n");
		scanf(" %c",&more);
	}
	if(more=='n'){
		printf("Az inke vaghtetan ra dar ekhtiare ma gozashtid mamnunim.");
	    exit(0);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void buy_or_see_or_edit_or_search_(char buy_or_see_or_edit_or_search){
	if(buy_or_see_or_edit_or_search=='y'){
		add2();
	}
	if(buy_or_see_or_edit_or_search=='s'){
		see2();
	}
	if(buy_or_see_or_edit_or_search=='e'){
		
	}
	if(buy_or_see_or_edit_or_search=='h'){
		search();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void buy(void){
	brl();
	char buy_or_see_or_edit_or_search,help,more;
	printf("Aya niaz be komak dar kar ba barname darid [y/n] ?\n");
	scanf(" %c",&help);
	if(help=='y'){
		help2();
	}
	scanf(" %c",&buy_or_see_or_edit_or_search);
	buy_or_see_or_edit_or_search_(buy_or_see_or_edit_or_search);
	printf("Aya darkhaste digari ham darid ?[y/n]\n");
	scanf(" %c",&more);
    while(more=='y'){
	   	printf("Aya baz ham niyaz be komak dar kar ba barname darid ? [y/n]");
 		scanf(" %c",&help);
		if(help=='y'){
			help2();
		}
		scanf(" %c",&buy_or_see_or_edit_or_search);
		buy_or_see_or_edit_or_search_(buy_or_see_or_edit_or_search);
		printf("Aya darkhaste digari ham darid ?[y/n]\n");
		scanf(" %c",&more);
	}
	if(more=='n'){
		printf("Az inke vaghtetan ra dar ekhtiare ma gozashtid mamnunim.");
		exit(0);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void see2(void){
	brl();
	FILE *fp;
	fp=fopen("sell_info.bin","rb");
	printf("Dar paiin list kala ha be hamrahe code kala noe kala va code takhfife on ra mibinid : \n");
	int j;
	for(j=0;j<n;j++){
		fread(p[j].name,sizeof(char)*1000,1,fp);
		fread(p[j].code,sizeof(char)*1000,1,fp);
		fread(p[j].brand,sizeof(char)*1000,1,fp);
		fread(&p[j].price,sizeof(double),1,fp);
		fread(&p[j].number,sizeof(int),1,fp);
		fread(&p[j].offpercent,sizeof(double),1,fp);
		fread(p[j].kind,sizeof(char)*1000,1,fp);
		if(p[j].number!=0){
			printf("brand : %s     name : %s     code : %s     kind : %s     price : %lf     number : %d     off percent : %lf.\n",p[j].brand,p[j].name,p[j].code,p[j].kind,p[j].price,p[j].number,p[j].offpercent);
		}
	}
	fclose(fp);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add2(void){//niaz be kar darad
	brl();
	FILE *fp;
	int a=0,i,j,b;
	char s='y',r='y',q,k[1000];
	fp=fopen("sell_info.bin","rb");
	printf("Aya mikhahid jostoju konid [y/n] ?");
	scanf(" %c",&q);
	if(q=='y'){
		search();
	}
	printf("Aya mikhahid list kala ha ra bebinid [y/n] ?");
	scanf(" %c",&q);
	if(q=='y'){
		see2();
	}
	printf("Aya mikhahid name kala ra vared konid ya code on ra [n/c] ?");
	scanf(" %c",&q);
	while(s=='y'){
		if(q=='n'){
			printf("Name kala ra vared konid :");
			scanf("%s",k);
			printf("Tedad?");
			scanf("%d",&b);
			for(i=0;i<n;i++){
				for(j=0;(p[i].name)[j];j++){
					fread(p[i].name,sizeof(char)*1000,1,fp);
					if((p[i].name)[j]==k[j]){
						a++;
					}
				}
				if(a==j){
					FILE *ff;
					ff=fopen("buy_info.bin","wb");
					fwrite(p[i].brand,sizeof(char)*1000,1,ff);
					fwrite(p[i].code,sizeof(char)*1000,1,ff);
					fwrite(p[i].kind,sizeof(char)*1000,1,ff);
					fwrite(p[i].name,sizeof(char)*1000,1,ff);
					fwrite(&p[i].price,sizeof(double),1,ff);
					fwrite(&p[i].number,sizeof(int),1,ff);
					fwrite(&p[i].offpercent,sizeof(double),1,ff);
					fclose(ff);
					double m=0;
					if(b>=10){
						p[i].price=(100-p[i].offpercent)*p[i].price;
						m=m+b*p[i].price;
					}
					else{
						m=m+b*p[i].price;
					}
				}
				a=0;
			}
		}
	}
	while(r=='y'){
		if(q=='c'){
			printf("code kala ra vared konid :");
			scanf("%s",k);
			printf("Tedad?");
			scanf("%d",&b);
			for(i=0;i<n;i++){
				for(j=0;(p[i].code)[j];j++){
					fread(p[i].code,sizeof(char)*1000,1,fp);
					if((p[i].code)[j]==k[j]){
						a++;
					}
				}
				if(a==j){
					FILE *ff;
					ff=fopen("buy_info.bin","wb");
					fwrite(p[i].brand,sizeof(char)*1000,1,ff);
					fwrite(p[i].code,sizeof(char)*1000,1,ff);
					fwrite(p[i].kind,sizeof(char)*1000,1,ff);
					fwrite(p[i].name,sizeof(char)*1000,1,ff);
					fwrite(&p[i].price,sizeof(double),1,ff);
					fwrite(&p[i].number,sizeof(int),1,ff);
					fwrite(&p[i].offpercent,sizeof(double),1,ff);
					fclose(ff);
					double m=0;
					if(b>=10){
						p[i].price=(100-p[i].offpercent)*p[i].price;
						m=m+b*p[i].price;
					}
					else{
						m=m+b*p[i].price;
					}
				}
				a=0;
			}
		}
		printf("Aya kalaye digari ham mikhahid?");
		scanf(" %c",&r);
		if(r=='n'){
			printf("Az inke zamane khod ra dar ekhtiare ma gozashtid mamnunim.");
			exit(0);
		}
	}
	fclose(fp);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
