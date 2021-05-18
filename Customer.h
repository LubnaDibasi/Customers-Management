#include <stdlib.h>
#include <stdio.h>


typedef struct
{
char fulName[100] ; 
char accType[15] ; 

int accNum ; 

} customer ;


int writeCustomer (customer* cList);
customer* loadCustomer( char* filename, int num);
int updateCustomer( char* filename );
void print_customer (customer * c );
customer enter_customerInfo( );