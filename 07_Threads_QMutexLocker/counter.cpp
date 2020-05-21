#include "counter.h"

counter::counter(QObject *parent) : QObject(parent)
{

}

void counter::increment()
{
    value++;
}

void counter::decrement()
{
    value--;
}

int counter::count()
{
    return value;
}
