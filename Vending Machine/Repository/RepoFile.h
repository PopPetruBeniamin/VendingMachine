//
// Created by Usuario on 19/05/2024.
//

#ifndef LAB_9_10_FINAL_FINAL_REPOFILE_H
#define LAB_9_10_FINAL_FINAL_REPOFILE_H

#include <utility>
#include <fstream>
#include "Repo.h"

template<typename TElem>
class RepoFile : public Repo<TElem> {
private:
    std::string filename;
public:
    explicit RepoFile(std::string  filename) : filename(std::move(filename)) {
        loadFromFile();
    }

    void loadFromFile() {
        std::ifstream in(filename);

        // Verifica si el archivo se abrió correctamente
        if (!in.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        TElem elem;
        while (in >> elem) {
            // Verifica si hubo un error al leer del archivo
            if (in.fail()) {
                in.close();
                throw std::runtime_error("Failed to read from file");
            }

            this->repoElements.add(elem);
        }

        in.close();
    }

    void saveToFile() {
        TElem currentElement;
        std::fstream dataFile;

        dataFile.open(filename, std::ios::out);

        // Verifica si el archivo se abrió correctamente
        if (!dataFile.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        for (int i = 0; i < this->repoElements.size(); i++) {
            currentElement = this->repoElements[i];
            for(int j = 0; j < this->repoElements.nroccurrences(currentElement); j++) {
                dataFile << this->repoElements[i] << "\n";

                // Verifica si hubo un error al escribir en el archivo
                if (dataFile.fail()) {
                    throw std::runtime_error("Failed to write to file");
                }
            }
        }

        dataFile.close();
    }

    void addElement(const TElem& givenElement) override {
        Repo<TElem>::addElement(givenElement);

        std::fstream dataFile;
        dataFile.open(filename, std::ios::app);

        // Verifica si el archivo se abrió correctamente
        if (!dataFile.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        dataFile << givenElement << "\n";

        // Verifica si hubo un error al escribir en el archivo
        if (dataFile.fail()) {
            throw std::runtime_error("Failed to write to file");
        }

        dataFile.close();
    }

    void removeElement(const TElem& givenElement) override {
        Repo<TElem>::removeElement(givenElement);
        saveToFile();
    }

    void updateElement(const TElem& searchedElement, const TElem& givenElement) override {
        Repo<TElem>::updateElement(searchedElement, givenElement);
        saveToFile();
    }
};
#endif //LAB_9_10_FINAL_FINAL_REPOFILE_H
