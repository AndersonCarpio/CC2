#include <iostream>
#include <vector>
#include <string>

// Memento class
class Memento {
private:
    std::string state;

public:
    Memento(const std::string& gameState) : state(gameState) {}

    std::string GetState() const {
        return state;
    }
};

// Originator class
class GameCharacter {
private:
    std::string state;

public:
    GameCharacter(std::string state_) :state(state_) {
        std::cout<<"Mi estado inicial es: "<< this->state << std::endl;
    }

    void SetState(const std::string& gameState) {
        state = gameState;
        std::cout<<"Mi estado ha sido cambiado a: "<<this->state<< std::endl;
    }

    Memento *SaveStateToMemento() {
        std::cout<<"Estado guardado: "<< this->state << std::endl;
        return new Memento(this->state);
    }

    void RestoreStateFromMemento(const Memento *memento) {
        state = memento->GetState();
        std::cout<<"Mi estado ha sido restaurado a: "<< this->state << std::endl;
    }

    void DisplayState() const {
        std::cout << "Estado actual: " << this->state << std::endl;
    }
};

// Caretaker class
class CheckpointManager {
private:
    std::vector<Memento *> mementos;
    GameCharacter *character;

public:
    CheckpointManager(GameCharacter *gamecharacter) : character(gamecharacter){

    }
    
    ~CheckpointManager() {
        for (auto m : mementos) delete m;
    }

    void AddMemento() {
        this->mementos.push_back(this->character->SaveStateToMemento());
    }

    Memento* GetMemento(int index) const {
        if (index >= 0 && index < mementos.size()) {
            return mementos[index];
        }
        throw std::out_of_range("Indice de memento invalido.");
    }
};

int main() {
    GameCharacter *character = new GameCharacter("Level 0");
    CheckpointManager *checkpointManager = new CheckpointManager(character);

    // Initial state
    character->SetState("Level 1");

    // Save current state
    checkpointManager->AddMemento();

    // Change state
    character->SetState("Level 2");
    character->DisplayState();

    // Save another state
    checkpointManager->AddMemento();

    // Restore previous state
    character->RestoreStateFromMemento(checkpointManager->GetMemento(0));
    character->DisplayState();

    // Restore the second saved state
    character->RestoreStateFromMemento(checkpointManager->GetMemento(1));
    character->DisplayState();

    return 0;
}
