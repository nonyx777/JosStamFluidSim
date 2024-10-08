#pragma once

#include <random>
#include "../GameObject.hpp"
#include "../Entities/Entities.hpp"
#include "../Util/Gizmo.hpp"
#include "../Util/Grid.hpp"
#include "../Globals.hpp"
#include "../Util/Collision.hpp"
#include "Fluid.hpp"

class Scene : public GameObject
{
private:
    static Scene *instance;
    std::vector<std::vector<Box>> grid;
    Fluid fluid;

private:
    Scene();
    ~Scene();

public:
    // Delete copy constructor and assignment operator to prevent cloning
    Scene(const Scene &) = delete;
    Scene &operator=(const Scene &) = delete;

    static Scene *getInstance();

    void update(float dt) override;
    void update(sf::Vector2f &curPos, sf::Vector2f &prevPos, float dt);
    void render(sf::RenderTarget *target) override;

    void mouseDragged(int x, int y, float velX, float velY);
};