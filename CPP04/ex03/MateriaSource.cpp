#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < maxTemplates; i++) {
        templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < maxTemplates; i++) {
        if (other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < maxTemplates; i++) {
            delete templates[i];
            if (other.templates[i])
                templates[i] = other.templates[i]->clone();
            else
                templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < maxTemplates; i++) {
        delete templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;

    for (int i = 0; i < maxTemplates; i++) {
        if (!templates[i]) {
            templates[i] = m;
            return;
        }
    }
    delete m;  // If inventory is full, delete the materia
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < maxTemplates; i++) {
        if (templates[i] && templates[i]->getType() == type) {
            return templates[i]->clone();
        }
    }
    return NULL;
}
