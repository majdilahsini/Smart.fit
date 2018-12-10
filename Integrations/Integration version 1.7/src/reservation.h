typedef struct Date
{
int jour;
int mois;
int annee;
}Date;

typedef struct calendrier
{
Date dt_res;//-1/-1/-1 si nn reserver
char hr_resr[50];//1 si matin 2 si apret midi -1 si non
char hr2_resr[50];
char evenement[50];
}calendrier;



void reserver(calendrier c);


