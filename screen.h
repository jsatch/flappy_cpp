#include "screenmanager.h"

class Screen
{
public:
    Screen(ScreenManager *manager);
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;
    virtual void dispose() = 0;
private:
    ScreenManager *manager;
};