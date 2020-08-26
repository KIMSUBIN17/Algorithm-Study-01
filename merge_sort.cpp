#include<stdio.h>

int number = 8;
int sorted[8];  //정렬된 결과담을 배열(정렬 배열은 반드시 전역변수로)

//시작 중간  끝 
void merge(int a[], int m, int middle, int n ){  ////새롭게 만들어지는 배
	int i = m;
	int j = middle + 1;
	int k = m;  //i랑 동일한 위치 가짐
	
	//작은 순서대로 배열에 삽입
	while(i <= middle  && j <= n){
		if(a[i] <= a[j]){
			sorted[k] = a[i];
			i++;
		} else{
			sorted[k] = a[j];
			j++;
		}
		k++;
	} 
	//남은 데이터도 삽입
	if(i > middle) {   //i가 먼저 끝난 경우 -> 남은 j값 넣어주기 
		for(int t = j; t <=n; t++){
			sorted[k] = a[t];
			k++;
		}
		
	} else {
		for(int t = i; t <= middle; t++){
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열을 삽입 
	for(int t = m ; t<= n; t++){
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	// 이외의 경우는 크기가 1개인 경우 
	if(m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {
	int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};
	mergeSort(array, 0, number - 1);
	for(int i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}
} 
