#include"header.h"
void instructions() {
    system("cls");
    cout << "\t\t\t\t\t\tWelcome to the Cheeseburger Adventure Game!" << endl;
    cout << "\t\t\t\t\t\tInstructions:" << endl;
    cout << "\t\t\t\t\t\t1. Control the Cheeseburger ('!') using the following keys:" << endl;
    cout << "\t\t\t\t\t\t   - 'w': Move up" << endl;
    cout << "\t\t\t\t\t\t   - 's': Move down" << endl;
    cout << "\t\t\t\t\t\t   - 'a': Move left" << endl;
    cout << "\t\t\t\t\t\t   - 'd': Move right" << endl;
    cout << "\t\t\t\t\t\t2. Avoid NyanCats ('@') as they reduce your lives." << endl;
    cout << "\t\t\t\t\t\t3. Collect special items:" << endl;
    cout << "\t\t\t\t\t\t   - Shield ('S'): Grants temporary protection from NyanCats." << endl;
    cout << "\t\t\t\t\t\t   - Booster ('B'): Increases your score by 10 points." << endl;
    cout << "\t\t\t\t\t\t   - Friend ('F'): Adds an extra life." << endl;
    cout << "\t\t\t\t\t\t4. The game speeds up as your score increases. Reach higher scores to progress to new levels!" << endl;
    cout << "\t\t\t\t\t\t5. Controls during gameplay:" << endl;
    cout << "\t\t\t\t\t\t   - 'p': Pause the game" << endl;
    cout << "\t\t\t\t\t\t   - 'r': Resume the game" << endl;
    cout << "\t\t\t\t\t\t   - 'q': Quit the game" << endl;
    cout << "\t\t\t\t\t\tGood luck and enjoy the game!" << endl << endl;
    system("pause");
}
void printmenu() {
    system("cls");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t\t\t*      Nayan Cat And Cheese Burger      *" << endl;
    cout << "\t\t\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t\t\t1. Play Game" << endl;
    cout << "\t\t\t\t\t\t2. Instructions" << endl;
    cout << "\t\t\t\t\t\t3. Quit Game" << endl;
    cout << "\t\t\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t\t\t Enter Your Choice: ";
}

int main() {
    int choice;
    bool quit = true;
    while (quit == true) {
        printmenu();
        cin >> choice;
        if (choice == 1) {
            srand(time(0));
            Game game;
            game.play();
            system("pause");
        }
        if (choice == 2) {
            instructions();
        }
        if (choice == 3) {
            quit = false;
        }
    }
    return 0;
}
