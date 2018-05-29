//
//  LevelController.cpp
//  PleaseControlMe
//
//  Created by Jerry Kougianos on 30/05/2018.
//

#include "LevelController.hpp"
#include "ofUtils.h"


void LevelController::setup(float s) {
    start_time = s;
    interval_time = 500;
}

bool LevelController::should_spawn() {
    if (ofGetElapsedTimeMillis() - start_time > interval_time) {
        start_time = ofGetElapsedTimeMillis();
        return true;
    }
    return false;
}
