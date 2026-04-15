// CONTACT APP

/*
Features...
-----------------------------------------------------------------
1. It can store, retrieve and search for contacts.
2. Saves contact if user want for later use.
3. Also shows country index and name with details.
Drawbacks...
----------------------------------------------------------------
1. It doesn't follow alphabetic indices to show all contact details.


*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int sear=5;        // for getting info from check_info if contact exists

struct contact_info        // to store and retrieve info from file
{
    char name[100];
    long long mobile_no;
    int country_index;
}c;

void get_info();  // to store data parmanently with help of other udfs

void store_info(char str[],long long num );  // to store data info file  
void check_info(char name[], long long m_no); // check whether contact exists
void show_all(); // to show all contacts
void search();   // to search for contact if exists with help of check_info
const char* country_details(int c_in);

int main(){
system("cls");
int temp=0;

while(temp != 4){
printf("\n\n\nCHOOSE ONE FROM BELOW.\n1. ADD NEW CONTACT\n2. ALL CONTACTS\n3. SEARCH CONTACT\n4. EXIT.\n\n");
scanf("%d",&temp);
if(temp==1){get_info();}
else if(temp==2){show_all();}
else if(temp==3){search();}
else{
printf("\nCONTACT CLOSED.");
}
} 
return 0;
}


void get_info(){
int temp;  // to check if user want to store save contact or no
int temp2; // to check whether contact exists
char name[100];
char cm[100];
long long m_no;
int c_i;

printf("\nENTER NAME: ");
scanf(" %[^\n]",name);


printf("\nENTER COUNTRY INDEX: ");
scanf("%d",&c_i);

strcpy(cm,country_details(c_i));
if((strcmp(cm,"Unknown"))==0){
    printf("\nUNKNOWN COUNTRY INTEX FOUND.");
    return;
}

printf("\nENTER MOBILE_NO: ");
scanf("%lld",&m_no);

if(m_no>9999999999 || m_no<1000000000){
    printf("\nPLEASE ENTER VALID MOBILE NUMBER.");
    return;
}

check_info(name,m_no);

temp=sear;
sear=5;

if(temp==0){
    strcpy(c.name,name);
    c.mobile_no=m_no;
    c.country_index=c_i;

printf("\nCONTACT INFO: \n");
printf("\nNAME   :  %s",c.name);
printf("\nNUMBER :  %lld",c.mobile_no);
printf("\nCOUNTRY:  +%d__%s",c.country_index,country_details(c.country_index));

printf("\n\nCHOOSE FROM BELOW. \n1. SAVE CONTACT.\n2. DON'T SAVE CONTACT.\n\n");
scanf("%d",&temp2);

if(temp2==1){ store_info(c.name,c.mobile_no);}

else if(temp2==2){ printf("\nYOUR CONTACT NOT SAVED.");}

else{ printf("\n ENTER VALID CHOICE.");}
}
else if(temp==1){
printf("\n\nCONTACT ALREADY EXISTS.");
return;
}
else{
printf("\nFILE ERROR.");
}
}


void store_info(char str[], long long num){
FILE *fptr;

if((fptr=fopen("CONTACT_INFO.bin","ab+")) == NULL){
printf("\nERROR IN OPENING FILE.");
return;
}

fwrite(&c,sizeof(struct contact_info),1,fptr);
printf("\nINFO STORED.");
if(fclose(fptr) != 0){
printf("\nERROR IN CLOSING FILE.");
return;
}

return;
}

void show_all(){
    system("cls");
    FILE *fptr;
    int i=1;
    if((fptr=fopen("CONTACT_INFO.bin","rb")) == NULL){
    printf("\nERROR IN OPENING FILE.");
    return;
    }

    while((fread(&c,sizeof(struct contact_info),1,fptr)) == 1){
        printf("\n\nCONTACT %d:",i);
        printf("\nNAME:      %s",c.name);
        printf("\nMOBILE NO: %lld",c.mobile_no);
        printf("\nCOUNTRY:   +%d__%s",c.country_index,country_details(c.country_index));
        i++;
    }

    if(fclose(fptr) != 0){
    printf("\nERROR IN CLOSING FILE.");
    return;
    }
}



void check_info(char name[], long long m_no){
    FILE *fptr;
   
    if((fptr=fopen("CONTACT_INFO.bin","rb")) == NULL){
    printf("\nERROR IN OPENING FILE.");
    sear=2;
    return;
    }

    while((fread(&c,sizeof(struct contact_info),1,fptr)) == 1){
        if(m_no == c.mobile_no){
            printf("\nCONTACT DETAIL: ");
            printf("\nNAME:      %s",c.name);
            printf("\nMOBILE NO: %lld",c.mobile_no);
            printf("\nCOUNTRY:   +%d__%s",c.country_index,country_details(c.country_index));
        
            sear=1;
            return;
        }
        else if((strcmp(name,c.name))==0){
            printf("\nCONTACT DETAIL: ");
            printf("\nNAME:      %s",c.name);
            printf("\nMOBILE NO: %lld",c.mobile_no);
            printf("\nCOUNTRY:   +%d__%s",c.country_index,country_details(c.country_index));
            
            sear=1;
            return;
        }
        else{
            continue;
        }
    }

    
    if(fclose(fptr) != 0){
    printf("\nERROR IN CLOSING FILE.");
    sear=2;
    return;
    }
    sear=0;
    return;

}




void search(){
char name[100];
long long m_no;
int temp=0;

printf("\nNAME: ");
scanf(" %[^\n]",name);

m_no=0;

check_info(name,m_no);

temp=sear;
if(temp==1){
    printf("\n\nCONTACT FOUND.");
    return;
}
else if(temp==0){
printf("\nDETAILS NOT FOUND.");
return;
}
else{
printf("\nERRROR IN FILE OPERATION.");
return;
}
}

const char* country_details(int c_in){

if(c_in==1){ return "USA/Canada"; }
else if(c_in==7){ return "Russia/Kazakhstan"; }
else if(c_in==20){ return "Egypt"; }
else if(c_in==27){ return "South Africa"; }
else if(c_in==30){ return "Greece"; }
else if(c_in==31){ return "Netherlands"; }
else if(c_in==32){ return "Belgium"; }
else if(c_in==33){ return "France"; }
else if(c_in==34){ return "Spain"; }
else if(c_in==36){ return "Hungary"; }
else if(c_in==39){ return "Italy"; }
else if(c_in==40){ return "Romania"; }
else if(c_in==41){ return "Switzerland"; }
else if(c_in==43){ return "Austria"; }
else if(c_in==44){ return "UK"; }
else if(c_in==45){ return "Denmark"; }
else if(c_in==46){ return "Sweden"; }
else if(c_in==47){ return "Norway"; }
else if(c_in==48){ return "Poland"; }
else if(c_in==49){ return "Germany"; }
else if(c_in==51){ return "Peru"; }
else if(c_in==52){ return "Mexico"; }
else if(c_in==53){ return "Cuba"; }
else if(c_in==54){ return "Argentina"; }
else if(c_in==55){ return "Brazil"; }
else if(c_in==56){ return "Chile"; }
else if(c_in==57){ return "Colombia"; }
else if(c_in==58){ return "Venezuela"; }
else if(c_in==60){ return "Malaysia"; }
else if(c_in==61){ return "Australia"; }
else if(c_in==62){ return "Indonesia"; }
else if(c_in==63){ return "Philippines"; }
else if(c_in==64){ return "New Zealand"; }
else if(c_in==65){ return "Singapore"; }
else if(c_in==66){ return "Thailand"; }
else if(c_in==81){ return "Japan"; }
else if(c_in==82){ return "South Korea"; }
else if(c_in==84){ return "Vietnam"; }
else if(c_in==86){ return "China"; }
else if(c_in==90){ return "Turkey"; }
else if(c_in==91){ return "India"; }
else if(c_in==92){ return "Pakistan"; }
else if(c_in==93){ return "Afghanistan"; }
else if(c_in==94){ return "Sri Lanka"; }
else if(c_in==95){ return "Myanmar"; }
else if(c_in==98){ return "Iran"; }
else if(c_in==211){ return "South Sudan"; }
else if(c_in==212){ return "Morocco"; }
else if(c_in==213){ return "Algeria"; }
else if(c_in==216){ return "Tunisia"; }
else if(c_in==218){ return "Libya"; }
else if(c_in==220){ return "Gambia"; }
else if(c_in==221){ return "Senegal"; }
else if(c_in==222){ return "Mauritania"; }
else if(c_in==223){ return "Mali"; }
else if(c_in==224){ return "Guinea"; }
else if(c_in==225){ return "Ivory Coast"; }
else if(c_in==226){ return "Burkina Faso"; }
else if(c_in==227){ return "Niger"; }
else if(c_in==228){ return "Togo"; }
else if(c_in==229){ return "Benin"; }
else if(c_in==230){ return "Mauritius"; }

else { return "Unknown"; }

}