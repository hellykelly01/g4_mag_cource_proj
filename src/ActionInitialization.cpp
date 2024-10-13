#include "ActionInitialization.h"
#include "PrimaryGeneratorAction.h"
#include "RunAction.h"
#include "EventAction.h"

void ActionInitialization::Build() const {
  SetUserAction(new PrimaryGeneratorAction);
  SetUserAction(new RunActionHook);
  SetUserAction(new EventActionHook);
}