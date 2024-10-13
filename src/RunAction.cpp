#include "G4AnalysisManager.hh"

#include "RunAction.h"

void RunActionHook::BeginOfRunAction(const G4Run *run){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
    manager->CreateNtuple("photons", "photons");
    manager->CreateNtupleIColumn("count");
    manager->FinishNtuple(0);
    manager->OpenFile("file.root");

}

void RunActionHook::EndOfRunAction(const G4Run *run){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
    manager->Write();
    manager->CloseFile();
}