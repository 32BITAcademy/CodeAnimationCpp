#pragma once
#ifndef _CA_LIB_
#define _CA_LIB_

#include "CodeAnimationController.h"
#include "TypeDefines.h"
#include "AlgorithmicOperators.h"

void CA_Init()
{
	ca::CodeAnimationController::Init();
}

void CA_Quit()
{
	ca::CodeAnimationController::Quit();
}
void CA_DebugMode()
{
	ca::CodeAnimationController::DebugMode();
}

#endif