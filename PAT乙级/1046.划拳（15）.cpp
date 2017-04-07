#include <cstdio>
int main(){
	int T;
	int A,A1,B,B1;
	int Acup = 0,Bcup = 0;
	scanf("%d",&T);
	while (T--) {
		scanf("%d %d %d %d",&A,&A1,&B,&B1);
		if (A + B == A1 && A + B != B1) {
			Bcup++;
		}
		if (A + B != A1 && A + B == B1){
			Acup++;
		}
		else continue;
	}
	printf("%d %d",Acup,Bcup);
}