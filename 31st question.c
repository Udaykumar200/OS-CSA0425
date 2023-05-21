#include <stdio.h>
#include <stdlib.h>


void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


float calculateAverageHeadMovement(int queue[], int n, int head) {
    int i, current, distance = 0;
    int seek_count = 0;
    int direction = 1; 

    
    sort(queue, n);

    
    for (i = 0; i < n; i++) {
        if (queue[i] == head)
            break;
    }
    current = i;


    while (direction == 1 ? current < n : current >= 0) {
        distance += abs(queue[current] - head);
        head = queue[current];
        seek_count++;
        current += direction;

        
        if (direction == 1 && current == n) {
            current = 0;
            direction = -1;
        }
        else if (direction == -1 && current < 0) {
            current = n - 1;
            direction = 1;
        }
    }

    return (float)distance / seek_count;
}

int main() {
    int n, head, i;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));

    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    float avg_head_movement = calculateAverageHeadMovement(queue, n, head);
    printf("Average head movement: %.2f\n", avg_head_movement);

    free(queue);

    return 0;
}
