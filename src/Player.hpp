//
//  Player.hpp
//  PleaseControlMe
//
//  Created by Jerry Kougianos on 28/05/2018.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "ofPoint.h"
#include "ofImage.h"



class Player {
public:
    ofPoint pos;
    ofPoint speed;
    float width, height;
    int lives;
    
    bool is_left_pressed, is_right_pressed, is_down_pressed, is_up_pressed;
    
    void setup(ofImage * _img);
    void update();
    void draw();
    void shoot();
    
    void calculate_movement();
    
    bool check_can_shoot();
    
    ofImage * img;
    
};


#endif /* Player_hpp */
