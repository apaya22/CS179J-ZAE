#include "snake_game.h"
#include "../home_os/home_config.h"

//=====================================
// TODO
//=====================================
/*
* need to integrate with the Home OS and update state machine for game logic
*/


SnakeGame snakeGame;
int lastScore = -1;
bool gameOverScreenRendered = false;
bool snakeGameNeedsFullRedraw = true;

//=====================================
// INIT
//=====================================

void initSnakeGame() {
  snakeGame.snakeLength = 3;
  snakeGame.dirX = 1;
  snakeGame.dirY = 0;
  snakeGame.nextDirX = 1;
  snakeGame.nextDirY = 0;
  snakeGame.score = 0;
  snakeGame.updateCounter = 0;
  lastScore = -1;
  gameOverScreenRendered = false;
  snakeGameNeedsFullRedraw = true;

  // Initialize snake in center
  for (int i = 0; i < 3; i++) {
    snakeGame.snake[i].x = 120 - (i * 8);
    snakeGame.snake[i].y = 135;  
  }

  // Random apple position (within game board bounds: x 0-240, y 30-240)
  snakeGame.appleX = random(1, SCREEN_W / 8) * 8;
  snakeGame.appleY = random(4, 30) * 8;  // From y=32 to y=240
}

//=====================================
// FRAME UPDATE
//=====================================


void updateSnakeGame() {
  snakeGame.updateCounter++;
  if (snakeGame.updateCounter < snakeGame.updateRate) return;
  snakeGame.updateCounter = 0;

  // Update direction
  snakeGame.dirX = snakeGame.nextDirX;
  snakeGame.dirY = snakeGame.nextDirY;

  // Move snake - add new head
  SnakeGame::Segment newHead;
  newHead.x = snakeGame.snake[0].x + snakeGame.dirX * snakeGame.gridSize;
  newHead.y = snakeGame.snake[0].y + snakeGame.dirY * snakeGame.gridSize;

  // Check boundaries (game board: x 0-240, y 30-240)
  if (newHead.x < 0 || newHead.x >= SCREEN_W || newHead.y < 30 || newHead.y >= 240) {
    return;  // Hit wall, game over
  }

  // Self collision check
  for (int i = 0; i < snakeGame.snakeLength; i++) {
    if (newHead.x == snakeGame.snake[i].x && newHead.y == snakeGame.snake[i].y) {
      return;  // Collision, let caller handle game over
    }
  }

  // Shift snake segments
  for (int i = snakeGame.snakeLength - 1; i > 0; i--) {
    snakeGame.snake[i] = snakeGame.snake[i - 1];
  }
  snakeGame.snake[0] = newHead;

  // Check apple collision
  if (newHead.x == snakeGame.appleX && newHead.y == snakeGame.appleY) {
    snakeGame.snakeLength++;
    snakeGame.score += 10;
    // Spawn apple within game board bounds (x 0-240, y 30-240)
    snakeGame.appleX = random(1, SCREEN_W / snakeGame.gridSize) * snakeGame.gridSize;
    snakeGame.appleY = random(4, 30) * snakeGame.gridSize;  // From y=32 to y=240
  }
}

//=====================================
// COLLISION DETECTION
//=====================================


bool checkSnakeCollision() {
  // Check wall collision (game board: x 0-240, y 30-240)
  if (snakeGame.snake[0].x < 0 || snakeGame.snake[0].x >= SCREEN_W ||
      snakeGame.snake[0].y < 30 || snakeGame.snake[0].y >= 240) {
    return true;
  }

  // Check self collision (head vs body)
  for (int i = 1; i < snakeGame.snakeLength; i++) {
    if (snakeGame.snake[0].x == snakeGame.snake[i].x &&
        snakeGame.snake[0].y == snakeGame.snake[i].y) {
      return true;
    }
  }
  return false;
}