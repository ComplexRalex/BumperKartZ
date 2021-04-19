#ifndef CARRO_HPP_INCLUDED
#define CARRO_HPP_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "GL/glut.h"
#include "../util/Utilities.hpp"
#include "BoundingSphere.hpp"
#include "Texture.hpp"

#define TEXTURE_LIMIT 4

class Carro
{
    protected:
        static int ID;
        int MyID;

        float radious;

        float posX,posY,posZ;   // pos = position
        float dirX,dirY,dirZ;   // dir = direction
        float velX,     velZ;   // vel = velocity
        float accX,     accZ;   // acc = acceleration
        float tX,tY,tZ;         // temporal position
        float direction;        // angle of direction
        float s_magnitude;      // step magnitude
        float r_magnitude;      // rotation magnitude

        BoundingSphere *boundingSphere;//The objects bounding sphere---UPDATE TO INCLUDE IN CONSTRUCTOR

        char* texFilename[TEXTURE_LIMIT];
        Texture tex;
        virtual void initTextures();    // this must be initialized inside derived classes

        void updateDirectionAngle();
        void updateDirection();
    public:
        Carro(float,float,float,float,float,float,float,float);
        Carro();
        ~Carro();

        int getID();
        float getRadious();
        void setRadious(float);
        void setPositionPoint(float,float,float);
        void setPosX(float);
        void setPosY(float);
        void setPosZ(float);
        float getPosX();
        float getPosY();
        float getPosZ();
        void setDirectionVector(float,float,float);
        void setDirX(float);
        void setDirY(float);
        void setDirZ(float);
        float getDirX();
        float getDirY();
        float getDirZ();
        void setVelocity(float,float);
        void setVelX(float);
        void setVelZ(float);
        float getVelX();
        float getVelZ();
        void setAcceleration(float,float);
        void setAccX(float);
        void setAccZ(float);
        float getAccX();
        float getAccZ();
        void setStepMagnitude(float);
        float getStepMagnitude();
        void setRotMagnitude(float);
        float getRotMagnitude();
        float getDirection();
        BoundingSphere* getBounds();

        // This function handles what will happend in case there is
        // a collition detected
        void handleCollisions(BoundingSphere*,int);

        virtual void draw() = 0;        // Función específica para dibujarlo
        virtual void update() = 0;      // Esto es específico para las animaciones que tenga.
        virtual void accelerateForward();     // Función especial para mover al objeto
        virtual void accelerateBackward();    // Función especial para mover al objeto
        virtual void moveRight();       // Función especial para mover al objeto
        virtual void moveLeft();        // Función especial para mover al objeto
        virtual void moveRewind();      // Función especial para rebobinar movimiento

        // Maybe some "actions", for instante, "explode" or something XD
};

#endif // CARRO_HPP_INCLUDED
