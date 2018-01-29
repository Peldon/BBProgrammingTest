#pragma once

/* Base class for all game objects
 */
class Entity {
public:
    virtual void Tick() = 0;
};

