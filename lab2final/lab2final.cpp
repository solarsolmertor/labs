#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	/* initial values */
	char substance1[] = "Zn", substance2[] = "Pb-Au", substance3[] = "NbC";
	char type1 = 'M', type2 = 'A', type3 = 'C';
	char temperature1[] = "0.8-0.8", temperature2[] = "2.0-7.3", temperature3[] = "10.1-10.5";

	/* entering values*/
	printf("1. Enter: Substance, type, temperature >");
	scanf("%s %c %s", substance1, &type1, temperature1);
	printf("2. Enter: Substance, type, temperature >");
	scanf("%s %c %s", substance2, &type2, temperature2);
	printf("3. Enter: Substance, type, temperature >");
	scanf("%s %c %s", substance3, &type3, temperature3);

	/* output table */
	/* output headers */
	printf("------------------------------------------------------------------\n");
	printf("|Temperature of substances in a superconducting state            |\n");
	printf("|----------------------------------------------------------------|\n");
	printf("|Substance                  |Type       |Temperature             |\n");
	/* output value rows */
	printf("|%-27s|%-11c|%-24s|\n", substance1, type1, temperature1);
	printf("|%-27s|%-11c|%-24s|\n", substance2, type2, temperature2);
	printf("|%-27s|%-11c|%-24s|\n", substance3, type3, temperature3);
	/* output description */
	printf("|----------------------------------------------------------------|\n");
	printf("|Type of substance: M - metal, A - alloy, C - compound           |\n");
	printf("------------------------------------------------------------------\n");
	return 0;
}
