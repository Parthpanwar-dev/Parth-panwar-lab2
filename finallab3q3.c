#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_TEAMS 5
#define SQUAD_SIZE 20

typedef struct {
    int day, month, year;
} date_t;

typedef struct {
    char name[25];
    int kitNumber;
    char club[30];
    date_t birthDate;
    char position[20];
} player_t;

typedef struct {
    char name[20];
    player_t players[SQUAD_SIZE];
    int activeSize;
} team_t;

// Function prototypes
void display_menu(team_t teams[], int* numTeams);
void enroll_club(team_t teams[], int* numTeams);
void add_player(team_t* team);
void search_update(team_t teams[], int numTeams);
void display_club_statistics(const team_t teams[], int numTeams);
void handle_error(const char* message);
int calculate_age(const date_t* birthDate);
bool is_duplicate_player(const team_t* team, const char* name, int kitNumber);

int main() {
    team_t teams[NUM_TEAMS] = {0}; // Initialize array of teams
    int numTeams = 0;

    display_menu(teams, &numTeams);
    return 0;
}

// Function to display the menu
void display_menu(team_t teams[], int* numTeams) {
    int choice;
    while (1) {
        printf("\n--- League Team Application Menu ---\n");
        printf("1. Enroll a club\n");
        printf("2. Add a player\n");
        printf("3. Search and update player details\n");
        printf("4. Display club statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enroll_club(teams, numTeams);
                break;
            case 2: {
                int teamIndex;
                printf("Enter team index to add a player (0 to %d): ", *numTeams - 1);
                scanf("%d", &teamIndex);
                if (teamIndex >= 0 && teamIndex < *numTeams) {
                    add_player(&teams[teamIndex]);
                } else {
                    handle_error("Invalid team index.");
                }
                break;
            }
            case 3:
                search_update(teams, *numTeams);
                break;
            case 4:
                display_club_statistics(teams, *numTeams);
                break;
            case 5:
                printf("Exiting the program.\n");
                return;
            default:
                handle_error("Invalid choice. Please try again.");
        }
    }
}

// Function to enroll a club
void enroll_club(team_t teams[], int* numTeams) {
    if (*numTeams >= NUM_TEAMS) {
        handle_error("Maximum number of teams reached.");
        return;
    }
    printf("Enter the club name: ");
    scanf(" %[^\n]", teams[*numTeams].name);
    teams[*numTeams].activeSize = 0;
    (*numTeams)++;
    printf("Club enrolled successfully.\n");
}

// Function to add a player to a team
void add_player(team_t* team) {
    if (team->activeSize >= SQUAD_SIZE) {
        handle_error("Maximum squad size reached for this team.");
        return;
    }

    player_t newPlayer;
    printf("Enter player name: ");
    scanf(" %[^\n]", newPlayer.name);
    printf("Enter kit number (1-99): ");
    scanf("%d", &newPlayer.kitNumber);
    printf("Enter birth date (dd mm yyyy): ");
    scanf("%d %d %d", &newPlayer.birthDate.day, &newPlayer.birthDate.month, &newPlayer.birthDate.year);
    printf("Enter position: ");
    scanf(" %[^\n]", newPlayer.position);

    if (is_duplicate_player(team, newPlayer.name, newPlayer.kitNumber)) {
        handle_error("Duplicate player name or kit number.");
        return;
    }

    team->players[team->activeSize] = newPlayer;
    team->activeSize++;
    printf("Player added successfully.\n");
}

// Function to check for duplicate players by name or kit number
bool is_duplicate_player(const team_t* team, const char* name, int kitNumber) {
    for (int i = 0; i < team->activeSize; i++) {
        if (strcmp(team->players[i].name, name) == 0 || team->players[i].kitNumber == kitNumber) {
            return true;
        }
    }
    return false;
}

// Function to search and update player details
void search_update(team_t teams[], int numTeams) {
    char searchName[25];
    int kitNumber;
    int choice;

    printf("Search by: 1. Name 2. Kit Number: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter player name: ");
        scanf(" %[^\n]", searchName);
        for (int i = 0; i < numTeams; i++) {
            for (int j = 0; j < teams[i].activeSize; j++) {
                if (strcmp(teams[i].players[j].name, searchName) == 0) {
                    printf("Player found in team %s. Enter new position: ", teams[i].name);
                    scanf(" %[^\n]", teams[i].players[j].position);
                    printf("Player details updated.\n");
                    return;
                }
            }
        }
        handle_error("Player not found.");
    } else if (choice == 2) {
        printf("Enter kit number: ");
        scanf("%d", &kitNumber);
        for (int i = 0; i < numTeams; i++) {
            for (int j = 0; j < teams[i].activeSize; j++) {
                if (teams[i].players[j].kitNumber == kitNumber) {
                    printf("Player found in team %s. Enter new position: ", teams[i].name);
                    scanf(" %[^\n]", teams[i].players[j].position);
                    printf("Player details updated.\n");
                    return;
                }
            }
        }
        handle_error("Player not found.");
    } else {
        handle_error("Invalid search choice.");
    }
}
// Function to display club statistics
void display_club_statistics(const team_t teams[], int numTeams) {
    for (int i = 0; i < numTeams; i++) {
        printf("\nTeam: %s\n", teams[i].name);
        printf("Number of players: %d\n", teams[i].activeSize);
        int totalAge = 0;

        for (int j = 0; j < teams[i].activeSize; j++) {
            const player_t* player = &teams[i].players[j]; // Use const player_t*
            int age = calculate_age(&player->birthDate);
            totalAge += age;
            printf("Player: %s, Kit Number: %d, Position: %s, Age: %d\n",
                   player->name, player->kitNumber, player->position, age);
        }
        printf("Average age of players: %.2f\n", (float)totalAge / teams[i].activeSize);
    }
}

// Function to calculate age of a player from birthdate
int calculate_age(const date_t* birthDate) {
    int currentYear = 2024;
    return currentYear - birthDate->year;
}

// Function to handle errors
void handle_error(const char* message) {
    printf("Error: %s\n", message);
}
