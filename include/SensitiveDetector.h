#ifndef SENSITIVE_DETECTOR_H
#define SENSITIVEDETECTOR_H

#include "G4VSensitiveDetector.hh"

class PrimitivePhotonCounter : public G4VSensitiveDetector{
public:
  PrimitivePhotonCounter(G4String);
  ~PrimitivePhotonCounter() = default;

  void ResetCounter();
  G4int GetCounter();

protected:
  G4bool ProcessHits(G4Step*, G4TouchableHistory*) override;

private:
  G4int count;
};

#endif // SENSITIVEDETECTOR_H
