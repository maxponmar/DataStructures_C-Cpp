#include <stdio.h>
#include <stdlib.h>

struct Array
{
	int *A;
	int size;
	int length;
};

void Display(struct Array arr)
{
	int i;
	printf("Elements are\n[ ");
	for (i=0; i<arr.length; i++)
		printf("%d ", arr.A[i]);
	printf("]\n");

}

void Append(struct Array *arr, int x)
{
	if(arr->length<arr->size)
		arr->A[arr->length++]=x;
	else
		printf("No sufficient size (Array size: %d)\n", arr->size);
}

void Insert(struct Array *arr, int index, int x)
{
	int i;
	if(index>=0 && index<=arr->length)
	{
		for(i=arr->length;i>index;i--)
			arr->A[i]=arr->A[i-1];
		arr->A[index]=x;
		arr->length++;
	}
	else
		printf("Length out of range (Array length: %d)\n", arr->length);

}

int Delete(struct Array *arr, int index)
{
	int x=0, i;
	if (index>=0 && index<arr->length)
	{
		x = arr->A[index];
		for(i=index;i<arr->length-1;i++)
			arr->A[i]=arr->A[i+1];
		arr->length--;
		return x;
	} else
		printf("Length out of range (Array length: %d)\n", arr->length);
	return 0;
}

void swap(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

int LinearSearch(struct Array *arr, int key)
{
	int i;
	for(i=0;i<arr->length; i++)
	{
		if(key==arr->A[i])
		{
			// Using move to head
			/*
			swap(&arr->A[i], &arr->A[0]);
			return 0;
			*/
			return i;
		}
	}
	return -1;
}

int BinarySearch(struct Array arr, int key)
{
	int l=0, mid, h=arr.length-1;

	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr.A[mid])
			return mid;
		else if(key<arr.A[mid])
			h=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int main()
{
	struct Array arr;
	int n,i;

	// Create the Array
	printf("Enter the size of an array: ");
	scanf("%d", &arr.size);
	arr.A =(int *)malloc(arr.size*sizeof(int));
	arr.length=0;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter all elements\n");
	for(i=0;i<n;i++)
	{
		printf("Element %d: ", i);
		scanf("%d", &arr.A[i]);
	}
	arr.length=n;

	// Display the Array
	Display(arr);
	/*
	// Append
	printf("Appending 1 value\nEnter the value: ");
	int x;
	scanf("%d", &x);
	Append(&arr, x);
	Display(arr);
	*/

	// Insert
	/*
	int y;
	printf("Inserting 1 value\nEnter the value: ");
	scanf("%d", &x);
	printf("Enter the index: ");
	scanf("%d", &y);
	Insert(&arr, y, x);
	Display(arr);
	*/

	// Delete
	/*
	printf("Deleting value at index 2: %d\n", Delete(&arr, 2));
	Display(arr);
	*/

	// Linear Search
	/*printf("Searching for 3: %d\n", LinearSearch(&arr, 3));
	Display(arr);*/

	// Binary Search
	printf("Searching for 3: %d\n", BinarySearch(arr, 3));

	return 0;
}
