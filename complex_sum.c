#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

void multiplyComplex(Complex *c1, Complex *c2, Complex *result) {
    result->real = (c1->real * c2->real) - (c1->imag * c2->imag);
    result->imag = (c1->real * c2->imag) + (c1->imag * c2->real);
}

int main() {
    int choice;
    Complex c1, c2, result;

    printf("Complex Number Operations\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter first complex number (real and imaginary): ");
    scanf("%f %f", &c1.real, &c1.imag);

    printf("Enter second complex number (real and imaginary): ");
    scanf("%f %f", &c2.real, &c2.imag);

    switch (choice) {
        case 1:
            result = addComplex(c1, c2);
            printf("Result: %.2f + %.2fi\n", result.real, result.imag);
            break;
        case 2:
            multiplyComplex(&c1, &c2, &result);
            printf("Result: %.2f + %.2fi\n", result.real, result.imag);
            break;
        default:
            printf("Invalid choice\n");
    }
}