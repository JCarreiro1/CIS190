#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    // Declare constants for item prices
    const double jaguarPrice = 249.00;
    const double remotePrice = 49.59;
    const double cdiPrice = 1000.00;
    const double threeDOPrice = 699.99;
    const double betamaxPrice = 1300.00;
    const double taxRate = 0.0525;

    // Declare variables
    int jaguar, remote, cdi, threeDO, betamax;
    double total, subtotal, tax;

    // User input to file input
    FILE* infile = fopen("input.txt", "r");

    fscanf(infile, "%d", &jaguar);
    fscanf(infile, "%d", &remote);
    fscanf(infile, "%d", &cdi);
    fscanf(infile, "%d", &threeDO);
    fscanf(infile, "%d", &betamax);

    fclose(infile);

    // Obtain user input and assign variables
    /*printf("How many Jaguars were sold?");
    scanf("%d", &jaguar);
    printf("How many Remotes were sold?");
    scanf("%d", &remote);
    printf("How many CDi's were sold?");
    scanf("%d", &cdi);
    printf("How many 3DO's were sold?");
    scanf("%d", &threeDO);
    printf("How many Betamax's were sold?");
    scanf("%d", &betamax);*/

    // Calculations
    subtotal = (jaguar * jaguarPrice) + (remote * remotePrice) + (cdi * cdiPrice) + (threeDO * threeDOPrice) + (betamax * betamaxPrice);
    tax = subtotal * taxRate;
    total = subtotal + tax;

    // Displaying results
    printf("QTY\tDESCRIPTION\tUNIT PRICE\tTOTAL PRICE\n\n---\t-----------\t----------\t-----------\n");
    printf("%3d\tJAGUAR\t\t%10.2lf\t%11.2lf\n", jaguar, jaguarPrice, jaguar * jaguarPrice);
    printf("%3d\tREMOTE\t\t%10.2lf\t%11.2lf\n", remote, remotePrice, remote * remotePrice);
    printf("%3d\tCDI\t\t%10.2lf\t%11.2lf\n", cdi, cdiPrice, cdi * cdiPrice);
    printf("%3d\t3DO\t\t%10.2lf\t%11.2lf\n", threeDO, threeDOPrice, threeDO * threeDOPrice);
    printf("%3d\tBETAMAX\t\t%10.2lf\t%11.2lf\n", betamax, betamaxPrice, betamax * betamaxPrice);

    printf("\n\t\t\t\t\t-----------\n");

    printf("\t\t\tSUBTOTAL\t%11.2lf\n", subtotal);
    printf("\t\t\tTAX\t\t%11.2lf\n", tax);
    printf("\t\t\tTOTAL\t\t%11.2lf\n", total);

    // User output to file output
    FILE* outfile = fopen("output.txt", "w");

    fprintf(outfile, "QTY\tDESCRIPTION\tUNIT PRICE\tTOTAL PRICE\n\n---\t-----------\t----------\t-----------\n");
    fprintf(outfile, "%3d\tJAGUAR\t\t%10.2lf\t%11.2lf\n", jaguar, jaguarPrice, jaguar * jaguarPrice);
    fprintf(outfile, "%3d\tREMOTE\t\t%10.2lf\t%11.2lf\n", remote, remotePrice, remote * remotePrice);
    fprintf(outfile, "%3d\tCDI\t\t%10.2lf\t%11.2lf\n", cdi, cdiPrice, cdi * cdiPrice);
    fprintf(outfile, "%3d\t3DO\t\t%10.2lf\t%11.2lf\n", threeDO, threeDOPrice, threeDO * threeDOPrice);
    fprintf(outfile, "%3d\tBETAMAX\t\t%10.2lf\t%11.2lf\n", betamax, betamaxPrice, betamax * betamaxPrice);

    fprintf(outfile, "\n\t\t\t\t\t-----------\n");

    fprintf(outfile, "\t\t\tSUBTOTAL\t%11.2lf\n", subtotal);
    fprintf(outfile, "\t\t\tTAX\t\t%11.2lf\n", tax);
    fprintf(outfile, "\t\t\tTOTAL\t\t%11.2lf\n", total);

    fclose(outfile);


    return 0;
}