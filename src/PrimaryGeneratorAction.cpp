#include <cmath>

#include "PrimaryGeneratorAction.h"

#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4Sphere.hh"

G4ThreeVector PrimaryGeneratorAction::GenerateRandomDirection(){
  G4double theta = acos(1 - 2 * G4UniformRand());
  G4double phi = 2 * M_PI * G4UniformRand();
  return G4ThreeVector(sin(theta) * cos(phi), sin(theta) * sin(phi), cos(theta));
}

G4ThreeVector PrimaryGeneratorAction::GenerateRandomPosition(){
  auto store = G4LogicalVolumeStore::GetInstance();
  G4double R = dynamic_cast<G4Sphere*>(store->GetVolume("ScintSphere")->GetSolid())->GetOuterRadius();
  G4double r = R * pow(G4UniformRand(), 1.0 / 3.0);
  return GenerateRandomDirection() * r;
}

PrimaryGeneratorAction::PrimaryGeneratorAction(){
  fParticleGun = new G4ParticleGun(1);

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle("e-");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleMomentumDirection(GenerateRandomDirection());
  fParticleGun->SetParticleEnergy(1.0 * MeV);

}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
  fParticleGun->SetParticlePosition(GenerateRandomPosition());
  fParticleGun->GeneratePrimaryVertex(event);

}

PrimaryGeneratorAction::~PrimaryGeneratorAction() { delete fParticleGun; }