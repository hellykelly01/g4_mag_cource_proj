#ifndef EVENT_ACTION_H
#define EVENT_ACTION_H

#include "G4UserEventAction.hh"

class EventActionHook : public G4UserEventAction{
public:
  EventActionHook() = default;
  ~EventActionHook() = default;
  void BeginOfEventAction(const G4Event*) override;
  void EndOfEventAction(const G4Event*) override;
};

#endif // EVENT_ACTION_H