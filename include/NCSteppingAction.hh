#ifndef NCSteppingAction_h
#define NCSteppingAction_h 1

#include "G4UserSteppingAction.hh"

#include "NCEventAction.hh"

class NCSteppingAction : public G4UserSteppingAction {
private:
  NCEventAction *fEventAction;

public:
  NCSteppingAction(NCEventAction *eventAction) :
    fEventAction(eventAction) {}

  void UserSteppingAction(const G4Step *step);
};

#endif
