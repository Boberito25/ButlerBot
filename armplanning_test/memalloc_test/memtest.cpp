#include <stdio.h>
typedef struct data{
	double theta[3];
	double value;
	double state[4];
} data;
int main(){
	data*** d = new data**[100];
	for(int i = 0; i < 100; i++){
		d[i] = new data*[100];
		for(int j = 0; j < 100; j++){
			d[i][j] = new data[100];
			
		}
	}
}