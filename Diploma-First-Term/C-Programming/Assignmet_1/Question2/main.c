/*
 * main.c
 *  check vowel or consonant
 *  Created on: Aug 29, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

 int main (){
	 char x;
	 printf("Enter an alphabet: ");
	 fflush(stdout);
	 scanf("%c",&x);
	 if(x =='i' || x == 'o' || x == 'a' || x == 'e' || x== 'u')
		 printf("%c is vowel.",x);
	 else
		 printf("%c is consonant. ",x);
	 return 0;
 }
