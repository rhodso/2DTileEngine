//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include <tileImage.h>

//Constructor and Destructor
tileImage::tileImage(){}
tileImage::~tileImage(){}

//Getters and Setters
std::string tileImage::getFileRoot(){ return fileRoot; }
int tileImage::getState(){ return state; }
int tileImage::getMaxStates(){ return maxStates; }

void tileImage::setFileRoot( std::string _fileRoot){ fileRoot = _fileRoot; }
void tileImage::setState( int _state){ state = _state; }
void tileImage::setMaxStates( int _maxStates){ maxStates = _maxStates; }

//Other methods
void tileImage::incrementState(){
    //Ensure that the state never goes above max
    if(state == maxStates){
        state = 0;
    } else {
        state++;
    }
}
void tileImage::loadImages(std::string ext){
    try{
        //For every file in a given directory, check if it's a png and if it is then load it
        for (const auto & file : std::filesystem::directory_iterator(fileRoot)){
            //Create a temporary image
            ofImage tmp;

            //If the extention matches, load it and add to the vector
            if(file.path().extension() == ext){
                tmp.load(file.path());
                imageFiles.push_back(tmp);
                debugger::log("Loaded image: " + file.path().string());
            }
        }
        maxStates = imageFiles.size(); //Ensure that the maxState is set so we don't segFault
    } catch(std::exception e){
        //Catch errors from accessing file system in case something got deleted
        //Fucking users
        debugger::logErr(e.what());
    }
}
void tileImage::draw(float _x, float _y, bool stateChange, float _w, float _h){
    if(stateChange){ incrementState(); } //Change the state if we want
    if(_w == 0 && _h == 0){
        imageFiles[state].draw(_x, _y); //Draw the image
    } else {
        imageFiles[state].draw(_x, _y, _w, _h); //Draw the image, but scaled
    }
}

