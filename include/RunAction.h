#ifndef RUN_ACTION_H
#define RUN_ACTION_H

#include "G4UserRunAction.hh"

class RunActionHook : public G4UserRunAction{
public:
  RunActionHook() = default;
  ~RunActionHook() = default;
  void BeginOfRunAction(const G4Run*) override;
  void EndOfRunAction(const G4Run*) override;
};

#endif // RUN_ACTION_H
