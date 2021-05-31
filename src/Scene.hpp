#ifndef SCENE_HPP_INCLUDED
#define SCENE_HPP_INCLUDED

#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <chrono>

#include "../util/Utilities.hpp"
#include "SkyBox.hpp"
#include "Camara.hpp"
#include "Carro.hpp"
#include "Model.hpp"
#include "Muro.hpp"
#include "Piso.hpp"

#define NUM_KARTS 4

#define FOVY 60.0
#define ZNEAR 0.01
#define ZFAR 120.0

class Scene
{
    private:
        std::chrono::steady_clock::time_point start;

        int w, h;
        float angle;
        SkyBox sky;
        Camara cam;
        ModelX mx,mx2;
        ModelY my,my2;
        Carro *karts[NUM_KARTS];
        Muro muro;
        Piso piso;

        bool arrowsP1[4];
        bool arrowsP2[4];
        bool player;

        void updateOthers();
        void updateMovement();
        void handleCollisions();
        void setFullViewport();
        void setHalfViewport(int,int);
        void draw(Carro*);
    public:
        Scene();
        ~Scene();

        void init();
        void setSinglePlayer(bool);
        void inputPressed(unsigned char,int,int);
        void inputReleased(unsigned char,int,int);
        void display();
        void setSize(int,int);
};

#endif // SCENE_HPP_INCLUDED
