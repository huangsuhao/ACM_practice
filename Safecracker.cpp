/*
					 === Op tech briefing, 2002/11/02 06:42 CST === 
"The item is locked in a Klein safe behind a painting in the second-floor 
	library. Klein safes are extremely rare; most of them, along with Klein and 
	his factory, were destroyed in World War II. Fortunately old Brumbaugh from 
	research knew Klein's secrets and wrote them down before he died. A Klein safe 
	has two distinguishing features: a combination lock that uses letters instead 
	of numbers, and an engraved quotation on the door. A Klein quotation always 
	contains between five and twelve distinct uppercase letters, usually at the 
	beginning of sentences, and mentions one or more numbers. Five of the uppercase 
	letters form the combination that opens the safe. By combining the digits from 
	all the numbers in the appropriate way you get a numeric target. (The details 
	of constructing the target number are classified.) To find the combination you 
	must select five letters v, w, x, y, and z that satisfy the following equation, 
	where each letter is replaced by its ordinal position in the alphabet (A=1, 
	B=2, ..., Z=26). The combination is then vwxyz. If there is more than one solution 
	then the combination is the one that is lexicographically greatest, i.e., the 
	one that would appear last in a dictionary." 


v - w^2 + x^3 - y^4 + z^5 = target 


"For example, given target 1 and letter set ABCDEFGHIJKL, one possible 
	solution is FIECB, since 6 - 9^2 + 5^3 - 3^4 + 2^5 = 1. There are actually several 
	solutions in this case, and the combination turns out to be LKEBA. Klein thought 
	it was safe to encode the combination within the engraving, because it could 
	take months of effort to try all the possibilities even if you knew the secret. 
	But of course computers didn't exist then." 


=== Op tech directive, computer division, 2002/11/02 12:30 CST === 


"Develop a program to find Klein combinations in preparation for field 
	deployment. Use standard test methodology as per departmental regulations. Input 
	consists of one or more lines containing a positive integer target less than 
	twelve million, a space, then at least five and at most twelve distinct uppercase 
	letters. The last line will contain a target of zero and the letters END; this 
	signals the end of the input. For each line output the Klein combination, break 
	ties with lexicographic order, or 'no solution' if there is no correct combination. 
	Use the exact format shown below."
	
	Input
	
	1 ABCDEFGHIJKL
	11700519 ZAYEXIWOVU
	3072997 SOUGHT
	1234567 THEQUICKFROG
	0 END


	Output
	
	LKEBA
	YOXUZ
	GHOST
	no solution
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char letters[12];
int value[12],target;
void process(int len){
	int a,b,c,d,e;
	for(a = 0; a < len; a++)
		for(b = 0; b < len; b++)
			if(a != b)
				for(c = 0; c < len; c++)
					if (a != c && b != c) 
						for(d = 0; d <= len; d++)
							if(a != d && b!= d && c!=d)
								for (e = 0; e <= len; e++) 
									if(a != e && b != e && c != e && d != e)
										if(value[a] -  pow(value[b], 2.0) 
											+pow(value[c], 3.0)
											-pow(value[d], 4.0)
											+pow(value[e], 5.0)
											== target){
												printf("%c%c%c%c%c\n",value[a]+'A'-1,value[b]+'A'-1,value[c]+'A'-1,value[d]+'A'-1,value[e]+'A'-1);
												return;
											}
	printf("no solution\n");
}

bool compare(int a, int b){
	return a>b;			
}
int main() {
	int i;
	while (~scanf("%d %s",&target,letters)) {
		if (target == 0 && strcmp(letters, "END") == 0) {
			return 0;
		}
	i = 0;
	while (letters[i]) {
		value[i] = letters[i] - 'A' + 1;
		i++; 
	}
	sort(value, value + i, compare );
	process(i);
	}
	return 0;
}