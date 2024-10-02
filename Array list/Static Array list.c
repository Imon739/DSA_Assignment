#include <stdio.h>

int main() {
    int pos, i, val, choice, size, flag = 0, len= 0;

    printf("Enter the maximum size of the array (up to 10): ");
    scanf("%d", &size);

    if (size > 10 || size <= 0) {
        printf("Invalid size. Size must be between 1 and 10.\n");
        return 1;
    }

    int arr[size];

    for (i = 0; i < size; i++) {
        arr[i] = 0;
    }

    while (1) {
       err:
       printf("\n1.Print Entire array (index 0 to len) \n2.Access a specific index\n3.Update the value of a specific index");
       printf("\n4.Linear Search\n5.Insert new value at a specific index \n6.Delete from an index \n7.Delete nth occurrence of a value ");
       printf("\n8.Bubble Sort the existing array \n9.Binary Search on the array \n10.find minimuum \n11.find median \n0.EXIT");
       printf("\n\nEnter choice: ");
       scanf("%d", &choice);

       if(choice == 1){
            for (i = 0; i < size; i++){
                printf("%d ",arr[i]);
            }

       }else if(choice == 2) {
            printf("\nEnter the index to print: ");
            scanf("%d", &pos);
            printf("\nThe val at index %d: %d", pos, arr[pos]);

       }else if (choice == 3){
            printf("\nEnter the index to update: ");
            scanf("%d", &pos);
            printf("\nEnter the new value: ");
            scanf("%d", &val);
            arr[pos] = val;
            printf("The new val at index %d: %d", pos, arr[pos]);

        }else if (choice == 4){

            printf("Enter the value you want to search: \n");
            scanf("%d", &val);

            for (i = 0; i < size; i++) {
                if (arr[i] == val) {
                    flag++;
                }
            }
            if (flag == 0) {
                printf("Not found\n");
            }else{
                printf("%d found at index %d\n", val, i);
            }
        }else if (choice == 5){

            printf("Enter the position where you want to insert : ");
            scanf("%d", &pos);

            if (pos < 0 || pos > len || len ==size) {
                printf("Invalid position\n");
                break;
            }

            printf("The value you want to insert: ");
            scanf("%d", &val);

            if (pos == len) {
                arr[len] = val;
            }
            else{
                for (int i = len; i > pos; i--) {
                    arr[i] = arr[i-1];
                }
                    arr[pos] = val;
            }
                len++;

            printf("\nCurrent arraylist: \n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }

        }else if (choice == 6) {
            printf("Current array: \n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            int pos;
            printf("The Position of Element/Value you want to delete: ");
            scanf("%d", &pos);
            if (pos > size) {
                printf("Index out of bounds. Give choice again\n");
                goto err;
            }

            else{
                for(int i= pos; i<size-1;i++){
                    arr[i]= arr[i+1];
                }
            }
            printf("Updated array: \n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");

        }else if (choice == 7){
            printf("Enter the value you want to delete: ");
            scanf("%d", &val);
            printf("Enter the occurrence you want to delete: ");
            int n, count = 0;
            scanf("%d", &n);

            for (i = 0; i < size; i++) {
                if (arr[i] == val) {
                    count++;
                    if (count == n) {
                        for (int j = i; j < size-1; j++) {
                            arr[j] = arr[j+1];
                        }
                        arr[size-1] = 0;
                        len--;
                        printf("Deleted %d occurrence of value %d\n", n, val);
                        break;
                    }
                }
            }
            if (count < n) {
                printf("The %d occurrence of value %d not found\n", n, val);
            }

            printf("Updated array: \n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");


        }else if(choice == 8){
            int j, temp;
            for(i=0;i<size-1;i++){
                for(j=0;j<size-1;j++){
                    if(arr[j] > arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            printf("After Bubble sort : \n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");

        }else if(choice == 9){

            int pos = -1;
            int low = 0, high = size - 1, middle;

            printf("Enter the Search variable : ");
            scanf("%d", &val);

            while(low <= high){
                middle = (low + high) / 2;
                if (val == arr[middle]){
                    pos = middle;
                    break;
                } else if (val < arr[middle]){
                    high = middle - 1;
                } else {
                    low = middle + 1;
                }
            }

            if(pos == -1)
                printf("The search variable is not in the array\n");
            else
                printf("The search variable %d is at index %d\n", val, pos);




        }else if(choice == 10){
            int j, temp, min;
            for(i=0;i<size-1;i++){
                for(j=0;j<size-1;j++){
                    if(arr[j] > arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }

            min = arr[0];
            printf("minimum element of the array is %d ",arr[0]);



        }else if(choice == 11){
            int j, temp;
            for(i=0;i<size-1;i++){
                for(j=0;j<size-1;j++){
                    if(arr[j] > arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }

            if(size % 2 == 0){
                int middle1 = size / 2;
                int middle2 = middle1 - 1;
                double median = (arr[middle1] + arr[middle2]) / 2;

                printf("median is %d ",median);
            }
            if(size % 2  == 1){
                int middle = (size - 1) / 2;
                int median = arr[middle];

                printf("median is %d ",median);
            }
        }


        else if (choice == 0) {
            printf("Thank you\n");
            break;

        }else {
            printf("Invalid choice. Select again: \n");
        }
    }

    return 0;
}
