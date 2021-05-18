#include <stdlib.h>
#include <stdio.h>
#include "Customer.h" 

int writeCustomer (customer* cList)
{
int num = 2; 
FILE* fp;
int i;
if ((fp = fopen("info.dat", "w"))){
//fwrite(&num, sizeof(int), 1, fp);

for (i=0; i< num ; i++)
if (!fwrite(cList+i, sizeof(customer), 1, fp)) {
perror("Problem writing to file");
return -2;
}
fclose(fp);
return 0;
}
perror("File could not be opened.");
return -1;

}
//---------------------------
customer* loadCustomer( char* filename, int num){
FILE* fp;
customer* result;
int i;
if ((fp = fopen(filename, "r"))){
//fread(&num, sizeof(int), 1, fp);
result = (customer*)calloc(num, sizeof(customer));
for (i=0; i< num; i++)
if (!fread(result+i, sizeof(customer), 1, fp)){
perror("Problem reading from file");
return NULL;
}
fclose(fp);
return result;
}
perror("File could not be opened.");
return NULL;
}
//---------------------------
int updateCustomer( char* filename )
{
FILE* fp;
int offset ;
customer c  ; ;
if ((fp = fopen(filename, "r+"))){
 
offset = (sizeof(customer) +3  )*-1; 
 fseek(fp,offset,SEEK_END); 
  fread(&c,sizeof(customer),1,fp);

    c = enter_customerInfo(); 

  //write on it 
fseek(fp, offset,SEEK_END); 
if (!fwrite( &c, sizeof(customer), 1, fp)) {
perror("Problem writing to file");
return -1;
}
fclose(fp);
return 0;
}
perror("File could not be opened.");
return -1;



}

//---------------------------
void print_customer (customer * c )
{
printf("Customer's Name : %s", c->fulName);
printf("Customer's Account#  : %d\n", c->accNum);
printf("Customer's Account Type : %s\n", c->accType);

printf("-----------------\n");

}

//------------------------
customer enter_customerInfo( )
{
customer s;
printf("\nEnter Full Name: ");
fgets(s.fulName, 100, stdin);

printf("Enter Account# :  "); 
scanf("%d", &(s.accNum));

getchar();
printf("Enter Account type (checking/saving) : ");
fgets(s.accType, 15, stdin);

return s;

}