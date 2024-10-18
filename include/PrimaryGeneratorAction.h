#ifndef PRIMARY_GENERATOR_ACTION_H
#define PRIMARY_GENERATOR_ACTION_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"

class G4ParticleGun;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  PrimaryGeneratorAction();
  ~PrimaryGeneratorAction();

  void GeneratePrimaries(G4Event*) override;

private:
  G4ParticleGun* fParticleGun = nullptr;  
  G4ThreeVector GenerateRandomDirection();
  G4ThreeVector GenerateRandomPosition();

};

#endif // PRIMARY_GENERATOR_ACTION_H

