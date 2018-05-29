//
//  Player.cpp
//  PleaseControlMe
//
//  Created by Jerry Kougianos on 28/05/2018.
//

#include "Player.hpp"
#include "ofApp.h"

void Player::setup(ofImage * _img){
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    img = _img;
    width = img->getWidth();
    height = img->getHeight();
}

void Player::update(){
    calculate_movement();
    pos.y += speed.y;
    pos.x += speed.x;
}

void Player::draw(){
    img->draw(pos.x - width/2, pos.y - height/2);
}

void Player::shoot(){
    
}

void Player::calculate_movement(){
    if(is_up_pressed){
        speed.y -= 0.5;
    }
    if(is_down_pressed){
        speed.y += 0.5;
    }
    if(is_left_pressed){
        speed.x -= 0.5;
    }
    if(is_right_pressed){
        speed.x += 0.5;
    }
}

bool Player::check_can_shoot(){
    
}
