#pragma once

#include "Client.h"

using namespace std;

class Inspector : public Client
{
    private:

    public:
    Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger) :
    Client(x, y, width, height, sprite, burger) {}
};