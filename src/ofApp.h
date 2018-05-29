#pragma once

#include "ofMain.h"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "LevelController.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
        string game_state;
        int score;
    
        LevelController level_controller;
    
        Player player_1;
    
        ofImage player_image;
        ofImage enemy_image;
        ofImage enemy_bullet_image;
        ofImage player_bullet_image;
    
        float max_enemy_shoot_interval;
        float max_enemy_amplitude;
    
        vector<Enemy> enemies;
        vector<Bullet> bullets;
    
        void update_bullets();
        void check_bullet_collisions();
    
		
};
