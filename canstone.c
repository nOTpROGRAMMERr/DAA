#include <stdio.h>
#include <stdlib.h>


struct Animal {
    char name[50];
    int age;
};

void initAnimal(struct Animal* animal, const char* name, int age) {
    sprintf(animal->name, "%s", name);
    animal->age = age;
}


void displayAnimal(struct Animal* animal) {
    printf("Name: %s\n", animal->name);
    printf("Age: %d\n", animal->age);
}



struct Dog {
    struct Animal animal;  // Inheriting from Animal
    char breed[50];
};

// Function to initialize derived class
void initDog(struct Dog* dog, const char* name, int age, const char* breed) {
    initAnimal(&dog->animal, name, age);  // Initialize base class part
    sprintf(dog->breed, "%s", breed);
}

// Function to display derived class data
void displayDog(struct Dog* dog) {
    displayAnimal(&dog->animal);  // Display base class data
    printf("Breed: %s\n", dog->breed);
}


int main(){
    // int a= 10;
    // printf("%d",a);
    // char name[] = "Rish";
    // printf(" %s", name);
    // int arr[] = {1,2,3,4,5,6};

    // int n = sizeof(arr) / sizeof(arr[0]);

    // printf("\nArray elements: ");
    // for(int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    
    // // Calculate sum of array
    // int sum = 0;
    // for(int i = 0; i < n; i++) {
    //     sum += arr[i];
    // }
    // printf("Sum of array elements: %d\n", sum);
    
    // // Calculate average
    // float avg = (float)sum / n;
    // printf("Average of array elements: %.2f\n", avg);


    // int t = 3;
    // int s = 9;
    // t = t+s;
    // s = t-s;
    // t = t-s;
    // printf("T = %d",t);
    // printf("\nS = %d",s);
    // Create and initialize a Dog
    struct Dog myDog;
    initDog(&myDog, "Max", 5, "Golden Retriever");
    
    // Display the dog's information
    printf("\nDog Information:\n");
    displayDog(&myDog);
}