//
//  LevelController.hpp
//  PleaseControlMe
//
//  Created by Jerry Kougianos on 30/05/2018.
//

#ifndef LevelController_hpp
#define LevelController_hpp

#include <stdio.h>


class LevelController {
public:
    float start_time;
    float interval_time;
    
    void setup(float e);
    bool should_spawn();
};


#endif /* LevelController_hpp */
