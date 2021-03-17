#ifndef ERROR_CODES_H
#define ERROR_CODES_H

enum error_code
{
    OK = 0,
    FILE_OPEN_ERROR = 1,
    FILE_NOT_FOUND = 2,
    FILE_ERROR = 3,
    MEMORY_ERROR = 4,
    MODEL_EMPTY = 5,
    //SCENE_NOT_FOUND
    ACTION_ERROR = -1
};

#endif // ERROR_CODES_H
