#include <iostream>
#include "objParser.h"
#include <GL/glut.h>



using namespace obj_loader;
using namespace std;


int main() {
    load_obj lod;
    lod.read_obj();
    //readShaderFile(teapot);
}
