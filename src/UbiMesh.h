#ifndef _UbiMesh_H_
#define _UbiMesh_H_

#include "Particle.h"

class UbiMesh {

    public:
        explicit UbiMesh();
        explicit UbiMesh(const char * device_label);
        bool ubiMeshPublish(const char * event_name, const char * variable_label, float value);

    private:
        char * _default_device_label;

};

#endif