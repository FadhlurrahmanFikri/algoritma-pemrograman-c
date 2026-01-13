#include <stdio.h>

int main() {

    // Pointer
    int x = 13;
    int * pX = &x;
    int y = *pX;
    printf("%d\n", y);

    // // Age w/ scanf
    // int age = 23;
    // printf("I am currently %d years old.\n", age);
    // int years = 0;
    // printf("Add years = ");
    // scanf("%d", &years);
    // age = age+years; 
    // printf("\nIn %d years, I am going to be %d years old.", years, age);
    
    // Shopping Cart
    // char item[50]= "";
    // float price = 0.0f;
    // int quantity = 0;
    // float totalPrice = 0.0f;
    // printf("Item apaan? ");
    // fgets(item, sizeof(item), stdin);
    // // scanf("%c", &item);
    // printf("Harga satunya? ");
    // scanf("%f", &price);
    // printf("Mau berapa? ");
    // scanf("%d", &quantity);
    // totalPrice = quantity*price;
    // printf("%d %s seharga %d", quantity, item, totalPrice);

    // // Triangle Area
    // int alasSegitiga = 10;
    // int tinggiSegitiga = 7;
    // int luas = alasSegitiga*tinggiSegitiga/2;
    // printf("\nLuas segitiga adalah %d", luas);

return 0;}