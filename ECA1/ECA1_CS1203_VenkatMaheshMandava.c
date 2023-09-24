#include <stdio.h>

// Function to print the current permutation
void printPermutation(int permutation[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", permutation[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");
}

// Function to generate and print all permutations of 1 to n
void generatePermutations(int n) {
    int permutation[n];
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    while (1) {
        printPermutation(permutation, n);

        // Find the largest index j such that permutation[j] < permutation[j+1]
        int j = n - 2;
        while (j >= 0 && permutation[j] >= permutation[j + 1]) {
            j--;
        }

        // If no such index is found, we have generated all permutations
        if (j < 0) {
            break;
        }

        // Find the largest index l such that permutation[j] < permutation[l]
        int l = n - 1;
        while (permutation[j] >= permutation[l]) {
            l--;
        }

        // Swap permutation[j] and permutation[l]
        int temp = permutation[j];
        permutation[j] = permutation[l];
        permutation[l] = temp;

        // Reverse the sub-array after index j
        int left = j + 1;
        int right = n - 1;
        while (left < right) {
            temp = permutation[left];
            permutation[left] = permutation[right];
            permutation[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n (1 <= n <= 8): ");
    scanf("%d", &n);

    if (n < 1 || n > 8) {
        printf("Invalid input. n must be between 1 and 8.\n");
        return 1;
    }

    printf("Permutations of 1 to %d:\n", n);
    generatePermutations(n);

    return 0;
}

