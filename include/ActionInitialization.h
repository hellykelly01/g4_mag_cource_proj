#ifndef ACTION_INITIALIZATION_H
#define ACTION_INITIALIZATION_H

#include "G4VUserActionInitialization.hh"

class ActionInitialization : public G4VUserActionInitialization
{
  public:
    ActionInitialization() = default;
    ~ActionInitialization() override = default;

    void Build() const override;
};



#endif // ACTION_INITIALIZATION_H