#include <iostream>
#include <conio.h>  // For kbhit() and _getch()
#include <windows.h> // For Sleep()
#include <cstdlib>

using namespace std;

class SnakeGame {
private:
    static const int WIDTH = 40;
    static const int HEIGHT = 15;
    
    int snakeX[300], snakeY[300]; // Arrays to hold snake body positions
    int snakeLength;
    int fruitX, fruitY; // Fruit position
    bool gameOver;
    char direction; // 'w' = up, 's' = down, 'a' = left, 'd' = right

public:
    SnakeGame() {
        Initialize();
    }

    void Initialize() {
        gameOver = false;
        direction = 'd'; // Default direction (right)
        snakeLength = 1;
        snakeX[0] = WIDTH / 2;
        snakeY[0] = HEIGHT / 2;

        // Random fruit position
        fruitX = rand() % (WIDTH - 2) + 1;
        fruitY = rand() % (HEIGHT - 2) + 1;
    }

    void Draw() {
        system("cls"); // Clear screen

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
                    cout << "*"; // Border
                else if (i == snakeY[0] && j == snakeX[0])
                    cout << "O"; // Snake head
                else if (i == fruitY && j == fruitX)
                    cout << "F"; // Fruit
                else {
                    bool isBodyPart = false;
                    for (int k = 1; k < snakeLength; k++) {
                        if (snakeX[k] == j && snakeY[k] == i) {
                            cout << "o"; // Snake body
                            isBodyPart = true;
                            break;
                        }
                    }
                    if (!isBodyPart) cout << " ";
                }
            }
            cout << endl;
        }
        cout << "Score: " << snakeLength - 1 << endl;
    }

    void Input() {
        if (_kbhit()) { // Check if a key was pressed
            char key = _getch();
            if ((key == 'w' && direction != 's') ||
                (key == 's' && direction != 'w') ||
                (key == 'a' && direction != 'd') ||
                (key == 'd' && direction != 'a'))
                direction = key;
        }
    }

    void Logic() {
        // Move the snake body
        for (int i = snakeLength; i > 0; i--) {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }

        // Move the snake head
        switch (direction) {
            case 'w': snakeY[0]--; break;
            case 's': snakeY[0]++; break;
            case 'a': snakeX[0]--; break;
            case 'd': snakeX[0]++; break;
        }

        // Check collision with walls
        if (snakeX[0] == 0 || snakeX[0] == WIDTH - 1 || snakeY[0] == 0 || snakeY[0] == HEIGHT - 1)
            gameOver = true;

        // Check collision with itself
        for (int i = 1; i < snakeLength; i++) {
            if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
                gameOver = true;
        }

        // Check if the snake eats the fruit
        if (snakeX[0] == fruitX && snakeY[0] == fruitY) {
            snakeLength++;
            fruitX = rand() % (WIDTH - 2) + 1;
            fruitY = rand() % (HEIGHT - 2) + 1;
        }
    }

    void Run() {
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(100); // Control speed
        }
        cout << "Game Over!" << endl;
    }
};

int main() {
    SnakeGame game;
    game.Run();
    return 0;
}
