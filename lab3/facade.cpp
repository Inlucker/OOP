#include "facade.h"

#include "basecommand.h"

Facade::Facade()
{

}

void Facade::execute(BaseCommand &cmd)
{
    cmd.execute();
}
