#include <stdio.h>

int main(){
    int n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    double vet[n];  //criou-se um vetor com n valores.
    int i;
    for(i=0; i<n; i++){
		printf("%f\n", vet[i]);
	}
}
