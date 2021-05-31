#include "Model.hpp"

ModelX::ModelX():Carro()
{
    initTextures();
}
ModelX::~ModelX(){}

void ModelX::initTextures()
{
    texUp.loadTexture("res/upX.bmp");
    texDown.loadTexture("res/baseX.bmp");
}

//Model Y
ModelY::ModelY():Carro()
{
    initTextures();
}
ModelY::~ModelY(){}

void ModelY::initTextures()
{
    texUp.loadTexture("res/upY.bmp");
    texDown.loadTexture("res/baseY.bmp");
}
