
#include "UbiMesh.h"
#include "UbiMeshConstants.h"
#include "Particle.h"


/**************************************************************************
* Constructors
***************************************************************************/
UbiMesh::UbiMesh();

/**************************************************************************
* Functions to SEND data to the mesh network and then Ubidots
***************************************************************************/
bool UbiMesh::ubiMeshPublish(const char * event_name, const char * variable_label, float value){
    char * name = (char *) malloc(sizeof(char) * MAX_NAME_SIZE);
    char * value = (char *) malloc(sizeof(char) * MAX_DATA_SIZE);

    sprintf(name, "%s/%s/%s", event_name, System.deviceID(), variable_label);
    sprintf(value, "%f", value);

    return Mesh.publish(name, value);

}
