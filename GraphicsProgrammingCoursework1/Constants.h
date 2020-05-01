#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include "Aliases.h"

//Models

const string mario = "Mario";
const string marioFile = "..\\Resources\\Mario.obj";
const string monkeyFile = "..\\Resources\\monkey3.obj";

//Textures

const string texture1 = "joker";
//const string texture1File = "..\\Resources\\Joker_1.png";
const string texture1File = "..\\Resources\\Water.jpg";
const string skyboxFiles = "..\\Resources\\skybox_temp\\skybox";
const string skyboxFiles2 = "..\\Resources\\skybox_temp2\\blep";
const string nightSkyBoxFiles = "..\\Resources\\skybox_temp3\\night";

//Shaders

const string tempShader = "tempShader";
const string tempShaderVertFile = "..\\Resources\\quadMShader.vert";
const string tempShaderFragFile = "..\\Resources\\quadMShader.frag";

const string skyboxShaderName = "skybox";
const string skyboxShaderVertFile = "..\\Resources\\skyboxShader.vert";
const string skyboxShaderFragFile = "..\\Resources\\skyboxShader.frag";

const string explosionShaderName = "explosionShader";
const string explosionShaderGeomFile = "..\\Resources\\explosionShader.geom";
const string explosionShaderVertFile = "..\\Resources\\explosionShader.vert";
const string explosionShaderFragFile = "..\\Resources\\explosionShader.frag";

//Scenes

const string sceneName = "graphicsCourseworkScene";

//Window meta

const string windowTitle = "GraphicsProgrammingCourseWork";
const float windowWidth = 1024.0f;
const float windowHeight = 768.0f;

#endif