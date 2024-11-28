/** 
* Martinez, Azeliah & Villanueva, Keisha
* LBYARCH S17
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayDoubleToInt(double *input, int *output, int width, int height);

void printImage(int *image, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) { 
        for (j = 0; j < height; j++) {
            printf("%d ", image[i * height + j]);
        }
        printf("\n");
    }
}

void printRandomValues(double *inputImage, int width, int height) {
    printf("Randomly generated pixel values:\n");
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            printf("%.2f ", inputImage[i * height + j]);
        }
        printf("\n");
    }
}

int main() {
    int width, height, i, j;

    printf("Enter width (# of rows) of the image: ");
    scanf("%d", &width);
	printf("Enter height (# of columns) of the image: ");
	scanf("%d", &height);

    // allocate memory for input and output images
    double *inputImage = (double *)malloc(width * height * sizeof(double));
    int *outputImage = (int *)malloc(width * height * sizeof(int));

    if (inputImage == NULL || outputImage == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    printf("Enter the pixel values (0.0 to 1.0):\n");
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            scanf("%lf", &inputImage[i * height + j]);
        }
    }

	
    // calculate the time taken by imgCvtGrayDoubleToInt() if w*h is 10*10 or 100*100 or 1000*1000
    if (width * height == 10 * 10 || width * height == 100 * 100 || width * height == 1000 * 1000) {
        int repeatCount = 30;  
        clock_t t = clock();
        for (i = 0; i < repeatCount; i++) {
            imgCvtGrayDoubleToInt(inputImage, outputImage, width, height);
        }
        t = clock() - t;

        double time_taken = ((double)t) / CLOCKS_PER_SEC / repeatCount;

        // prints the converted image
        printf("\nConverted Image:\n");
        printImage(outputImage, width, height);

        printf("\nimgCvtGrayDoubleToInt() took %f seconds to execute (average over %d runs)\n\n", time_taken, repeatCount);
    } else {
        // execute function once for unsupported sizes, but do not time it
        imgCvtGrayDoubleToInt(inputImage, outputImage, width, height);

        // prints the converted image
        printf("\nConverted Image:\n");
        printImage(outputImage, width, height);
        
        printf("\nTiming not recorded for this image size.\n\n");
    }

    return 0;
}