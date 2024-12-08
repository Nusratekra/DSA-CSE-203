#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int Uap_id[] = {2,2,2,0,1,2,2,5,1};
    int n = sizeof(Uap_id) / sizeof(Uap_id[0]);

    printf("Original Uap_id: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Uap_id[i]);
    }
    printf("\n");

    bubbleSort(Uap_id, n);

    printf("Uap_id in ascending order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Uap_id[i]);
    }
    printf("\n");

    return 0;
}
