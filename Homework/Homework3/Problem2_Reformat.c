/*  Jonathan Carreiro
    Homework 3
    10/30/20*/

#include <stdio.h>

// Constants for array dimensions
#define SZSUB 3
#define SZSTUD 2
#define SZEX 5

// Prototype definitions for functions
double avgAll(int ex1[SZSTUD][SZSUB], int ex2[SZSTUD][SZSUB], int ex3[SZSTUD][SZSUB], int ex4[SZSTUD][SZSUB], int ex5[SZSTUD][SZSUB]);
double avgSubGrd(int score1, int score2, int score3, int score4, int score5);
double allSubStudAvg(int set1[SZSUB], int set2[SZSUB], int set3[SZSUB], int set4[SZSUB], int set5[SZSUB], int sub);

int main(){
    double subjectsTotal = 0.0;
    double subjectsAvg;
    /*  3d array that will hold class data
        Each plane represents an exam (exam 1, 2, etc.), each row represents a student, each column represents the exam score for a subject 
        [0][0][0] = 20 means that on exam 1 student 1 got a 20 for subject 1)*/
    int classData[SZEX][SZSTUD][SZSUB] = 
        {
            { // Plane 0 (exam 1)
                {20, 30, 75}, // Row 0 (student 1)
                {60, 40, 0}   // Row 1 (student 2)
            },

            { // Plane 1 (exam 2)
                {40, 45, 80},  // Row 0 (student 1)
                {70, 55, 30}   // Row 1 (student 2)
            },

            { // Plane 2 (exam 3)
                {60, 60, 85},  // Row 0 (student 1)
                {80, 70, 60}   // Row 1 (student 2)
            },

            { // Plane 3 (exam 4)
                {80, 75, 90}, // Row 0 (student 1)
                {90, 85, 90}  // Row 1 (student 2)
            },

            { // Plane 4 (exam 5)
                {100, 90, 95},   // Row 0 (student 1)
                {100, 100, 100}  // Row 1 (student 2)
            }
        };

        printf("\nAverage of all grades is: %0.2lf\n\n", avgAll(classData[0], classData[1], classData[2], classData[3], classData[4]));

        // Nested loop structure that prints the test data for each subject
        for(int i = 0; i < SZSUB; i++){
            printf("Subject %d:\n", i + 1);
            for( int j = 0; j < SZSTUD; j++){
                printf("\tAverage of student %d: %0.2lf\n", j + 1, avgSubGrd(classData[0][j][i], classData[1][j][i], classData[2][j][i], classData[3][j][i], classData[4][j][i]));
            }
        }

        printf("\n");

        // Nested loop structure that prints the subject data for each student
        for(int i = 0; i < SZSTUD; i++){
            subjectsTotal = 0.0;
            printf("Student %d's data:\n", i + 1);
            // Gets student's average in each subject and adds it to a total
            for(int j = 0; j < SZSUB; j++){
                printf("\tAverage in subject %d: %0.2lf\n", j + 1, allSubStudAvg(classData[0][i], classData[1][i], classData[2][i], classData[3][i], classData[4][i], j));
                subjectsTotal += allSubStudAvg(classData[0][i], classData[1][i], classData[2][i], classData[3][i], classData[4][i], j);
            }

            // Gets average for all subjects using the total
            subjectsAvg = subjectsTotal / 3.0;
            printf("\tAverage between all three subjects: %0.2lf\n", subjectsAvg);
        }

    return 0;
}

/*  This function takes the average of all grades in the classData array
    The parameters are each plane of the array. This allows for easy access to all grades within a plane
    The return is the average as a double so that it doesnt get truncated*/
double avgAll(int ex1[SZSTUD][SZSUB], int ex2[SZSTUD][SZSUB], int ex3[SZSTUD][SZSUB], int ex4[SZSTUD][SZSUB], int ex5[SZSTUD][SZSUB]){
    double avg;
    int total;

    for(int i = 0; i < SZSTUD; i++){
        for (int j = 0; j < SZSUB; j ++){
            total += ex1[i][j] + ex2[i][j] + ex3[i][j] + ex4[i][j] + ex5[i][j];
        }
    }

    avg = (double)total / 30.0;

    return avg;
}

/*  This function takes the average grade for a students exam scores in one subject
    It will be used in conjuction with a loop to get the average score for all subjects
    The parameters are invdiviual scores. This allows me to get scores from a single column across multiple planes
    The return is the average as a double so that it doesnt get truncated*/
double avgSubGrd(int score1, int score2, int score3, int score4, int score5){
    double avg;

    avg = (double)(score1 + score2 + score3 + score4 + score5) / 5.0;

    return avg;
}

/*  This function does the same thing as the function above it
    It will be used in conjunction with loops to get the average across all subjects for a student
    The parameters are rows of the classData array. This gives me acces to all three subjects at once and multiple planes through the use of multiple parameters
    The return is the average as a double so that it doesnt get truncated*/
double allSubStudAvg(int set1[SZSUB], int set2[SZSUB], int set3[SZSUB], int set4[SZSUB], int set5[SZSUB], int sub){
    double avg;
    int total = 0;

    total += set1[sub];
    total += set2[sub];
    total += set3[sub];
    total += set4[sub];
    total += set5[sub];

    avg = (total) / 5.0;

    return avg;
}