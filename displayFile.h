#ifndef DISPLAY_FILE_H
#define DISPLAY_FILE_H

#include <vector>
#include "objects/displayFileObject.h"

class DisplayFile{
    private:
        std::vector<DisplayFileObject*> objects;
    public:
        DisplayFile();
        ~DisplayFile();
        void addObject(DisplayFileObject * obj);
        std::vector<DisplayFileObject*> getObjects();
};

#endif
