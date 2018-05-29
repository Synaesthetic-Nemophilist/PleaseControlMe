//
//  Bullet.hpp
//  PleaseControlMe
//
//  Created by Jerry Kougianos on 29/05/2018.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "ofPoint.h"
#include "ofImage.h"

class Bullet {
public:
    ofPoint pos;
    ofPoint speed;
    float width;
    bool from_player;
    
    void setup(bool f_p, ofPoint p, ofPoint s, ofImage * bullet_image);
    void update();
    void draw();
    
    ofImage * img;
};


#endif /* Bullet_hpp */
