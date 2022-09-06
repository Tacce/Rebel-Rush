//
// Created by Francesco Taccetti on 11/07/2022.
//

#ifndef TACCETTIELABORATO_DEFINITIONS_H
#define TACCETTIELABORATO_DEFINITIONS_H

//SCREEN
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 675;

//PLAYER
const int PLAYER_DIMENSIONS = 60.0;
const int PLAYER_POSX = 200;
const float POINTS_FOR_FRAME = 0.1;
const int POINTS_MULTIPLIER = 100;
const int FIRE_COOLDOWN = 18;
const int DAMAGE_HEAL_COOLDOWN = 7;

//JUMP
const int GRAVITY = 20;
const int JUMP_FORCE = (-420);
const int MAX_YVELOCITY = 400;

//PROJECTILES
const int PROJECTILE_SPEED = 50;
const int PROJECTILE_COOLDOWN = 15;

//ENEMIES
const int ENEMY_DIMENSIONS = 60;
const int ENEMY_COOLDOWN = 45;
const float ENEMY_SPEED = 15;

//SWORD
const int SWORD_COOLDOWN = 25;
const int SWORD_DRAW_COOLDOWN = 12;
const int SWORD_ROTATION = 10;

//OBSTACLES
const int OBSTACLE_DIMENSION = 100;
const float OBSTACLE_SPEED = 12;
const int OBSTACLE_COOLDOWN = 80*2;
const int OBSTACLE_SPAN = 350;

//SHIELD
const int SHIELD_RADIUS = 30;
const float SHIELD_SPEED = 10;
const int SHIELD_SPRITE_RADIUS = 50;
const int SHIELD_PROBABILITY_HP = 500;
const int SHIELD_PROBABILITY_LEVEL = 300;
const int SHIELD_PROBABILITY_MAX = 330;

//GAME
const int GAMEOVER_COOLDOWN = 50;


#endif //TACCETTIELABORATO_DEFINITIONS_H
