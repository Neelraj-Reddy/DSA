#include <stdio.h>

void print(int* frame_array, int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        printf("%d ", frame_array[i]);
    }
    printf("\n");
}

int search(int* frame_array, int value, int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frame_array[i] == value) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, frames;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int frame_array[frames], page_array[n];

    for (int i = 0; i < n; i++) {
        printf("Enter page %d: ", i);
        scanf("%d", &page_array[i]);
    }

    for (int i = 0; i < frames; i++) {
        frame_array[i] = -1;
    }

    int nose = 0;
    int curr_index = 0;

    for (int i = 0; i < n; i++) {
        if (!search(frame_array, page_array[i], frames)) {
            frame_array[curr_index % frames] = page_array[i];
            curr_index += 1;
            nose += 1;
        }
        printf("%d \n",page_array[i]);
        print(frame_array, frames);
    }

    printf("Total Page Faults: %d\n", nose);

    return 0;
}
