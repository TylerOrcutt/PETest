#pragma once
#include <ParalyzedEngine/Model.hpp>
class ThreeDTest{
PEWindow * pe;
PEModel * model;
    public:
    ThreeDTest(PEWindow * _pe){
        pe=_pe;
       model = new PEModel("../models/stall.obj");

    }
    void Render(){
         model->Draw();
    }

};