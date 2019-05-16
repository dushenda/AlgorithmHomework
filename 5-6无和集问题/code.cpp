#include<stdio.h>

#define N 100

int F[N][N],answer[N][N];

int n,maxValue; 

int judge(int t,int k){
	int i,j;
	for(i=1;i<=F[k][0];i++){
		for(j=i+1;j<=F[k][0];j++){
			if(F[k][i]+F[k][j]==t)
                return 0;
		}
	}
	return 1;
	
}

void dfs(int t){
	int i,j;
	if(t>maxValue){
		for(i=0;i<n;i++){
			for(j=0;j<=F[i][0];j++){  
				answer[i][j] = F[i][j];
			}
		}
		maxValue = t;
	}
	
	for(i=0;i<n;i++){
		F[i][F[i][0]+1]=t;
		if(judge(t,i)){
			F[i][0]+=1;
			dfs(t+1);
			F[i][0]-=1;
		}
	} 
}

void output(){
	int i,j;
	printf("%d\n",maxValue-1);
	for(i=0;i<n;i++){
		for(j=1;j<=answer[i][0];j++){
			printf("%d\t",answer[i][j]);
		}
		printf("\n");
	} 
}

int main(){
	
	scanf("%d",&n);
	maxValue = 0;
	dfs(1);
	output();
	return 0;
}
