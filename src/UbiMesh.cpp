
#include "UbiMesh.h"
#include "UbiMeshConstants.h"
#include "Particle.h"


/**************************************************************************
* Constructors
***************************************************************************/
UbiMesh::UbiMesh(){
    String particle_id_str = System.deviceID();
    _default_device_label = new char[particle_id_str.length() + 1];
    strcpy(_default_device_label, particle_id_str.c_str());
}

UbiMesh::UbiMesh(const char * device_label){
    _default_device_label = device_label;
}

/**************************************************************************
* Functions to SEND data to the mesh network and then Ubidots
***************************************************************************/
bool UbiMesh::ubiMeshPublish(const char * event_name, const char * variable_label, float value){
    char * name = (char *) malloc(sizeof(char) * MAX_NAME_SIZE);
    char * char_value = (char *) malloc(sizeof(char) * MAX_DATA_SIZE);

    sprintf(name, "%s/%s/%s", event_name, _default_device_label, variable_label);
    sprintf(char_value, "%f", value);

    delay(500);

    return Mesh.publish(name, value);

}
