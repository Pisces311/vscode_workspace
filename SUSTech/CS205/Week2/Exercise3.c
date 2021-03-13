#include <stdio.h>

int main() {
    char ch;
    int integer;
    float f;
    printf("Please Enter a Character : ");
    scanf("%c", &ch);
    printf("Please Enter an Integer Value : ");
    scanf("%d", &integer);
    printf("Please Enter Float Value : ");
    scanf("%f", &f);
    printf("\nThe variables you entered were:\n");
    printf("The Character Value that you Entered is : %c\n", ch);
    printf("The Integer Value that you Entered is : %d\n", integer);
    printf("The Float Value that you Entered is : %f\n", f);
    return 0;
}