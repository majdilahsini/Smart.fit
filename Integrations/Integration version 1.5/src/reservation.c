#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservation.h"

void reserver(calendrier c)
{
FILE* f=fopen("src/salle.txt","a+");
if(f!=NULL)
{
fprintf(f,"%d/%d/%d %s %s %s\n",c.dt_res.jour,c.dt_res.mois,c.dt_res.annee,c.hr_resr,c.hr2_resr,c.evenement);
fclose(f); 
}
}
