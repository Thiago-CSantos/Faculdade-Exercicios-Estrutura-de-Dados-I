#include <stdio.h>

//exercicio 2
float restoDivisao(float m, float n){
	if(n >m){
		return m;
	}
	else{
		return restoDivisao(m-n, n);
	}
}

int main(){
	float s = restoDivisao(5,3);
	
	printf("%f", s);
}
