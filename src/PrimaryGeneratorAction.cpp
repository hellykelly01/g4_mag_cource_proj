#include "G4ThreeVector.hh"

#include "PrimaryGeneratorAction.h"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction(){
  fParticleGun = new G4ParticleGun(1);

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle("e-");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.0, 0.0, 1.0));
  fParticleGun->SetParticleEnergy(1.0 * MeV);

}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
  fParticleGun->SetParticlePosition(G4ThreeVector(0.0, 0.0, 0.0));
  fParticleGun->GeneratePrimaryVertex(event);

}

PrimaryGeneratorAction::~PrimaryGeneratorAction() { delete fParticleGun; }