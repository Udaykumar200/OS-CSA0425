#include <stdio.h>
#include <stdlib.h>
void sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int scan(int *arr, int n, int head, char direction) {
    int i, totalHeadMovement = 0;
    int index = -1;

    
    sort(arr, n);
    
    for (i = 0; i < n; i++) {
        if (arr[i] >= head) {
            index = i;
            break;
        }
    }

    
    if (direction == 'l') {
        for (i = index - 1; i >= 0; i--) {
            printf("%d -> ", arr[i]);
            totalHeadMovement += abs(head - arr[i]);
            head = arr[i];
        }

        
        printf("0 -> ");
        totalHeadMovement += head;

    
        for (i = index; i < n; i++) {
            printf("%d -> ", arr[i]);
            totalHeadMovement += abs(head - arr[i]);
            head = arr[i];
        }
    }

    
    else if (direction == 'r') {
        for (i = index; i < n; i++) {
            printf("%d -> ", arr[i]);
            totalHeadMovement += abs(head - arr[i]);
            head = arr[i];
        }

        
        printf("199 -> ");
        totalHeadMovement += (199 - head);

    
        for (i = index - 1; i >= 0; i--) {
            printf("%d -> ", arr[i]);
            totalHeadMovement += abs(head - arr[i]);
            head = arr[i];
        }
    }

    return totalHeadMovement;
}

int main() {
    int n, head, i;
    char direction;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int *requests = (int*)malloc(n * sizeof(int));

    printf("Enter the requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the direction (l for left, r for right): ");
    scanf(" %c", &direction);

    printf("Sequence of head movements:\n");
    int totalHeadMovement = scan(requests, n, head, direction);
    printf("\n\nTotal head movement = %d\n", totalHeadMovement);
    printf("Average head movement = %.2f\n", (float)totalHeadMovement / n);

    free(requests);
    return 0;
}
