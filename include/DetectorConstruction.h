#ifndef DETECTOR_CONSTRUCTION_H
#define DETECTOR_CONSTRUCTION_H

#include "G4VUserDetectorConstruction.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;


class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  ~DetectorConstruction() = default;

  G4VPhysicalVolume* Construct() override;
  void ConstructSDandField() override;


protected:
  void DefineMaterials();
  G4Material* fLAB;
  G4Material* fScintillator = nullptr;
  G4Material* fStainlessSteel = nullptr;
  G4Material* fPMMA = nullptr;

  G4RotationMatrix* CalcRotation(const G4ThreeVector& targetPosition);

  G4bool fCheckOverlaps = false;

};


#endif // DETECTOR_CONSTRUCTION_H