//
//  Bullet.cpp
//  PleaseControlMe
//
//  Created by Jerry Kougianos on 29/05/2018.
//

#include "Bullet.hpp"


void Bullet::setup(bool f_p, ofPoint p, ofPoint s, ofImage * bullet_image) {
    from_player = f_p;
    pos = p;
    speed.x = s.x + 3;
    speed.y = s.y + 3;

    img = bullet_image;
    width = img->getWidth();
    
}
void Bullet::update() {
    if (from_player) {
        pos.y -= speed.y;
        pos.x -= speed.x;
    } else {
        pos.y += speed.y;
        pos.x += speed.x;
    }
}
void Bullet::draw() {
    img->draw(pos.x - width/2, pos.y - width/2);
    
}
