#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// varabile define	
int loops = 30;
const int maxWait = 0;

// function
void welcome();

void level();

void Histroy();

void condition(int,int);

void spacemaker(int);

int file2Game(int);

int check_way();

int start();

int logo();

int Question_display();

int myran();

int Ans_checker();

int Sroce();

int Exit_Game();

int timer(int);

int mainTodo();

//structure
struct my{
	char Question[300];
	char A[30];
	char B[30];
	char C[30];
	char D[30];
	char Ans;
	int repect;	
}Questions[74];

struct your{
	char name[300];
	int Q;
	int lifeline;
	int Q_C;
	int Q_W;
	int Q_T_P;
	int Level;
	int Sroce;
}player;

// main 
int main(){
	
	player.lifeline = 3;
	player.Q = 1;
	player.Sroce = 0;
	player.Level = 1;
	mainTodo();
	
}

// function defination
int mainTodo(){	

int left = 1,start = 1;

file2Game(74);

do{
	system("cls");


	if(start){
		welcome();
 		check_way();
		start--;
	}
	else{
		level();	
		printf("Player: %s\tLevel: %d\tLifeLine: %d\t Your Score: $%d\n\n",player.name,player.Level,player.lifeline,player.Sroce);
		Question_display();

		if(player.Q %7 == 0){
			system("cls");
			player.Level += 1;
			level();
		}
		
		fflush(stdin);
		printf("PRESS ANY KEY FOR NEXT(Question): \b");
		fflush(stdin);
		left = toupper(getch()) == 'E' ? Exit_Game() : 1;
	}
}while(player.Level != 7);


system("cls");
printf("\t\t\tYOU WON THE GAME/n/n");
Exit_Game();
sroce();

}

