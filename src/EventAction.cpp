#include <iostream>

#include "G4LogicalVolumeStore.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

#include "EventAction.h"
#include "SensitiveDetector.h"

void EventActionHook::BeginOfEventAction(const G4Event*){
  auto store = G4LogicalVolumeStore::GetInstance();
  auto sensDet = dynamic_cast<PrimitivePhotonCounter*>(store->GetVolume("PhotoMultiplier")->GetSensitiveDetector());
  sensDet->ResetCounter();
}

void EventActionHook::EndOfEventAction(const G4Event*){
  auto store = G4LogicalVolumeStore::GetInstance();
  auto *manager = G4AnalysisManager::Instance();
  auto EvtId =  G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
  auto sensDet = dynamic_cast<PrimitivePhotonCounter*>(store->GetVolume("PhotoMultiplier")->GetSensitiveDetector());
  G4int count = sensDet->GetCounter();
  std::cout << "EvtId: " << EvtId << " -> photon count: " << count << std::endl;
  manager->FillNtupleIColumn(0, count);
  manager->AddNtupleRow(0);
}