#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    game_state = "start";
    
    max_enemy_amplitude = 3.0;
    max_enemy_shoot_interval = 1.5;
    
    enemy_image.load("enemy0.png");
    player_image.load("player.png");
    enemy_bullet_image.load("enemy_bullet.png");
    player_bullet_image.load("player_bullet.png");
    
    player_1.setup(&player_image);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (game_state == "start") {
        
    } else if (game_state == "game") {
        player_1.update();
        update_bullets();
        
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].update();
            if (enemies[i].time_to_shoot()) {
                Bullet b;
                b.setup(false, enemies[i].pos, enemies[i].speed, &enemy_bullet_image);
                bullets.push_back(b);
            }
        }
        
        if (level_controller.should_spawn() == true) {
            Enemy e;
            e.setup(max_enemy_amplitude, max_enemy_shoot_interval, &enemy_image);
            enemies.push_back(e);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (game_state == "start") {
        
        // draw intro screen
        
    } else if (game_state == "game") {
        ofBackground(0,0,0);
        player_1.draw();
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].draw();
        }
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].draw();
        }
    } else if (game_state == "end") {
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (game_state == "game") {
        if (key == OF_KEY_LEFT) {
            player_1.is_left_pressed = true;
        }
        
        if (key == OF_KEY_RIGHT) {
            player_1.is_right_pressed = true;
        }
        
        if (key == OF_KEY_UP) {
            player_1.is_up_pressed = true;
        }
        
        if (key == OF_KEY_DOWN) {
            player_1.is_down_pressed = true;
        }
        
        if (key == ' ') {
            Bullet b;
            b.setup(true, player_1.pos, player_1.speed, &player_bullet_image);
            bullets.push_back(b);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (game_state == "start") {
        game_state = "game";
        level_controller.setup(ofGetElapsedTimeMillis());
    } else if (game_state == "game") {
        if (key == OF_KEY_LEFT) {
            player_1.is_left_pressed = false;
        }
        
        if (key == OF_KEY_RIGHT) {
            player_1.is_right_pressed = false;
        }
        
        if (key == OF_KEY_UP) {
            player_1.is_up_pressed = false;
        }
        
        if (key == OF_KEY_DOWN) {
            player_1.is_down_pressed = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update_bullets() {
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].update();
        if (bullets[i].pos.y - bullets[i].width/2 < 0 || bullets[i].pos.y + bullets[i].width/2 > ofGetHeight()) {
            bullets.erase(bullets.begin()+i);
        }
    }
    check_bullet_collisions();
}

//--------------------------------------------------------------
void ofApp::check_bullet_collisions() {
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].from_player) {
            for (int e = enemies.size()-1; e >= 0; e--) {
                if (ofDist(bullets[i].pos.x, bullets[i].pos.y, enemies[e].pos.x, enemies[e].pos.y) < (enemies[e].width + bullets[i].width)/2) {
                    enemies.erase(enemies.begin()+e);
                    bullets.erase(bullets.begin()+i);
                    score+=10;
                }
            }
        } else {
            if (ofDist(bullets[i].pos.x, bullets[i].pos.y, player_1.pos.x, player_1.pos.y) < (bullets[i].width+player_1.width)/2) {
                bullets.erase(bullets.begin()+i);
                player_1.lives--;
                
                if (player_1.lives <= 0) {
                    game_state = "end";
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
