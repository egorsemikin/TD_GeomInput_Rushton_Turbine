//
//  Header.h
//  TD_GeomInput_Rushton_Turbine
//
//  Created by Nile Ó Broin on 13/02/2019.
//  Copyright © 2019 Nile Ó Broin. All rights reserved.
//

#ifndef Rushton_Geometry_Config_hpp
#define Rushton_Geometry_Config_hpp


#include "define_typealias.h"





struct Baffles
{
    int num_baffles = 0;

    tGeomShape firstBaffleOffset = 0.0;

    tGeomShape innerRadius = 0.0f;
    tGeomShape outerRadius = 0.0f;
    tGeomShape thickness = 0.0f; // Half thickness a.k.a. symmetric thickness
};

struct Impellers
{
    int num_impellers = 0;

    tGeomShape theta = 0.0; // starting angle impeller

    tGeomShape innerRadius = 0.0;
    tGeomShape outerRadius = 0.0;
    tGeomShape bottom = 0.0;
    tGeomShape top = 0.0;
    tGeomShape bladeThickness = 0.0;
    tGeomShape w0 = 0.0; // max speed

};

struct Disk
{
    tGeomShape radius = 0.0;
    tGeomShape bottom = 0.0;
    tGeomShape top = 0.0;
};






class GeometryConfig
{
public:
    void setGeometryStartup(tStep starting_step, tGeomShape impeller_start_angle, tStep impeller_startup_steps_until_normal_speed);

    void setGeometryConfig(tNi snx, tGeomShape uav);



    int saveGeometryConfigAsJSON(std::string filepath);
    void loadGeometryConfigAsJSON(std::string filepath);


    // Instantaneous angular velocity impeller
    tGeomShape wa = 0.0;

    //Normal velocity at impeller tip
    tGeomShape uav = 0.0;


    tStep starting_step = 0;
    tGeomShape impeller_start_angle = 0.0;
    tStep impeller_startup_steps_until_normal_speed = 0;


    // Model resolution
    tGeomShape resolution = 0.0;
    tGeomShape tankDiameter = 0.0;
    tGeomShape shaftRadius = 0.0f;

    Baffles baffles;
    Impellers impellers;
    Disk disk;
    Disk hub;


};








#endif
