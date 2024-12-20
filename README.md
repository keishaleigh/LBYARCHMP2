# LBYARCHMP2

## Project Specifications

Introduction

A grayscale image is internally represented as a 2 dimensional array. Size is defined by the number of
pixels in a row (width), and number of pixels in a column (height). Each cell represents the pixel value.
Pixel values in grayscale are represented as white, black, and shades of gray using different numerical data 
type representation depending on the library used.

Some Image Processing Libraries represent grayscale images as having double float based pixel
values between 0 to 1: 0 for black, 1 for white, 0.25 lighter gray, 0.75 darker gray, and all other gray
values in between.

Image =
0.25, 0.35, 0.45, 0.33
0.55, 0.65, 0.75, 0.33
0.85, 0.95, 0.15, 0.33

Some Libraries represent using 8 bit unsigned integer. 0 for black, 255 for white, 64 lighter gray, 191
darker gray, and all other gray values in between.

Image =
64, 89, 114, 84
140, 166, 191, 84
216, 242, 38, 84

To enable using different image processing libraries simultaneously, conversion from one format 
to theother has to be done. Perform Mapping from double precision float based grayscale to uint8
based integer representation. Each pixel is calculated using ratio and proportion equation

(f/i) = (1/255)

Where f is the double float based pixel value and i is the integer based pixel value.

Task

Implement a program that converts the grayscale image representation from float based to integer
based using C and x86 assembly language. Implement the function imgCvtGrayDoubleToInt().

- Required to use functional scalar SIMD registers
- Required to use functional scalar SIMD floating-point instructions

Input: height, width, double float pixel values

Output: Integer pixel values

# Execution Time Analysis of the Performance

## Execution Time Results

Based on the specifications, the timing is measured only for input image sizes with dimensions `width*height = 10*10, 100*100, and 1000*1000`. If a 1000*1000 size is not feasible, it may be reduced to a size that the machine can support. Additionally, we have included results for 4x3 and 3x4 image sizes to provide more sample data for performance analysis. The table below shows the execution time (in seconds) for the conversion function `imgCvtGrayDoubleToInt()` across different image sizes. Each result is averaged over 30 runs:

| **Image Size**      | **Execution Time (seconds)** |
|----------------------|------------------------------|
| 10x10               | 0.000000                    |
| 100x100             | 0.000533                    |
| 1000x1000           | 0.010300                    |
| 4x3                 | Timing not recorded for this image size                    |
| 3x4                 | Timing not recorded for this image size                   |
---

## Analysis

1. **Efficiency**: 
   - The program efficiently handles small images, with negligible execution time for sizes like 10x10.
   - For larger images like 1000x1000, the function still performs well, taking just approximately 0.01 seconds on average.

2. **Scaling Behavior**:
   - The execution time increases proportionally with the image size, demonstrating consistent linear scaling with the number of pixels.

3. **Use Case**:
   - The function is suitable for real-time or near-real-time processing of moderate-sized images.
   - It can scale to larger datasets for batch processing scenarios.

---

## Program Output 

The image below demonstrates the program's output for a 3x4 and 10x10 image. The input consists of randomly generated grayscale pixel values in the range [0.0, 1.0], and the expected output is the corresponding integer values. The output aligns with the correctness check, as the conversion accurately scales the input values to the expected range, preserving the relative intensities of the pixels.

<p align="center">
  <img src="Sample.png" width="400"/>
</p>

<p align="center">
  <img src="Sample2.png" width="400"/>
</p>

---

## Usage

To use the program:
1. Clone the repository.
2. Run the bat file (run.bat) in the command line to generate random grayscale values, convert them to integers, and measure execution time.

