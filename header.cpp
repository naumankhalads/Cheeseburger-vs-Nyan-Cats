#include"header.h"
void loadScores(int topScores[], const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < 3; ++i) {
            if (!(file >> topScores[i])) {
                topScores[i] = 0; // Default to 0 if file has no data
            }
        }
        file.close();
    }
    else {
        for (int i = 0; i < 3; ++i) {
            topScores[i] = 0; // Default to 0 if file does not exist
        }
    }
}
void saveScores(const int topScores[], const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < 3; ++i) {
            file << topScores[i] << endl;
        }
        file.close();
    }
}
void updateScores(int topScores[], int newScore) {
    for (int i = 0; i < 5; ++i) {
        if (newScore > topScores[i]) {
            for (int j = 2; j > i; --j) { // Shift lower scores down
                topScores[j] = topScores[j - 1];
            }
            topScores[i] = newScore; // Insert new score
            break;
        }
    }
}
// GameObject Implementation
GameObject::GameObject(int posX, int posY, int w, int h)
    : x(posX), y(posY), width(w), height(h) {}

GameObject::~GameObject() {}

int GameObject::getX() const { return x; }
int GameObject::getY() const { return y; }

void GameObject::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

// Cheeseburger Implementation
Cheeseburger::Cheeseburger(int x, int y, int w, int h)
    : GameObject(x, y, w, h), score(0), lives(3), shielded(false) {}

void Cheeseburger::move() {}
void Cheeseburger::move(string direction) {
    if (direction == "up" && y > 0) y--;
    else if (direction == "down" && y < 9) y++;
    else if (direction == "left" && x > 0) x--;
    else if (direction == "right" && x < 9) x++;
}

void Cheeseburger::draw() {
    cout << "Cheeseburger at (" << x << ", " << y << "), Lives: " << lives << ", Score: " << score << endl;
}

void Cheeseburger::decreaseLife() { if (!shielded) lives--; }
void Cheeseburger::increaseLife() { lives++; }
int Cheeseburger::getLives() const { return lives; }
void Cheeseburger::increaseScore(int points) { score += points; }
int Cheeseburger::getScore() const { return score; }
void Cheeseburger::activateShield() { shielded = true; }
void Cheeseburger::deactivateShield() { shielded = false; }
bool Cheeseburger::isShielded() const { return shielded; }

// NyanCat Implementation
NyanCat::NyanCat(int x, int y, int w, int h)
    : GameObject(x, y, w, h), fallSpeed(1) {}

void NyanCat::move() {
    y += fallSpeed;
    if (y > 9) { y = 0; x = rand() % 10; }
}

void NyanCat::draw() {
    cout << "NyanCat at (" << x << ", " << y << ")" << endl;
}

// Shield, Booster, and Friend Implementations
Shield::Shield(int x, int y, int w, int h)
    : GameObject(x, y, w, h) {}

void Shield::move() {
    y++;
    if (y > 9) { y = 0; x = rand() % 10; }
}

void Shield::draw() { cout << "Shield at (" << x << ", " << y << ")" << endl; }

Booster::Booster(int x, int y, int w, int h)
    : GameObject(x, y, w, h) {}

void Booster::move() {
    y++;
    if (y > 9) { y = 0; x = rand() % 10; }
}

void Booster::draw() { cout << "Booster at (" << x << ", " << y << ")" << endl; }

Friend::Friend(int x, int y, int w, int h)
    : GameObject(x, y, w, h) {}

void Friend::move() {
    y++;
    if (y > 9) { y = 0; x = rand() % 10; }
}

void Friend::draw() { cout << "Friend at (" << x << ", " << y << ")" << endl; }

// Game Implementation
Game::Game() : isGameOver(false), isPaused(false), level(1) {
    player = new Cheeseburger(5, 5, 2, 2);

    for (int i = 0; i < 5; i++) {
        nyanCats[i] = new NyanCat(rand() % 10, rand() % 10, 2, 2);
    }
    shield = new Shield(rand() % 10, 0, 2, 2);
    booster = new Booster(rand() % 10, 0, 2, 2);
    friendObj = new Friend(rand() % 10, 0, 2, 2);

    loadScores(topScores, scoreFile); // Load scores from file
}

