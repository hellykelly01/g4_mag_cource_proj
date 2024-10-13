#include "Randomize.hh"
#include "SensitiveDetector.h"

PrimitivePhotonCounter::PrimitivePhotonCounter(G4String name) : count(0), G4VSensitiveDetector(name){}

void PrimitivePhotonCounter::ResetCounter(){
  count = 0;
}

G4int PrimitivePhotonCounter::GetCounter(){
  return count;
}

G4bool PrimitivePhotonCounter::ProcessHits(G4Step *step, G4TouchableHistory *){
  G4Track *track = step->GetTrack();
  if(track->GetParticleDefinition()->GetParticleName() == "opticalphoton"){
    if (G4UniformRand() < 0.28) ++count;
  }
  track->SetTrackStatus(fStopAndKill);
  return true;
}

