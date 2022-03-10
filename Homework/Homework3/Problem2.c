/*  Jonathan Carreiro
    Homework 3
    10/29/20*/

#include <stdio.h>

// Constants for array dimensions
#define SZSUB 3
#define SZSTUD 2
#define SZEX 5

// Prototype definitions for functions
double avgAll(int sub1[SZSTUD][SZEX], int sub2[SZSTUD][SZEX], int sub3[SZSTUD][SZEX]);
double avgSubGrd(int student[SZEX]);
double allSubStudAvg (int score1, int score2, int scor3, int score4, int score5);

int main(){
    double subjectsTotal = 0.0;
    double subjectsAvg;
    /*  3d array that will hold class data
        Each plane represents a subject (subject 1, 2, etc.), each row represents a student, each column represents an exam score 
        [0][0][0] = 20 means that for subject 1, student 1 got a 20 on the first exam)*/
    int classData[SZSUB][SZSTUD][SZEX] = 
        {
            { // Plane 0 (subject 1)
                {20, 40, 60, 80, 100}, // Row 0 (student 1)
                {60, 70, 80, 90, 100}  // Row 1 (student 2)
            },

            { // Plane 1 (subject 2)
                {30, 45, 60, 75, 90},  // Row 0 (student 1)
                {40, 55, 70, 85, 100}  // Row 1 (student 2)
            },

            { // Plane 2 (subject 3)
                {75, 80, 85, 90, 95},  // Row 0 (student 1)
                {0, 30, 60, 90, 100}   // Row 1 (student 2)
            }
        };

    printf("\nAverage of all grades is: %0.2lf\n\n", avgAll(classData[0], classData[1], classData[2]));
    
    // Nested loop structure that prints the test data for each subject
    for(int i = 0; i < 3; i++){
        printf("Subject %d:\n", i + 1);
        for(int j = 0; j < 2; j++){
            printf("\tAverage of student %d: %0.2lf\n", j + 1, avgSubGrd(classData[i][j]));
        }
    }

    // Nested loop structure that prints the subject data for each student
    for(int i = 0; i < 2; i++){
        subjectsTotal = 0.0;
        printf("\nStudent %d's data:\n", i + 1);
        // Gets student's average in each subject and adds it to a total
        for(int j = 0; j < 3; j++){
            printf("\tAverage in subject %d: %0.2lf\n", j + 1, allSubStudAvg(classData[j][i][0], classData[j][i][1], classData[j][i][2], classData[j][i][3], classData[j][i][4]));
            subjectsTotal += allSubStudAvg(classData[j][i][0], classData[j][i][1], classData[j][i][2], classData[j][i][3], classData[j][i][4]);
        }

        // Gets average for all subjects using the total
        subjectsAvg = subjectsTotal / 3.0;
        printf("\tAverage between all three subjects: %0.2lf", subjectsAvg);
    }

    printf("\n");
    
    return 0;
}


/*  This function takes the average of all grades in the classData array
    The parameters are each plane of the array. This allows for easy access to all grades within a plane
    The return is the average as a double so that it doesnt get truncated */
double avgAll(int sub1[SZSTUD][SZEX], int sub2[SZSTUD][SZEX], int sub3[SZSTUD][SZEX]){
    double avg;
    int tot1 = 0, tot2 = 0, tot3 = 0;

    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 5; j ++){
            tot1 += sub1[i][j];
            tot2 += sub2[i][j];
            tot3 += sub3[i][j];
        }
    }

    avg = (double)(tot1 + tot2 + tot3) / 30.0;

    return avg;
}


/*  This function takes the average grade for a students exam scores in one subject
    It will be used in conjuction with a loop to get the average score for all subjects
    The parameter is a row of the classData array. This allows for access to all grades for a student in a subject
    The return is the average as a double so that it doesnt get truncated*/
double avgSubGrd(int grades[SZEX]){
    double avg;
    int total = 0;

    for(int i = 0; i < SZEX; i++){
        total += grades[i];
    }

    avg = (double)total / 5.0;

    return avg;
}

/*  This function does the same thing as the function above it
    It will be used in conjunction with loops to get the average across all subjects for a student
    The parameters are individual scores in a subject. Used for calculation of average
    The return is the average as a double so that it doesnt get truncated*/
double allSubStudAvg (int score1, int score2, int score3, int score4, int score5){
    double avg;

    avg = (score1 + score2 + score3 + score4 + score5) / 5.0;

    return avg;
}