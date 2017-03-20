#include <stdlib.h>

int partition(int* arr, int lo, int hi){
	if(lo<hi){
		int pivot = hi;
		int pivotVal = arr[pivot];
		int i=lo-1, j=lo, tmp, x;
		for(x=lo;x<hi;x++){
			if(arr[j]<=pivotVal){
				i++;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
		tmp = arr[i];
		arr[i] = pivotVal;
		arr[pivot] = tmp;
		return i;
	}
	else if(lo==hi){
		return lo;
	}
}

void quickSort(int* arr, int start, int end){
	if(start<end){
		int part = partition(arr, start, end);
		quickSort(arr, start, part-1);
		quickSort(arr, part+1, end);
	}
}

int main(){
	int n_elem, elem;
	printf("Enter number of elements\n");
	scanf("%d", &n_elem);
	int *arr = (int *)malloc(n_elem*sizeof(int));
	printf("Enter the elements one per line\n");
	for(elem=0; elem<n_elem; elem++){
		scanf("%d", &arr[elem]);
	}
	quickSort(arr, 0, n_elem-1);
	for(elem=0; elem<n_elem; elem++){
		printf("%d", arr[elem]);
	}
	printf("\n");
}