#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
#include<unistd.h>

#define max_size 1000
void admin();
void user();
void admin_login();
void choose_option();
void close_fun();
void menu();
void breakfast();
void lunch();
void addStock();
void seeStock();
void addOrder();
void seeOrder();
void payment(double price);
void bKash(double bkash_pay);
void dbbl(double dbbl_pay);
double total=0;

COORD coord={0,0};
 void gotoxy(int x,int y)
 {
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 struct login{
    char fname[100];
    char lname[100];
    char username[100];
    char password[100];
};
int main()

{
    system("COLOR F2");

    loading();
    system("cls");
    gotoxy(0,3);
    printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    gotoxy(39,3);
    printf(" Welcome To  Food Corner \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    switch_option();
  return 0;
}
void loading(){

     int i;
     system("cls");
     gotoxy(20,3);
     printf("Please wait Loading ");
     for(i=0;i<40;i++){
     Sleep(100);
     printf("\xB2");
     }
}
void switch_option(){
    gotoxy(37,6);
    printf("\xdb\xdb 1.Admin ");
    gotoxy(37,8);
    printf("\xdb\xdb 2.User ");
    gotoxy(37,10);
    printf("\xdb\xdb 3. Exit");

    int choose_option;
    gotoxy(40,13);
    printf("Enter your option: ");
    choose_option=getch();

    switch(choose_option){
      case '1':
        system("cls");
        chooseAdmin();
        break;
      case '2':
        system("cls");
        chooseUser();
        break;
      case '3':
          system("cls");
          close_fun();
          break;

      default:
        printf("You've Enter wrong Input, Please enter 1 or 2\n");
        system("cls");
        main();

    }

}
void chooseAdmin(){
    int cho;
    gotoxy(35,4);
    printf("\xdb\xdb\xdb\xdb\xdb\xdb Please  Login to Access \xdb\xdb\xdb\xdb\xdb\xdb");
    gotoxy(45,6);
    printf("1.Admin Login");
    gotoxy(45,7);
    printf("2.Return");
    gotoxy(45,8);
    printf("Choose: ");
    scanf("%d",&cho);
    if(cho==1){
        system("CLS");
        login_admin();
    }
    else if(cho==2){
        system("CLS");
        switch_option();
    }
}

void login_admin(){
     int j;
    char password[100], ch= "*";
    char username[100];

    gotoxy(40,4);
    printf("\xdb\xdb\xdb\xdb\xdb Admin Portal \xdb\xdb\xdb\xdb\xdb ");
    gotoxy(47,7);

    printf("Username: ");
    scanf("%s",&username);
    gotoxy(48,11);
    printf("Password: ");
    for(j=0;j<4;j++){
    ch =getch();
    password[j]=ch;
    printf("*");

  }
  password[j] = '\0';
   if((strcmp(username,"admin") ==0)&& (strcmp(password,"abcd")==0)){
          gotoxy(45,11);

        printf("Loading ");
         gotoxy(45,12);
        system("cls");
        admin();

    }
    else{
        gotoxy(47,9);
        printf("Incorrect Password!");

        getch();
        system("cls");
        login_admin();
    }


}
void admin(){
     int choose_admin;

     gotoxy(29,4);
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Welcome To The Admin Portal \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xdb\xdb\xdb\xdb");
     gotoxy(29,5);
     printf("\xdb\xdb");
     gotoxy(80,5);
     printf("\xdb\xdb");
     gotoxy(29,6);
     printf("\xdb\xdb\t\t 1.Add Stock\t\t\t\t\xdb\xdb");
     gotoxy(29,7);
     printf("\xdb\xdb\t\t 2.See Stock\t\t\t\t\xdb\xdb ");
     gotoxy(29,8);
     printf("\xdb\xdb\t\t 3.Add to Order\t\t\t\t\xdb\xdb");
     gotoxy(29,9);
     printf("\xdb\xdb\t\t 4.See Order\t\t\t\t\xdb\xdb");
     gotoxy(29,10);
     printf("\xdb\xdb\t\t 5.Return\t\t\t\t\xdb\xdb");
     gotoxy(29,11);
     printf("\xdb\xdb");
     gotoxy(80,11);
     printf("\xdb\xdb");
     gotoxy(29,12);
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
     gotoxy(37,14);
     printf("Choose: ");
     scanf("%d",&choose_admin);
     if(choose_admin==1){
        system("cls");
        addStock();
     }else if(choose_admin==2){
        system("cls");
        seeStock();
     }else if(choose_admin==3){
        system("cls");
        addOrder();
     }else if(choose_admin==4){
        system("cls");
        seeOrder();
     }else if(choose_admin==5){
        system("cls");
        switch_option();
     }

}
struct stock{
    char pname[max_size];
    char pdes[max_size];
    char pprice[max_size];
    char pquantity[max_size];
    char pcompany[max_size];
}stocks;
void addStock(){
    FILE *stockfile;
    FILE *stocktable;
         stockfile=fopen("stock.txt","a+");
         stocktable=fopen("stocktable.txt","a+");
         if(stockfile==NULL && stocktable==NULL){
            printf("Error!Opening the file.");
            exit(0);
         }
         else{
            gotoxy(30,4);
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            gotoxy(50,5);
            printf("Add To Stocks\n\n");
            gotoxy(30,5);
            printf("\xb2\xb2\xb2\xb2");
            gotoxy(82,5);
            printf("\xb2\xb2\xb2\xb2\n");
            gotoxy(30,6);
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");

            gotoxy(30,7);
            printf("\xb2\xb2 Product Name: ");
            scanf("%s",stocks.pname);
            fprintf(stocktable,"Product Name: %s",stocks.pname);
            gotoxy(84,7);
            printf("\xb2\xb2");
            gotoxy(30,8);
            printf("\xb2\xb2 Product Description(Food / Bevarage) : ");
            scanf("%s",stocks.pdes);
            fprintf(stocktable,"\tProduct Description: %s",stocks.pdes);
            gotoxy(84,8);
            printf("\xb2\xb2");
            gotoxy(30,9);
            printf("\xb2\xb2 Product Price: ");
            scanf("%s",stocks.pprice);
            fprintf(stocktable,"\nProduct Price: %s",stocks.pprice);
            gotoxy(84,9);
            printf("\xb2\xb2");
            gotoxy(30,10);
            printf("\xb2\xb2 Product Quantity: ");
            scanf("%s",stocks.pquantity);
            fprintf(stocktable,"\tProduct Quantity: %s",stocks.pquantity);
            gotoxy(84,10);
            printf("\xb2\xb2");
            gotoxy(30,11);
            printf("\xb2\xb2 Product Company: ");
            scanf("%s",stocks.pcompany);
            fprintf(stocktable,"\nProduct Company: %s\n",stocks.pcompany);
            gotoxy(84,11);
            printf("\xb2\xb2");
            gotoxy(30,12);
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");



            fwrite(&stocks,sizeof(stocks),1,stockfile);

            gotoxy(32,15);
            printf("Congratulation! Added new products");
            gotoxy(32,16);
            printf("\n\n\t\t\t\tPress any key to continue.....");
            getch();

	        fclose(stockfile);
            fclose(stocktable);
            printf("\n\t\t\t\t1.Return\n");
            printf("\t\t\t\t2.Exit\n");
            printf("\t\t\t\tPress: ");
            getch();
            switch(getch()){
                 case '1':
                    system("cls");
                    admin();
                    break;
                 case '2':
                    system("cls");
                    break;
            }

         }
}
void seeStock(){
    FILE *stockfile;
    stockfile=fopen("stock.txt","r+");
    printf("\n\n\t\t\t");
    printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
    printf(" Product In Stock ");
    printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
    if(stockfile==NULL){
        printf("\nError!");
        exit(1);
    }
	while(fread(&stocks,sizeof(stocks),1,stockfile)==1)
	{	printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n\n");
		printf("\t\xdb\xdb Product Name: %s\n",stocks.pname);
		printf("\t\xdb\xdb Product Description: %s\n",stocks.pdes);
		printf("\t\xdb\xdb Product Price: %s\n",stocks.pprice);
		printf("\t\xdb\xdb Product Quantity: %s\n",stocks.pquantity);
		printf("\t\xdb\xdb Product Company: %s\n",stocks.pcompany);
	}
	printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\n\t\t\t\tPress any key to continue.....");
	getch();

	fclose(stockfile);
	printf("\n\t\t\t\t1.Return\n");
	printf("\t\t\t\t2.Exit\n");
	printf("\t\t\t\tPress: ");
	getch();
	switch(getch()){
         case '1':
            system("cls");
            admin();
            break;
         case '2':
            system("cls");
            break;
	}
}
struct order{
    char oname[max_size];
    char ocode[max_size];
    char odes[max_size];
    char oprice[max_size];
    char oquantity[max_size];
    char clientName[max_size];
    char clientPhn[max_size];
}orders;
void addOrder(){
        FILE *orderfile;
        FILE *ordertable;
         orderfile=fopen("order.txt","a+");
         ordertable=fopen("ordertable.txt","a+");
         if(orderfile==NULL){
            printf("Error!Opening the file.");
            exit(0);
         }
         else{
            gotoxy(30,4);
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            gotoxy(50,5);
            printf("Add to Order\n\n");
            gotoxy(30,5);
            printf("\xb2\xb2\xb2\xb2");
            gotoxy(82,5);
            printf("\xb2\xb2\xb2\xb2\n");
            gotoxy(30,6);
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");

            gotoxy(30,7);
            printf("\xb2\xb2 Order Name: ");
            scanf("%s",orders.oname);
            fprintf(ordertable,"Order Name: %s",orders.oname);
            gotoxy(84,7);
            printf("\xb2\xb2");
            gotoxy(30,8);
            printf("\xb2\xb2 Order Code : ");
            scanf("%s",orders.ocode);
            fprintf(ordertable,"\tOrder Code: %s",orders.ocode);
            gotoxy(84,8);
            printf("\xb2\xb2");
            gotoxy(30,9);
            printf("\xb2\xb2 Order Price: ");
            scanf("%s",orders.oprice);
            fprintf(ordertable,"\nOrder Price: %s",orders.oprice);
            gotoxy(84,9);
            printf("\xb2\xb2");
            gotoxy(30,10);
            printf("\xb2\xb2 Order Description: ");
            scanf("%s",orders.odes);
            fprintf(ordertable,"\tOrder Description: %s",orders.odes);
            gotoxy(84,10);
            printf("\xb2\xb2");
            gotoxy(30,11);
            printf("\xb2\xb2 Order Quantity: ");
            scanf("%s",orders.oquantity);
            fprintf(ordertable,"\nOrder Quantity: %s",orders.oquantity);
            gotoxy(84,11);
            printf("\xb2\xb2");
            gotoxy(30,12);
            printf("\xb2\xb2 Customer Name: ");
            scanf("%s",orders.clientName);
            fprintf(ordertable,"\tCustomer Name: %s",orders.clientName);
            gotoxy(84,12);
            printf("\xb2\xb2");
            gotoxy(30,13);
            printf("\xb2\xb2 Phone: ");
            scanf("%s",orders.clientPhn);
            fprintf(ordertable,"\nPhone: %s\n\n",orders.clientPhn);
            gotoxy(84,13);
            printf("\xb2\xb2");
            gotoxy(30,14);
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
            printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");



            fwrite(&orders,sizeof(orders),1,orderfile);

            gotoxy(32,17);
            printf("Congratulation! Added new orders!");
            gotoxy(32,18);
            printf("Press any key....");
            getch();
            system("CLS");
            fclose(orderfile);
            fclose(ordertable);
            admin();

         }
}
void seeOrder(){
     FILE *orderfile;
    orderfile=fopen("order.txt","r+");
    printf("\n\n\t\t\t");
    printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
    printf(" List of Orders ");
    printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
    if(orderfile==NULL){
        printf("\nError!");
        exit(1);
    }
	while(fread(&orders,sizeof(orders),1,orderfile)==1)
	{	printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n\n");
		printf("\t\xdb\xdb Order Name: %s\n",orders.oname);
		printf("\t\xdb\xdb Order Code: %s\n",orders.ocode);
		printf("\t\xdb\xdb Order Description: %s\n",orders.odes);
		printf("\t\xdb\xdb Order Price: %s\n",orders.oprice);
		printf("\t\xdb\xdb Order Quantity: %s\n",orders.oquantity);
		printf("\t\xdb\xdb Company Name: %s\n",orders.clientName);
		printf("\t\xdb\xdb Phone : %s\n",orders.clientPhn);
	}
	printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\n\t\t\t\tPress any key to continue.....");
	getch();

	fclose(orderfile);
	printf("\n\t\t\t\t1.Return\n");
	printf("\t\t\t\t2.Exit\n");
	printf("\t\t\t\tPress: ");
	getch();
	switch(getch()){
         case '1':
            system("cls");
            admin();
            break;
         case '2':
            system("cls");
            break;
	}
}
void chooseUser(){
    int cho;
    gotoxy(35,4);
    printf("\xdb\xdb\xdb\xdb\xdb\xdb Please Register Before Login \xdb\xdb\xdb\xdb\xdb\xdb");
    gotoxy(45,6);
    printf("1.Register");
    gotoxy(45,7);
    printf("2.Press for login");
    gotoxy(45,8);
    printf("Choose: ");
    scanf("%d",&cho);
    if(cho==1){
        system("CLS");
        reg();
    }
    else if(cho==2){
        system("CLS");
        login();
    }
}




static int i=0;
struct web
{
char name[30],pass[30];
}w[99];
int n;
void login(void);
void reg(void);

void reg()
  {
    FILE *fp;
    char c,checker[30]; int z=0;
    fp=fopen("User_reg.txt","ab+");
    gotoxy(40,4);
    printf("\xdb\xdb\xdb\xdb\xdb Please Register To Access Into User Panel \xdb\xdb\xdb\xdb\xdb");
    for(i=0;i<100;i++)
    {
       gotoxy(47,6);
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&w[i],sizeof(w[i]),1,fp);
          if(strcmp(checker,w[i].name)==0)
            {
            printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
            system("CLS");
            reg();
            }
          else
          {
            strcpy(w[i].name,checker);
            break;
          }
        }
          gotoxy(47,8);
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          w[i].pass[z++]=c;
          printf("%c",'*');
        }
      fwrite(&w[i],sizeof(w[i]),1,fp);
      fclose(fp);

      printf("\n\n\tPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
        system("CLS");
        printf("\n\n\t\tYou are successfully registered");
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        scanf("%d",&n);
        switch(n)
          {
              case 1: system("CLS");
                    login();
                    break;
              case 2: system("CLS");
                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                    break;
          }
        }
        break;
      }
    getch();
  }
  void login()
    {
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      fp=fopen("User_reg.txt","rb");
      gotoxy(40,4);
      printf("\xdb\xdb\xdb\xdb\xdb Please login with your username and password! \xdb\xdb\xdb\xdb\xdb ");
      for(i=0;i<1000;i++)
      {
          gotoxy(47,6);
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        gotoxy(47,8);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      while(!feof(fp))
        {
        fread(&w[i],sizeof(w[i]),1,fp);
          checku=strcmp(name,w[i].name);
          checkp=strcmp(pass,w[i].pass);
          if(checku==0&&checkp==0)
          {
            system("CLS");
              user();
            break;
          }
        else if(checku==0&&checkp!=0)
          {
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        else if(checku!=0)
          {
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
            if(getch()==13)
            system("CLS");
            reg();
          }
        }
        break;
      }
      getch();
    }


void user(){
     int choose_user;
     gotoxy(29,5);
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Welcome To  Food Corner \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
     gotoxy(37,7);
     printf("\xdb\xdb");
     gotoxy(71,7);
     printf("\xdb\xdb");
     gotoxy(40,7);
     printf("1.Menu");
     gotoxy(37,8);
     printf("\xdb\xdb");
     gotoxy(71,8);
     printf("\xdb\xdb");
     gotoxy(40,8);
     printf("2.Exit");
     gotoxy(37,9);
     printf("\xdb\xdb");
     gotoxy(71,9);
     printf("\xdb\xdb");

     gotoxy(37,10);
     printf("\xdb\xdb");
     gotoxy(71,10);
     printf("\xdb\xdb");

     gotoxy(29,12);
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
     gotoxy(40,14);
     printf("Enter input: ");
     choose_user=getch();
     if(choose_user=='1'){
        system("cls");
        menu();
     }else if(choose_user=='2'){
        system("cls");
        close_fun();
     }

}
void menu(){
    int choose_menu;
    gotoxy(35,4);
    printf("\xdb\xdb\xdb\xdb\xdb Please choose your meal \xdb\xdb\xdb\xdb\xdb");
    gotoxy(43,6);
    printf("1.Breakfast");
    gotoxy(43,7);
    printf("2.Lunch");
    gotoxy(43,8);
    printf("Choose: ");
    choose_menu=getch();
    if(choose_menu=='1'){
        system("cls");
         breakfast();

    }else if(choose_menu=='2'){
        system("cls");
        lunch();

    }
}
void breakfast(){
    int choose_breakfast;
    int price[5]={5,5,20,80,120};
    gotoxy(40,3);
    printf("\xdb\xdb\xdb\xdb\xdb Breakfast (8.00 AM - 11.00 AM) \xdb\xdb\xdb\xdb\xdb");
    gotoxy(46,6);
    printf("1.Singara - BTD 5\n");
    gotoxy(46,7);
    printf("2.Samossa - BTD 5\n");
    gotoxy(46,8);
    printf("3.Roll - BTD 20\n");
    gotoxy(46,9);
    printf("4.Chicken Fry - BTD 80\n");
    gotoxy(46,10);
    printf("5.Burger - BTD 120\n");
    gotoxy(46,11);
    printf("6.Exit\n");
    gotoxy(46,12);
    printf("Choose: ");
    choose_breakfast=getch();
    if(choose_breakfast=='1'){
        system("cls");
        total+=price[0];
        gotoxy(46,5);
        printf("Total: %.2lf\n",total);
        breakfast();
    }else if(choose_breakfast=='2'){
        system("cls");
        total+=price[1];
        gotoxy(46,5);
        printf("Total: %.2lf\n",total);
        breakfast();
    }else if(choose_breakfast=='3'){
        system("cls");
        total+=price[2];
        gotoxy(46,5);
        printf("Total: %.2lf\n",total);
        breakfast();
    }else if(choose_breakfast=='4'){
        system("cls");
        total+=price[3];
        gotoxy(46,5);
        printf("Total: %.2lf\n",total);
        breakfast();
    }else if(choose_breakfast=='5'){
        system("cls");
        total+=price[4];
        gotoxy(46,5);
        printf("Total: %.2lf\n",total);
        breakfast();
    }else if(choose_breakfast=='6'){
        payment(total);
    }

}
void lunch(){
    int choose_breakfast;
    int price[5]={90,120,120,150,80};
    gotoxy(40,3);
    printf("\xdb\xdb\xdb\xdb\xdb Lunch (1.00 AM - 3.00 AM) \xdb\xdb\xdb\xdb\xdb");
    gotoxy(45,6);
    printf("1.Fried Rice - BTD 90\n");
    gotoxy(45,7);
    printf("2.Buna Kichuri - BTD 120\n");
    gotoxy(45,8);
    printf("3.Murog Pulaw - BTD 120\n");
    gotoxy(45,9);
    printf("4.Kachi Biriyani - BTD 150\n");
    gotoxy(45,10);
    printf("5.Dim Kichuri - BTD 80\n");
    gotoxy(45,11);
    printf("6.Exit\n");
    gotoxy(45,12);
    printf("Choose: ");
    choose_breakfast=getch();
    if(choose_breakfast=='1'){
        system("cls");
        total+=price[0];
        gotoxy(45,5);
        printf("Total: %.2lf\n",total);
        lunch();
    }else if(choose_breakfast=='2'){
        system("cls");
        total+=price[1];
        gotoxy(45,5);
        printf("Total: %.2lf\n",total);
        lunch();
    }else if(choose_breakfast=='3'){
        system("cls");
        total+=price[2];
        gotoxy(45,5);
        printf("Total: %.2lf\n",total);
        lunch();
    }else if(choose_breakfast=='4'){
        system("cls");
        total+=price[3];
        gotoxy(45,5);
        printf("Total: %.2lf\n",total);
        lunch();
    }else if(choose_breakfast=='5'){
        system("cls");
        total+=price[4];
        gotoxy(45,5);
        printf("Total: %.2lf\n",total);
        lunch();
    }else if(choose_breakfast=='6'){
        system("cls");
        payment(total);
    }
}
void payment(double price){
    system("cls");
    int choose_payment;
    gotoxy(40,4);
    printf("\xdb\xdb\xdb\xdb\xdb Please choose your preferred payment method \xdb\xdb\xdb\xdb\xdb");
    gotoxy(45,6);
    printf("1.Bkash");
    gotoxy(45,7);
    printf("2.DBBL");
    gotoxy(45,8);

    printf("Choose: ");
    choose_payment=getch();
    if(choose_payment=='1'){
        system("cls");
        bKash(price);
    }else if(choose_payment=='2'){
        system("cls");
        dbbl(price);
    }
}
void bKash(double bkash_pay){
    system("Cls");
    printf("Total Price: %.2lf BTD Paid By Bkash\n",bkash_pay);
    getch();
    close_fun();
}
void dbbl(double dbbl_pay){
    system("Cls");
    printf("Total Price: %.2lf BTD Paid By DBBC pay\n",dbbl_pay);
    getch();
    close_fun();
}


void close_fun(){
    gotoxy(30,3);
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    gotoxy(30,4);
    printf("\xdb\xdb\xdb\xdb    Thank You For using Our Application        \xdb\xdb\xdb\xdb");
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    gotoxy(30,5);
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n\n");
}

