//
//  Enemy.hpp
//  PleaseControlMe
//
//  Created by Jerry Kougianos on 29/05/2018.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "ofPoint.h"
#include "ofImage.h"



class Enemy {
public:
    ofPoint pos;
    ofPoint speed;
    float amplitude;
    float width;
    
    float start_shoot;
    float shoot_interval;
    
    void setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage * enemy_image);
    void update();
    void draw();
    bool time_to_shoot();
    
    ofImage * img;
};
#endif /* Enemy_hpp */
