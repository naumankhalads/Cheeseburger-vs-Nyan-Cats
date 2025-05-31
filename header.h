#include <iostream>
#include <string>
#include <cstdlib>
#include<fstream>
#include<conio.h>
#include <windows.h> // For colors
using namespace std;

// Base Class: GameObject
class GameObject {
protected:
    int x, y;
    int width, height;

public:
    GameObject(int posX, int posY, int w, int h);
    virtual ~GameObject();

    virtual void draw() = 0;
    virtual void move() = 0;

    int getX() const;
    int getY() const;
    void setPosition(int newX, int newY);
};

// Cheeseburger Class
class Cheeseburger : public GameObject {
private:
    int score;
    int lives;
    bool shielded;

public:
    Cheeseburger(int x, int y, int w, int h);

    void move() override;
    void move(string direction);
    void draw() override;

    void decreaseLife();
    void increaseLife();
    int getLives() const;
    void increaseScore(int points);
    int getScore() const;
    void activateShield();
    void deactivateShield();
    bool isShielded() const;
};

// NyanCat Class
class NyanCat : public GameObject {
private:
    int fallSpeed;

public:
    NyanCat(int x, int y, int w, int h);

    void move() override;
    void draw() override;
};

// Shield, Booster, and Friend Classes
class Shield : public GameObject {
public:
    Shield(int x, int y, int w, int h);

    void move() override;
    void draw() override;
};

class Booster : public GameObject {
public:
    Booster(int x, int y, int w, int h);

    void move() override;
    void draw() override;
};

class Friend : public GameObject {
public:
    Friend(int x, int y, int w, int h);

    void move() override;
    void draw() override;
};

// Game Class
class Game {
private:
    Cheeseburger* player;
    NyanCat* nyanCats[5];
    Shield* shield;
    Booster* booster;
    Friend* friendObj;
    bool isGameOver;
    bool isPaused;
    int level;
    int topScores[3]; // Array to store top 3 scores
    string scoreFile = "scores.txt";

public:
    Game();
    ~Game();

    void render();
    void update();
    void checkLevelProgression();
    void pauseGame();
    void play();
};


