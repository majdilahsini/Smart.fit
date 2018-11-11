void ajouter(char login[],char password[], int role);
int str_to_int (char a[]);
int verifier (char login[], char password[]);
void verifi_ajout 
(char login[] ,char password[], char role [],char msg_l [], char msg_r[], char msg_p [], char msg_pr []); //Verify Login (Length >3), Password (Length >3 AND Must contain at least 1 INT), Role (INT between 1 and 6) and if Login/Pass combinations already exists. Returns Messages.
