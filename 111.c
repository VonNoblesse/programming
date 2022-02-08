#include<stdio.h>
#include<math.h>
#include<malloc.h>
void sort(double array[], int size);
int size(char *name);
int Marlboro(double *A,double *B, int N);
int size(char *name){
	double x;
	FILE *IN=NULL;
	int n=0;
	IN=fopen(name,"r");
	while(fscanf(IN,"%lf",&x)==1){
		++n;
	}
	fclose(IN);
	return n;
}
void sort(double array[], int size){
	double buffer;
	int i, j;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-1-i;j++){
			if(array[j]>=array[j+1]){
				buffer=array[j];
				array[j]=array[j+1];
				array[j+1]=buffer;
			}
		}
	}
}
int Marlboro(double *A,double *B, int N){
	double sim, buf=0;
	int i, k = 0;
	sim=A[1]-B[1];
	buf = sim;
	for(i=2;i<N-1;i++){
		sim = A[i]-B[i];
		if(sim<=0){
			return(-1);
		}
		else if(sim<buf){
			k=i;
			buf=sim;
		}
	}
	return(k);
}	
int main(void){
	FILE *INa;
	FILE *INb;
	FILE *OUT;
	double *A, *B, x, y;
	int N, M, i, k=0;
	INa=fopen("ina.txt","r");
	if(INa==NULL){
		printf("file ina.txt not found\n");
		return -1;
	}
	if(fscanf(INa,"%lf",&x)!=1){
		printf("Not enough numbers\n");
		return -1;
	}
	fclose(INa);
	INb=fopen("inb.txt","r");
	if(INb==NULL){
		printf("file inb.txt not found\n");
		return -1;
	}
	if(fscanf(INb,"%lf",&y)!=1){
		printf("Not enough numbers\n");
		return -1;
	}
	fclose(INb);
	N=size("ina.txt");
	M=size("inb.txt");
	if(M!=N){
		printf("the sizes of array are different\n");
		return -1;
	}
	A=(double*)malloc(N*sizeof(double));
	B=(double*)malloc(N*sizeof(double));
	INa=fopen("ina.txt","r");
	INb=fopen("inb.txt","r");
	for(i=0;i<N;i++){
	fscanf(INa,"%lf",&A[i]);
		}
	for(i=0;i<N;i++){
	fscanf(INb,"%lf",&B[i]);
		}
	fclose(INa);
	fclose(INb);
	sort(A,N);
	sort(B,N);
	k=Marlboro(A,B,N);
	printf("%d", k);
	return 0;
}