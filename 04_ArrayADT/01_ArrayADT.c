#include <features.h>
#include <stdio.h>
#include <stdlib.h>

struct Array
{
	int *A;
	int size;
	int length;
};

struct Array *CreateArray(int size, int length)
{
	struct Array *arr;
	if (length <= size)
	{
		arr = (struct Array *)malloc(sizeof(struct Array));
		arr->length = length;
		arr->size = size;
		arr->A = (int *)malloc(size * sizeof(int));
	}
	else
	{
		printf("Insufficient size, size must be greater or equals than lenght\n");
	}
	return arr;
}

void FillArray(struct Array *arr)
{
	int i;
	printf("Enter all elements\n");
	for (i = 0; i < arr->length; i++)
	{
		printf("Array[%d] = ", i);
		scanf("%d", &arr->A[i]);
	}
}

void Display(struct Array arr)
{
	int i;
	printf("Elements are\n[ ");
	for (i = 0; i < arr.length; i++)
		printf("%d ", arr.A[i]);
	printf("]\n");
}

void Append(struct Array *arr, int x)
{
	if (arr->length < arr->size)
		arr->A[arr->length++] = x;
	else
		printf("No sufficient size (Array size: %d)\n", arr->size);
}

void Insert(struct Array *arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
	else
		printf("Length out of range (Array length: %d)\n", arr->length);
}

int Delete(struct Array *arr, int index)
{
	int x = 0, i;
	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for (i = index; i < arr->length - 1; i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
		return x;
	}
	else
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
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
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
	int l = 0, mid, h = arr.length - 1;

	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr.A[mid])
			return mid;
		else if (key < arr.A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	return -1;
}

void Set(struct Array *arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
		arr->A[index] = x;
}

int Max(struct Array arr)
{
	int max = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
			max = arr.A[i];
	}
	return max;
}

int Min(struct Array arr)
{
	int min = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
			min = arr.A[i];
	}
	return min;
}

int Sum(struct Array arr)
{
	int s = 0;
	int i;
	for (i = 0; i < arr.length; i++)
		s += arr.A[i];
	return s;
}

float Avg(struct Array arr)
{
	return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array *arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
		swap(&arr->A[i], &arr->A[j]);
}

void InsertSort(struct Array *arr, int x)
{
	int i = arr->length - 1;
	if (arr->length == arr->size)
		return;
	while (arr->A[i] > x)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;
}

int isSorted(struct Array arr)
{
	int i;
	for (i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
			return 0;
	}
	return 1;
}

void Rearrange(struct Array *arr)
{
	int i, j;
	i = 0;
	j = arr->length - 1;
	while (i < j)
	{
		while (arr->A[i] < 0)
			i++;
		while (arr->A[j] >= 0)
			j--;
		if (i < j)
			swap(&arr->A[i], &arr->A[j]);
	}
}

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

	arr3->length = arr1->length + arr2->length;
	arr3->size = arr3->length;

	arr3->A = (int *)malloc(arr3->size * sizeof(int));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}

	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	for (; j < arr2->length; j++)
		arr3->A[k++] = arr1->A[j];

	return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

	arr3->size = arr1->length + arr2->length;

	arr3->A = (int *)malloc(arr3->size * sizeof(int));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			arr3->A[k++] = arr2->A[j++];
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}

	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	for (; j < arr2->length; j++)
		arr3->A[k++] = arr1->A[j];

	arr3->length = k;

	return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

	arr3->size = (arr1->length + arr2->length / 2) + 1;

	arr3->A = (int *)malloc(arr3->size * sizeof(int));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}

	arr3->length = k;

	return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

	arr3->size = arr1->length + arr2->length;

	arr3->A = (int *)malloc(arr3->size * sizeof(int));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else
		{
			i++;
			j++;
		}
	}

	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	arr3->length = k;

	return arr3;
}

int main()
{
	struct Array arr1;
	int ch;
	int x, index;
	printf("Enter Size of Array: ");
	scanf("%d", &arr1.size);
	arr1.A = (int *)malloc(arr1.size * sizeof(int));
	arr1.length = 0;

	do
	{
		printf("\n\nMenu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Sum\n");
		printf("5. Display\n");
		printf("6.Exit\n");
		printf("enter you choice ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("Enter an element and index: ");
			scanf("%d%d", &x, &index);
			Insert(&arr1, index, x);
			break;
		case 2:
			printf("Enter index: ");
			scanf("%d", &index);
			x = Delete(&arr1, index);
			printf("Deleted Element is %d\n", x);
			break;
		case 3:
			printf("Enter element to search: ");
			scanf("%d", &x);
			index = LinearSearch(&arr1, x);
			printf("Element index %d", index);
			break;
		case 4:
			printf("Sum is %d\n", Sum(arr1));
			break;
		case 5:
			Display(arr1);
		}
	} while (ch < 6);

	//int size;
	//int length;

	// Create the Array 1
	//printf("Enter the size of the array 1: ");
	//scanf("%d", &size);
	//printf("Enter the length of the array 1: ");
	//scanf("%d", &length);
	//struct Array arr1 = *CreateArray(length, length);
	//FillArray(&arr1);

	// Create the Array 2
	//printf("Enter the length of the array 2: ");
	//scanf("%d", &length);
	//struct Array arr2 = *CreateArray(length, length);
	//FillArray(&arr2);

	//struct Array *arr3;

	/*
	// Append
	printf("Appending 1 value\nEnter the value: ");
	int x;
	scanf("%d", &x);
	Append(&arr, x);
	Display(arr);

	// Insert
	int y;
	printf("Inserting 1 value\nEnter the value: ");
	scanf("%d", &x);
	printf("Enter the index: ");
	scanf("%d", &y);
	Insert(&arr, y, x);
	Display(arr);

	// Delete
	printf("Deleting value at index 2: %d\n", Delete(&arr, 2));
	Display(arr);

	// Linear Search
	printf("Searching for 3: %d\n", LinearSearch(&arr, 3));
	Display(arr);

	// Binary Search
	printf("Searching for 3: %d\n", BinarySearch(arr, 3));

	// Get
	printf("Get(1) ->%d\n",Get(arr, 1));

	// Set
	printf("Set(0,9)");
	Set(&arr, 0, 9);
	Display(arr);

	// Max
	printf("Max ->%d\n",Max(arr));

	// Min
	printf("Min ->%d\n",Min(arr));

	// Sum
	printf("Sum ->%d\n",Sum(arr));

	// Avg
	printf("Avg ->%f\n",Avg(arr));

	// Reverse
	Reverse(&arr);
	Display(arr);

	// Insert sort
	InsertSort(&arr, 7);
	Display(arr);

	// Is sorted
	printf("Is sorted: %d\n", isSorted(arr));

	// Rearrange
	Rearrange(&arr);
	Display(arr);

	// Merge
	arr3 = Merge(&arr1, &arr2);
	Display(*arr3);

	// Union
	arr3=Union(&arr1, &arr2);
	Display(*arr3);

	// Intersection
	arr3=Intersection(&arr1, &arr2);
	Display(*arr3);

	// Difference
	arr3=Difference(&arr1, &arr2);
	Display(*arr3);
	*/

	return 0;
}
