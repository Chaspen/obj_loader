// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include "objParser.h"
#include <GL/glut.h>
using namespace obj_loader;
using namespace std;

bool isFace = false;
bool isVert = false;


void load_obj::read_obj() {
    string teapot;
    ifstream teapotFile("teapot.obj");
    //ofstream teapotOutput ("teapot.txt");
    if (teapotFile.is_open())
    {
      while ( getline (teapotFile,teapot) )
      {
        //read contents of obj file
        //cout << teapot << '\n';
        

        //if starts with f then get faces
        
        if (teapot.front() == 'f') {
            //cout << "starts with f" << '\n';  
            
            isFace = true;       
        }
        else if (teapot.front() == 'v') {
            //cout << "starts with v" << '\n'; 
             
            isVert = true;
        }

        //is this line a face?
        if (isFace == true) {
            //cout << "cum";
            teapot.erase(0,2);
            std::replace(teapot.begin(), teapot.end(), ' ', ',');
            std::stoi(teapot);
            cout << teapot << "," << "\n";
            
           
        }

        else if (isVert == true) {
            //cout << "cum";
            teapot.erase(0,2);
            std::replace(teapot.begin(), teapot.end(), ' ', ',');
            std::stof(teapot);
            cout << teapot << "," << "\n";
        }
        
        

        
        //output contents of obj to txt file
        //teapotOutput << teapot << '\n';
      }

    }

    
    else cout << "Unable to open file"; 
}