void welcome(){

printf("\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("\t        |                 WELCOME                   |\n");
printf("\t        |                   TO                      |\n");
printf("\t        |                  QUIZ                     |\n");
printf("\t        |                  GAME                     |\n");
printf("\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

	logo();	
}

void level(){
	
	printf("\t  ##-##-##-##-##-##-##-##-##-##-##-##-##-##-##-##-##-##-##\n");
	
	printf("       ##-##-##-##-## 		LEVEL: %d 	       ##-##-##-##-##\n",player.Level);
	
	printf("\t  ##-##-##-##-##-##-##-##-##-##-##-##-##-##-##-##-##-##-##\n\n");	
}

int timer(int ans){
	
    bool exit = false;
	
	printf("(Time left :  ");
	int x = 0;
	while( !exit ){		

	loops >= 10 ? printf("\b\b\b%d)",loops) : printf("\b\b\b %d)",loops);

    
	if(kbhit()){
		x = Ans_checker(ans);
		break;
    }
    Sleep(740);
    exit = exit || ( --loops < maxWait ) ;  
}	

}

void condition(int x,int ans){
	
	if(x == ans || ans == x-32){
		printf("\nYou are correct!\n\n");
		player.Q_C+=1;	
		player.Sroce += 5;

	}
		else{
			x == 0 ? player.Q_T_P += 1,printf("\nOut of Time\n\n") : printf("\nYou are Wrong Correct answer is %c!\n\n",ans),player.Q_W+= 1; 
			player.lifeline -= 1;
			if(player.lifeline == 0){
				Exit_Game();
			}
		}
}

int Exit_Game(){
	
	printf("\nSummary of the Game of %s\nLevel: %d\tLifeline: %d\tSroce: $%d\nAnswer Correct: %d\nAnswer Wrong: %d\nAnswer in which Time up: %d\n"
	,player.name,player.Level,player.lifeline,player.Sroce,player.Q_C,player.Q_W,player.Q_T_P);
	sroce();
	exit(0);
}

int sroce(){
	FILE *Fptr = fopen("Scores.txt","a");
	
	fprintf(Fptr,"\n%s\tLevel: %d\tLifeline: %d\tSroce: $%d\tAnswer Correct: %d\tAnswer Wrong: %d\tAnswer in which Time up: %d\n"
		,player.name,player.Level,player.lifeline,player.Sroce,player.Q_C,player.Q_W,player.Q_T_P);
	
	fclose(Fptr);
}

int Question_display(){
	int c;
	int randomMy = myran();
	
	printf("\t\tQ %d: %s",player.Q,Questions[randomMy].Question);
	printf("\n\n\t\t %s",Questions[randomMy].A);
	
	spacemaker(20);
	
	printf(" %s",Questions[randomMy].B);
	printf("\n\n\t\t %s",Questions[randomMy].C);
	
	c = strlen(Questions[randomMy].A)+20;
	c -= +strlen(Questions[randomMy].C);
	spacemaker(c);
		
	printf(" %s",Questions[randomMy].D);
	
	player.Q += 1;

	printf("\n\n\t\t");	
	
	loops=30;
	timer(Questions[randomMy].Ans);
	return 0;
}

int myran(){
	int randomMy =  rand() % 74;
	if(Questions[randomMy].repect == 1){
		return rand() % randomMy; //
	}
	else{
		Questions[randomMy].repect = 1;
		return randomMy;
	}
	
	
}

void spacemaker(int num){

	do{
	printf(" ");
	num--;	
	}while(num > 1);
}

int Ans_checker(int ans){

	fflush(stdin);	
	int x =  toupper(getch());
	
	switch(x){
		case 65:
			condition(x,ans);			
			break;
		case 66:
			condition(x,ans);			
			break;
		case 67:
			condition(x,ans);			
			break;
		case 68:
			condition(x,ans);			
			break;
		default:
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			timer(ans);
	}

}

int file2Game(int x){
	char str[300];
	int i=0;
	FILE *Fptr = fopen("New Text Document.txt","r");

	do{
	
		fgets(str,300,Fptr);	
		
		if(str[0]=='&'){
			char *pch;
			pch = strtok (str,"&:");
			strcpy(Questions[i].Question,pch);
		}
		
		else if(str[0]=='$'){
				char * pch;
				pch = strtok (str,"! :$");
				while (pch != NULL){	
					  if(pch[1] == '.' && pch[0] == 'A'){
			  			strcpy(Questions[i].A,pch);
				    					  			
					}
					  else if(pch[1] == '.' && pch[0] == 'B'){
			  			strcpy(Questions[i].B,pch);
				    					  			
					  }
					  else if(pch[1] == '.' && pch[0] == 'C'){
			  			strcpy(Questions[i].C,pch);
				    					  			
					  }
					  else if(pch[1] == '.' && pch[0] == 'D'){
			  			strcpy(Questions[i].D,pch);
				    					  			
					  }
				    pch = strtok(NULL, " !");
			 	 }
		}
		
		else if(str[0]=='@'){	
			Questions[i].Ans = str[2];
			i++;
		}
	
	}while(i <= x);

	fclose(Fptr);
}

int check_way(){
	printf("Press to Continue: \b");
	fflush(stdin);
	char press = toupper(getch());	

	switch(press){
		case 83://s
			system("cls");
			level();
		    printf("\n\n");
			start();
			break;
		case 72://H
			Histroy();
			break;
		case 69://exit
			exit(0);
			break;
		default:
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			 check_way();
	}
	
	return 0;
}

int start(){
	fflush(stdin);
	printf("Enter the player Name:  \b");
	gets(player.name);
	fflush(stdin);
	player.name[0] == 0 ? printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") , start() : 0;
	system("cls");		
	return 0;
}

int logo(){
	
	printf("\n\nPress\n");
	printf("   S -->>> Start Game\n   H -->>> Scroe\n   E -->>> Exits\n\n");
	
}

void Histroy(){
	
	system("cls");
	
	printf("\n\n================================================================================");
	
								printf("\n\t\t\t\t Histroy\n");
	
	printf("================================================================================");


	FILE *Fptr = fopen("Scores.txt","r");
	int i=1;
	
		if(Fptr==NULL){
			printf("NO RECORD FOUND!");
		}
		else{		
		
			while((fscanf(Fptr,"\n%s\tLevel: %d\tLifeline: %d\tSroce: $%d\tAnswer Correct: %d\tAnswer Wrong: %d\tAnswer in which Time up: %d\n"
				,player.name,&player.Level,&player.lifeline,&player.Sroce,&player.Q_C,&player.Q_W,&player.Q_T_P))!= EOF){
			
				printf("\n%d) Summary of the Game of %s\n\nLevel: %d\tLifeline: %d\tSroce: $%d\nAnswer Correct: %d\nAnswer Wrong: %d\nAnswer in which Time up: %d\n",i
					,player.name,player.Level,player.lifeline,player.Sroce,player.Q_C,player.Q_W,player.Q_T_P);	
				
				i++;
			
			}
		}
	

	fclose(Fptr);

	printf("\nGo Back");
	getch();
	fflush(stdin);
	mainTodo();
	
}

//THERE WILL ALWAYS A NEW START AT EVERY END.