Game::~Game() {
    delete player;
    for (int i = 0; i < 5; i++) delete nyanCats[i];
    delete shield;
    delete booster;
    delete friendObj;
}

void Game::render() {
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char grid[10][10];

    // Initialize grid with empty cells
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = '.';
        }
    }

    // Place objects on the grid
    grid[player->getY()][player->getX()] = '!'; // Cheeseburger
    for (int i = 0; i < 5; i++) {
        grid[nyanCats[i]->getY()][nyanCats[i]->getX()] = '@'; // NyanCats
    }
    grid[shield->getY()][shield->getX()] = 'S'; // Shield
    grid[booster->getY()][booster->getX()] = 'B'; // Booster
    grid[friendObj->getY()][friendObj->getX()] = 'F'; // Friend

    // Render the grid
    cout << endl << endl << endl;
    for (int i = 0; i < 10; i++) {
        cout << "\t\t\t\t\t\t";
        for (int j = 0; j < 10; j++) {
            char cell = grid[i][j];
            // Set colors
            switch (cell) {
            case '!':
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                break;
            case '@':
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                break;
            case 'S':
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                break;
            case 'B':
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                break;
            case 'F':
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                break;
            default:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            cout << cell << " ";
        }
        cout << endl;
    }

    // Reset console color to default
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "Lives: " << player->getLives() << "  Score: " << player->getScore() << "  Level: " << level << endl;
    cout << "'w' for up, 's' for down, 'd' for right, 'a' for left, 'p' for pause, 'q' for quit" << endl;
}

void Game::update() {
    for (int i = 0; i < 5; i++) {
        nyanCats[i]->move();
        if (player->getX() == nyanCats[i]->getX() && player->getY() == nyanCats[i]->getY()) {
            if (player->isShielded()) {
                player->deactivateShield();
            }
            else {
                player->decreaseLife();
            }
            if (player->getLives() <= 0) {
                isGameOver = true;
            }
        }
    }

    shield->move();
    booster->move();
    friendObj->move();

    if (player->getX() == shield->getX() && player->getY() == shield->getY()) {
        player->activateShield();
    }
    if (player->getX() == booster->getX() && player->getY() == booster->getY()) {
        player->increaseScore(10);
    }
    if (player->getX() == friendObj->getX() && player->getY() == friendObj->getY()) {
        player->increaseLife();
    }

    player->increaseScore(1);
}

void Game::checkLevelProgression() {
    int score = player->getScore();
    if (score == 100 || score == 200 || score == 300) {
        isPaused = true;
        cout << "Congratulations! You have reached Level " << (level + 1) << "!" << endl;
        cout << "Do you want to continue to the next level? If yes then press 'Y': ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            level++;
            isPaused = false;
        }
        else {
            isGameOver = true;
        }
    }
}

void Game::pauseGame() {
    isPaused = true;
    cout << "Game Paused! Press 'r' to resume." << endl;
    while (isPaused) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'r') {
                isPaused = false;
            }
        }
    }
}

void Game::play() {
    while (!isGameOver) {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
            case 'w':
            {
                player->move("up");
                break;
            }
            case 's':
            {
                player->move("down");
                break;
            }
            case 'a': {
                player->move("left");
                break;
            }
            case 'd': {
                player->move("right");
                break;
            }
            case 'p': {
                pauseGame();
                break;
            }// Pause the game when 'p' is pressed
            case 'q': {
                isGameOver = true;
                break;
            }// Quit the game when 'q' is pressed
            }
        }

        if (!isPaused) {
            update();
            checkLevelProgression();
            render();
            Sleep(200 - (level * 30)); // Increase game speed with levels
        }
    }
    cout << "Game Over! Final Score: " << player->getScore() << endl;
    // Update and save scores
    updateScores(topScores, player->getScore());
    saveScores(topScores, scoreFile);

    cout << "Top 3 Scores:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << topScores[i] << endl;
    }
}

