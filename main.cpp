#include "G4RunManager.hh"
#include "QBBC.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "FTFP_BERT.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"


#include "DetectorConstruction.h"
#include "ActionInitialization.h"

int main(int argc, char** argv){
  auto runManager = new G4RunManager;
  G4VModularPhysicsList* physicsList = new FTFP_BERT;
  physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());
  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();

  physicsList->RegisterPhysics(opticalPhysics);
  runManager->SetUserInitialization(physicsList);
  runManager->SetUserInitialization(new DetectorConstruction);
  runManager->SetUserInitialization(new ActionInitialization);


  runManager->Initialize();
  runManager->BeamOn(1000);

  //G4UIExecutive* ui = new G4UIExecutive(argc, argv);
  //G4VisManager* visManager = new G4VisExecutive;
  //visManager->Initialize();

  //G4UImanager* UImanager = G4UImanager::GetUIpointer();
  //UImanager->ApplyCommand("/run/bemOn 10000");
  //UImanager->ApplyCommand("/vis/open OGL");
  //UImanager->ApplyCommand("/vis/drawVolume");
  //UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
  //UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
  //ui->SessionStart();

  delete runManager;
  //delete visManager;

  return 0;
}