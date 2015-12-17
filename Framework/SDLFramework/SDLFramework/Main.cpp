#include "Context.h"
int main(int args[])
{
	Context* context{ new Context() };
	context->startApplication();
}