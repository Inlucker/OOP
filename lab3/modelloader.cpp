#include "modelloader.h"

#include "carcasmodelbuilder.h"
#include "modeldirector.h"
#include "fileloader.h"

ModelLoader::ModelLoader()
{
    fileLoader = shared_ptr<BaseFileLoader>(new FileLoader());
}

shared_ptr<Model> ModelLoader::loadModel(string fileName)
{
    //fileLoader->loadFile(fileName);
    fileLoader->open(fileName);

    shared_ptr<BaseModelBuilder> builder(new CarcasModelBuilder());
    shared_ptr<ModelDirector> director(new ModelDirector());

    shared_ptr<Model> prod = director->create(builder, fileLoader->loadFile());

    fileLoader->close();
    return prod;
}
