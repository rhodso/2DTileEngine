//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef TILEIMAGE_H
#define TILEIMAGE_H

//Includes
#include <string>
#include <ofMain.h>
#include <debugger.h>

class tileImage {
	public:
		//Constructor and Destructor
		tileImage();
		~tileImage();

		//Getters and Setters
		std::string getFileRoot();
		int getState();
		int getMaxStates();

		void setFileRoot( std::string _fileRoot );
		void setState( int _state );
		void setMaxStates( int _maxStates );

		//Other methods
		void incrementState();
        void draw(float _x, float _y, bool stateChange = true);
        void loadImages(std::string ext = ".png");

	private:
		//Variables
		std::string fileRoot;
		int state;
		int maxStates;
        std::vector<ofImage> imageFiles;

};
#endif
