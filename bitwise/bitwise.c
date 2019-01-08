
#include <stdio.h>

int		main()
{
	 int	n1;
	 int	n2;
	 int	n3;

	 n1 = 10;
	 n2 = 15;
	 printf("---------------------------------------\n");
	 printf("BITWISE OPERATORS\n\n");
	 printf("Example:\n\n");
	 printf("AND operator is: &\n");
	 printf(" OR operator is: |\n");
	 printf("XOR operator is: ^\n");
	 printf("\nn1 = 10\nn2 = 15\n\n");
	 n3 = n1 & n2;
	 printf("AND rules: \t\"like bits is 1\"\n\n");
	 printf("\t\twhat is n3 if (n3 = n1 & n2)\n\n");
	 printf("\t\t1 & 1 = 1\n\t\t1 & 0 = 0\n\t\t0 & 1 = 0\n\n");
	 printf("\t|\t0 0 1 0 1 0 = decimal value 10\n");
	 printf("\t|\t0 0 1 1 1 1 = decimal value 15\n");
	 printf("\tV\t------------------------------\n");
	 printf("\t\t0 0 1 0 1 0 = bitwise 10 & 15\n");
	 printf("\t\tn3 = %d\n\n", n3);
	 n3 = n1 | n2;
	 printf(" OR rules: \t\"any 1 is 1\"\n\n");
	 printf("\t\twhat is n3 if (n3 = n1 | n2)\n\n");
	 printf("\t\t1 | 1 = 1\n\t\t1 | 0 = 1\n\t\t0 | 1 = 1\n\n");
	 printf("\t|\t0 0 1 0 1 0 = decimal value 10\n");
	 printf("\t|\t0 0 1 1 1 1 = decimal value 15\n");
	 printf("\tV\t------------------------------\n");
	 printf("\t\t0 0 1 1 1 1 = bitwise 10 | 15\n");
	 printf("\t\tn3 = %d\n\n", n3);
	 n3 = n1 ^ n2;
	 printf("XOR rules: \t\"like bits is 0\"\n\n");
	 printf("\t\twhat is n3 if (n3 = n1 ^ n2)\n\n");
	 printf("\t\t1 ^ 1 = 0\n\t\t1 ^ 0 = 1\n\t\t0 ^ 1 = 1\n\n");
	 printf("\t|\t0 0 1 0 1 0 = decimal value 10\n");
	 printf("\t|\t0 0 1 1 1 1 = decimal value 15\n");
	 printf("\tV\t------------------------------\n");
	 printf("\t\t0 0 0 1 0 1 = bitwise 10 ^ 15\n");
	 printf("\t\tn3 = %d\n\n", n3);
	 n3 = ~n1;
	 printf("NOR rules: \t\"all values are flipped and is negative\"\n\n");
	 printf("\t\twhat is n3 if (n3 = ~n1)\n\n");
	 printf("\t\t1 = 0 \n\t\t0 = 1\n\n");
	 printf("\t|\t0 ....0 0 1 0 1 0 = original value 10 = OV\n");
	 printf("\t|\t1 ....1 1 0 1 0 1 = negation of value 10 = NV\n");
	 printf("\t|\t-.....0 0 1 0 1 0 = Neg of NV\n");
	 printf("\t|\t-.....0 0 1 0 1 1 = result in binary\n");
	 printf("\t|\t**when using negation always do 2-complement by adding 1\n");
	 printf("\t|\t               +1 = 2-complement = (~origninal value) + 1\n");
	 printf("\t|\t    orignal value = ~(2-complement) + 1\n");
	 printf("\tV\t------------------------------------\n");
	 printf("\t\t0 0 1 0 1 1 = bitwise ~10 = -11\n");
	 printf("\t\tn3 = %d\n\n", n3);
	 printf("---------------------------------------\n");
	 return (0);
}
