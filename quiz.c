#include <stdio.h>

void askQuestion(int questionNumber, const char* question, const char* options[], int correctAnswer, int *score) {
    int answer;
    
    printf("%d) %s\n", questionNumber, question);
    for(int i = 0; i < 4; i++) {
        printf("%d) %s\n", i + 1, options[i]);
    }
    
    printf("Enter Your Answer: ");
    scanf("%d", &answer);
    
    if(answer == correctAnswer) {
        printf("Correct Answer\n");
        *score = 5;
    } else {
        printf("Wrong Answer\n");
        *score = 0;
    }
    
    printf("You have scored %d points\n\n", *score);
}

int main() {
    int i;
    int totalScore = 0;
    
    printf("    Welcome to the Game\n\n");
    printf("> Press 1 to start the game\n");
    printf("> Press 0 to quit the game\n");
    
    scanf("%d", &i);
    
    if(i == 1) {
        printf("The game has started\n\n");

        const char* questions[] = {
            "Which one is the first search engine in internet?",
            "Which one is the first web browser invented in 1990?",
            "First computer virus is known as?",
            "Firewall in computer is used for?",
            "Which of the following is not a database management software?"
        };

        const char* options[][4] = {
            {"Google", "Archie", "Wais", "Altavista"},
            {"Internet Explorer", "Mosaic", "Mozilla", "Nexus"},
            {"Rabbit", "Creeper Virus", "Elk Cloner", "SCA Virus"},
            {"Security", "Data Transmission", "Monitoring", "Authentication"},
            {"Mysql", "Oracle", "Cobal", "Sybase"}
        };

        int correctAnswers[] = {2, 4, 2, 1, 3};
        int scores[5];

        for(int j = 0; j < 5; j++) {
            askQuestion(j + 1, questions[j], options[j], correctAnswers[j], &scores[j]);
            totalScore += scores[j];
        }
        
        printf("Your total score is %d points\n", totalScore);

    } else if(i == 0) {
        printf("The game has ended\n\n");
    } else {
        printf("Invalid input\n\n");
    }
    
    return 0;
}
