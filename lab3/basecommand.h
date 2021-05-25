#ifndef BASECOMMAND_H
#define BASECOMMAND_H

class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = 0;
    virtual void execute() = 0;
};

#endif // BASECOMMAND_H
